#include<bits/stdc++.h>
using namespace std;
#define int long long
const int CONST1 = 1e9 + 7;
const int CONST2 = 998244353;
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	 cout.tie(NULL);
  	int n, h;
  	cin >> n >> h;
  	vector <vector <int> > dp(n + 1, vector <int> (n + 1, 0));
  	dp[0][0] = 1;
  	for(int i = 1; i <= n; i++)
  	{
  		for(int j = 1; j <= min(n, i); j++)
  		{
  			for(int k = 0; k <= i - 1; k++)
  			{
  				for(int k1 = 0; k1 <= j - 1; k1++)
  				{
  					dp[i][j] = (dp[i][j] + dp[k][j - 1] * dp[i - k - 1][k1]) ;
  				}
  				for(int k1 = 0; k1 < j - 1; k1++)
  				{
  					dp[i][j] = (dp[i][j] + dp[k][k1] * dp[i - k - 1][j - 1]);
  				}
  			}
  		}
  	}
  	int sum = 0;
  	for(int i = h; i <= n; i++)
  	{
  		sum += dp[n][i];
  	}
  	cout << sum;
    return 0;
}