#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <int> > g;
vector <int> used, used1;
vector <int> par;
bool dfs(int v, int cnt)
{
	if(used[v] == cnt)
	{
		return 0;
	}
	used[v] = cnt;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(par[g[v][i]] == -1 && used[g[v][i]] != cnt)
		{
			par[v] = g[v][i];
			par[g[v][i]] = v;
			return 1;
		}
		if(par[g[v][i]] != -1 && dfs(par[g[v][i]], cnt))
		{
			par[v] = g[v][i];
			par[g[v][i]] = v;
			return 1;
		}
	}
	return 0;
}
signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	par.resize(m + 5000, -1);
	used.resize(m + 5000);
	g.resize(m + 5000);
	used1.resize(n, 1);
	vector <int> p(n), c(n);
	for(int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
		c[i]--;
	}
	int d;
	cin >> d;
	vector <int> query(d);
	for(int i = 0; i < d; i++)
	{
		cin >> query[i];
		query[i]--;
		used1[query[i]] = 0;
	}
	for(int i = 0; i < n; i++)
	{
		if(used1[i] == 0)
		{
			continue;
		}
		g[c[i] + 5000].push_back(p[i]);
		g[p[i]].push_back(c[i] + 5000);
	}
	vector <int> ans(d);
	int iter = 0;
	int cnt = 1;
	for(int i = d - 1; i >= 0; i--)
	{
		while(iter < 5000 && dfs(iter, cnt++))
		{
			iter++;
		}
		ans[i] = iter;
		g[c[query[i]] + 5000].push_back(p[query[i]]);
		g[p[query[i]]].push_back(c[query[i]] + 5000);
	}
	for(int i = 0; i < d; i++)
	{
		cout << ans[i] << "\n";
	}
	return 0;
}