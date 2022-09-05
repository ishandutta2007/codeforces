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

const int N = 1e6 + 5, INF = 1e8;

struct edge_t { int u, v, next, val; } G[N];

int seq[N], dep1[N], dep2[N], in[N], out[N], head[N], lg[N], x[N], y[N];
int n, m, len, tot;

inline void addedge(int u, int v, int val) {
    G[++tot] = (edge_t) {u, v, head[u], val}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], val}, head[v] = tot;
}

void dfs1(int u, int fa) {
    seq[++len] = u; in[u] = len;
    for (int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if (v == fa) continue;
        dep1[v] = dep1[u] + 1;
        dep2[v] = dep2[u] ^ G[i].val;
        dfs1(v, u);
        seq[++len] = u;
    }
    out[u] = len;
}

struct info { int lmax[2], rmax[2], maxv[2], minv, maxn; };

info merge(info a, info b) {
    info ans;
    ans.maxv[0] = max(a.maxv[0], b.maxv[0]);
    ans.maxv[1] = max(a.maxv[1], b.maxv[1]);
    ans.minv = min(a.minv, b.minv);
    ans.lmax[0] = max(max(a.lmax[0], b.lmax[0]), a.maxv[0] - 2 * b.minv);
    ans.lmax[1] = max(max(a.lmax[1], b.lmax[1]), a.maxv[1] - 2 * b.minv);
    ans.rmax[0] = max(max(a.rmax[0], b.rmax[0]), b.maxv[0] - 2 * a.minv);
    ans.rmax[1] = max(max(a.rmax[1], b.rmax[1]), b.maxv[1] - 2 * a.minv);
    ans.maxn = max(max(a.maxn, b.maxn), max(max(a.lmax[0] + b.maxv[0], a.lmax[1] + b.maxv[1]), max(b.rmax[0] + a.maxv[0], b.rmax[1] + a.maxv[1])));
    return ans;
}

struct node_t {
    int l, r, tag;
    info val;
} p[N << 2];

void add_tag(int u) {
    p[u].tag ^= 1;
    swap(p[u].val.lmax[0], p[u].val.lmax[1]);
    swap(p[u].val.rmax[0], p[u].val.rmax[1]);
    swap(p[u].val.maxv[0], p[u].val.maxv[1]);
}

void pushdown(int u) {
    if (p[u].tag) {
        add_tag(u << 1);
        add_tag(u << 1 | 1);
        p[u].tag = 0;
    }
}

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if (l == r) {
        p[u].val.maxn = 0;
        int _ = dep2[seq[l]];
        p[u].val.lmax[_] = p[u].val.rmax[_] = -dep1[seq[l]];
        p[u].val.maxv[_] = p[u].val.minv = dep1[seq[l]];
        p[u].val.lmax[_ ^ 1] = p[u].val.rmax[_ ^ 1] = p[u].val.maxv[_ ^ 1] = -INF;
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    p[u].val = merge(p[u << 1].val, p[u << 1 | 1].val);
}

void change(int u, int l, int r) {
    if (l <= p[u].l && p[u].r <= r) {
        add_tag(u);
        return;
    }
    pushdown(u);
    int mid = (p[u].l + p[u].r) >> 1;
    if (mid >= l) change(u << 1, l, r);
    if (mid + 1 <= r) change(u << 1 | 1, l, r);
    p[u].val = merge(p[u << 1].val, p[u << 1 | 1].val);
}

int main() {
    read(n);
    for (int i = 1; i < n; i++) {
        int u, v, w;
        read(u); read(v); read(w);
        addedge(u, v, w);
        x[i] = u; y[i] = v;
    }
    dfs1(1, 0); build(1, 1, len);
    read(m);
    for (int i = 1; i <= m; i++) {
        int id, u; read(id);
        u = (dep1[x[id]] < dep1[y[id]] ? y[id] : x[id]);
        change(1, in[u], out[u]);
        print(p[1].val.maxn, '\n');
    }
    return 0;
}