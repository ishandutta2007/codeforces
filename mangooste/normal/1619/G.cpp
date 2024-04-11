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
    int n, k;
    cin >> n >> k;

    vector<int> x(n), y(n), t(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i] >> t[i];

    vector<vector<int>> g(n);
    for (int rot = 0; rot < 2; rot++, swap(x, y)) {
        map<int, vector<pair<int, int>>> coords;
        for (int i = 0; i < n; i++)
            coords[x[i]].emplace_back(y[i], i);

        for (auto &[c, v] : coords) {
            sort(all(v));
            v.resize(unique(all(v)) - v.begin());

            for (int i = 0; i < len(v); i++)
                for (int d : {-1, 1})
                    if (i + d >= 0 && i + d < len(v) && abs(v[i].first - v[i + d].first) <= k)
                        g[v[i].second].push_back(v[i + d].second);
        }
    }

    vector<bool> used(n);
    vector<int> a;
    for (int i = 0; i < n; i++) {
        if (used[i])
            continue;

        int mn = 1e9;

        y_combinator([&](auto dfs, int v) -> void {
            used[v] = true;
            mn = min(mn, t[v]);

            for (auto u : g[v])
                if (!used[u])
                    dfs(u);
        })(i);

        a.push_back(mn);
    }
    sort(all(a));

    auto can = [&](int mid) {
        return a.end() - upper_bound(all(a), mid) <= mid + 1;
    };

    int l = -1, r = a.back();
    while (r - l > 1) {
        int mid = (l + r) >> 1;
        (can(mid) ? r : l) = mid;
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--)
        solve();
}