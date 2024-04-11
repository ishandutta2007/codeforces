#include <bits/stdc++.h>
using namespace std;
const int maxN = (int)1e5 + 10;
int n, m;
int dp[22][1 << 20];
char a[22][maxN];
int main() {
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int  j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++) {
        int mask = 0;
        for (int j = 1; j <= n; j++) {
            if (a[j][i] == '1') mask |= (1 << (j - 1));
        }
        dp[0][mask]++;
    }
    for (int k = 1; k <= n; k++) {
        for (int mask = 0; mask < (1 << n); mask++) {
            int sum = 0;
            for (int bit = 0; bit < n; bit++) {
                sum += dp[k - 1][mask ^ (1 << bit)];
            }
            if (k >= 2) sum += (k - 2 - n) * dp[k - 2][mask];
            dp[k][mask] = sum / k;
        }
    }
    int ans = (int)1e9;
    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt = 0;
        for (int k = 0; k <= n; k++) {
            cnt += min(k, n - k) * dp[k][mask];
        }
        ans = min(ans, cnt);
    }
    cout << ans;
    return 0;
}