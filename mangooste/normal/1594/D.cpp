#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun_;

    explicit y_combinator(const Fun&& fun) : fun_(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    decltype(auto) operator()(Args&&... args) const {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; i++) {
        int v, u;
        string s;
        cin >> v >> u >> s;
        v--, u--;

        int type = s[0] != 'i';
        g[v].push_back({u, type});
        g[u].push_back({v, type});
    }

    vector<bool> used(n);
    int answer = 0;
    vector<int> color(n);

    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;

        bool failed = false;
        int cnt = 0;
        int tot = 0;

        y_combinator([&](auto dfs, int v) -> void {
            used[v] = true;
            cnt += color[v] == 0;
            tot++;

            for (auto [u, type] : g[v]) {
                int need = type == color[v];
                if (!used[u]) {
                    color[u] = need;
                    dfs(u);
                    if (failed)
                        return;
                } else if (color[u] != need) {
                    failed = true;
                    return;
                }
            }
        })(i);

        if (failed) {
            cout << "-1\n";
            return;
        }
        answer += max(cnt, tot - cnt);
    }

    cout << answer << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}