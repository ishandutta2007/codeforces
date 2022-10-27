#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
int mod = 1e9 + 7;
const int N = 2e5+ 100;


signed main()
{
  //  ifstream cin("input1.txt.4c");
//    ios_base::sync_with_stdio(0);
  //  cin.tie(0);
    //cout.tie(0);
    int n;
    cin >> n >> mod;
    vector <int> dp1(n + 1, 0);
    vector <vector <int> > dp2(n + 1, vector <int> (n + 1, 0));
    dp2[1][1] = 1;
    for(int k = 2; k <= n; k++)
    {
        for(int l1 = 1; l1 <= n && k - l1 >= 1; l1++)
        {
            int l2 = k - l1;
            if(l1 < n)
            {
            dp2[l1 + 1][l2] = (dp2[l1][l2] + dp2[l1 + 1][l2]) % mod;
            }
            if(l2 < n)
            {
            dp2[l1][l2 + 1] = (dp2[l1][l2 + 1] + dp2[l1][l2]) % mod;
            }
        }
    }
  //  cout << "A";
    dp1[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        dp1[i] = 0;
        for(int l1 = 0; l1 <= n; l1++)
        {
            if(i - l1 + 1 <= n && i - l1 >= 0)
            {
                dp1[i] = (dp1[i] + dp2[l1][i - l1 + 1]) % mod;
            }
        }
    }
  //  cout << "B";
    vector <vector <int> > cnk(n + 1, vector <int> (n + 1, 0));
    cnk[0][0] = 1;
    for(int i = 1; i <= n; i++)
    {
        cnk[0][i] = 1;
        for(int j = 1; j <= i; j++)
        {
            cnk[j][i] = (cnk[j - 1][i - 1] + cnk[j][i - 1]) % mod;
        }
    }
    //cout << "C";
    vector <vector <int> > dp(n + 2, vector <int> (n + 1, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
    {
    //    cout << i << "\n";/
        for(int j = 1; j + i <= n; j++)
        {
            for(int t = 0; t < n; t++)
            {
                if(j + i - t >= 0)
                {
             //       cout << j << " " << j + i - t << "\n";
                dp[i + j + 1][t + 1] = (dp[i + j + 1][t + 1] + dp[i][t] * cnk[j][j + i - t] % mod * dp1[j]) % mod;
                }
            }
        }
    }
  //  cout << "D";
    int ans = 0;
    for(int t = 0;t <= n; t++)
    {
        ans += dp[n + 1][t];
    }
    cout << ans % mod;
    return 0;
}