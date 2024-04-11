#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> poses(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i], a[i]--;
        poses[a[i]].push_back(i);
    }

    vector<int> dp(n + 1), cnt(n);
    for (int i = n - 1; i >= 0; i--) {
        cnt[a[i]]++;
        dp[i] = dp[i + 1];
        if (i != poses[a[i]][0])
            dp[i] = max(dp[i], cnt[a[i]]);
        else
            dp[i] = max(dp[i], cnt[a[i]] + dp[poses[a[i]].back() + 1]);
    }
    cout << n - dp[0] << '\n';
}