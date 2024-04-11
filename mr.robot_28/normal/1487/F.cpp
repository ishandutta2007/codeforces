#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define ld long double
#define int long long
#define sz(s) (int)s.size()
void min(int &a, int b)
{
    if(b < a)
    {
        a = b;
    }
}
signed main()
{
//ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    s += "0";
    n++;
    int k = 240;
    int k1 = 18;
    int dp[2][k + 10][k + 10][2 * (k1 + 10)];
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < k + 10; j++)
        {
            for(int j1 = 0; j1 < k + 10; j1++)
            {
                for(int j2 = 0; j2 < 2 * (k1 + 10); j2++)
                {
                    dp[i][j][j1][j2] = 1e9;
                }
            }
        }
    }
    for(int u = 0; u < k + 10; u++)
    {
        for(int u1 = 0; u1 < k + 10; u1++)
        {
            dp[0][u][u1][k1 + 10] = 0;
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < k + 10; j++)
        {
            for(int j1 = 0; j1 < k + 10; j1++)
            {
                for(int j2 = 0; j2 < 2 * (k1 + 10); j2++)
                {
                    dp[i & 1][j][j1][j2] = 1e9;
                }
            }
        }
        int t = (s[i - 1] - '0');
        for(int j = 0; j < k + 10; j++)
        {
            for(int j1 = 0; j1 < k + 10; j1++)
            {
                int p = (j - j1 - (k1 + 9) + 10000) % 10;
                if(t < p)
                {
                    p = (t - p + 10);
                }
                else
                {
                    p = t - p;
                }
                for(int j2 = -(k1 + 9) + p; j2 < k1 + 10; j2 += 10)
                {
                    int t = (j - j1 + j2) / 10;
                    if(t <= 0 && t * 10 > (j - j1 + j2))
                    {
                        t--;
                    }
                    if(t + k1 + 10 < 0 || t + k1 + 10 >= 2* (k1 + 10))
                    {
                        continue;
                    }
                    dp[i & 1][j][j1][t + k1 + 10] = dp[(i - 1) & 1][j][j1][j2 + k1 + 10] + j + j1;
                }
            }
        }
        for(int j2 = 0; j2 < 2 *(k1 + 10); j2++)
        {
            for(int j = 0; j < k + 10; j++)
            {
                for(int j1 = k  + 8; j1 >= 0; j1--)
                {
                    min(dp[i & 1][j][j1][j2], dp[i & 1][j][j1 +1][j2]);
                }
            }
            for(int j1 = 0; j1 < k + 10; j1++)
            {
                for(int j = k + 8; j >= 0; j--)
                {
                    min(dp[i & 1][j][j1][j2], dp[i & 1][j + 1][j1][j2]);
                }
            }
        }
    }
  //  cout << dp[1][1][6][k + 10 - 1] << " ";
 //   cout << dp[1][4][0][0] << " ";
    cout << dp[n & 1][0][0][k1 + 10];
    return 0;
}