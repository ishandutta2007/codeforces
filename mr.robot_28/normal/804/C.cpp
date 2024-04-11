#include<bits/stdc++.h>
 
using namespace std;
vector <vector <int> > g;
vector <vector <int> > colors;
vector <int> col;
vector <bool> used;
void dfs(int v, int p = -1)
{
	int j = 0;
	for(int i = 0; i < colors[v].size(); i++)
	{
		if(col[colors[v][i]] != -1)
		{
			used[col[colors[v][i]]] = 1;
		}
	}
	for(int i = 0; i < colors[v].size(); i++)
	{
		if(col[colors[v][i]] == -1)
		{
			while(used[j])
			{
				j++;
			}
			col[colors[v][i]] = j;
			used[j] = 1;
		}
	}
	for(int i = 0; i < colors[v].size(); i++)
	{
		used[col[colors[v][i]]] = 0;
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs(to, v);
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	g.resize(n);
	col.resize(m, -1);
	colors.resize(n);
	used.resize(m);
	int maxcnt = 1;
	for(int i = 0; i < n; i++)
	{
		int k;
		cin >> k;
		maxcnt = max(maxcnt, k);
		for(int j = 0; j < k; j++)
		{
			int a;
			cin >> a;
			a--;
			colors[i].push_back(a);
		}
	}
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs(0);
	int maxans = 0;
	for(int i = 0; i < m; i++)
    {
    	if(col[i] == -1)
    	{
    		col[i] = 0;
		}
    	col[i]++;
    	maxans = max(maxans, col[i]);
	}
	cout << maxans << "\n";
	for(int i = 0; i < m; i++)
	{
		cout << col[i] << " ";
	}
	return 0;
}