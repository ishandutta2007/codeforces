/*
    16.11.2018 22:05:05
*/

#include <bits/stdc++.h>

using namespace std;

const bool debug = true;

int main(int argc, char const *argv[]) {
    int n, k, x;
    cin >> n >> k >> x;
    // if (x * k + k - 1 < n) {
    //     cout << -1 << '\n';
    //     return 0;
    // }
    vector< long long > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    // dp[i][j] = max_{i - k <= i1 < i} dp[i1][j - 1]
    vector< multiset< long long > > mx(x);
    vector< vector< long long > > dp(n, vector< long long >(x, -1));
    dp[0][0] = a[0];
    for (int i = 0; i < x; ++i) {
        mx[i].insert(dp[0][i]);
    }
    // print(mx);
    // mx[0].insert(5);
    // mx[0].insert(6);
    // print(mx);
    // mx[0].erase(mx[0].find(5));
    // print(mx);
    // return 0;
    for (int i = 1; i < n; ++i) {
        if (i + 1 > k) {
            dp[i][0] = -1;
        } else {
            dp[i][0] = a[i];
        }
        // cout << "mx = ";
        // print(mx);
        for (int j = 1; j < x; ++j) {
            auto it = mx[j - 1].end();
            --it;
            if (*it != -1) {
                dp[i][j] = a[i] + *it;
            }
        }
        for (int j = 0; j < x; ++j) {
            mx[j].insert(dp[i][j]);
            // cout << "j = " << j << endl;
            // cout << "mx = ";
            // print(mx);
            // cout << "dp = ";
            // print(dp);
            if (i >= k) {
                mx[j].erase(mx[j].find(dp[i - k][j]));
                // cout << "deleted dp[" << i - k << "][" << j << "]: " << dp[i - k][j] << endl;
            }
        }
        // print(dp);
        // print(mx);
    }
    long long ans = -1;
    for (int i = max(0, n - k); i < n; ++i) {
        ans = max(ans, dp[i][x - 1]);
    }
    cout << ans << '\n';
    return 0;
}