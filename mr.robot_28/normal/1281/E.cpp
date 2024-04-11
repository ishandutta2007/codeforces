#include <bits/stdc++.h>
using namespace std;
#define int long long
vector <vector <pair <int, int> > > g;
vector <int> size1;
pair <int, int> dfs(int v, int pred)
{
	int ans = 0;
	int cnt = 0;
	size1[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i].first != pred)
		{
			pair <int, int> t = dfs(g[v][i].first, v);
			size1[v] += size1[g[v][i].first];
			if(t.second == 0)
			{
				ans += t.first;
			}
			else
			{
				ans += t.first + g[v][i].second;
				cnt++;
			}
		}
	}
	if(cnt % 2 == 1)
	{
		return {ans, 0};
	}
	else
	{
		return {ans, 1};
	}
}
int dfs1(int v, int k, int pred)
{
	int ans = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i].first != pred)
		{
			ans += dfs1(g[v][i].first, k, v);
			if(size1[g[v][i].first] > k)
			{
				ans += (2 * k - size1[g[v][i].first]) * g[v][i].second;
			}
			else
			{
				ans += size1[g[v][i].first] * g[v][i].second;
			}
		}
	}
	return ans;
}
signed main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int k;
		cin >> k;
		g.resize(2 * k);
		size1.resize(2 * k);
		for(int i = 0; i < 2 * k - 1; i++)
		{
			int a, b, t;
			cin >> a >> b >> t;
			g[a - 1].push_back({b - 1, t});
			g[b - 1].push_back({a - 1, t});
		}
		pair <int, int> v1 = dfs(0, -1);
		int v2 = dfs1(0, k, -1);
		for(int i = 0; i < 2 * k; i++)
		{
			if(g[i].size() != 0)
			{
				g[i].clear();
			}
		}
		cout << v1.first << " " << v2 << "\n";
	}
    return 0;
}