#include <stdio.h>

int nhanGF4(int a, int b) {
    int kq = 0;
    for (int i = 0; i < 4; i++) {
        if (b & 1) {
            kq = kq ^ a;
        }
        b = b >> 1;
        a = a << 1;
        if (a & 0x10) {
            a = a ^ 0x13;
        }
    }
    return kq;
}

int nhanGF8(int a, int b) {
    int kq = 0;

    for (int i = 0; i < 8; i++) {
        if (b & 1) {
            kq = kq ^ a;
        }
        b = b >> 1;
        a = a << 1;
        if (a & 0x100) {
            a = a ^ 0x11B;
        }
    }
    return kq;
}

int main() {
    int a, b;
    int chon;
    printf("Chon phep tinh:\n");
    printf("1. Nhan trong GF(2^4)\n");
    printf("2. Nhan trong GF(2^8)\n");
    printf("Chon: ");
    scanf("%d", &chon);
    printf("Nhap a (he 16): ");
    scanf("%x", &a);
    printf("Nhap b (he 16): ");
    scanf("%x", &b);
    if (chon == 1) {
        if (a < 0 || a > 15 || b < 0 || b > 15) {
            printf("Gia tri khong hop le!\n");
            return 1;
        }
        int kq = nhanGF4(a, b);
        printf("Ket qua GF(2^4): %X\n", kq);
    }
    else if (chon == 2) {
        if (a < 0 || a > 255 || b < 0 || b > 255) {
            printf("Gia tri khong hop le!\n");
            return 1;
        }
        int kq = nhanGF8(a, b);
        printf("Ket qua GF(2^8): %X\n", kq);
    }
    else {
        printf("Lua chon khong hop le!\n");
    }
    return 0;
}
