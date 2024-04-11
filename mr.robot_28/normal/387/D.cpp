#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > g, g1, G;
vector <int> mt, was;
bool dfs(int v, int count)
{
	if(was[v] == count)
	{
		return false;
	}
	was[v] = count;
	for(int i = 0; i< G[v].size(); i++){
		if(mt[G[v][i]] == -1 || dfs(mt[G[v][i]], count))
		{
			mt[G[v][i]] = v;
			return true;
		}
	}
	return false;
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	g.resize(n);
	g1.resize(n);
	mt.resize(2 * n);
	was.resize(2 * n);
	G.resize(2 * n);
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		if(x != y)
		{
			g1[y].push_back(x);
		}
	}
	int ans = 1e9;
	for(int i = 0; i < n; i++)
	{
		int u= n * 2 - 1 - g[i].size() - g1[i].size();
		int m1 = m - g[i].size() - g1[i].size();
		for(int j = 0; j < n * 2; j++)
		{
			was[j] = 0;
			mt[j] = -1;
			if(G[j].size() != 0)
			{
				G[j].clear();
			}
		}
		for(int p = 0; p < n; p++)
		{
			if(p != i)
			{
				for(int p1 = 0; p1 < g[p].size(); p1++)
				{
					if(g[p][p1] != i)
					{
						G[p].push_back(g[p][p1] + n);
						G[n + g[p][p1]].push_back(p);
					}
				}
			}
		}
		for(int j = 0; j < n; j++)
		{
			dfs(j, j + 1);
		}
		for(int j = n; j < 2 * n; j++)
		{
			if(j - n != i && mt[j] == -1)
			{
				u++;
			}
			else if(mt[j] != -1)
			{
				m1--;
			}
		}
		ans = min(ans, u + m1);
	}
	cout << ans;
	return 0;
}