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

const int N = 1e5 + 5, M = 2e5 + 5;

int sz[N], fa[N], dep[N], top[N], hson[N], f[N], dfn[N], dfncnt, pre[N];

vector<int> g[N];

int fd(int x) {
    return x == f[x] ? x : f[x] = fd(f[x]);
}

bool mg(int x, int y) {
    x = fd(x), y = fd(y);
    if (x == y) return 0;
    f[x] = y;
    return 1;
}

void dfs1(int u) {
    sz[u] = 1;
    for (int v: g[u]) {
        if (v == fa[u]) continue;
        dep[v] = dep[u] + 1, fa[v] = u;
        dfs1(v);
        sz[u] += sz[v];
        if (sz[v] > sz[hson[u]]) hson[u] = v;
    }
}

void dfs2(int u, int tp) {
    top[u] = tp; dfn[u] = ++dfncnt;
    pre[dfn[u]] = u;
    if (hson[u]) dfs2(hson[u], tp);
    for (int v: g[u]) {
        if (v == fa[u] || v == hson[u]) continue;
        dfs2(v, v);
    }
}

int la;

int lca(int x, int y) {
    while (top[x] != top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        la = top[x];
        x = fa[top[x]];
    }
    if (dep[x] < dep[y]) swap(x, y);
    if (x != y) la = pre[dfn[y] + 1];
    return y;
}

int n, m, U[M], V[M], c[N];

bool st[M];

void add(int x, int k) {
    c[dfn[x]] += k;
    c[dfn[x] + sz[x]] -= k;
}

int main() {
    read(n), read(m);
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= m; i++) {
        read(U[i]), read(V[i]);
        if (mg(U[i], V[i])) g[U[i]].pb(V[i]), g[V[i]].pb(U[i]);
        else st[i] = 1;
    }
    dfs1(1);
    dfs2(1, 1);
    int sm = 0;
    for (int i = 1; i <= m; i++) {
        if (st[i]) {
            ++sm;
            int x = U[i], y = V[i];
            if (dep[x] > dep[y]) swap(x, y);
            //cerr << i << " - " << x << " " << y << endl;
            int p = lca(x, y);
            if (x == p) {
                add(y, 1);
                add(1, 1);
                add(la, -1);
            } else {
                add(x, 1), add(y, 1);
            }
        }
    }
    for (int i = 1; i <= n; i++) c[i] += c[i - 1];
    for (int i = 1; i <= n; i++) {
        putchar(c[dfn[i]] == sm ? '1' : '0');
    }
    return 0;
}