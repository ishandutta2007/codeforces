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

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<int> vertex_parity(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
        vertex_parity[v] ^= 1;
        vertex_parity[u] ^= 1;
    }

    vector<array<bool, 2>> dp(n, {false, false});
    vector<array<vector<array<int, 3>>, 2>> ops(n);

    y_combinator([&](auto dfs, int v) -> void {
        if (g[v].empty()) {
            dp[v][0] = true;
            return;
        }

        array<vector<int>, 4> childs;
        for (auto u : g[v]) {
            g[u].erase(find(all(g[u]), v));
            dfs(u);

            int cur_mask = 0;
            for (int i : {0, 1}) {
                if (!dp[u][i]) continue;
                int bit_num = i == (vertex_parity[v] ^ 1) ? 0 : 1;
                cur_mask ^= 1 << bit_num;
            }
            if (cur_mask == 0) return;
            childs[cur_mask].push_back(u);
        }

        for (int take : {0, 1}) {
            for (int take3 = 0; take3 <= len(childs[3]); take3++) {
                int cnt1 = len(childs[1]) + take3;
                int cnt2 = len(childs[2]) + (len(childs[3]) - take3);
                if (v == 0) {
                    if (take) continue;
                    if (cnt1 < cnt2 || cnt1 > cnt2 + 1) continue;
                } else if (take) {
                    if (cnt1 < cnt2 + 1 || cnt1 > cnt2 + 2) continue;
                    if (cnt1 == 0) continue;
                } else {
                    if (cnt1 > cnt2 || cnt1 < cnt2 - 1) continue;
                }

                int new_parity = v == 0 ? 0 : (vertex_parity[v] ^ take ^ 1);
                if (dp[v][new_parity]) continue;

                dp[v][new_parity] = true;
                auto first = childs[1], second = childs[2];
                for (int i = 0; i < take3; i++) {
                    first.push_back(childs[3][i]);
                }
                for (int i = take3; i < len(childs[3]); i++) {
                    second.push_back(childs[3][i]);
                }
                assert(len(first) == cnt1 && len(second) == cnt2);

                int first_parity = vertex_parity[v] ^ 1;
                int second_parity = vertex_parity[v];
                if (take) {
                    ops[v][new_parity].push_back({first.back(), first_parity, 1});
                    first.pop_back();
                }
                for (int step = v == 0 ? 0 : (take ^ 1); !first.empty() || !second.empty(); step ^= 1) {
                    if (step) {
                        ops[v][new_parity].push_back({second.back(), second_parity, 0});
                        second.pop_back();
                    } else {
                        ops[v][new_parity].push_back({first.back(), first_parity, 0});
                        first.pop_back();
                    }
                }
            }
        }
    })(0);

    if (!dp[0][0]) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    vector<pair<int, int>> ans;
    ans.reserve(n - 1);

    y_combinator([&](auto dfs, int v, int parent, int parity) -> void {
        for (int now : {1, 0}) {
            for (auto [u, u_parity, need] : ops[v][parity]) {
                if (need == now) dfs(u, v, u_parity);
            }
            if (now && v != 0) ans.emplace_back(v, parent);
        }
    })(0, -1, 0);

    assert(len(ans) == n - 1);
    for (auto [v, u] : ans) cout << v + 1 << ' ' << u + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}