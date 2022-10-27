#include<bits/stdc++.h>
using namespace std;
#define int long long
vector <int> ans;
vector <vector <int> > g;
vector <int> _sz;
int sum = 0;
int n;
void dfs(int v, int p = -1)
{
	_sz[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs(to, v);
			_sz[v] += _sz[to];
			sum += 2 * min(_sz[to], n - _sz[to]);
		}
	}
}
int centroid = -1;
void dfs1(int v, int p = -1)
{
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p && _sz[to] > n / 2){
			dfs1(to, v);
		}
	}
	if(centroid == -1){
		centroid = v;
	}
}
vector <int> vec;
vector <vector <int> > mass;
void dfs2(int v, int p)
{
	vec.push_back(v);
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			dfs2(to, v);
		}
	}
}
signed main() {
	cin >> n;
	ans.resize(n);
	g.resize(n);
	_sz.resize(n);
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
	dfs1(0);
	vector <int> iter(n, 0);
	for(int i = 0; i < g[centroid].size(); i++)
	{
		dfs2(g[centroid][i], centroid);
		mass.push_back(vec);
		vec.clear();
	}
	vec.push_back(centroid);
	mass.push_back(vec);
	vector <pair <int, int> > ind;
	for(int i = 0; i < mass.size(); i++)
	{
		ind.push_back({mass[i].size(), i});
	}
	sort(ind.begin(), ind.end());
	int ind1 = mass.size() - 1;
	for(int i = 0; i < ind.size(); i++)
	{
		int index1 = ind[i].second;
		for(int j = 0; j < mass[index1].size(); j++){
			if(iter[ind[ind1].second] == ind[ind1].first)
			{
				ind1 = (ind1 + 1) % (mass.size());
			}
			ans[mass[index1][j]] = mass[ind[ind1].second][iter[ind[ind1].second]];
			iter[ind[ind1].second]++;
		}
	}
	cout << sum << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] + 1 << " ";
	}
  	return 0;
}