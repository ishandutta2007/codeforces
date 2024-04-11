#include <bits/stdc++.h>
#define pb push_back
using namespace std;

const int N = 205;
const long long M = 1e9 + 7;


int n, l, k, p[N], a[N];
double dp[N][N][N + 200];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> k;
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0][0][k + 200] = 1;
    for (int i = 0; i < n; i++){
            double pp = 0;
        for (int j = 0; j <= i; j++)
            for (int sum = -200; sum <= 200; sum++) {
                if (dp[i][j][sum + 200] == 0)
                    continue;
                pp += dp[i][j][sum + 200];
                //cout << i << ' ' << j << ' ' << sum << ' ' << dp[i][j][sum + 200] << endl;
                if (a[i + 1] != -1) {
                    dp[i + 1][j + 1][min(sum + a[i + 1] + 200, 400)] += p[i + 1] * 1.0 / 100 * dp[i][j][sum + 200];

                    dp[i + 1][j][sum + 200] += (100 - p[i + 1])*  1.0 / 100 * dp[i][j][sum + 200];


                }
                else {
                    dp[i + 1][j + 1][sum - 1 + 200] += p[i + 1] * 1.0 / 100 * dp[i][j][sum + 200];

                    dp[i + 1][j][sum + 200] += (100 - p[i + 1]) * 1.0 / 100 * dp[i][j][sum + 200];
                }
            }
        //cout << pp << endl;
    }
    double ans = 0;
    for (int i = l; i <= n; i++)
        for (int j = 0; j <= 200; j++)
            ans += dp[n][i][j + 200];
    cout << fixed << setprecision(6) << ans;
    return 0;
}