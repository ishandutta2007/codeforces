/*
    author:  Maksim1744
    created: 23.10.2020 01:38:26
*/

#include <stdio.h>
#include <inttypes.h>

int main() {
    int n;
    scanf("%d", &n);
    int64_t f[25];
    f[0] = 1;
    for (int i = 1; i < 25; ++i)
        f[i] = f[i - 1] * i;

    int64_t C[25][25];
    for (int i = 0; i < 25; ++i) {
        C[0][i] = 0;
        C[i][0] = 1;
    }
    for (int i = 1; i < 25; ++i) {
        for (int j = 1; j < 25; ++j) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
    int64_t ans = C[n][n / 2] / 2;
    ans = ans * f[n / 2 - 1];
    ans = ans * f[n / 2 - 1];
    printf("%lld\n", ans);

    return 0;
}