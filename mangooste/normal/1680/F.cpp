#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "/home/Templates/debug.h"
#else
    #define dbg(...)
#endif // LOCAL

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

struct bipartite_disjoin_set_union {
    std::vector<int> par, rank, value;
    bool bipartite = true;

    struct update {
        int v, u;
        bool flipped_u, old_bipartite;
    };
    std::vector<update> updates;

    bipartite_disjoin_set_union(int n = 0) : par(n), rank(n, 1), value(n) {
        std::iota(par.begin(), par.end(), 0);
    }

    int version() const {
        return updates.size();
    }

    void reset() {
        std::iota(par.begin(), par.end(), 0);
        std::fill(rank.begin(), rank.end(), 1);
        std::fill(value.begin(), value.end(), 0);
        bipartite = true;
        updates.clear();
    }

    int color(int v) {
        return par[v] == v ? value[v] : (value[v] ^ color(par[v]));
    }

    int root(int v) {
        return par[v] == v ? v : root(par[v]);
    }

    void flip_component(int v) {
        value[root(v)] ^= 1;
    }

    void unite(int v, int u) {
        if (!bipartite)
            return;

        int v_root = root(v), u_root = root(u);
        if (v_root == u_root) {
            updates.push_back({-1, -1, false, true});
            bipartite &= color(v) != color(u);
            return;
        }

        if (rank[v_root] < rank[u_root]) {
            std::swap(v, u);
            std::swap(v_root, u_root);
        }

        bool flipped_u = color(v) == color(u);
        if (flipped_u)
            value[u_root] ^= 1;

        rank[v_root] += rank[u_root];
        par[u_root] = v_root;
        updates.push_back({v_root, u_root, flipped_u, true});
    }

    void roll_back() {
        auto [v, u, flipped_u, old_bipartite] = updates.back();
        updates.pop_back();

        bipartite = old_bipartite;
        if (v != -1) {
            rank[v] -= rank[u];
            par[u] = u;
            if (flipped_u)
                value[u] ^= 1;
        }
    }

    void roll_back(int old_version) {
        assert(old_version <= version());
        while (version() != old_version)
            roll_back();
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for (auto &[v, u] : edges) {
        cin >> v >> u;
        v--, u--;
    }

    bipartite_disjoin_set_union dsu(n);
    bool found = false;

    y_combinator([&](auto solve, int l, int r) -> void {
        if (!dsu.bipartite) return;

        if (r - l == 1) {
            assert(dsu.bipartite && !found);
            auto [v, u] = edges[l];
            if (!dsu.color(v)) dsu.flip_component(v);

            found = true;
            cout << "YES\n";
            for (int i = 0; i < n; i++) {
                cout << dsu.color(i);
            }
            cout << '\n';
            return;
        }

        int m = (l + r) >> 1;
        int prev_size = len(dsu.updates);
        for (int i = m; i < r && dsu.bipartite; i++) {
            dsu.unite(edges[i].first, edges[i].second);
        }

        solve(l, m);
        if (found) return;

        dsu.roll_back(prev_size);
        for (int i = l; i < m && dsu.bipartite; i++) {
            dsu.unite(edges[i].first, edges[i].second);
        }
        solve(m, r);
        if (found) return;

        dsu.roll_back(prev_size);
    })(0, m);

    if (!found) cout << "NO\n";
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}