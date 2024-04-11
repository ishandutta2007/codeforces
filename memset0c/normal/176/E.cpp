// =================================
//   author: memset0
//   date: 2019.03.29 08:17:49
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
#define int long long
#define debug(...) ((void)0)
#ifndef debug
#define debug(...) fprintf(stderr,__VA_ARGS__)
#endif
namespace ringo {
template <class T> inline void read(T &x) {
    x = 0; register char c = getchar(); register bool f = 0;
    while (!isdigit(c)) f ^= c == '-', c = getchar();
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
    if (f) x = -x;
}
template <class T> inline void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) print(x / 10);
    putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 1e5 + 10;
int n, m, tim, dep[N], fa[N], top[N], son[N], siz[N], dfn[N];
ll ans, dis[N];
int tot = 2, hed[N], nxt[N << 1], val[N << 1], to[N << 1];

struct cmp { inline bool operator () (int a, int b) { return dfn[a] < dfn[b]; } };
std::set <int, cmp> set;

void dfs1(int u) {
    siz[u] = 1;
    for (int i = hed[u], v; v = to[i], i; i = nxt[i])
        if (v != fa[u]) {
            fa[v] = u, dis[v] = dis[u] + val[i], dep[v] = dep[u] + 1, dfs1(v), siz[u] += siz[v];
            if (siz[v] > siz[son[u]]) son[u] = v;
        }
}

void dfs2(int u, int tpt) {
    top[u] = tpt, dfn[u] = ++tim;
    if (siz[u] == 1) return;
    dfs2(son[u], top[u]);
    for (int i = hed[u], v; v = to[i], i; i = nxt[i])
        if (v != fa[u] && v != son[u])
            dfs2(v, v);
}

inline int lca(int u, int v) {
    if (!u || !v) return 0;
    while (top[u] != top[v]) {
        if (dep[top[u]] > dep[top[v]]) std::swap(u, v);
        v = fa[top[v]];
    } return dep[u] < dep[v] ? u : v;
}

inline int get(int u, int v) {
    // printf(">> get %d %d %d => %d %d %d\n", u, v, lca(u, v), dis[u], dis[v], dis[lca(u, v) << 1]);
    return !u || !v ? 0 : dis[u] + dis[v] - (dis[lca(u, v)] << 1);
}
inline ll solve(int x) {
    if (set.size() == 1) return 0;
    if (set.size() == 2) return get(*set.begin(), *++set.begin()) << 1;
    int a = 0, b = x, c = 0, d, e, f;
    auto it = set.find(x), tp = it;
    if (it != set.begin()) tp = it, a = *--tp;
    if ((tp = it, ++tp) != set.end()) c = *tp;
    if (!a) a = *--set.end();
    if (!c) c = *set.begin();
    // printf("solve %d %d %d : %d %d %d\n", a, b, c, get(a, b), get(b, c), get(a, c));
    // if (!a) return lca(b, c) == b ? ((dis[c] - dis[b]) << 1) : ((dis[b] - dis[lca(b, c)]) << 1);
    // if (!c) return lca(a, b) == b ? ((dis[a] - dis[b]) << 1) : ((dis[b] - dis[lca(a, b)]) << 1);
    return get(a, b) + get(b, c) - get(a, c);
}

void main() {
    read(n);
    for (int i = 1, u, v, w; i < n; i++) {
        read(u), read(v), read(w);
        nxt[tot] = hed[u], to[tot] = v, val[tot] = w, hed[u] = tot++;
        nxt[tot] = hed[v], to[tot] = u, val[tot] = w, hed[v] = tot++;
    }
    dep[1] = 1, dfs1(1), dfs2(1, 1);
    // for (int i = 1; i <= n; i++) print(dis[i], " \n"[i == n]);
    read(m);
    for (int i = 1, x, opt; i <= m; i++) {
        while (opt = getchar(), opt != '?' && opt != '+' && opt != '-');
        if (opt == '?') print(ans >> 1, '\n');
        else if (opt == '+') {
            read(x), set.insert(x), ans += solve(x);
        } else if (opt == '-') {
            read(x), ans -= solve(x), set.erase(x);
        }
    }
}

} signed main() { return ringo::main(), 0; }