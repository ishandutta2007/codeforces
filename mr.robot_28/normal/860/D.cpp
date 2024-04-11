#include<bits/stdc++.h>
using namespace std;
vector <bool> used;
vector <vector <pair <int, int> > > g;
vector <bool> used1;
vector <pair <int, pair <int,int> > > ans;
bool dfs(int v, int p = -1)
{
	used[v] = true;
	vector <int> mass;
	vector <int> mass1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int ind = g[v][i].second;
		if(to == p)
		{
			continue;
		}
		if(!used[to])
		{
			if(dfs(to, v))
			{
				mass.push_back(ind);
				mass1.push_back(to);
			}
		}
		else if(!used1[ind])
		{
			mass.push_back(ind);
			mass1.push_back(to);
		}
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		int ind = g[v][i].second;
		if(to == p)
		{
			mass1.push_back(to);
			mass.push_back(ind);
		}
	}
	int k = mass.size();
	for(int i = 0; i + 1 < k; i += 2)
	{
		used1[mass[i]] = true;
		used1[mass[i + 1]] = true;
		ans.push_back({mass1[i] + 1, {v + 1, mass1[i + 1] + 1}});
	}
	if(k % 2 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	g.resize(n);
	used1.resize(m);
	used.resize(n);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back({b, i});
		g[b].push_back({a, i});
	}
	for(int i = 0;i < n; i++)
	{
		if(!used[i])
		{
			dfs(i);
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++)
	{
		cout << ans[i].first << " " << ans[i].second.first << " " << ans[i].second.second << "\n";
	}
	return 0;
}