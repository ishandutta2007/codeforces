#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
#define ll long long
#define int long long
using namespace std;

signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	int n;
	cin >> n;
	vector <int> p(n);
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	int dp[n + 1][n + 1][2];
	for(int i = 0; i <= n; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			for(int t = 0; t < 2; t++)
			{
				dp[i][j][t] = 1e9;
			}
		}
	}
	if(p[0] == 0)
	{
		dp[0][1][1] = dp[1][0][0] = 0;
	}
	else
	{
		dp[p[0] % 2 == 0][p[0] % 2][p[0] % 2] = 0;
	}
		int dp1[n + 2][n + 2][2];
	for(int it = 1; it < n; it++)
	{
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j <= n; j++)
			{
				for(int t = 0; t < 2; t++)
				{
					dp1[i][j][t] = 1e9;
				}
			}
		}
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j <= n; j++)
			{
				for(int t1 = 0; t1 < 2; t1++)
				{
					if(p[it] == 0)
					{
						for(int t2 = 0; t2 < 2; t2++)
						{
							dp1[i + 1 - t2][j + t2][t2] = min(dp1[i + 1 - t2][j + t2][t2], dp[i][j][t1] + (t1 != t2));
						}
					}
					else
					{
						int fl = p[it] % 2;
						dp1[i + 1 - fl][j + fl][fl] = min(dp1[i + 1 - fl][j + fl][fl], dp[i][j][t1] + (t1 != fl));
					}
				}
			}
		}
		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j <= n; j++)
			{
				for(int t = 0; t < 2; t++)
				{
					dp[i][j][t] = dp1[i][j][t];
				}
			}
		}
	}
	cout << min(dp[n / 2][n - n / 2][0], dp[n / 2][n - n / 2][1]);
	return 0;
}