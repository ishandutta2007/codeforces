#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
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

struct segtree {
    struct node {
        int mx, cnt;

        node() : mx(0), cnt(0) {}

        inline node operator+(const node nd) const {
            node res;
            res.mx = max(mx, nd.mx);
            if (mx == res.mx) res.cnt += cnt;
            if (nd.mx == res.mx) res.cnt += nd.cnt;
            return res;
        }
    };

    int n;
    vec<node> tree;
    vec<int> mod;

    segtree() {}
    segtree(int n) : n(n), tree(4 * n), mod(4 * n) { build(1, 0, n); }

    void build(int v, int vl, int vr) {
        if (vr - vl == 1) {
            tree[v].mx = 0;
            tree[v].cnt = 1;
            return;
        }
        int vm = (vl + vr) / 2;
        build(v << 1, vl, vm);
        build(v << 1 | 1, vm, vr);
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }

    inline void push(int v, int vl, int vr) {
        if (!mod[v]) return;
        if (vr - vl > 1) mod[v << 1] += mod[v], mod[v << 1 | 1] += mod[v];
        tree[v].mx += mod[v];
        mod[v] = 0;
    }

    inline void add(int l, int r, int delta) { add(1, 0, n, l, r, delta); }
    void add(int v, int vl, int vr, int l, int r, int delta) {
        if (r <= vl || vr <= l) return;
        if (l <= vl && vr <= r) {
            mod[v] += delta;
            return;
        }
        push(v, vl, vr);
        int vm = (vl + vr) / 2;
        add(v << 1, vl, vm, l, r, delta);
        add(v << 1 | 1, vm, vr, l, r, delta);
        push(v << 1, vl, vm);
        push(v << 1 | 1, vm, vr);
        tree[v] = tree[v << 1] + tree[v << 1 | 1];
    }

    node get() {
        push(1, 0, n);
        return tree[1];
    }
};

const int N = 2e5 + 4;
const int LG = __lg(N) + 1;
vec<int> g[N];
int n, q, par[N][LG], tin[N], tout[N], timer;
segtree tree;

void dfs(int v) {
    tin[v] = timer++;
    for (int i = 1; i < LG; i++) {
        par[v][i] = par[par[v][i - 1]][i - 1];
    }
    for (auto u : g[v]) {
        if (u == par[v][0]) continue;
        par[u][0] = v;
        dfs(u);
    }
    tout[v] = timer;
}

inline bool is_par(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

inline int lca(int v, int u, bool under_mod = false) {
    assert(!is_par(v, u));
    for (int i = LG - 1; i >= 0; i--) {
        if (!is_par(par[v][i], u)) v = par[v][i];
    }
    return under_mod ? v : par[v][0];
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    dfs(0);
    tree = segtree(n);
    set<pair<int, int>> edges;
    while (q--) {
        int v, u;
        cin >> v >> u, v--, u--;
        if (tin[v] < tin[u]) swap(v, u);
        int p;
        if (edges.find({v, u}) == edges.end()) {
            p = 1;
            edges.insert({v, u});
        } else {
            p = -1;
            edges.erase({v, u});
        }
        int w = lca(v, u);
        if (w != u) {
            tree.add(tin[v], tout[v], p);
            tree.add(tin[u], tout[u], p);
        } else {
            tree.add(tin[v], tout[v], p);
            tree.add(0, n, p);
            w = lca(v, u, true);
            tree.add(tin[w], tout[w], -p);
        }
        auto val = tree.get();
        int ans = 0;
        assert(val.mx <= len(edges));
        if (val.mx == len(edges)) ans += val.cnt;
        cout << ans << '\n';
    }
}