#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 2005;
int dp[maxN][maxN];
int n, k;
int tp[maxN];
int coef[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++) {
        tp[i] = s[i] - 'a';
    }
    dp[n][0] = 1;
    coef[0] = 1;
    for (int i = n - 1; i >= 0; i--) {
        // me < tp[i]
        for (int p = 0; p <= k; p++) {
            dp[i][p] = sum(dp[i][p], mult(tp[i], dp[i + 1][p]));
        }
        // me > tp[i]
        for (int p = 0; p + n - i <= k; p++) {
            dp[i][p + n - i] = sum(dp[i][p + n - i], mult(25 - tp[i], dp[i + 1][p]));
        }
        // me = tp[i]
        // tp[j] > tp[i]
        // (j - i + 1) * (n - j)
        for (int j = i + 1; j <= n - 1; j++) {
            int val = (j - i + 1) * (n - j);
            if (val > k) continue;
            for (int p = 0; p + val <= k; p++) {
                dp[i][p + val] = sum(dp[i][p + val], mult(25 - tp[j], dp[j + 1][p]));
            }
        }
        for (int p = 0; p <= k; p++) {
            dp[i][p] = sum(dp[i][p], coef[p]);
        }
        for (int p = 0; p <= k; p++) {
            coef[p] = sum(coef[p], mult(tp[i], dp[i + 1][p]));
        }
    }
    cout << dp[0][k] << '\n';
    return 0;
}