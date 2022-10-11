#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, l, r;
    cin >> n >> l >> r;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u, c;
        cin >> v >> u >> c;
        v--, u--;
        g[v].emplace_back(u, c);
        g[u].emplace_back(v, c);
    }
    for (auto &v : g) shuffle(all(v), mt19937(239));
    
    vector<bool> used(n);
    vector<int> sz(n);
    int ans_v = -1, ans_u = -1, ans = -1;

    struct segtree {
        int n;
        vector<pair<int, int>> tree;

        segtree(int n) : n(n), tree(2 * n, {-1e9, -1}) {}

        void reset(int new_n) {
            n = new_n;
            fill(tree.begin(), tree.begin() + 2 * n, pair{-1e9, -1});
        }

        void update(int pos, const pair<int, int> &x) {
            for (pos += n; pos; pos >>= 1) {
                tree[pos] = max(tree[pos], x);
            }
        }

        pair<int, int> query(int l, int r) {
            pair<int, int> res{-1e9, -1};
            for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res = max(res, tree[l++]);
                if (r & 1) res = max(res, tree[--r]);
            }
            return res;
        }
    } tree(n);

    y_combinator([&](auto dfs, int v) -> void {
        vector<int> values;

        y_combinator([&](auto dfs, int v, int p) -> void {
            sz[v] = 1;
            for (auto &[u, c] : g[v]) {
                values.push_back(c);
                if (u == p || used[u]) continue;
                dfs(u, v);
                sz[v] += sz[u];
            }
        })(v, v);

        sort(all(values));
        values.resize(unique(all(values)) - values.begin());
        int tot_size = sz[v];

        v = y_combinator([&](auto dfs, int v, int p) -> int {
            for (auto &[u, c] : g[v]) {
                if (u == p || used[u]) continue;
                if (sz[u] * 2 > tot_size) return dfs(u, v);
            }
            return v;
        })(v, v);

        used[v] = true;
        for (int rot = 0; rot < 2; rot++, reverse(all(g[v]))) {
            auto solve = [&](int mid) {
                int any_v = -1, any_u = -1;
                tree.reset(tot_size);
                
                auto add_vertex = [&](int v, int depth, int up) {
                    tree.update(depth, {up, v});
                };
                
                auto relax_answer = [&](int v, int depth, int up) {
                    int from = max(0, l - depth);
                    int to = min(tot_size - 1, r - depth) + 1;
                    if (to <= from) return;
                    auto [u_up, u] = tree.query(from, to);
                    if (up + u_up >= 0) {
                        any_v = v;
                        any_u = u;
                    }
                };

                if (rot == 0) add_vertex(v, 0, 0);
                for (auto &[u, c] : g[v]) {
                    if (used[u]) continue;

                    y_combinator([&](auto dfs, int v, int p, int depth, int up) -> void {
                        relax_answer(v, depth, up);
                        for (auto &[u, c] : g[v]) {
                            if (u == p || used[u]) continue;
                            if (any_v != -1) return;
                            dfs(u, v, depth + 1, up + (c >= values[mid] ? 1 : -1));
                        }
                    })(u, v, 1, c >= values[mid] ? 1 : -1);

                    if (any_v != -1) return pair{any_v, any_u};

                    y_combinator([&](auto dfs, int v, int p, int depth, int up) -> void {
                        add_vertex(v, depth, up);
                        for (auto &[u, c] : g[v]) {
                            if (u == p || used[u]) continue;
                            dfs(u, v, depth + 1, up + (c >= values[mid] ? 1 : -1));
                        }
                    })(u, v, 1, c >= values[mid] ? 1 : -1);
                }

                if (rot) relax_answer(v, 0, 0);
                return pair{any_v, any_u};
            };

            int lb = int(lower_bound(all(values), ans) - values.begin()) - 1, rb = len(values);
            while (rb - lb > 1) {
                int mid = (lb + rb) >> 1;
                (solve(mid).first != -1 ? lb : rb) = mid;
            }
            if (lb == -1) continue;

            if (ans < values[lb]) {
                auto [v, u] = solve(lb);
                assert(v != -1);
                ans_v = v;
                ans_u = u;
                ans = values[lb];
            }
        }

        for (auto [u, c] : g[v]) {
            if (!used[u]) dfs(u);
        }
    })(0);

    assert(ans != -1);
    cout << ans_v + 1 << ' ' << ans_u + 1 << '\n';
}