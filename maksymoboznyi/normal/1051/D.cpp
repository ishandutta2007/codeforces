#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 2000;
const long long inf = 2e18;
const long long M = 998244353;
int n, k, dp[2][2][N][N];

signed main()
{
    cin >> n >> k;
    int pp = k;
    if (k == 1)
    {
        cout << 2;
        return 0;
    }
    dp[0][0][1][1] = 1;
    dp[1][1][1][1] = 1;
    dp[1][0][1][2] = 1;
    dp[0][1][1][2] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[0][0][i][1] = 1;
        dp[1][1][i][1] = 1;
        for (int k = 2; k <= pp; k++)
        {
            dp[0][0][i][k] = (dp[1][1][i-1][k-1] + dp[0][1][i-1][k] + dp[0][0][i-1][k] + dp[1][0][i-1][k])%M;
            dp[1][1][i][k] = (dp[0][0][i-1][k-1] + dp[0][1][i-1][k] + dp[1][1][i-1][k] + dp[1][0][i-1][k])%M;
            dp[1][0][i][k] = (dp[0][1][i-1][k-2] + dp[0][0][i-1][k-1] + dp[1][1][i-1][k-1] + dp[1][0][i-1][k])%M;
            dp[0][1][i][k] = (dp[1][0][i-1][k-2] + dp[0][0][i-1][k-1] + dp[1][1][i-1][k-1] + dp[0][1][i-1][k])%M;
            //cout << i << ' ' << k << ' ' << dp[0][0][i][k] << ' ' << dp[1][1][i][k] << ' '<<dp[0][1][i][k] << ' ' << dp[1][0][i][k] << endl;
        }
    }

    cout << (dp[0][0][n][k] + dp[0][1][n][k] + dp[1][0][n][k] + dp[1][1][n][k])%M;
    return 0;
}