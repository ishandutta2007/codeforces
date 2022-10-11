#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename T>
void setmax(T &a, const T &b) {
    if (a < b) a = b;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    cout << fixed << setprecision(10);

    int n, a, b;
    cin >> n >> a >> b;
    vector<ld> p(n);
    for (auto &x : p) cin >> x;
    vector<ld> q(n);
    for (auto &x : q) cin >> x;
    vector<ld> t(n);
    for (int i = 0; i < n; i++) {
        t[i] = p[i] + q[i] - p[i] * q[i];
    }

    constexpr ld INF = 1e18;
    vector<pair<ld, int>> dp(a + 1), new_dp(a + 1);

    auto solve = [&](ld mid) {
        fill(all(dp), pair{-INF, -1});
        dp[0] = {0, -1};
        for (int i = 0; i < n; i++) {
            new_dp = dp;
            for (int take = 0; take <= a; take++) {
                setmax(new_dp[take], {dp[take].first + q[i] - mid, dp[take].second + 1});
            }
            for (int take = 1; take <= a; take++) {
                for (int k : {0, 1}) {
                    setmax(new_dp[take], {dp[take - 1].first + (k == 0 ? p[i] : t[i]) - k * mid, dp[take - 1].second + k});
                }
            }
            swap(dp, new_dp);
        }
    };

    ld l = -2e5, r = 2e5;
    for (int it = 0; it < 50; it++) {
        ld mid = (l + r) / 2;
        solve(mid);
        (dp[a].second >= b ? l : r) = mid;
    }

    ld mid = (l + r) / 2;
    solve(mid);
    cout << dp[a].first + b * mid << '\n';
}