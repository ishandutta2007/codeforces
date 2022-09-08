#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
#define DEBUG(x) cerr << "DEBUG" << x << " >>> " << endl;
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

const int N = 2e5 + 5, md = 1e9 + 7;

inline int add(int x, int y) {
    x += y;
    if(x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if(x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while(y) {
        if(y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

struct edge_t {
    int u, v, next;
} G[N << 1];

vector <int> adj[N];
int fa[N][20];
int head[N], pri[N], phi[N], isp[N], a[N], tops[N], d[N], st[N], pre[N], p[N], siz[N], f[N], g[N], mu[N];
int n, tot, len, dfn, top;

void init_t() {
    phi[1] = mu[1] = 1;
    for(register int i = 2; i <= 200000; i++) {
        if(!isp[i]) { pri[++len] = i; phi[i] = i - 1; mu[i] = md - 1; }
        for(register int j = 1; j <= len && i * pri[j] <= 200000; j++) {
            isp[i * pri[j]] = 1;
            if(i % pri[j] == 0) { phi[i * pri[j]] = phi[i] * pri[j]; break; }
            phi[i * pri[j]] = phi[i] * (pri[j] - 1); mu[i * pri[j]] = sub(0, mu[i]);
        }
    }
}

inline void addedge(int u, int v) {
    G[++tot] = (edge_t) {u, v, head[u]}, head[u] = tot;
    G[++tot] = (edge_t) {v, u, head[v]}, head[v] = tot;
}

bool cmp(int x, int y) { return tops[x] < tops[y]; }

void dfs1(int u, int father) {
    fa[u][0] = father; tops[u] = ++dfn;
    for(register int i = 1; i <= 18; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for(register int i = head[u]; i; i = G[i].next) {
        int v = G[i].v;
        if(v == father) continue;
        d[v] = d[u] + 1;
        dfs1(v, u);
    }
}

int LCA(int u, int v) {
    if(d[u] < d[v]) swap(u, v);
    for(register int i = 18; i >= 0; i--)
        if(d[fa[u][i]] >= d[v])
            u = fa[u][i];
    if(u == v) return u;
    for(register int i = 18; i >= 0; i--)
        if(fa[u][i] != fa[v][i])
            u = fa[u][i], v = fa[v][i];
    return fa[u][0];
}

ll ans;
int now;
void dfs2(int u) {
    siz[u] = a[u] % now == 0 ? phi[a[u]] : 0;
    ans = sub(ans, mul(siz[u], mul(siz[u], d[u])));
    for(register unsigned i = 0; i < adj[u].size(); i++) {
        int v = adj[u][i]; dfs2(v);
        ans = sub(ans, mul(mul(d[u], 2), mul(siz[u], siz[v])));
        siz[u] = add(siz[u], siz[v]);
    }
    // fprintf(stderr, "siz[%d] = %d\n", u, siz[u]);
}

int main() {
    init_t();
    read(n);
    for(register int i = 1; i <= n; i++) read(a[i]), pre[a[i]] = i;
    for(register int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        addedge(u, v);
    }
    d[1] = 1; dfs1(1, 0);
    for(register int d = 1; d <= n; d++) {
        ans = 0; now = d;
        int maxn = n / d;
        for(register int i = 1; i <= maxn; i++) p[i] = pre[i * d];
        sort(p + 1, p + maxn + 1, cmp);
        int root = p[1];
        for(register int i = 2; i <= maxn; i++) root = LCA(root, p[i]);
        adj[root].clear(); st[top = 1] = root;
        for(register int i = 1; i <= maxn; i++) {
            if(p[i] == root) continue;
            int lca = LCA(p[i], st[top]);
            if(lca != st[top]) {
                while(tops[lca] < tops[st[top - 1]]) {
                    adj[st[top - 1]].push_back(st[top]);
                    // fprintf(stderr, "addedge %d %d\n", st[top - 1], st[top]);
                    --top;
                }
                if(tops[lca] > tops[st[top - 1]]) {
                    adj[lca].clear();
                    adj[lca].push_back(st[top]);
                    // fprintf(stderr, "addedge %d %d\n", lca, st[top]);
                    st[top] = lca;
                } else {
                    // fprintf(stderr, "addedge %d %d\n", lca, st[top]);
                    adj[lca].push_back(st[top]), --top;
                }
            }
            // fprintf(stderr, "p[%d] = %d\n", i, p[i]);
            adj[p[i]].clear(); st[++top] = p[i];
        }
        for(register int i = 1; i < top; i++) adj[st[i]].push_back(st[i + 1]); // fprintf(stderr, "addedge %d %d\n", st[i], st[i + 1]);
        dfs2(root);
        ans = mul(ans, 2);
        int s1 = 0, s2 = 0;
        for(register int i = 1; i <= maxn; i++) s1 = add(s1, phi[a[p[i]]]), s2 = add(s2, mul(phi[a[p[i]]], ::d[p[i]]));
        ans = add(ans, mul(2, mul(s1, s2)));
        g[d] = ans;
        // fprintf(stderr, "s1 = %d, s2 = %d, g[%d] = %d\n", s1, s2, d, g[d]);
    }
    // g[1] = 14;
    for(register int i = 1; i <= n; i++) {
        for(register int j = i, cnt = 1; j <= n; j += i, cnt++) f[i] = add(f[i], mul(g[j], mu[cnt]));
    }
    ans = 0;
    for(register int i = 1; i <= n; i++) {
        // fprintf(stderr, "f[%d] = %d\n", i, f[i]);
        // fprintf(stderr, "mu[%d] = %d\n", i, mu[i]);
        ans = add(ans, mul(f[i], mul(i, fpow(phi[i], md - 2))));
    }
    // print(ans, '\n');
    print(mul(ans, fpow(mul(n, n - 1), md - 2)), '\n');
    return 0;
}