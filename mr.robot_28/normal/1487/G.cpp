#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ld long double
#define int long long
#define sz(s) (int)s.size()
const int mod = 998244353;
void relax(int &a, int b)
{
    a += b;
    if(a >= mod)
    {
        a -= mod;
    }
}
signed main()
{
//ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    int n;
    cin >> n;
    vector <int> c(26);
    for(int i = 0; i < 26; i++)
    {
        cin >> c[i];
    }
    int ans = 26 * 26;
    for(int i = 0; i < n - 2; i++)
    {
        ans = ans * 25 % mod;
    }
        int dp[2][n + 1][4];
        for(int i = 0; i < n + 1; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                dp[0][i][j] = 0;
                dp[1][i][j] = 0;
            }
        }
        dp[0][0][0] = 1;
        for(int i = 1; i <= n; i++)
        {
            for(int c = 0; c <= n; c++)
            {
                for(int j = 0; j < 4; j++)
                {
                    dp[i & 1][c][j] = 0;
                }
            }
            for(int c = 0; c < n; c++)
            {
                for(int j = 0; j < 4; j++)
                {
                    int k;
                    if(((j & 2) > 0) || i <= 2)
                    {
                        k = 25;
                    }
                    else
                    {
                        k = 24;
                    }
                    if((j & 2) == 0)
                    {
                        relax(dp[i & 1][c + 1][(j & 1) * 2 + 1], dp[(i - 1) & 1][c][j]);
                    }
                    relax(dp[i & 1][c][(j & 1) * 2], dp[(i - 1) & 1][c][j] * k % mod);
                }
            }
        }
    for(int a = 0; a < 26; a++)
    {
        for(int c1 = c[a] + 1; c1 <= n; c1++)
        {
            for(int j = 0; j < 4; j++)
            {
                relax(ans, (mod - dp[n & 1][c1][j]) % mod);
            }
        }
    }
    int dp1[2][n + 1][n + 1][9];
    for(int i = 0; i < n + 1; i++)
    {
        for(int j = 0; j < n + 1; j++)
        {
            for(int m = 0; m < 9; m++)
            {
                dp1[0][i][j][m] = dp1[1][i][j][m] = 0;
            }
        }
    }
    dp1[0][0][0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int c1 = 0; c1 <= n; c1++)
        {
            for(int c2 = 0; c2 <= n; c2++)
            {
                for(int j = 0; j < 9; j++)
                {
                    dp1[i & 1][c1][c2][j] = 0;
                }
            }
        }
        for(int c1 = 0; c1 < n; c1++)
        {
            for(int c2 = 0; c2 + c1 < i; c2++)
            {
                for(int j = 0; j < 9; j++)
                {
                    if((j / 3) % 3 == 0 && i >= 3)
                    {
                        relax(dp1[i & 1][c1][c2][(j % 3) * 3], dp1[(i - 1) & 1][c1][c2][j] * (26 - 3) % mod);
                    }
                    else
                    {
                        relax(dp1[i & 1][c1][c2][(j % 3) * 3], dp1[(i - 1) & 1][c1][c2][j] * (26 - 2) % mod);
                    }
                    if((j / 3) % 3 != 1)
                    {
                        relax(dp1[i & 1][c1 + 1][c2][(j % 3) * 3 + 1], dp1[(i - 1) & 1][c1][c2][j]);
                    }
                    if((j / 3) % 3 != 2)
                    {
                        relax(dp1[i & 1][c1][c2 + 1][(j % 3) * 3 + 2], dp1[(i - 1) & 1][c1][c2][j]);
                    }
                }
            }
        }
    }
    int cnt[n + 1][n + 1];
    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            cnt[i][j] = 0;
            for(int t = 0; t < 9; t++)
            {
                relax(cnt[i][j], dp1[n & 1][i][j][t]);
            }
        }
    }
    for(int a = 0; a < 26; a++)
    {
        for(int b = a + 1; b < 26; b++)
        {
            for(int i = c[a] + 1; i <= n; i++)
            {
                for(int j = c[b] + 1; j <= n; j++)
                {
                    relax(ans, cnt[i][j]);
                }
            }
        }
    }
    cout << ans;
    return 0;
}