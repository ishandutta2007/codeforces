#include<bits/stdc++.h>
 
using namespace std;
vector <vector <int> > g;
vector <int> c;
void dfs(int v, int p = -1)
{
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to == p)
		{
			continue;
		}
		if(c[to] != c[v])
		{
			cout << "NO";
			exit(0);
		}
		dfs(to, v);
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	g.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	c.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	int v = 0, maxcol = 0;
	for(int i = 0; i < n; i++)
	{
		int col = 0;
		for(int j = 0; j < g[i].size(); j++)
		{
			if(c[g[i][j]] != c[i])
			{
				col++;
			}
		}
		if(col > maxcol)
		{
			maxcol = col;
			v = i;
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		dfs(g[v][i], v);
	}
	cout << "YES\n";
	cout << v + 1 ;
	return 0;
}