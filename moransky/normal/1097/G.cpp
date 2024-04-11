// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1e5 + 5, M = 205, P = 1e9 + 7;

int n, k, z[M], p[N], ans, f[N][M], h[M], sz[N], C[M][M];

vector<int> g[N];


void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}
 
int inline power(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = (LL)res * a % P;
        a = (LL)a * a % P;
        b >>= 1;
    }
    return res;
}

int inv2 = (P + 1) / 2;

void inline prework() {
    for (int i = 1; i <= n; i++) {
        p[i] = (P + 1 - power(inv2, i)) % P;
    }
    C[0][0] = 1;
    for (int i = 1; i <= k; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % P;
    }
    z[1] = 1;
    for (int i = 2; i <= k; i++) {
        z[i] = power(i, k);
        for (int j = 1; j < i; j++)
            add(z[i], P - 1ll * z[j] * C[i][j] % P);
    }
}

void merge(int u, int v) {
    int A = min(sz[u], k), B = min(sz[v], k);
    for (int i = 0; i <= A; i++) {
        for (int j = 0; i + j <= k && j <= B; j++) {
            add(h[i + j], 1ll * f[u][i] * f[v][j] % P);
        }
    }
    sz[u] += sz[v];
    int C = min(sz[u], k);
    for (int i = 0; i <= C; i++) f[u][i] = h[i], h[i] = 0;
}

void inline upd(int u) {
    int C = min(sz[u], k);
    for (int i = 0; i <= C; i++) h[i] = f[u][i];
    for (int i = 0; i < C; i++) {
        int w = f[u][i];
        if (!i) w = 1ll * w * p[sz[u]] % P;
        add(ans, 1ll * w * p[n - sz[u]] % P * z[i + 1] % P);
        add(h[i + 1], w);
    }
    for (int i = 0; i <= C; i++) f[u][i] = h[i], h[i] = 0;
}

void dfs(int u, int fa) {
    f[u][0] = 1;
    sz[u] = 1;
    for (int v: g[u]) {
        if (v == fa) continue;
        dfs(v, u);
        merge(u, v);
    }
    for (int i = 1; i <= k; i++) h[i] = f[u][i];
    for (int v: g[u]) {
        if (v == fa) continue;
        for (int i = 1; i <= k; i++) add(h[i], P - f[v][i]);
    }
    for (int i = 1; i <= k; i++)
        add(ans, 1ll * h[i] * z[i] % P);
    for (int i = 1; i <= k; i++) h[i] = 0;
    if (u != 1) upd(u);
}

int main() {
    read(n), read(k);
    for (int i = 1, u, v; i < n; i++)
        read(u), read(v), g[u].pb(v), g[v].pb(u);
    prework();
    dfs(1, 0);
    ans = 1ll * ans * power(2, n) % P;
    printf("%d\n", ans);
    return 0;
}