#include <bits/stdc++.h>

using namespace std;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		int dp[n][2][2][2][2];
		for(int i = 0; i < n; i++)
		{
			for(int k = 0; k < 2; k++)
			{
			for(int a = 0; a < 2; a++)
			{
				for(int b = 0; b < 2; b++)
				{
					for(int c = 0; c < 2; c++)
					{
						dp[i][k][a][b][c] = 1e9;
					}
				}
			}
			}
		}
		if(s[0] == 'L')
		{
			dp[0][0][0][0][0] = 0;
			dp[0][0][1][0][1] = 1;
		}
		else
		{
			dp[0][0][0][0][0] = 1;
			dp[0][0][1][0][1] = 0;
		}
		for(int i = 1; i < n; i++)
		{
			int t = 0;
			if(s[i] == 'R')
			{
				t = 1;
			}
			if(i == 1)
			{
			for(int a = 0; a < 2; a++)
			{
				for(int b = 0; b < 2; b++)
				{
					for(int c = 0; c < 2; c++)
					{
							dp[i][1][a][c][0] = min(dp[i][1][a][c][0], dp[i - 1][0][a][b][c] + t);
							dp[i][0][a][c][1] = min(dp[i][0][a][c][1], dp[i - 1][0][a][b][c] + 1 - t);
					}
				}
			}
			}
			else
			{
				for(int k = 0; k < 2; k++)
				{
					for(int a = 0; a < 2; a++)
			{
				for(int b = 0; b < 2; b++)
				{
					for(int c = 0; c < 2; c++)
					{
						if(b == 0 && c == 0)
						{
							dp[i][k][a][c][1] = min(dp[i][k][a][c][1], dp[i - 1][k][a][b][c] + 1 - t);
						}
						if(b == 1 && c == 1)
						{
							dp[i][k][a][c][0] = min(dp[i][k][a][c][0], dp[i - 1][k][a][b][c] + t);
						}
						if(b != c)
						{
							dp[i][k][a][c][0] = min(dp[i][k][a][c][0], dp[i - 1][k][a][b][c] + t);
							dp[i][k][a][c][1] = min(dp[i][k][a][c][1], dp[i - 1][k][a][b][c] + 1 - t);
						}
					}
				}
			}
				}
			}
		}
		int ans = 1e9;
		for(int a = 0; a < 2; a++)
		{
			for(int b = 0; b < 2; b++)
			{
				for(int c = 0; c < 2; c++)
				{
					for(int k = 0; k < 2; k++)
					{
						if(a == 1 && c == 1 && b != k)
						{
							ans = min(ans, dp[n - 1][a][b][c][k]);
						}
						if(a == 1 && c == 0 && (b == 1 || k == 1))
						{
							ans = min(ans, dp[n - 1][a][b][c][k]);
						}
						if(a == 0 && c == 1 && (b == 0 || k == 0))
						{
							ans = min(ans, dp[n - 1][a][b][c][k]);
						}
						if(a == 0 && c == 0 && b != k)
						{
							ans = min(ans, dp[n - 1][a][b][c][k]);
						}
				//		cout << dp[n - 1][a][b][c][k] << " ";
					}
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
}