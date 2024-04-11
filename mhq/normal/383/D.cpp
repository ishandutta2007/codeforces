#include <bits/stdc++.h>
using namespace std;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
const int maxN = 1005;
const int SHIFT = (int)1e4;
int a[maxN];
int n;
int dp[20 * maxN];
int cop[20 * maxN];
int ans = 0;
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int all = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        all += a[i];
    }
    for (int i = 1; i <= n; i++) {
        memset(cop, 0, sizeof cop);
        dp[all] = sum(dp[all], 1);
        for (int j = -all; j <= all; j++) {
            if (dp[j + all] == 0) continue;
            cop[j + a[i] + all] = sum(cop[j + a[i] + all], dp[j + all]);
            cop[j - a[i] + all] = sum(cop[j - a[i] + all], dp[j + all]);
        }
        ans = sum(ans, cop[all]);
        for (int j = 0; j <= 2 * all; j++) dp[j] = cop[j];
    }
    cout << ans;
	return 0;
}