#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
#define int long long
const int  CONST = 998244353;
vector <vector <int> > g;
int k;
int ans = 0;
int dfs(int v, int pred = -1)
{
	vector <int> d;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred)
		{
			d.push_back(dfs(g[v][i], v) + 1);
		}
	}
	if(d.size() == 0)
	{
		return 0;
	}
	sort(d.begin(), d.end());
	while(d.size() > 1)
	{
		if(d[d.size() - 1] + d[d.size() - 2] <= k)
		{
			break;
		}
		ans++;
		d.pop_back();
	}
	return d.back();
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n >> k;
	g.resize(n);
	for(int i = 0; i < n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		u--;
		v--;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i = 0; i < n; i++)
	{
		if(g[i].size() > 1)
		{
			dfs(i);
			break;
		}
	}
	cout << ans + 1;
	return 0;
}