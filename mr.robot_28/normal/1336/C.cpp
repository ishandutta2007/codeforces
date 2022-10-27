#include <bits/stdc++.h>
using namespace std;
const int const1 = 998244353;
void funct(int &a)
{
	while(a >= const1)
	{
		a -= const1;
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s, t;
	cin >> s >> t;
	int m = s.size();
	int n = t.size();
	vector <vector <int> > dp(n + 2, vector <int> (n + 2));
	vector <vector <int> > dp2(n + 2, vector <int> (n + 2));
	int ans = 0;
	for(int i = 0; i < m; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			if(t[j - 1] != s[i])
			{
				continue;
			}
			if(i == 0)
			{
				dp2[j][j] += 2;
				continue;
			}
			dp2[max(0, j - i)][j] += dp[max(0, j - i)][j - 1];
			funct(dp2[max(0, j - i)][j]);
			dp2[j][min(n + 1, j + i)] += dp[j + 1][min(n + 1, j + i)];
			funct(dp2[j][min(n + 1, j + i)]);
		}
		dp2[n + 1][n + 1] += 2 * dp[n + 1][n + 1];
		if(i == 0)
		{
			dp2[n + 1][n + 1] += 2;
		}
		funct(dp2[n + 1][n + 1]);
		for(int j = 1; j < n + 1; j++)
		{
			dp2[j][n + 1] += dp[j][n + 1];
			funct(dp2[j][n + 1]);
		}
		for(int j = 1; j <= n; j++)
		{
			dp2[j][n + 1] += dp[j][n];
			funct(dp2[j][n]);
		}
		if(i != 0)
		{
		for(int j = 1; j <= n; j++)
		{
			dp[max(j - i + 1, 0)][j] = 0;
			dp[j][n + 1] = 0;
		}
		}
		for(int j = 1; j <= n; j++)
		{
			dp[max(j - i, 0)][j] = dp2[max(j - i, 0)][j];
			dp[j][min(n + 1, j + i)] = dp2[j][min(n + 1, j + i)];
		}
		for(int j = 1; j <= n + 1; j++)
		{
			dp[j][n + 1] = dp2[j][n + 1];
			funct(dp[j][n + 1]);
		}
		for(int j = 0; j <= n + 1; j++)
		{
			dp2[max(0, j - i)][j] = 0;
			dp2[j][n + 1] = 0;
		}
		for(int j = 0; j < n + 2; j++)
		{
			for(int k = 0; k < n + 2; k++)
			{
			//	cout << dp2[j][k] << " ";
			}
		//	cout << "\n";
		}
		//cout << "\n";
		ans += dp[1][n] + dp[1][n + 1];
		while(ans >= const1)
		{
			ans -= const1;
		}
	}
	cout << (ans) % const1;
	return 0;
}