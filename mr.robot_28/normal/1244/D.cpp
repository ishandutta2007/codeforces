#include <bits/stdc++.h>

using namespace std;
#define int long long
vector <vector <int> > g;
vector <vector <int> > c;
vector <vector <int> > p = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 1, 0}, {2, 0, 1}};
vector <vector <vector <int> > > dp;
int ans = 1e18;
vector <int> color;
void dfs(int v, int pred)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			dp[v][i][j] = 1e18;
		}
	}
	if(v == 0)
	{
		if(g[v].size() == 2)
		{
			dfs(g[v][0], v);
			dfs(g[v][1], v);
			for(int j = 0; j < 6; j++)
			{
				dp[v][p[j][0]][p[j][1]] = min(dp[v][p[j][0]][p[j][1]], dp[g[v][0]][p[j][1]][p[j][2]] + c[v][p[j][0]] + dp[g[v][1]][p[j][2]][p[j][1]]);
			}
			for(int i = 0; i < 3; i++)
			{
				for(int j = 0; j < 3; j++)
				{
					if(i != j && dp[v][i][j] < ans)
					{
						ans = dp[v][i][j];
						color[v] = i;
						color[g[v][0]] = j;
						for(int k = 0; k < 3; k++)
						{
							if(k != i && k != j)
							{
								color[g[v][1]] = k;
							}
						}
					}
				}
			}
			
		}
		else if(g[v].size() == 1)
		{
			dfs(g[v][0], v);
			for(int j = 0; j < 6; j++)
			{
				dp[v][p[j][0]][p[j][1]] = min(dp[v][p[j][0]][p[j][1]], dp[g[v][0]][p[j][1]][p[j][2]] + c[v][p[j][0]]);
			}
			for(int i = 0; i < 3; i++)
			{
				for(int j = 0; j < 3; j++)
				{
					if(i != j && dp[v][i][j] < ans)
					{
						ans = dp[v][i][j];
						color[v] = i;
						color[g[v][0]] = j;
					}
				}
			}
		}
		else
		{
			if(c[v][0] <= c[v][1] && c[v][0] <= c[v][2])
			{
				ans = c[v][0];
				color[v] = 0;
			}
			else if(c[v][1] <= c[v][0] && c[v][1] <= c[v][2])
			{
				ans = c[v][1];
				color[v] = 1;
			}
			else
			{
				ans = c[v][2];
				color[v] = 2;
			}
		}
	}
	else
	{
		int cnt = 0;
		for(int i = 0; i < g[v].size(); i++)
		{
			if(g[v][i] != pred)
			{
				dfs(g[v][i], v);
				cnt++;
				for(int j = 0; j < 6; j++)
				{
					dp[v][p[j][0]][p[j][1]] = min(dp[v][p[j][0]][p[j][1]], dp[g[v][i]][p[j][1]][p[j][2]] + c[v][p[j][0]]);
				}
			}
		}
		if(cnt == 0)
		{
			for(int i = 0; i < 3; i++)
			{
				for(int j = 0; j < 3; j++)
				{
					if(i != j)
					{
						dp[v][i][j] = c[v][i];
					}
				}
			}
		}
	}
}
void dfs2(int v, int pred1, int pred2)
{
	if(color[v] == -1)
	{
		for(int k = 0; k < 3; k++)
		{
			if(k != color[pred1] && k != color[pred2])
			{
				color[v] = k;
			}
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred1)
		{
			dfs2(g[v][i], v, pred1);
		}
	}
}
signed main() {
	int n;
	cin >> n;
	g.resize(n);
	color.resize(n, -1);
	c.resize(n, vector <int> (3));
	dp.resize(n, vector <vector <int> > (3, vector <int> (3, 1e9)));
	for(int i = 0; i < n; i++)
	{
		cin >> c[i][0];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> c[i][1];
	}
	for(int i = 0; i < n; i++)
	{ 
		cin >> c[i][2];
	}
	for(int i = 0; i <n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i = 0; i < n; i++)
	{
		if(g[i].size() >= 3)
		{
			cout << -1;
			return 0;
		}
	}
	dfs(0, -1);
	cout << ans << "\n";
	dfs2(0, -1, -1);
	for(int i = 0; i < n; i++)
	{
		cout << color[i] + 1<< " ";
	}
	return 0;
}