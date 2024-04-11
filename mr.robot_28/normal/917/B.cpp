#include <bits/stdc++.h>
using namespace std;
vector <int> vec;
vector <bool> used;
vector <vector <pair <int, int> > > g;
void dfs(int v)
{
	used[v] = true;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(!used[to])
		{
			dfs(to);
		}
	}
	vec.push_back(v);
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	g.resize(n);
	used.resize(n);
	for(int i = 0; i < m; ++i)
	{
		int a, b;
		char t;
		cin >> a >> b >> t;
		a--;
		b--;
		g[a].push_back({b, t - 'a'});
	}
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			dfs(i);
		}
	}
	reverse(vec.begin(), vec.end());
	bool dp[n][n][26][2];
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = n - 1; j >= 0; j--)
		{
			int a = vec[i];
			int b = vec[j];
			for(int k = 25; k >= 0; k--)
			{
				for(int t = 0; t < 2; t++)
				{
					dp[a][b][k][t] = 0;
					if(t == 0)
					{
						for(int id = 0; id < g[a].size(); id++)
						{
							int to = g[a][id].first;
							int tox = g[a][id].second;
							if(tox >= k && !dp[to][b][tox][1 - t])
							{
								dp[a][b][k][t] = 1;
							}
						}
					}
					else
					{
						for(int id = 0; id < g[b].size(); id++)
						{
							int to = g[b][id].first;
							int tox = g[b][id].second;
							if(tox >= k && !dp[a][to][tox][1 - t])
							{
								dp[a][b][k][t] = 1;
							}
						}
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(dp[i][j][0][0])
			{
				cout << "A";
			}
			else
			{
				cout << "B";
			}
		}
		cout << "\n";
	}
    return 0;
}