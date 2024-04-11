#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll INF = ll(1e18);

void solve() {
    int n;
    cin >> n;
    vector<ll> c(n), a(n), b(n);
    for (auto &x : c)
        cin >> x;
    for (auto &x : a)
        cin >> x;
    for (auto &x : b)
        cin >> x;

    a.erase(a.begin());
    b.erase(b.begin());

    for (int i = 0; i < n; i++)
        if (a[i] < b[i])
            swap(a[i], b[i]);

    vector<ll> dp(n, -INF);
    dp[1] = 2 + a[0] - b[0];
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans = max(ans, dp[i] + c[i] - 1);
        if (i == n - 1)
            continue;

        if (a[i] != b[i])
            dp[i + 1] = max(dp[i + 1], dp[i] + (b[i] - 1) + c[i] - a[i] + 2);
        dp[i + 1] = max(dp[i + 1], a[i] - b[i] + 2);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}