#include <bits/stdc++.h>
                  
using namespace std;
vector <vector <pair <int, int> > > g;
vector <int> used;
vector <int> mass;
int dfs(int v, int p = -1)
{
	mass.push_back(v);
	used[v] = 1;
	int ans = -1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i].first;
		if(g[v][i].second == p)
		{
			continue;
		}
		int k;
		if(used[to] == 1)
		{
			ans = to;
		}
		else if((k = dfs(to, g[v][i].second)) != -1){
			ans = k;
		}
	}
	used[v] = 2;
	return ans;
}
signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n;
	cin >> n;
	used.resize(n);
	vector <int> a(n);
	g.resize(n);
	for(int i =  0; i < n; i++)
	{
		cin >> a[i];
		a[i]--;
		if(a[i] != i)
		{
			g[a[i]].push_back({i, i});
			g[i].push_back({a[i], i});
		}
	}
	vector <int> mass1;
	vector <pair <int, int> > comp;
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			int t = dfs(i);
			comp.push_back({i, t});
			for(int j = 0; j < mass.size(); j++)
			{
				if(a[mass[j]] == mass[j])
				{
					mass1.push_back(mass[j]);
				}
			}
			if(mass1.size() != comp.size())
			{
				mass1.push_back(-1);
			}
			mass.clear();
		}
	}
	int st = -1;
	bool flag = false;
	for(int i = 0; i < comp.size(); i++){
		if(comp[i].second == -1)
		{
			flag = true;
			st = comp[i].first;
		}
	}
	int cnt = 0;
	if(!flag)
	{
		for(int i = 0; i < comp.size(); i++)
		{
			a[comp[i].second] = comp.back().second;
			cnt++;
		}
	}
	else
	{
	for(int i = 0; i < comp.size(); i++)
	{
		if(comp[i].second == -1 && st != comp[i].first)
		{
			a[mass1[i]] = st;
			cnt++;
		}
		if(comp[i].second != -1)
		{
			cnt++;
			a[comp[i].second] = st;
		}
	}
	}
	cout << cnt << "\n";
	for(int i = 0; i < n; i++)
	{
		cout << a[i] + 1 << " ";
	}
	return 0;
}