#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 205;
const int maxLG = 30;
int dp[maxN][maxN * maxLG];
int ndp[maxN][maxN * maxLG];
int n, k;
ll a[maxN];
int val2[maxN], val5[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            val2[i]++;
        }
        while (a[i] % 5 == 0) {
            a[i] /= 5;
            val5[i]++;
        }
    }
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for (int i = 0; i + 1 <= n; i++) {
        memset(ndp, -1, sizeof ndp);
        for (int cnt = 0; cnt <= min(i, k); cnt++) {
            for (int lg5 = 0; lg5 <= maxLG * cnt; lg5++) {
                if (dp[cnt][lg5] == -1) continue;
                ndp[cnt + 1][lg5 + val5[i + 1]] = max(ndp[cnt + 1][lg5 + val5[i + 1]], dp[cnt][lg5] + val2[i + 1]);
                ndp[cnt][lg5] = max(ndp[cnt][lg5], dp[cnt][lg5]);
            }
        }
        for (int cnt = 0; cnt <= min(i + 1, k); cnt++) {
            for (int lg5 = 0; lg5 <= maxLG * cnt; lg5++) {
                dp[cnt][lg5] = ndp[cnt][lg5];
            }
        }
    }
    int mx = 0;
    for (int i = 0; i < maxN * maxLG; i++) {
        mx = max(mx, min(i, dp[k][i]));
    }
    cout << mx;
    return 0;
}