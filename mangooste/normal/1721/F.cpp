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
    #define dprint(...)
#endif // LOCAL

struct matching {
    int n, m;
    std::vector<std::vector<int>> g;
    std::vector<int> p_left, p_right;

    matching(int n = 0, int m = 0) :
        n(n), m(m), g(n), p_left(n, -1), p_right(m, -1)
    {}

    std::pair<int, int> size() const {
        return {n, m};
    }

    void add(int left, int right) {
        g[left].push_back(right);
    }

    std::vector<int> used;
    int timer;

    bool khun(int v) {
        if (used[v] == timer)
            return false;

        used[v] = timer;
        for (auto u : g[v])
            if (p_right[u] == -1) {
                p_right[u] = v;
                p_left[v] = u;
                return true;
            }

        for (auto u : g[v])
            if (khun(p_right[u])) {
                p_right[u] = v;
                p_left[v] = u;
                return true;
            }

        return false;
    }

    int solve(bool need_to_shuffle = false) {
        std::fill(p_left.begin(), p_left.end(), -1);
        std::fill(p_right.begin(), p_right.end(), -1);
        used.assign(n, 0);
        timer = 0;

        std::vector<int> order(n);
        std::iota(order.begin(), order.end(), 0);
        if (need_to_shuffle)
            std::shuffle(order.begin(), order.end(), std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count()));

        int pairs = 0;
        for (int v : order) {
            timer++;
            pairs += khun(v);
        }
        return pairs;
    }

    void dfs(int v) {
        if (used[v])
            return;

        used[v] = 1;
        for (auto u : g[v])
            if (u != p_left[v])
                dfs(p_right[u]);
    }

    std::pair<std::vector<int>, std::vector<int>> minimum_vertex_covering(bool need_to_shuffle = false) {
        int pairs = solve(need_to_shuffle);
        used.assign(n, 0);

        for (int i = 0; i < n; i++)
            if (p_left[i] == -1)
                dfs(i);

        std::vector<int> left;
        std::vector<bool> used_right(m);

        for (int i = 0; i < n; i++)
            if (!used[i]) {
                left.push_back(i);
            } else if (p_left[i] != -1) {
                for (auto j : g[i])
                    used_right[j] = true;
            }

        std::vector<int> right;
        for (int i = 0; i < m; i++)
            if (used_right[i])
                right.push_back(i);

        assert(int(left.size() + right.size()) == pairs);
        return std::make_pair(left, right);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    int n1, n2, m, q;
    cin >> n1 >> n2 >> m >> q;
    matching mat(n1, n2);
    vector<pair<int, int>> edges(m);
    for (auto &[v, u] : edges) {
        cin >> v >> u;
        v--, u--;
        mat.add(v, u);
    }
    auto [left, right] = mat.minimum_vertex_covering(true);

    unordered_map<ll, int> edge_id;
    edge_id.rehash(m);
    for (int i = 0; i < m; i++) {
        edge_id[edges[i].first + ll(1e9) * edges[i].second] = i + 1;
    }

    vector<int> left_id(n1);
    for (int i = 0; i < n1; i++) {
        if (mat.p_left[i] != -1) left_id[i] = edge_id[i + ll(1e9) * mat.p_left[i]];
    }
    vector<int> right_id(n2, -1);
    for (int i = 0; i < n2; i++) {
        if (mat.p_right[i] != -1) right_id[i] = edge_id[mat.p_right[i] + ll(1e9) * i];
    }
    ll cur_sum = accumulate(all(left_id), 0ll);

    while (q--) {
        cout << flush;
        int type;
        cin >> type;

        if (type == 1) {
            cout << "1\n";
            if (!left.empty()) {
                int v = left.back();
                left.pop_back();
                cout << v + 1 << '\n';
                cur_sum -= left_id[v];
            } else {
                int v = right.back();
                right.pop_back();
                cout << -v - 1 << '\n';
                cur_sum -= right_id[v];
            }
            cout << cur_sum << '\n';
        } else {
            assert(type == 2);
            cout << len(left) + len(right) << '\n';
            for (auto x : left) cout << left_id[x] << ' ';
            for (auto x : right) cout << right_id[x] << ' ';
            cout << '\n';
        }
    }
}