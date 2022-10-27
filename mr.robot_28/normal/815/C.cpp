#include<bits/stdc++.h>
 
using namespace std;
int dp[5001][5001][2];
vector <int> c, d;
vector <vector <int> > g;
int n, b;
void dfs(int v)
{
	dp[v][0][0] = 0;
	dp[v][1][0] = min(dp[v][1][0], c[v]);
	dp[v][1][1] = min(dp[v][1][1], c[v] - d[v]);
	for(int i = 0; i < g[v].size(); i++)
	{
		dfs(g[v][i]);
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		int ma1 = 0, ma2 = 0;
		for(int j = 1; j <= n; j++)
		{
			if(dp[v][j][0] > b)
			{
				break;
			}
			ma1 = j;
		}
		for(int j = 1; j <= n; j++)
		{
			if(dp[v][j][1] > b)
			{
				break;
			}
			ma2 = j;
		}
		for(int j = ma2; j >= 0; j--)
		{
			for(int d1 = 1;  d1 + j <= n; d1++)
			{
				if(min(dp[to][d1][0], dp[to][d1][1]) > b)
				{
					break;
				}
				dp[v][d1 + j][1] = min(dp[v][d1 + j][1], min(dp[to][d1][0], dp[to][d1][1]) + dp[v][j][1]);
			}
		}
		for(int j = ma1; j >= 0; j--)
		{
			for(int d1 = 1; d1 + j <= n; d1++)
			{
				if(dp[to][d1][0] > b)
				{
					break;
				}
				dp[v][j + d1][0] = min(dp[v][j + d1][0], dp[v][j][0] + dp[to][d1][0]);
			}
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> b;
	c.resize(n);
	d.resize(n);
	g.resize(n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			dp[i][j][0] = dp[i][j][1] = b + 1;
		}
	}
	for(int i = 0; i < n; i++)
	{
		cin >> c[i] >> d[i];
		if(i != 0)
		{
			int p;
			cin >> p;
			p--;
			g[p].push_back(i);
		}
	}
	dfs(0);
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(min(dp[0][i][0], dp[0][i][1]) <= b)
		{
			ans = i;
		}
	}
	cout << ans;
    return 0;
}