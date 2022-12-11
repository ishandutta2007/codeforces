#pragma GCC optimize(2)
#pragma GCC optimize(3)
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
    int u, v, val, id, tag;
    bool operator < (const ele A) const { return val < A.val; }
} a[N * 10];

struct edge_t { int u, v, next, val, id; } G[N << 1];

multiset <int> g[N];
multiset <int> :: iterator it;
vector <int> del[N];
int ans[N * 10], f[N], head[N], maxn[N][20], fa[N][20], id[N], d[N], trueid[N];
int n, m, tot;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

inline void addedge(int u, int v, int val, int id) {
    G[++tot] = (edge_t) {u, v, head[u], val, id}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v], val, id}, head[v] = tot;
}

void dfs1(int u, int f) {
    for(register int i = 1; i <= 19; i++) {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
        maxn[u][i] = max(maxn[u][i - 1], maxn[fa[u][i - 1]][i - 1]);
    }
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == f) continue;
        fa[v][0] = u; maxn[v][0] = G[i].val; id[v] = G[i].id; d[v] = d[u] + 1;
        dfs1(v, u);
    }
}

int lca(int u, int v) {
    if(d[u] < d[v]) swap(u, v);
    for(register int i = 19; i >= 0; i--) {
        if(d[fa[u][i]] >= d[v]) {
            u = fa[u][i];
        }
    }
    if(u == v) return u;
    for(register int i = 19; i >= 0; i--) {
        if(fa[u][i] != fa[v][i]) {
            u = fa[u][i]; v = fa[v][i];
        }
    }
    return fa[u][0];
}

int query(int u, int v) {
    int ans = 0;
    if(d[u] < d[v]) swap(u, v);
    for(register int i = 19; i >= 0; i--) {
        if(d[fa[u][i]] >= d[v]) {
            ans = max(ans, maxn[u][i]);
            u = fa[u][i];
        }
    }
    if(u == v) return ans;
    for(register int i = 19; i >= 0; i--) {
        if(fa[u][i] != fa[v][i]) {
            ans = max(ans, max(maxn[u][i], maxn[v][i]));
            u = fa[u][i]; v = fa[v][i];
        }
    }
    return max(ans, max(maxn[u][0], maxn[v][0]));
}

void dfs2(int u, int f) {
    trueid[u] = u;
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == f) continue;
        dfs2(v, u);
        if(g[trueid[v]].size() < g[trueid[u]].size()) {
            for(it = g[trueid[v]].begin(); it != g[trueid[v]].end(); ++it) g[trueid[u]].insert(*it);
            g[trueid[v]].clear();
        } else {
            for(it = g[trueid[u]].begin(); it != g[trueid[u]].end(); ++it) g[trueid[v]].insert(*it);
            g[trueid[u]].clear(); trueid[u] = trueid[v];
        }
    }
    if(u == 1) return;
    for(register unsigned i = 0; i < del[u].size(); i++) g[trueid[u]].erase(g[trueid[u]].find(del[u][i]));
    if(g[trueid[u]].size() == 0) ans[id[u]] = 1e9; else ans[id[u]] = *g[trueid[u]].begin();
}

int main() {
    read(n); read(m);
    for(register int i = 1; i <= m; i++) {
        read(a[i].u); read(a[i].v); read(a[i].val);
        a[i].id = i;
    }
    sort(a + 1, a + m + 1);
    for(register int i = 1; i <= n; i++) f[i] = i;
    for(register int i = 1; i <= m; i++) {
        int x = find(a[i].u), y = find(a[i].v);
        if(x != y) {
            f[x] = y; a[i].tag = 1;
            addedge(a[i].u, a[i].v, a[i].val, a[i].id);
        }
    }
    d[1] = 1; dfs1(1, 0);
    for(register int i = 1; i <= m; i++) {
        if(a[i].tag == 0) {
            ans[a[i].id] = query(a[i].u, a[i].v);
            int d = lca(a[i].u, a[i].v);
            g[a[i].u].insert(a[i].val); g[a[i].v].insert(a[i].val);
            del[d].push_back(a[i].val); del[d].push_back(a[i].val);
        }
    }
    dfs2(1, 0);
    for(register int i = 1; i <= m; i++) print(ans[i], '\n');
    return 0;
}