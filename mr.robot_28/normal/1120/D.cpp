#include<bits/stdc++.h>
 
using namespace std;
#define int long long
vector <vector <int> > dp;
vector <vector <int> > g;
vector <int> c;
vector <bool> ability;
vector <vector <vector <int> > > next1;
void dfs(int v, int pred = -1)
{
	vector <int> prefsum(g[v].size());
	vector <int> postsum(g[v].size());
	int cnt = 0;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred)
		{
			dfs(g[v][i], v);
			cnt++;
		}
	}
	if(cnt == 0)
	{
		dp[v][0] = 0;
		dp[v][1] = c[v];
		return;
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred)
		{
			prefsum[i] = dp[g[v][i]][1];
			if(i != 0)
			{
				prefsum[i] += prefsum[i - 1];
			}
		}
		else if(i != 0)
		{
			prefsum[i] += prefsum[i - 1];
		}
	}
	for(int i = g[v].size() - 1; i >= 0; i--)
	{
		if(g[v][i] != pred)
		{
			postsum[i] = dp[g[v][i]][1];
			if(i != g[v].size() - 1)
			{
				postsum[i] += postsum[i + 1];
			}
		}
		else if(i != g[v].size() - 1)
		{
			postsum[i] += postsum[i + 1];
		}
	}
	dp[v][1] = min(dp[v][1], postsum[0]);
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred)
		{
			int k1 = 0, k2 = 0;
			if(i != 0)
			{
				k1 = prefsum[i - 1];
			}
			if(i != g[v].size() - 1)
			{
				k2 = postsum[i + 1];
			}
			dp[v][1] = min(dp[v][1], k1 + k2 + c[v] + dp[g[v][i]][0]);
			dp[v][0] = min(dp[v][0], k1 + k2 + dp[g[v][i]][0]);
		}
	}
	if(postsum[0] == dp[v][1])
	{
		ability[v] = true;
	}
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred)
		{
			int k1 = 0, k2 = 0;
			if(i != 0)
			{
				k1 = prefsum[i - 1];
			}
			if(i != g[v].size() - 1)
			{
				k2 = postsum[i + 1];
			}
			if(k1 + k2 + c[v] + dp[g[v][i]][0] == dp[v][1])
			{
				next1[v][1].push_back(g[v][i]);
			}
			if(k1 + k2 + dp[g[v][i]][0] == dp[v][0])
			{
   				next1[v][0].push_back(g[v][i]);
			}
		}
	}
}
set <int> ans;
vector <vector <bool> > used;
void dfs1(int v, int type, int pred = -1)
{
	if(used[v][type])
	{
		return;
	}
	int cnt =0;
	for(int i =0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred)
		{
			cnt++;
		}
	}
	used[v][type] = true;
	if(type == 1 && (next1[v][type].size() > 0 || cnt == 0))
	{
		ans.insert(v);
	}
	if(type == 1 && ability[v])
	{
		for(int i = 0; i < g[v].size(); i++)
		{
			if(pred != g[v][i])
			{
				dfs1(g[v][i], 1, v);
			}
		}
	}
	if(next1[v][type].size() >= 2)
	{
		for(int i = 0; i < g[v].size(); i++)
		{
			if(g[v][i] != pred)
			{
				dfs1(g[v][i], 1, v);
			}
		}
		for(int i = 0; i < next1[v][type].size(); i++)
		{
			dfs1(next1[v][type][i], 0, v);
		}
	}
	else if(next1[v][type].size() == 1)
	{
		for(int i = 0; i < next1[v][type].size(); i++)
		{
			dfs1(next1[v][type][i], 0, v);
		}
		for(int i = 0; i < g[v].size(); i++)
		{
			if(g[v][i] != pred && !used[g[v][i]][0])
			{
				dfs1(g[v][i], 1, v);
			}
		}
	}
	else
	{
		for(int i =0; i < g[v].size(); i++)
		{
			if(g[v][i] != pred)
			{
				dfs1(g[v][i], 1, v);
			}
		}
	}
}
signed main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int n;
	cin >> n;
	ability.resize(n);
	used.resize(n, vector <bool> (2, false));
	dp.resize(n, vector <int> (2, 1e18));
	c.resize(n);
	g.resize(n);
	next1.resize(n, vector <vector <int> > (2));
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	for(int i = 0; i < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	dfs(0);
	cout << dp[0][1] << " ";
	dfs1(0, 1, -1);
	cout << ans.size() << "\n";
	set <int> :: iterator it;
	for(it = ans.begin(); it != ans.end(); it++)
	{
		cout << *it + 1<< " ";
	}
	return 0;
}