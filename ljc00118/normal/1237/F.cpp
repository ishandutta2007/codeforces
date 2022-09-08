#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 3605, md = 998244353;

inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if(x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

int f[N][N], g[N][N], r[N], h[N], fac[N], inv[N];
int n, m, k, cr, ch, ans;

inline int C(int n, int m) {
    if(n < m) return 0;
    return mul(fac[n], mul(inv[m], inv[n - m]));
}

inline int A(int n, int m) {
    if(n < m) return 0;
    return mul(fac[n], inv[n - m]);
}

int main() {
    read(n); read(m); read(k);
    fac[0] = 1;
    for(register int i = 1; i <= N - 5; i++) fac[i] = mul(fac[i - 1], i);
    inv[N - 5] = fpow(fac[N - 5], md - 2);
    for(register int i = N - 5; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    for(register int i = 1; i <= k; i++) {
        int x, y;
        read(x); read(y); r[x] = h[y] = 1;
        read(x); read(y); r[x] = h[y] = 1;
    }
    f[0][0] = 1;
    for(register int i = 1; i <= n; i++) {
        cr += (r[i] == 0);
        memcpy(f[i], f[i - 1], sizeof(f[i]));
        if(i >= 2 && r[i] == 0 && r[i - 1] == 0) {
            for(register int j = 1; j <= n; j++) {
                f[i][j] = add(f[i][j], f[i - 2][j - 1]);
            }
        }
    }
    g[0][0] = 1;
    for(register int i = 1; i <= m; i++) {
        ch += (h[i] == 0);
        memcpy(g[i], g[i - 1], sizeof(g[i]));
        if(i >= 2 && h[i] == 0 && h[i - 1] == 0) {
            for(register int j = 1; j <= m; j++) {
                g[i][j] = add(g[i][j], g[i - 2][j - 1]);
            }
        }
    }
    for(register int i = 0; i <= n / 2; i++) {
        for(register int j = 0; j <= m / 2; j++) {
            if(f[n][i] && g[m][j]) {
                ans = add(ans, mul(mul(f[n][i], g[m][j]), mul(A(cr - i * 2, j), A(ch - j * 2, i))));
                // fprintf(stderr, "i = %d, j = %d, val = %d\n", i, j, mul(mul(f[n][i], g[m][j]), mul(A(cr - i * 2, j), A(ch - j * 2, i))));
            }
        }
    }
    print(ans, '\n');
    return 0;
}