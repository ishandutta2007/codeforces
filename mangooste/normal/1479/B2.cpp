#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x, x--;

    vector<int> dp(n + 1, INF);
    dp[n] = 1;
    int to_add = 0, mn = 1;

    for (int i = 1; i < n; i++) {
        int cur = (a[i] != a[i - 1]);
        to_add += cur;
        int can = min(mn + to_add - cur + 1, dp[a[i]] + to_add - cur);
        dp[a[i - 1]] = min(dp[a[i - 1]], can - to_add);
        mn = min(mn, dp[a[i - 1]]);
    }

    int ans = INF;
    for (int i = 0; i <= n; i++)
        ans = min(ans, dp[i] + to_add);
    cout << ans << '\n';
}