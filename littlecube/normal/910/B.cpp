#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main()
{
    int n, a, b, dp[5][3][2];
    cin >> n >> a >> b;
    dp[0][0][0] = 0;
    dp[0][0][1] = 0;
    for (int i = 0; i <= 4; i++)
        for (int j = 0; j <= 2; j++)
        {
            if (i == 0 && j == 0)
            {
                dp[0][0][0] = 0;
                dp[0][0][1] = 0;
            }
            else if (i == 0)
            {
                if (dp[i][j - 1][1] < b)
                {
                    dp[i][j][1] = n - b;
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                }
                else
                {
                    dp[i][j][1] = dp[i][j - 1][1] - b;
                    dp[i][j][0] = dp[i][j - 1][0];
                }
            }
            else if (j == 0)
            {
                if (dp[i - 1][j][1] < a)
                {
                    dp[i][j][1] = n - a;
                    dp[i][j][0] = dp[i - 1][j][0] + 1;
                }
                else
                {
                    dp[i][j][1] = dp[i - 1][j][1] - a;
                    dp[i][j][0] = dp[i - 1][j][0];
                }
            }
            else
            {
                if (dp[i][j - 1][1] < b)
                {
                    dp[i][j][1] = n - b;
                    dp[i][j][0] = dp[i][j - 1][0] + 1;
                }
                else
                {
                    dp[i][j][1] = dp[i][j - 1][1] - b;
                    dp[i][j][0] = dp[i][j - 1][0];
                }
                if (dp[i - 1][j][1] < a)
                {
                    if (dp[i - 1][j][0] + 1 < dp[i][j][0] || (dp[i - 1][j][0] + 1 == dp[i][j][0] && dp[i][j][1] < n - a))
                    {
                        dp[i][j][1] = n - a;
                        dp[i][j][0] = dp[i - 1][j][0] + 1;
                    }
                }
                else
                {
                    if (dp[i - 1][j][0] < dp[i][j][0] || (dp[i - 1][j][0] + 1 == dp[i][j][0] && dp[i][j][1] < dp[i - 1][j][1] - a))
                    {
                        dp[i][j][1] = dp[i - 1][j][1] - a;
                        dp[i][j][0] = dp[i - 1][j][0];
                    }
                }
            }
        }
    cout << dp[4][2][0];
}