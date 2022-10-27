#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector <vector <vector <int> > > dp(n + 1, vector <vector <int> > (2, vector <int> (3, -1e9)));
	dp[0][0][0] = 0;
	dp[0][1][0] = 0;
	for(int i = 0; i < s.size(); i++)
	{
		for(int j = 0; j < 3; j++)
		{
			for(int t = 0; t < 3; t++)
			{
				if(j == 2 && t < 2 || j == 0 && t == 2 || j == 1 && t == 0)
				{
					continue;
				}
				int a = s[i] - '0';
				if(t == 1)
				{
					a ^= 1;
				}
				for(int b = 0; b < 2; b++)
				{
					if(a == b)
					{
						dp[i + 1][a][t] = max(dp[i + 1][a][t], dp[i][b][j]);
					}
					else
					{
						dp[i + 1][a][t] = max(dp[i + 1][a][t], dp[i][b][j] + 1);
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			ans = max(ans, dp[n][i][j]);
		}
	}
	cout << ans;
	return 0;
}