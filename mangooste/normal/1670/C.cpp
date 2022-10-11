#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

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

constexpr int MOD = int(1e9) + 7;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) {
        int n;
        cin >> n;
        
        auto read = [&]() -> pair<vector<int>, vector<int>> {
            vector<int> p(n), where(n);
            for (int i = 0; i < n; i++) {
                cin >> p[i];
                p[i]--;
                where[p[i]]= i;
            }
            return {p, where};
        };

        auto [a, where_a] = read();
        auto [b, where_b] = read();
        
        disjoin_set_union dsu(n);
        for (int i = 0; i < n; i++) {
            dsu.unite(i, where_a[b[i]]);
            dsu.unite(i, where_b[a[i]]);
        }

        vector<bool> good(n, true);
        for (int i = 0; i < n; i++) {
            if (a[i] == b[i]) good[i] = false;
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (x) good[dsu.root(i)] = false;
        }

        int ans = 1;
        for (int i = 0; i < n; i++) {
            if (dsu.root(i) == i && good[i]) {
                ans *= 2;
                if (ans >= MOD) ans -= MOD;
            }
        }
        cout << ans << '\n';
    }
}