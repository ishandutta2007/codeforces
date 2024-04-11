#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

template<int N>
struct segtree {
    int tree[N << 1];
    segtree() {
        fill(tree, tree + (N << 1), 0);
    }
    inline void update(int pos, int delta) {
        pos += N, tree[pos] += delta;
        for (pos >>= 1; pos; pos >>= 1) tree[pos] = tree[pos << 1] + tree[pos << 1 | 1];
    }
    inline int get(int l, int r) const {
        int sum = 0;
        for (l += N, r += N; l < r; l >>= 1, r >>= 1) {
            if (l & 1) sum += tree[l++];
            if (r & 1) sum += tree[--r];
        }
        return sum;
    }
};

const int N = 2e5 + 1;
const int LG = 19;
vec<int> g[N];
int n, m, par[N][LG], tin[N], tout[N], timer, sz[N], head[N];
segtree<N> sum_one, sum_all;
struct edge { int from, to, w; };
vec<edge> qry[N];
int dp[N];

void dfs1(int v) {
    sz[v] = 1;
    for (int i = 1; i < LG; i++) par[v][i] = par[par[v][i - 1]][i - 1];
    for (auto u : g[v]) {
        par[u][0] = v;
        dfs1(u);
        sz[v] += sz[u];
    }
    sort(all(g[v]), [&](int a, int b) { return sz[a] > sz[b]; });
}

inline bool is_par(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

inline int lca(int v, int u) {
    if (is_par(v, u)) return v;
    for (int i = LG - 1; i >= 0; i--) if (!is_par(par[v][i], u)) v = par[v][i];
    return par[v][0];
}

void dfs2(int v) {
    tin[v] = timer++;
    for (int i = 0; i < len(g[v]); i++) {
        int u = g[v][i];
        head[u] = (i ? u : head[v]);
        dfs2(u);
    }
    tout[v] = timer;
}

inline void update(int v, int delta, segtree<N> &tree) {
    tree.update(tin[v], delta);
}

inline int get(int v, int u, segtree<N> &tree) {
    int sum = 0;
    for (; head[v] != head[u]; v = par[head[v]][0]) sum += tree.get(tin[head[v]], tin[v] + 1);
    return sum + tree.get(tin[u], tin[v] + 1);
}

void dfs3(int v) {
    int tot = 0;
    for (auto u : g[v]) { dfs3(u); tot += dp[u]; }
    update(v, dp[v] = tot, sum_all);
    for (auto [a, b, w] : qry[v]) {
        if (tin[b] > tin[a]) swap(a, b);
        int sum_dp_a = get(a, v, sum_one);
        int tot_sum_a = get(a, v, sum_all);
        if (b == v) {
            dp[v] = max(dp[v], tot_sum_a - sum_dp_a + w);
        } else {
            int sum_dp_b = get(b, v, sum_one);
            int tot_sum_b = get(b, v, sum_all);
            dp[v] = max(dp[v], tot_sum_a - sum_dp_a + tot_sum_b - sum_dp_b - tot + w);
        }
    }
    update(v, dp[v], sum_one);
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        cin >> par[i][0], par[i][0]--;
        g[par[i][0]].push_back(i);
    }
    dfs1(0), dfs2(0);
    for (int i = 0; i < m; i++) {
        int v, u, w; cin >> v >> u >> w, v--, u--;
        qry[lca(v, u)].push_back({v, u, w});
    }
    dfs3(0);
    cout << dp[0] << '\n';
}