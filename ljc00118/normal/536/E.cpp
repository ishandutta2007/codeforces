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

template <typename T>
struct hash_map_t {
    vector <T> v, val, nxt;
    vector <int> head;
    int mod, tot, lastv;
    T lastans;
    bool have_ans;

    hash_map_t (int md = 0) {
        head.clear(); v.clear(); val.clear(); nxt.clear(); tot = 0; mod = md;
        nxt.resize(1); v.resize(1); val.resize(1); head.resize(mod);
        have_ans = 0;
    }

    void clear() { *this = hash_map_t(mod); }

    bool count(int x) {
        int u = x % mod;
        for(register int i = head[u]; i; i = nxt[i]) {
            if(v[i] == x) {
                have_ans = 1;
                lastv = x;
                lastans = val[i];
                return 1;
            }
        }
        return 0;
    }

    void ins(int x, int y) {
        int u = x % mod;
        nxt.push_back(head[u]); head[u] = ++tot;
        v.push_back(x); val.push_back(y);
    }

    int qry(int x) {
        if(have_ans && lastv == x) return lastans;
        count(x);
        return lastans;
    }
};

const int N = 1e5 + 5;

struct ele {
    int u, v, val, id;
    bool operator < (const ele A) const { return val < A.val; }
} G[N], Q[N];

vector <int> adj[N];
int f[N], siz[N], tops[N], wson[N], d[N], fa[N], top[N], ans[N];
int n, m, dfn, now = 1;

struct info { int left, right, sum, all; };

info merge(info a, info b) {
    info ans;
    ans.sum = a.sum + b.sum - f[a.right] - f[b.left] + f[a.right + b.left];
    ans.all = a.all + b.all;
    if(a.left == a.all) ans.left = a.all + b.left;
    else ans.left = a.left;
    if(b.right == b.all) ans.right = b.all + a.right;
    else ans.right = b.right;
    return ans;
}

struct node_t {
    int l, r;
    info val;
} p[N << 2];

void build(int u, int l, int r) {
    p[u].l = l; p[u].r = r;
    if(l == r) {
        p[u].val = (info) {1, 1, f[1], 1};
        return;
    }
    int mid = (l + r) >> 1;
    build(u << 1, l, mid); build(u << 1 | 1, mid + 1, r);
    p[u].val = merge(p[u << 1].val, p[u << 1 | 1].val);
}

void change(int u, int x) {
    if(p[u].l == p[u].r) {
        p[u].val = (info) {0, 0, 0, 1};
        return;
    }
    int mid = (p[u].l + p[u].r) >> 1;
    if(mid >= x) change(u << 1, x);
    else change(u << 1 | 1, x);
    p[u].val = merge(p[u << 1].val, p[u << 1 | 1].val);
}

info query(int u, int l, int r) {
    if(l <= p[u].l && p[u].r <= r) return p[u].val;
    int mid = (p[u].l + p[u].r) >> 1;
    info ans = (info) {0, 0, 0, 0};
    if(mid >= l) ans = query(u << 1, l, r);
    if(mid + 1 <= r) ans = merge(ans, query(u << 1 | 1, l, r));
    return ans;
}
 
void dfs1(int u, int f) {
    siz[u] = 1;
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == f) continue;
        d[v] = d[u] + 1; fa[v] = u;
        dfs1(v, u); siz[u] += siz[v];
        if(siz[v] > siz[wson[u]]) wson[u] = v;
    }
}

void dfs2(int u, int tp) {
    tops[u] = ++dfn; top[u] = tp;
    if(wson[u]) dfs2(wson[u], tp);
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i];
        if(v == fa[u] || v == wson[u]) continue;
        dfs2(v, v);
    }
}

int LCA(int u, int v) {
    while(top[u] != top[v]) {
        if(d[top[u]] < d[top[v]]) swap(u, v);
        u = fa[top[u]];
    }
    return d[u] < d[v] ? u : v;
}

info split(int u, int lca) {
    info ans = (info) {0, 0, 0, 0};
    while(top[u] != top[lca]) {
        ans = merge(query(1, tops[top[u]], tops[u]), ans);
        u = fa[top[u]];
    }
    if(u == lca) return ans;
    return merge(query(1, tops[lca] + 1, tops[u]), ans);
}

int main() {
    read(n); read(m);
    for(register int i = 1; i < n; i++) read(f[i]);
    for(register int i = 1; i < n; i++) {
        int u, v, val;
        read(u); read(v); read(val);
        adj[u].push_back(v);
        adj[v].push_back(u);
        G[i] = (ele) {u, v, val, 0};
    }
    for(register int i = 1; i <= m; i++) read(Q[i].u), read(Q[i].v), read(Q[i].val), Q[i].id = i;
    sort(G + 1, G + n); sort(Q + 1, Q + m + 1);
    dfs1(1, 0); dfs2(1, 1); build(1, 1, n);
    for(register int i = 1; i < n; i++) {
        while(now <= m && Q[now].val <= G[i].val) {
            int lca = LCA(Q[now].u, Q[now].v);
            info ans = split(Q[now].u, lca);
            swap(ans.left, ans.right);
            ans = merge(ans, split(Q[now].v, lca));
            ::ans[Q[now].id] = ans.sum;
            ++now;
        }
        int x = d[G[i].u] > d[G[i].v] ? G[i].u : G[i].v;
        change(1, tops[x]);
    }
    for(register int i = 1; i <= m; i++) print(ans[i], '\n');
    return 0;
}