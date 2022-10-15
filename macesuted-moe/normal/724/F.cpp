/**
 * @author Macesuted
 * @date 2021-01-08
 *
 * @copyright Copyright (c) 2021
 *
 */

#include <bits/stdc++.h>
using namespace std;

#define bufferSiz (1 << 18)
char Buff[bufferSiz], *_S = Buff, *_T = Buff;
#define getchar() (_S == _T && (_T = (_S = Buff) + fread(Buff, 1, bufferSiz, stdin), _S == _T) ? EOF : *_S++)

template <typename T>
T read(void) {
    T f = 1, num = 0;
    char c = getchar();
    while (!isdigit(c)) {
        if (c == '-')
            f = -f;
        c = getchar();
    }
    while (isdigit(c)) {
        num = (num << 3) + (num << 1) + (c ^ 48);
        c = getchar();
    }
    return f * num;
}

int f[1005][15][1005];
int n, d, mod, half;

inline int Mod(int x) { return x >= mod ? x - mod : x; }

long long power(long long x, int k) {
    long long res = 1;
    while (k) {
        if (k & 1) res = res * x % mod;
        k >>= 1;
        x = x * x % mod;
    }
    return res;
}

inline int solve(int n, int m) {
    if (n < m) return 0;
    int up = 1, down = 1;
    for (register int i = n - m + 1; i <= n; i++) up = 1LL * up * i % mod;
    for (register int i = 1; i <= m; i++) down = 1LL * down * i % mod;
    return 1LL * up * power(down, mod - 2) % mod;
}

int main() {
    n = read<int>(), d = read<int>(), mod = read<int>(), half = n >> 1;
    if (n <= 2) return puts("1"), 0;
    for (int i = 0; i <= n; i++) f[1][0][i] = 1;
    f[1][d - 1][0] = 1;
    for (register int i = 2; i <= n; i++)
        for (register int j = 1; j <= min(i - 1, d); j++)
            for (register int k = 1; k <= half; k++) {
                f[i][j][k] = f[i][j][k - 1];
                for (register int t = 1; t * k <= i && t <= j; t++)
                    f[i][j][k] = Mod(f[i][j][k] + f[i - t * k][j - t][k - 1] * 1LL * solve(f[k][d - 1][k - 1] + t - 1, t) % mod);
            }
    // for (register int i = 1; i <= n; i++)
    //     for (register int j = 0; j <= d; j++)
    //         for (register int k = 1; k <= half; k++)
    //             if (f[i][j][k]) cerr << i << ' ' << j << ' ' << k << ' ' << f[i][j][k] << endl;
    printf("%d\n", (n & 1) ? f[n][d][half] : ((f[n][d][half] - solve(f[half][d - 1][half - 1], 2)) % mod + mod) % mod);
    return 0;
}