
#include <bits/stdc++.h>
 
using namespace std;
#define int long long
vector <vector <int> > g;
vector <set <int> > isbridge;
vector <int> cnt;
vector <int> tin, fup;
vector <int> dp1;
vector <bool> used;
vector <bool> e;
vector <int> A;
vector <int> dp;
int timer = 0;
void dfs(int v, int p = -1)
{
	used[v] = true;
	tin[v] = fup[v] = timer++;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to == p)
		{
			continue;
		}
		if(used[to])
		{
			fup[v] = min(fup[v], tin[to]);
		}
		else
		{
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if(fup[to] > tin[v])
			{
				isbridge[v].insert(g[v][i]);
				isbridge[g[v][i]].insert(v);
			}
		}
	}
}
void dfs1(int v)
{
	int sum = 0, Max = 0;
	queue <int> q;
	q.push(v);
	used[v] = true;
	while(q.size() != 0)
	{
		int r = q.front();
		q.pop();
		sum += A[r];
		cnt[v]++;
		for(int i = 0; i < g[r].size(); i++)
		{
			if(!used[g[r][i]] && isbridge[r].find(g[r][i]) != isbridge[r].end())
			{
				dfs1(g[r][i]);
				if(!e[g[r][i]])
				{
					dp1[v] = max(dp1[v], dp1[g[r][i]] + A[g[r][i]]);
				}
				else
				{
					e[v] = true;
					sum += dp[g[r][i]];
					dp1[v] = max(dp1[v], dp1[g[r][i]]);
				}
			}
			else if(!used[g[r][i]])
			{
				q.push(g[r][i]);
			}
			used[g[r][i]] = true;
		}
	}
	if(cnt[v] > 1)
	{
		e[v] = true;
	}
	dp[v] = sum + Max;
}
main() {
	int n, m;
	cin >> n >> m;
	g.resize(n);
	isbridge.resize(n);
	tin.resize(n);
	e.resize(n);
	dp.resize(n);
	cnt.resize(n);
	fup.resize(n);
	A.resize(n);
	dp1.resize(n, 0);
	used.resize(n, false);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		g[a - 1].push_back(b - 1);
		g[b - 1].push_back(a - 1);
	}
	int start;
	cin >> start;
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			dfs(i);
		}
	}
	for(int i = 0; i < n; i++)
	{
		used[i] = false;
	}
	dfs1(start - 1);
	cout << dp[start - 1] + dp1[start - 1];
    return 0;
}