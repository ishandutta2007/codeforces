#include <bits/stdc++.h>

using namespace std;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 205;
int a[maxN];
int n, k;
int dp[maxN][5 *  maxN];
int ndp[maxN][5 * maxN];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    dp[0][0] = 1;
    for (int i = 0; i + 1 <= n; i++) {
        memset(ndp, 0, sizeof ndp);
        for (int opened = 0; opened <= n; opened++) {
            for (int balance = 0; balance <= k; balance++) {
                if (dp[opened][balance] == 0) continue;
                int nbalance = opened * (a[i + 1] - a[i]) + balance;
                if (nbalance > k) continue;
                ndp[opened][nbalance] = sum(ndp[opened][nbalance], mult(opened + 1, dp[opened][balance]));
                if (opened >= 1) ndp[opened - 1][nbalance] = sum(ndp[opened - 1][nbalance], mult(opened, dp[opened][balance]));
                ndp[opened + 1][nbalance] = sum(ndp[opened + 1][nbalance], dp[opened][balance]);
            }
        }
        for (int opened = 0; opened <= n; opened++) {
            for (int balance = 0; balance <= k; balance++) {
                dp[opened][balance] = ndp[opened][balance];
            }
        }
    }
    int ans = 0;
    for (int bal = 0; bal <= k; bal++) ans = sum(ans, dp[0][bal]);
    cout << ans;
    return 0;
}