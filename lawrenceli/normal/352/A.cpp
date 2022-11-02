#include <cstdio>

int n, x, y;

int main() {
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d", &a);
        if (a == 0) x++; else y++;
    }
    if (x == 0) printf("-1\n");
    else if (y / 9 == 0) printf("0\n");
    else {
        y = (y / 9) * 9;
        for (int i=0; i<y; i++) printf("5");
        for (int i=0; i<x; i++) printf("0");
    }
}