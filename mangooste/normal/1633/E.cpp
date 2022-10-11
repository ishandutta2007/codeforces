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

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<array<int, 3>> edges(m);
    for (auto &[v, u, w] : edges) {
        cin >> v >> u >> w;
        v--, u--;
    }

    vector<int> good{-1, int(1e9)};
    for (int i = 0; i < m; i++) {
        good.push_back(edges[i][2]);
        for (int j = i + 1; j < m; j++) {
            good.push_back((edges[i][2] + edges[j][2]) >> 1);
            good.push_back((edges[i][2] + edges[j][2] + 1) >> 1);
        }
    }

    sort(all(good));
    good.resize(unique(all(good)) - good.begin());

    vector<pair<ll, int>> positive, negative;
    for (auto &x : good) {
        sort(all(edges), [&](const auto &a, const auto &b) {
            return pair{abs(a[2] - x), -a[2]} < pair{abs(b[2] - x), -b[2]};
        });

        positive.emplace_back(0, 0);
        negative.emplace_back(0, 0);

        disjoin_set_union dsu(n);
        for (auto &[v, u, w] : edges)
            if (dsu.unite(v, u)) {
                if (w > x) {
                    positive.back().first += w;
                    positive.back().second++;
                } else {
                    negative.back().first += w;
                    negative.back().second++;
                }
            }
    }

    ll answer = 0;

    auto solve = [&](int x) {
        int id = upper_bound(all(good), x) - good.begin() - 1;
        ll res = positive[id].first - 1ll * positive[id].second * x;
        res += -negative[id].first + 1ll * negative[id].second * x;
        // cout << res << '\n';
        answer ^= res;
    };

    int p, k, a, b, c;
    cin >> p >> k >> a >> b >> c;

    for (int i = 0, cur; i < k; i++) {
        if (i < p)
            cin >> cur;
        else
            cur = (1ll * cur * a + b) % c;

        solve(cur);
    }

    cout << answer << '\n';
}