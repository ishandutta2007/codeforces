#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > level;
int T;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n >> T;
	level.resize(T);
	vector <vector <int> > dp(T + 1, vector <int> (n + 1, -1e9));
	dp[0][1] = 0;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		int t, q;
		cin >> t >> q;
		level[T - t].push_back(q);
		ans = max(ans, q);
	}
	for(int i = 1; i < T; i++)
	{
		sort(level[i].begin(), level[i].end());
		int sum = 0;
		int c = 0;
		for(int t = 0; t <= n; t++)
		{
			dp[i][min(t * 2, n)] = dp[i - 1][t];
		}
		for(int j = level[i].size() - 1; j >= 0; j--)
		{
			c++;
			sum += level[i][j];
			for(int t = (c + 1) / 2; t <= n; t++)
			{
				dp[i][min(n, t * 2 - c)] = max(dp[i - 1][t] + sum, dp[i][min(n, t * 2 - c)]);
			}
		} 
	}
	for(int i = 0; i <= T; i++)
	{
		for(int j = 0;  j<= n; j++)
		{ans = max(ans, dp[i][j]);
		}
	}
	cout << ans;
	return 0;
}