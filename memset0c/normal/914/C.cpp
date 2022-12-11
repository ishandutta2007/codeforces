// =================================
//   author: memset0
//   date: 2018.12.05 19:17:50
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define int long long
namespace ringo {
typedef long long ll;

template < class T >
inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}

template < class T >
inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}

template < class T >
inline void print(T x, char c) {
    print(x), putchar(c);
}

const int N = 1e3 + 10, mod = 1e9 + 7;
int n, m, ans;
int a[N], stp[N], f[2][N][2];
char s[N];

void main() {
    scanf("%s", s + 1), n = strlen(s + 1), read(m);
    if (m == 0) { puts("1"); return; }
    for (int i = 1; i <= n; i++) a[i] = s[i] - '0';
    for (int i = 2; i <= n; i++)
        stp[i] = stp[__builtin_popcount(i)] + 1;
    f[0][0][1] = 1;
    for (int i = 1; i <= n; i++) {
        memset(f[i & 1], 0, sizeof(f[i & 1]));
        for (int j = 0; j < i; j++)
            if (a[i]) {
                (f[i & 1][j][0] += f[(i & 1) ^ 1][j][0]) %= mod;
                (f[i & 1][j][0] += f[(i & 1) ^ 1][j][1]) %= mod;
                (f[i & 1][j + 1][0] += f[(i & 1) ^ 1][j][0]) %= mod;
                (f[i & 1][j + 1][1] += f[(i & 1) ^ 1][j][1]) %= mod;
            } else {
                (f[i & 1][j][0] += f[(i & 1) ^ 1][j][0]) %= mod;
                (f[i & 1][j][1] += f[(i & 1) ^ 1][j][1]) %= mod;
                (f[i & 1][j + 1][0] += f[(i & 1) ^ 1][j][0]) %= mod;
            }
    }
    for (int i = 1; i <= n; i++) {
        int v = (f[n & 1][i][0] + f[n & 1][i][1]) % mod;
        if (stp[i] == m - 1)
            (ans += v) %= mod;
    }
    if (m == 1) ans = (ans - 1 + mod) % mod;
    print(ans % mod, '\n');
}

} signed main() { return ringo::main(), 0; }