/*
    26.03.2019 21:37:00
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
    long long w;
    cin >> w;
    vector<long long> c(9);
    for (int i = 0; i < 8; ++i) {
        cin >> c[i + 1];
    }
    long long k = 840;
    vector<vector<long long>> dp(9, vector<long long>(k * 8, -1));
    dp[0][0] = 0;
    // for (int i = 1; i <= 8; ++i)
    //     dp[0][0] += c[i] / (k / i);
    for (int i = 1; i <= 8; ++i) {
        for (int j = 0; j < k * 8; ++j) {
            for (int u = 0; u < min(c[i] + 1, k / i); ++u) {
                if (u * i > j) break;
                if (dp[i - 1][j - u * i] != -1)
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - u * i] + (c[i] - u) / (k / i));
            }
        }
    }
    // show(dp[1]);
    long long best = 0;
    for (int i = 0; i < min(w + 1, k * 8); ++i)
        if (dp[8][i] != -1)
            best = max(best, (long long)i + k * min((w - i) / k, dp[8][i]));
    cout << best << '\n';
    return 0;
}