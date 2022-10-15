/**
 * @author Macesuted
 * @date 2021-01-07
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

#define mod 1000000007
#define maxn 1000005
#define maxlgn 25

int f[maxn][maxlgn][2];

int get(int a, int b) { return (1 << a) * (b ? 3 : 1); }

int main() {
    int n = read<int>(), lgn = log2(n);
    f[1][lgn][0] = 1;
    if ((1 << (lgn - 1)) * 3 <= n) f[1][lgn - 1][1] = 1;
    for (register int i = 2; i <= n; i++)
        for (register int j = 0; j <= lgn; j++) {
            for (register int k = 0; k < 2; k++) f[i][j][k] = 1LL * f[i - 1][j][k] * (n / get(j, k) - (i - 1)) % mod;
            if (j < lgn)
                for (register int k = 0; k < 2; k++)
                    f[i][j][k] = (f[i][j][k] + 1LL * f[i - 1][j + 1][k] * (n / get(j, k) - n / get(j + 1, k)) % mod) % mod;
            f[i][j][0] = (f[i][j][0] + 1LL * f[i - 1][j][1] * (n / get(j, 0) - n / get(j, 1)) % mod) % mod;
        }
    printf("%d\n", f[n][0][0]);
    return 0;
}