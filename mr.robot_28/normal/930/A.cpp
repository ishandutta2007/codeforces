#include<bits/stdc++.h>
 
using namespace std;
vector <int> h, cnt;
vector <vector <int> > g;
void dfs(int v)
{
	cnt[h[v]]++;
	for(int i = 0; i < g[v].size(); i++)
	{
		h[g[v][i]] = h[v] + 1;
		dfs(g[v][i]);
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	h.resize(n);
	cnt.resize(n);
	g.resize(n);
	for(int i = 1; i < n; i++)
	{
		int p;
		cin >> p;
		p--;
		g[p].push_back(i);
	}
	dfs(0);
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		ans += cnt[i] % 2;
	}
	cout << ans;
	return 0;
}