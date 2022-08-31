/*
    16.03.2019 15:34:30
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

long long mod = 1e9 + 7;

int main() {
    int m;
    cin >> m;
    string s(m, '0');
    for (int i = 0; i < m; ++i) {
        cin >> s[i];
    }
    vector< vector< int > > same(m);
    for (int i = 0; i < m; ++i) {
        same[i].assign(i, 0);
        for (int j = 0; j < i; ++j) {
            if (s[i] == s[j]) {
                if (i == 0 || j == 0)
                    same[i][j] = 1;
                else
                    same[i][j] = same[i - 1][j - 1] + 1;
            }
        }
    }
    same[0].push_back(0);
    // show(same);
    vector< long long > dp(m + 10);
    long long ans = 0;
    for (int i = 0; i < m; ++i) {
        dp[i + 1] = 1;
        dp[i + 2] = 0;
        dp[i + 3] = 0;
        dp[i + 4] = 0;
        for (int j = i; j >= 0; --j) {
            dp[j] = dp[j + 1] + dp[j + 2] + dp[j + 3] + dp[j + 4];
            if (j + 4 <= m) {
                string s1 = s.substr(j, 4);
                if (s1 == (string)"0011" ||
                    s1 == (string)"0101" ||
                    s1 == (string)"1110" ||
                    s1 == (string)"1111")
                    dp[j] -= dp[j + 4];
            }
            dp[j] = dp[j] % mod;
        }
        int mx = *max_element(same[i].begin(), same[i].end());
        show(dp);
        for (int j = i - mx; j >= 0; --j)
            ans += dp[j];
        ans %= mod;
        cout << ans << '\n';
    }
    return 0;
}