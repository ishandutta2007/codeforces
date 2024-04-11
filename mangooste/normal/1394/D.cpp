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

    int n;
    cin >> n;
    vector<int> t(n), h(n);
    for (auto &x : t) cin >> x;
    for (auto &x : h) cin >> x;

    vector<vector<int>> g(n);
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        g[v].push_back(u);
        g[u].push_back(v);
    }

    ll ans = 0;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        ans += 1ll * t[i] * len(g[i]);
        for (auto j : g[i]) {
            if (h[i] == h[j]) continue;
            (h[i] < h[j] ? b[i] : a[i])++;
        }
    }

    vector<bool> used(n);
    constexpr ll INF = 1e18;
    vector<array<ll, 2>> dp(n, {-INF, -INF});

    for (int i = 0; i < n; i++) {
        if (used[i]) continue;

        y_combinator([&](auto dfs, int v) -> void {
            used[v] = true;
            vector<array<ll, 2>> childs;
            childs.reserve(len(g[v]));

            for (auto u : g[v]) {
                if (h[u] != h[v]) continue;
                g[u].erase(find(all(g[u]), v));
                dfs(u);
                childs.push_back(dp[u]);
            }
            
            for (int type : {0, 1}) {
                int cur_a = a[v] + (type == 0 && v != i);
                int cur_b = b[v] + (type == 1 && v != i);
                ll cur = 0;
                for (auto &[a, b] : childs) cur += b;

                sort(all(childs), [&](const auto &a, const auto &b) {
                    return -a[1] + a[0] > -b[1] + b[0];
                });
                for (int i = 0;; i++) {
                    int new_a = cur_a + (len(childs) - i);
                    int new_b = cur_b + i;
                    dp[v][type] = max(dp[v][type], cur + 1ll * min(new_a, new_b) * t[v]);
                    if (i == len(childs)) break;
                    cur += -childs[i][1] + childs[i][0];
                }
            }
        })(i);

        assert(dp[i][0] == dp[i][1]);
        ans -= dp[i][0];
    }
    cout << ans << '\n';
}