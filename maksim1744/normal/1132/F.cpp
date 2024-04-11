/*
    26.03.2019 20:58:46
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

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n ; ++i)
        dp[i][i] = 1;
    for (int k = 1; k < n; ++k) {
        for (int i = 0; i + k < n; ++i) {
            int j = i + k;
            if (s[i] == s[i + 1]) dp[i][j] = dp[i + 1][j];
            else if (s[j - 1] == s[j]) dp[i][j] = dp[i][j - 1];
            else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                for (int k = i + 1; k <= j; ++k) {
                    if (s[k] == s[i])
                        dp[i][j] = min(dp[i][j], dp[i + 1][k - 1] + dp[k][j]);
                }
            }
        }
    }
    cout << dp[0][n - 1] << '\n';
    return 0;
}