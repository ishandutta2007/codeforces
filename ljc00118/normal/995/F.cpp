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

const int N = 3005, md = 1e9 + 7;

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

vector <int> adj[N];
int f[N][N], fac[N], inv[N], s1[N], s2[N];
int n, d, ans;

void dfs1(int u) {
    for (int i = 1; i <= n + 1; i++) f[u][i] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i]; dfs1(v);
        for (int j = 1; j <= n + 1; j++) {
            f[u][j] = mul(f[u][j], f[v][j]);
        }
    }
    for (int i = 2; i <= n + 1; i++) f[u][i] = add(f[u][i], f[u][i - 1]);
}

int lagrange(int x) {
    for (int i = 1; i <= n + 1; i++) s1[i] = s2[i] = sub(x, i);
    for (int i = 2; i <= n + 1; i++) s1[i] = mul(s1[i - 1], s1[i]);
    for (int i = n; i >= 1; i--) s2[i] = mul(s2[i + 1], s2[i]);
    int ans = 0;
    for (int i = 1; i <= n + 1; i++) {
        int L = (i == 1 ? 1 : mul(s1[i - 1], inv[i - 1]));
        int R = (i == n + 1 ? 1 : mul(s2[i + 1], inv[n + 1 - i]));
        ans = add(ans, mul(mul(f[1][i], mul(L, R)), ((n + 1 - i) & 1) ? md - 1 : 1));
    }
    return ans;
}

int main() {
    read(n); read(d);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = mul(fac[i - 1], i);
    inv[n] = fpow(fac[n], md - 2);
    for (int i = n; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    for (int i = 2; i <= n; i++) {
        int fa; read(fa);
        adj[fa].push_back(i);
    }
    dfs1(1);
    print(lagrange(d), '\n');
    return 0;
}