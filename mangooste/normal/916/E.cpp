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

const int N = 1e5 + 4;
const int LG = __lg(N) + 1;
vec<int> g[N];
int n, q, tin[N], tout[N], timer, a[N], par[N][LG];

void init(int v) {
    tin[v] = timer++;
    for (int i = 1; i < LG; i++) {
        par[v][i] = par[par[v][i - 1]][i - 1];
    }
    for (auto u : g[v]) {
        g[u].erase(find(all(g[u]), v));
        par[u][0] = v;
        init(u);
    }
    tout[v] = timer;
}

inline bool is_par(int v, int u) {
    return tin[v] <= tin[u] && tout[u] <= tout[v];
}

inline int lca(int v, int u, bool under_mod = false) {
    if (is_par(v, u)) swap(v, u);
    if (under_mod) assert(v != u);
    if (v == u) return v;
    for (int i = LG - 1; i >= 0; i--) {
        if (!is_par(par[v][i], u)) v = par[v][i];
    }
    return under_mod ? v : par[v][0];
}

struct segtree {
    int n;
    vec<ll> tree, mod;

    segtree() {}
    segtree(int n) : n(n), tree(4 * n), mod(4 * n) {}

    inline void push(int v, int vl, int vr) {
        if (vr - vl > 1) mod[v << 1] += mod[v], mod[v << 1 | 1] += mod[v];
        tree[v] += mod[v] * (vr - vl);
        mod[v] = 0;
    }

    inline void add(int l, int r, int delta) {
        add(1, 0, n, l, r, delta);
    }

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

    inline ll get(int l, int r) {
        return get(1, 0, n, l, r);
    }

    ll get(int v, int vl, int vr, int l, int r) {
        if (r <= vl || vr <= l) return 0;
        push(v, vl, vr);
        if (l <= vl && vr <= r) return tree[v];
        int vm = (vl + vr) / 2;
        return get(v << 1, vl, vm, l, r) + get(v << 1 | 1, vm, vr, l, r);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }
    init(0);
    segtree tree(n);
    for (int i = 0; i < n; i++) {
        tree.add(tin[i], tin[i] + 1, a[i]);
    }
    int root = 0;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            cin >> root, root--;
        } else if (type == 2) {
            int v, u, x;
            cin >> v >> u >> x, v--, u--;
            int w = (lca(v, u) ^ lca(v, root) ^ lca(u, root));
            if (w == root) {
                tree.add(0, n, x);
                continue;
            }
            if (w != lca(root, w)) {
                tree.add(tin[w], tout[w], x);
            } else {
                int r = lca(root, w, true);
                tree.add(0, n, x);
                tree.add(tin[r], tout[r], -x);
            }
        } else {
            int v;
            cin >> v, v--;
            if (v == root) {
                cout << tree.get(0, n) << '\n';
                continue;
            }
            if (v != lca(v, root)) {
                cout << tree.get(tin[v], tout[v]) << '\n';
            } else {
                int r = lca(v, root, true);
                cout << tree.get(0, n) - tree.get(tin[r], tout[r]) << '\n';
            }
        }
    }
}