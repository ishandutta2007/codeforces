#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
class y_combinator {
    const Fun fun_;
public:
    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    vector<vector<int>> g(n);

    int root = y_combinator([&](auto dfs, int l, int r) -> int {
        int root = min_element(a.begin() + l, a.begin() + r) - a.begin();
        if (l != root)
            g[root].push_back(dfs(l, root));

        if (root + 1 != r)
            g[root].push_back(dfs(root + 1, r));

        return root;
    })(0, n);

    vector<vector<ll>> dp(n);

    y_combinator([&](auto dfs, int v) -> void {
        dp[v] = {0, 1ll * (m - 1) * a[v]};
        if (g[v].empty())
            return;

        for (auto u : g[v]) {
            dfs(u);

            vector<ll> new_dp(len(dp[v]) + len(dp[u]) - 1, LLONG_MIN);
            for (int cnt1 = 0; cnt1 < len(dp[v]); cnt1++)
                for (int cnt2 = 0; cnt2 < len(dp[u]); cnt2++)
                    new_dp[cnt1 + cnt2] = max(new_dp[cnt1 + cnt2], dp[v][cnt1] + dp[u][cnt2] - 2ll * cnt1 * cnt2 * a[v]);

            dp[v] = new_dp;
        }
    })(root);

    cout << dp[root][m] << '\n';
}