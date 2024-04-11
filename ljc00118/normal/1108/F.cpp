#include <cstdio>
#include <cstring>
#include <algorithm>

inline int read() {
    char c = getchar(); int x = 0;
    while (c < '0' || c > '9') { c = getchar(); }
    while (c >= '0' && c <= '9') { x = (x << 1) + (x << 3) + (c & 15); c = getchar(); }
    return x;
}

const int maxLog = 20, maxN = 200005;

int n, m, ans, logN, f[maxN], dep[maxN], fa[maxLog][maxN], g[maxLog][maxN];

struct Edge { int u, v, w; bool used; } e[maxN];
bool operator <(const Edge &x, const Edge &y) { return x.w < y.w; }

struct List {
    int len, fst[maxN], nxt[maxN << 1], v[maxN << 1], w[maxN << 1];
    
    List() { memset(fst, -1, sizeof(fst)); }
    inline void insert(int u, int vv, int ww) { v[len] = vv, w[len] = ww, nxt[len] = fst[u], fst[u] = len++; }
    inline void link(int u, int vv, int ww) { insert(u, vv, ww), insert(vv, u, ww); }
} ls;

int find(int u) { return f[u] == u ? u : f[u] = find(f[u]); }

void dfs(int u) {
    dep[u] = dep[fa[0][u]] + 1;
    for (int i = 1; i <= logN; i++) { fa[i][u] = fa[i - 1][fa[i - 1][u]]; g[i][u] = std::max(g[i - 1][u], g[i - 1][fa[i - 1][u]]); }
    for (int i = ls.fst[u]; ~i; i = ls.nxt[i]) {
        int v = ls.v[i], w = ls.w[i];
        if (v != fa[0][u]) { fa[0][v] = u; g[0][v] = w; dfs(v); }
    }
}

int query(int u, int v) {
    if (dep[u] < dep[v]) { std::swap(u, v); }
    int c = dep[u] - dep[v], max = 0;
    for (int i = logN; ~i; i--) {
        if (1 << i <= c) {
            c -= 1 << i;
            max = std::max(max, g[i][u]);
            u = fa[i][u];
        }
    }
    if (u == v) { return max; }
    for (int i = logN; ~i; i--) {
        if (fa[i][u] != fa[i][v]) {
            max = std::max(max, std::max(g[i][u], g[i][v]));
            u = fa[i][u]; v = fa[i][v];
        }
    }
    return std::max(max, std::max(g[0][u], g[0][v]));
}

int main() {
    n = read(); m = read();
    while (1 << logN + 1 <= n) { logN++; }
    for (int i = 1; i <= n; i++) { f[i] = i; }
    for (int i = 1; i <= m; i++) { e[i].u = read(); e[i].v = read(); e[i].w = read(); }
    std::sort(e + 1, e + m + 1);
    for (int i = 1; i <= m; i++) {
        if (find(e[i].u) != find(e[i].v)) {
            f[find(e[i].u)] = find(e[i].v);
            ls.link(e[i].u, e[i].v, e[i].w);
            e[i].used = true;
        }
    }
    dfs(1);
    for (int i = 1; i <= m; i++) {
        if (!e[i].used) { ans += query(e[i].u, e[i].v) == e[i].w; }
    }
    printf("%d\n", ans);
    return 0;
}