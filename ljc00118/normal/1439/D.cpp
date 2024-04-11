#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 505;

int n, m, md;

inline int add(int x, int y) {
    x += y;
    if (x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if (x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

int fac[N], inv[N], f[N], g[N], dp[N][N][2], dp2[N][N][2];

inline int C(int n, int m) {
    return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
    read(n); read(m); read(md);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
    inv[n] = fpow(fac[n], md - 2);
    for (int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    f[0] = 0; g[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            int now = mul(C(i - 1, j - 1), i + 1);
            g[i] = add(g[i], mul(mul(g[j - 1], g[i - j]), now));
            f[i] = add(f[i], mul(mul(f[j - 1], g[i - j]), now));
            f[i] = add(f[i], mul(mul(g[j - 1], f[i - j]), now));
            f[i] = add(f[i], mul(mul(C(i - 1, j - 1), mul(g[j - 1], g[i - j])), (j - 1) * j / 2 + (i - j) * (i - j + 1) / 2));
        }
        // fprintf(stderr, "f[%d] = %d, g[%d] = %d\n", i, f[i], i, g[i]);
    }
    dp[0][0][1] = 0; dp2[0][0][1] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            dp[i][j][1] = add(dp[i - 1][j][0], dp[i - 1][j][1]);
            dp2[i][j][1] = add(dp2[i - 1][j][0], dp2[i - 1][j][1]);
            for (int k = 1; k <= j; k++) {
                dp[i][j][0] = add(dp[i][j][0], mul(C(j, k), mul(dp2[i - k][j - k][1], f[k])));
                dp[i][j][0] = add(dp[i][j][0], mul(C(j, k), mul(dp[i - k][j - k][1], g[k])));
                dp2[i][j][0] = add(dp2[i][j][0], mul(C(j, k), mul(dp2[i - k][j - k][1], g[k])));
            }
        }
    }
    print(add(dp[n][m][0], dp[n][m][1]), '\n');
    return 0;
}