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

const int N = 3e5 + 5;

struct edge_t { int u, v, next, val; } G[N << 1];

vector <int> adj[N];
ll sum[N], f[N], g[N], ans[N];
int head[N], u[N], v[N], val[N], low[N], dfn[N], st[N], col[N], w[N], s[N], po[N];
int n, m, k, tot, dfn_t, col_t, top;

inline void addedge(int u, int v, int val) {
    G[++tot] = (edge_t) {u, v, head[u], val}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], val}, head[v] = tot;
}

void tarjan(int u, int fa) {
    low[u] = dfn[u] = ++dfn_t; st[++top] = u;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        if (!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        } else low[u] = min(low[u], dfn[v]);
    }
    if (low[u] == dfn[u]) {
        ++col_t;
        while (st[top + 1] != u) {
            int tmp = st[top--];
            col[tmp] = col_t;
            sum[col_t] += w[tmp];
        }
    }
}

void dfs1(int u, int fa) {
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (v == fa) continue;
        dfs1(v, u); s[u] += s[v];
        if (s[v] == k) s[u] = 0;
    }
}

void dfs2(int u, int fa) {
    f[u] = sum[u];
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (v == fa) continue;
        dfs2(v, u);
        f[u] += max(0ll, f[v] - G[i].val);
    }
}

void dfs3(int u, int fa) {
    g[u] += sum[u];
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (v == fa) continue;
        g[u] += max(0ll, f[v] - G[i].val);
    }
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (v == fa) continue;
        g[v] = max(0ll, g[u] - max(0ll, f[v] - G[i].val) - G[i].val);
        dfs3(v, u);
    }
}

void dfs4(int u, int fa, ll res) {
    ans[u] = res;
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (v == fa) continue;
        dfs4(v, u, res);
    }
}

int main() {
    read(n); read(m); read(k);
    for (int i = 1; i <= k; i++) read(po[i]);
    for (int i = 1; i <= n; i++) read(w[i]);
    for (int i = 1; i <= m; i++) read(val[i]);
    for (int i = 1; i <= m; i++) {
        read(u[i]); read(v[i]);
        adj[u[i]].push_back(v[i]);
        adj[v[i]].push_back(u[i]);
    }
    tarjan(1, 0);
    for (int i = 1; i <= k; i++) ++s[col[po[i]]];
    for (int i = 1; i <= m; i++) if (col[u[i]] != col[v[i]]) addedge(col[u[i]], col[v[i]], val[i]);
    dfs1(1, 0);
    for (int i = 1; i <= tot; i++) if (!s[G[i].u] || !s[G[i].v]) G[i].val = 0;
    dfs2(1, 0); dfs3(1, 0);
    for (int u = 1; u <= col_t; u++) {
        if (s[u]) {
            ans[u] = g[u];
            for (int i = head[u]; i; i = G[i].next) {
                int v = G[i].v;
                if (!s[v]) dfs4(v, u, g[u]);
            }
        }
    }
    for (int i = 1; i <= n; i++) print(ans[col[i]], i == n ? '\n' : ' ');
    return 0;
}