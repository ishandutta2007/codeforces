#include <bits/stdc++.h>
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define int long long
#define vi vector<int>
#define pi pair<int, int>

using namespace std;

const int N = 501;

int dp[N][N], val[N][N], a[N], b[N], n, k;
int sum1 = 0, sum2 = 0;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i], sum1 += a[i], sum2 += b[i];
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = dp[i][j] = -1;
    dp[0][0] = 0;
    val[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            val[i][j] = val[i - 1][j];
            if (dp[i][j] != -1)
                continue;
            for (int take = 1; take < min(a[i] + 1, k); take++) {
                if (k - take <= b[i] && dp[i - 1][(j - take + k) % k] != -1) {
                    dp[i][j] = dp[i - 1][(j - take + k) % k] + 1;
                    val[i][j] = val[i - 1][(j - take + k) % k] + take;
                    break;
                }
            }
        }
    int ans = sum1 / k + sum2 / k;
    if (dp[n][sum1 % k]) {
        int s1 = sum1, s2 = sum2;
        s1 -= val[n][sum1 % k];
        s2 -= (k * dp[n][sum1 % k] - val[n][sum1 % k]);
        ans = max(ans, dp[n][sum1 % k] + s1 / k + s2 / k);
    }

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= k; j++)
            dp[i][j] = dp[i][j] = -1;
    dp[0][0] = 0;
    val[0][0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i - 1][j];
            val[i][j] = val[i - 1][j];
            if (dp[i][j] != -1)
                continue;
            for (int take = 1; take < min(b[i] + 1, k); take++) {
                if (k - take <= a[i] && dp[i - 1][(j - take + k) % k] != -1) {
                    dp[i][j] = dp[i - 1][(j - take + k) % k] + 1;
                    val[i][j] = val[i - 1][(j - take + k) % k] + take;
                    break;
                }
            }
        }
    if (dp[n][sum2 % k]) {
        int s1 = sum1, s2 = sum2;
        s2 -= val[n][sum2 % k];
        s1 -= (k * dp[n][sum2 % k] - val[n][sum2 % k]);
        ans = max(ans, dp[n][sum2 % k] + s1 / k + s2 / k);
    }
    cout << ans;
    return 0;
}