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

const int N = 2005;

int n, P, f[N][N], s[N][N], ans[N], pr[N][N], sf[N][N], C[N][N];

vector<int> g[N];

void inline del(int &x, int y) {
    x -= y;
    if (x < 0) x += P;
}

void inline add(int &x, int y) {
    x += y;
    if (x >= P) x -= P;
}

void dfs(int u, int fa) {
    int sz = 0;
    vector<int> w;
    for (int v: g[u]) {
        if (v == fa) continue;
        dfs(v, u); ++sz;
        w.pb(v);
    }
    if (!sz) {
        for (int i = 1; i < n; i++) f[u][i] = 1;
    } else if (sz == 1) {
        int v = w[0];
        for (int i = 1; i < n; i++) {
            f[u][i] = (s[v][i] + 1ll * f[v][i] * (i - 1)) % P;
        }   
    } else {
        for (int i = 1; i < n; i++) {
            f[u][i] = 1;
            for (int v: w) f[u][i] = 1ll * f[u][i] * s[v][i] % P;
        }
        int len = w.size();
        for (int i = 0; i < len; i++) {
            for (int k = 1; k < n; k++) sf[i][k] = pr[i][k] = s[w[i]][k];
            if (i > 0) {
                for (int k = 1; k < n; k++)
                    pr[i][k] = 1ll * pr[i][k] * pr[i - 1][k] % P;
            }
        }
        for (int i = len - 2; i >= 0; i--) {
            for (int k = 1; k < n; k++)
                sf[i][k] = 1ll * sf[i][k] * sf[i + 1][k] % P;
        }
        for (int i = 0; i < len; i++) {
            int v = w[i];
            int t = 0;
            for (int k = 1; k < n; k++) {
                add(f[u][k], 1ll * f[v][k] * t % P);
                int z = 1;
                if (i > 0) z = 1ll * z * pr[i - 1][k] % P;
                if (i + 1 < len) z = 1ll * z * sf[i + 1][k] % P;
                add(t, z);
            }
        }
    }

    for (int i = 1; i < n; i++)
        s[u][i] = (s[u][i - 1] + f[u][i]) % P;
}

int main() {
    read(n), read(P);
    C[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
    }
    for (int i = 1, u, v; i < n; i++) ans[i] = 1, read(u), read(v), g[u].pb(v), g[v].pb(u);
    for (int v: g[1]) {
        dfs(v, 1);
        for (int k = 1; k < n; k++) {
            ans[k] = 1ll * ans[k] * s[v][k] % P;
        }
    }
    for (int i = 1; i < n; i++)
        for (int j = 1; j < i; j++) del(ans[i], 1ll * ans[j] * C[i][j] % P);
    for (int i = 1; i < n; i++) printf("%d ", ans[i]);
    return 0;
}