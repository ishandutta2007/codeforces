/*
    author:  Maksim1744
    created: 07.05.2019 18:45:13
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<long long>> dp(n, vector<long long>(11, 0));
    for (int i = 0; i < n; ++i)
        if (s[i] != '0')
            ++dp[i][s[i] - '0'];
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < 11; ++j)
            if (s[i + 1] - '0' < j)
                dp[i + 1][(j / 11 * 55 + 10 + (j % 11 - 1) * (j % 11) / 2 + s[i + 1] - '0') % 11] += dp[i][j];
    long long ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 11; ++j)
            ans += dp[i][j];
    cout << ans << '\n';
}