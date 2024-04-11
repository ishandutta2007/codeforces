#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > g, g1;
vector <int> used;
int n;
int timer = 0;
void dfs(int v)
{
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(!used[g[v][i]])
		{
			dfs(g[v][i]);
		}	
	}
	used[v] = 2;
}
void dfs1(int v)
{
	used[v] = 1;
	for(int i = 0; i < g1[v].size(); i++)
	{
		if(!used[g1[v][i]])
		{
			dfs1(g1[v][i]);
		}
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	used.resize(n, 0);
	g.resize(n);
	g1.resize(n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			int a;
			cin >> a;
			if(i != j && a != 0)
			{
				g[i].push_back(j);
				g1[j].push_back(i);
			}
		}
	}
	dfs(0);
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			cout << "NO";
			return 0;
		}
		used[i] = false;
	}
	dfs1(0);
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
    return 0;
}