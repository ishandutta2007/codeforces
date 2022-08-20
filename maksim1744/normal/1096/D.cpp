/*
    28.12.2018 18:02:58
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector< long long > a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector< vector< long long > > dp(4, vector< long long >(n + 1, 0));
    for (int i = 0; i < n; ++i) {
        dp[0][i + 1] = dp[0][i];
        if (s[i] == 'h') {
            dp[0][i + 1] += a[i];
        }
    }
    string bad = "hard";
    for (int i = 1; i < 4; ++i) {
        for (int j = 0; j < n; ++j) {
            if (bad[i] != s[j]) {
                dp[i][j + 1] = dp[i][j];
            } else {
                dp[i][j + 1] = min(dp[i][j] + a[j], dp[i - 1][j]);
            }
        }
    }
    cout << dp[3][n] << '\n';
    return 0;
}