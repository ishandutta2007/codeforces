#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
vector <bool> used;
vector <int> val;
int ans = 0;
void dfs(int v, int p = -1)
{
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs(to, v);
			if(!used[to])
			{
				used[to] = 1;
				used[v] = 1;
				swap(val[to], val[v]);
				ans += 2;
			}
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p && v ==0 && !used[v])
		{
			swap(val[v], val[to]);
			used[v] = 1;
			ans += 2;
		}
	}
}
signed main() {
	int n;
	cin >> n;
	used.resize(n);
	g.resize(n);
	val.resize(n);
	for(int i = 0; i < n; i++)
	{
		val[i] = i + 1;
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
	cout << ans << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << val[i] << " ";
	}
  	return 0;
}