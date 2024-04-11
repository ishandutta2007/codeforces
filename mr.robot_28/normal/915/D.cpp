# include <bits/stdc++.h>
using namespace std;
vector <vector <pair <int, int> > > g;
vector <pair <int, int> > pred;
vector <pair <int, int> > A;
vector <int> used;
vector <int> pred1;
vector <int> e;
bool dfs(int v, int pr = -1, int pr1 = -1)
{
	pred[v].first = pr; 
	pred[v].second = pr1;
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(used[g[v][i].first] == 1)
		{
			int t = v;
			e.push_back(g[v][i].second);
			while(t != g[v][i].first)
			{
				e.push_back(pred[t].second);
				t = pred[t].first;
			}
			return true;
		}
		else if(used[g[v][i].first] == 0)
		{
			if(dfs(g[v][i].first, v, g[v][i].second))
			{
				return true;
			}
		}
	}
	used[v] = 2;
	return false;
}
bool dfs1(int v, int pred, int ind)
{
	used[v] = 1;
	for(int j = 0; j < g[v].size(); j++)
	{
		if(g[v][j].second != ind)
		{
			if(used[g[v][j].first] == 1)
			{
				return true;
			}
			else if(used[g[v][j].first] == 0)
			{
				if(dfs1(g[v][j].first, v, ind))
				{
					return true;
				}
			}
		}
	}
	used[v] = 2;
	return false;
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	used.resize(n);
	pred.resize(n);
	g.resize(n);
	pred1.resize(n);
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		A.push_back({x - 1, y - 1});
		g[x - 1].push_back({y - 1, i});
	}
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			if(dfs(i))
			{
				break;
			}
		}
	}
	if(e.size() == 0)
	{
		cout << "YES";
		return 0;
	}
	for(int i = 0; i < e.size(); i++)
	{
		for(int j = 0; j < n; j++)
		{
			used[j] = 0;
			pred1[j] = -1;
		}
		bool flag = true;
		for(int j = 0; j < n; j++)
		{
			if(!used[j])
			{
				if(dfs1(j, -1, e[i]))
				{
					flag = false;
					break;
				}
			}
		}
		if(flag)
		{
			cout << "YES";
			return 0;
		}
	}
	cout << "NO";
	return 0;
}