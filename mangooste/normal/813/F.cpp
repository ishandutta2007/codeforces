#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) begin(a), end(a)
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

struct DSU  {
    struct event {
        int v, u, prev_flipped;
        bool prev_valid;
    };

    int n;
    vec<int> par, sz, flipped;
    bool valid;
    vec<event> events;

    DSU() {}
    DSU(int n) : n(n), par(n), sz(n, 1), flipped(n), valid(true) { iota(all(par), 0); }

    inline int color(int v) {
        return par[v] == v ? 0 : (color(par[v]) ^ 1 ^ flipped[v]);
    }

    inline int get_par(int v) {
        return par[v] == v ? v : get_par(par[v]);
    }

    inline void unite(int v, int u) {
        int pv = v, pu = u;
        v = get_par(v), u = get_par(u);
        bool x = color(pv) != color(pu);
        if (v == u) {
            events.push_back({-1, -1, -1, valid});
            valid &= x;
            return;
        }
        if (sz[v] < sz[u]) swap(v, u);
        par[u] = v;
        sz[v] += sz[u];
        events.push_back({v, u, flipped[u], valid});
        flipped[u] ^= x;
    }

    inline void roll_back() {
        auto [v, u, prev_flipped, prev_valid] = events.back();
        events.pop_back();
        valid = prev_valid;
        if (v == -1) return;
        par[u] = u;
        sz[v] -= sz[u];
        flipped[u] = prev_flipped;
    }
};

struct segtree {
    int n;
    vec<vec<pair<int, int>>> tree;

    segtree() {}
    segtree(int n) : n(n), tree(4 * n) {}

    inline void add_edge(int l, int r, pair<int, int> e) {
        add_edge(1, 0, n, l, r, e);
    }

    void add_edge(int v, int vl, int vr, int l, int r, pair<int, int> e) {
        if (r <= vl || vr <= l) return;
        if (l <= vl && vr <= r) {
            tree[v].push_back(e);
            return;
        }
        int vm = (vl + vr) / 2;
        add_edge(v << 1, vl, vm, l, r, e);
        add_edge(v << 1 | 1, vm, vr, l, r, e);
    }

    inline void solve(int nvers) {
        DSU dsu(nvers);
        solve(1, 0, n, dsu);
    }

    void solve(int v, int vl, int vr, DSU &dsu) {
        for (auto [v, u] : tree[v]) {
            dsu.unite(v, u);
        }
        if (vr - vl == 1) {
            cout << (dsu.valid ? "YES\n" : "NO\n");
        } else {
            int vm = (vl + vr) / 2;
            solve(v << 1, vl, vm, dsu);
            solve(v << 1 | 1, vm, vr, dsu);
        }
        for (int i = 0; i < len(tree[v]); i++) {
            dsu.roll_back();
        }
    }
};

inline pair<int, int> mp(int a, int b) {
    return {min(a, b), max(a, b)};
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    map<pair<int, int>, int> from;
    segtree tree(q);
    for (int i = 0; i < q; i++) {
        int v, u;
        cin >> v >> u, v--, u--;
        auto cur = mp(v, u);
        if (from.find(cur) == from.end()) {
            from[cur] = i;
        } else {
            tree.add_edge(from[cur], i, cur);
            from.erase(cur);
        }
    }
    for (auto [e, when] : from) {
        tree.add_edge(when, q, e);
    }
    tree.solve(n);
}