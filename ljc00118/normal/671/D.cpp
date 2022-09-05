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

vector <int> adj[N];
int lc[N], rc[N], rt[N], dis[N], key[N], val[N], mn[N], tag[N], dep[N];
int n, m, tot; ll ans;

void update(int u) {
    mn[u] = min(val[u], min(mn[lc[u]], mn[rc[u]]));
    dis[u] = dis[rc[u]] + 1;
}

void add_tag(int u, int x) {
    val[u] += x;
    mn[u] += x;
    tag[u] += x;
}

void pushdown(int u) {
    if (tag[u]) {
        if (lc[u]) add_tag(lc[u], tag[u]);
        if (rc[u]) add_tag(rc[u], tag[u]);
        tag[u] = 0;
    }
}

inline int newNode(int v1, int v2) {
    ++tot; key[tot] = v1; val[tot] = v2;
    return update(tot), tot;
}

int merge(int u, int v) {
    if (!u || !v) return u | v;
    pushdown(u); pushdown(v);
    if (key[u] < key[v]) swap(u, v);
    rc[u] = merge(rc[u], v);
    if (dis[lc[u]] < dis[rc[u]]) swap(lc[u], rc[u]);
    return update(u), u;
}

void dfs1(int u, int fa) {
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        dep[v] = dep[u] + 1; dfs1(v, u);
    }
}

void dfs2(int u, int fa) {
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        dfs2(v, u); rt[u] = merge(rt[u], rt[v]);
    }
    if (u == 1) return;
    while (rt[u] && key[rt[u]] == dep[u]) {
        pushdown(rt[u]);
        rt[u] = merge(lc[rt[u]], rc[rt[u]]);
    }
    if (!rt[u]) {
        puts("-1");
        exit(0);
    }
    ans += mn[rt[u]]; add_tag(rt[u], -mn[rt[u]]);
}

int main() {
    mn[0] = 1e9;
    read(n); read(m);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs1(1, 0);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        read(u); read(v); read(w);
        rt[u] = merge(rt[u], newNode(dep[v], w));
    }
    dfs2(1, 0);
    print(ans, '\n');
    return 0;
}