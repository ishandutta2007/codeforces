#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define sz(a) (int)a.size()
#define int long long
const int mod = 998244353;
signed main()
{
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    string x, y;
    cin >> x >> y;
    int n = sz(x);
    int m = sz(y);
    int dp[n + 1][m + 1][2][4];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            for(int t = 0; t < 2; t++)
            {
                for(int k = 0; k < 4; k++)
                {
                    dp[i][j][t][k] = 0;
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            dp[i][j][0][1] = 1;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            dp[j][i][1][2] = 1;
        }
    }
  /*  for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(x[i - 1] != y[j - 1])
            {
                dp[i][j][0] = dp[i][j][1] = 1;
            }
        }
    }*/
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= m; j++)
        {
            for(int f1 = 0; f1 < 4; f1++)
            {
            if(i + 1 <= n)
            {
                int s = 0;
                if(i == 0 || x[i - 1] != x[i])
                {
                    s += dp[i][j][0][f1];
                }
                if(j == 0 || y[j - 1] != x[i])
                {
                    s += dp[i][j][1][f1];
                }
                dp[i + 1][j][0][f1 | 1] = (dp[i + 1][j][0][f1 | 1] + s) % mod;
            }
            if(j + 1 <= m)
            {
                int s = 0;
                if(i == 0 || x[i - 1] != y[j])
                {
                    s += dp[i][j][0][f1];
                }
                if(j == 0 || y[j - 1] != y[j])
                {
                    s += dp[i][j][1][f1];
                }
                dp[i][j + 1][1][f1 | 2] = (dp[i][j + 1][1][f1 | 2] + s) % mod;
            }
            if(f1 == 3)
            {
                ans = (ans + dp[i][j][0][f1] + dp[i][j][1][f1]) % mod;
            }
            }
        }
    }
    cout << ans;
    return 0;
}