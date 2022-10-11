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

void setmax(int &a, int b) {
    if (a < b) a = b;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    queue<int> que;
    vector<int> h(n, n);
    for (int i = 0; i < n; i++) {
        int f;
        cin >> f;
        if (f) {
            h[i] = 0;
            que.push(i);
        }
    }

    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto u : g[v]) {
            if (h[u] > h[v] + 1) {
                h[u] = h[v] + 1;
                que.push(u);
            }
        }
    }

    vector<bool> good(n);
    for (int i = 0; i < n; i++) {
        for (auto j : g[i]) {
            good[i] = good[i] || h[j] == h[i];
        }
    }
    
    vector<bool> used(n);
    vector<int> sz(n), ans = h;

    y_combinator([&](auto dfs, int v) -> void {
        y_combinator([&](auto dfs, int v, int p) -> void {
            sz[v] = 1;
            for (auto u : g[v]) {
                if (u == p || used[u]) continue;
                dfs(u, v);
                sz[v] += sz[u];
            }
        })(v, v);

        int tot_size = sz[v];
        v = y_combinator([&](auto dfs, int v, int p) -> int {
            for (auto u : g[v]) {
                if (u == p || used[u]) continue;
                if (sz[u] * 2 > tot_size) return dfs(u, v);
            }
            return v;
        })(v, v);
        used[v] = true;

        for (int rot = 0; rot < 2; rot++, reverse(all(g[v]))) {
            struct binary_index_tree {
                int n;
                vector<int> bit;

                binary_index_tree(int n = 0) : n(n), bit(n + 1, -1e9) {}

                void setmax(int pos, int value) {
                    for (pos++; pos <= n; pos += pos & -pos) {
                        bit[pos] = max(bit[pos], value);
                    }
                }

                int query(int pref) {
                    int res = -1e9;
                    for (pref++; pref; pref -= pref & -pref) {
                        res = max(res, bit[pref]);
                    }
                    return res;
                }
            };

            array<binary_index_tree, 2> dp1;
            dp1.fill(binary_index_tree(tot_size + 2));
            auto dp2 = dp1;
            if (good[v] && rot == 0) {
                dp2[0].setmax(0, h[v]);
            }

            auto relax_v = [&](int v, int depth, int pref) {
                if (pref >= 0) {
                    setmax(ans[v], dp1[(depth & 1) ^ 1].query(pref) + depth + pref);
                    setmax(ans[v], dp2[depth & 1].query(pref) + depth + pref);
                }
            };

            for (auto u : g[v]) {
                if (used[u]) continue;

                if (h[u] >= h[v]) {
                    y_combinator([&](auto dfs, int v, int p, int depth, int pref, int max_pref) -> void {
                        setmax(max_pref, pref);
                        if (pref >= max_pref) {
                            relax_v(v, depth, pref);
                        }
                        for (auto u : g[v]) {
                            if (u == p || used[u] || h[v] > h[u]) continue;
                            dfs(u, v, depth + 1, pref + (h[v] == h[u] ? -1 : 1), max_pref);
                        }
                    })(u, v, 1, h[u] == h[v] ? -1 : 1, 0);
                }

                if (h[v] == h[u]) {
                    dp1[0].setmax(1, h[u]);
                }
                if (h[u] > h[v]) continue;

                y_combinator([&](auto dfs, int v, int p, int depth, int pref, int min_bal) -> void {
                    min_bal = min(min_bal, pref);
                    if (good[v]) {
                        dp2[depth & 1].setmax(-min_bal, h[v] + depth + pref);
                    }
                    for (auto u : g[v]) {
                        if (u == p || used[u] || h[u] > h[v]) continue;
                        if (h[v] == h[u]) {
                            dp1[depth & 1].setmax(-min_bal + 1, h[u] + depth + pref);
                        }
                        dfs(u, v, depth + 1, pref + (h[u] == h[v] ? -1 : 1), min_bal);
                    }
                })(u, v, 1, h[u] == h[v] ? -1 : 1, 0);
            }

            if (rot) {
                relax_v(v, 0, 0);
            }
        }

        for (auto u : g[v]) {
            if (!used[u]) dfs(u);
        }
    })(0);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}