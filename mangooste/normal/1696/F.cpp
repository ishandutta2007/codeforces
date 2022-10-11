#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

struct disjoin_set_union {
    int components;
    std::vector<int> parent, rank;

    disjoin_set_union(int n = 0) : components(n), parent(n), rank(n, 1) {
        std::iota(parent.begin(), parent.end(), 0);
    }

    int size() const {
        return rank.size();
    }

    void set_default() {
        components = size();
        std::fill(rank.begin(), rank.end(), 1);
        std::iota(parent.begin(), parent.end(), 0);
    }

    int root(int v) {
        return (v ^ parent[v]) == 0 ? v : parent[v] = root(parent[v]);
    }

    bool unite(int v, int u) {
        v = root(v), u = root(u);
        if (v == u)
            return false;

        if (rank[v] < rank[u])
            std::swap(v, u);

        rank[v] += rank[u];
        parent[u] = v;
        components--;
        return true;
    }

    bool connected(int v, int u) {
        return root(v) == root(u);
    }
};

void solve(int test_num) {
    int n;
    cin >> n;
    vector<pair<int, int>> inv;
    inv.reserve(n * (n - 1) / 2);
    vector id(n, vector<int>(n, -1));
    for (int v = 0; v < n; v++) {
        for (int u = v + 1; u < n; u++) {
            id[v][u] = len(inv);
            inv.emplace_back(v, u);
        }
    }
    disjoin_set_union dsu(len(inv));

    auto encode = [&](int v, int u) {
        assert(v != u);
        return id[min(v, u)][max(v, u)];
    };

    auto decode = [&](int id) {
        return inv[id];
    };

    bool fail = false;
    vector ok(n, vector<bitset<100>>(n));
    for (int v = 0; v < n; v++) {
        for (int u = v + 1; u < n; u++) {
            string s;
            cin >> s;
            ok[v][u].reset();
            for (int c = 0; c < n; c++) {
                if (s[c] == '0') continue;
                ok[v][u][c] = true;
                if (c == v || c == u) {
                    fail = true;
                    break;
                }
                dsu.unite(encode(v, c), encode(u, c));
            }
        }
    }
    if (fail) {
        cout << "No\n";
        return;
    }

    for (int root = 0; root < len(inv); root++) {
        vector<int> v;
        for (int i = 0; i < len(inv); i++) {
            if (dsu.root(i) == root) v.push_back(i);
        }
        if (len(v) != n - 1) continue;

        vector<vector<int>> g(n);
        for (auto &x : v) {
            auto [v, u] = decode(x);
            g[v].push_back(u);
            g[u].push_back(v);
        }

        vector dist(n, vector<int>(n, n));
        bool fail = false;
        for (int c = 0; c < n; c++) {
            dist[c][c] = 0;
            vector<int> que{c};
            for (int ptr = 0; ptr < len(que); ptr++) {
                int v = que[ptr];
                for (auto u : g[v]) {
                    if (dist[c][u] == n) {
                        dist[c][u] = dist[c][v] + 1;
                        que.push_back(u);
                    }
                }
            }
            fail |= count(all(dist[c]), n);
        }

        for (int v = 0; v < n; v++) {
            for (int u = v + 1; u < n; u++) {
                for (int c = 0; c < n; c++) {
                    fail |= ok[v][u][c] != (dist[v][c] == dist[u][c]);
                }
            }
        }
        if (!fail) {
            cout << "Yes\n";
            for (auto &x : v) {
                auto [v, u] = decode(x);
                cout << v + 1 << ' ' << u + 1 << '\n';
            }
            return;
        }
    }
    cout << "No\n";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int tests;
    cin >> tests;
    for (int test_num = 1; test_num <= tests; test_num++) {
        solve(test_num);
    }
}