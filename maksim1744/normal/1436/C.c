/*
    author:  Maksim1744
    created: 24.10.2020 17:14:50
*/

#include <stdio.h>
#include <inttypes.h>

#define max(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a > _b ? _a : _b; })
#define min(a, b) ({ __typeof__ (a) _a = (a); __typeof__ (b) _b = (b); _a < _b ? _a : _b; })

#define mod 1000000007

int a[1005];

int main() {
    int n, x, pos;
    scanf("%d%d%d", &n, &x, &pos);
    for (int i = 0; i < n; ++i) {
        a[i] = 0;
    }
    int left = 0, right = n;
    while (left < right) {
        int middle = (left + right) / 2;
        if (pos < middle) {
            a[middle] = 1;
            right = middle;
        } else {
            a[middle] = -1;
            left = middle + 1;
        }
    }
    int bigger = 0, smaller = 0;
    for (int i = 0; i < n; ++i) {
        if (i != pos) {
            if (a[i] == 1) bigger++;
            else if (a[i] == -1) smaller++;
        }
        if (a[i] == 1 && i == pos) {
            printf("0\n");
            return 0;
        }
    }

    long long C[1005][1005];
    for (int i = 0; i < 1005; ++i) {
        C[0][i] = 0;
        C[i][0] = 1;
    }

    for (int i = 1; i < 1005; ++i) {
        for (int j = 1; j < 1005; ++j) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }

    // printf("%d %d\n", smaller, bigger);
    // for (int i = 0; i < n; ++i) {
    //     printf("%d ", a[i]);
    // }
    // printf("\n");

    long long f[1005];
    f[0] = 1;
    for (int i = 1; i < 1005; ++i)
        f[i] = (f[i - 1] * i) % mod;

    if (smaller > x - 1 || bigger > n - x) {
        printf("0\n");
        return 0;
    }

    long long res = C[x - 1][smaller] * C[n - x][bigger] % mod * f[smaller] % mod * f[bigger] % mod * f[n - smaller - bigger - 1] % mod;
    printf("%d\n", res);

    return 0;
}