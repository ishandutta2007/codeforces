#include<bits/stdc++.h>
using namespace std;
#define int long long
int n, m, k;
vector <vector <int> > g, g2;
vector <vector <pair <int, int> > > g1;
vector <int> tin, fup;
vector <int> cnt, cnt1, c, c1;
set <pair <int, int> > s;
vector <bool> used;
int timer = 0;
int max(int a, int b)
{
	if(a > b)
	{
		return a;
	}
	return b;
}
void dfs(int v, int p= -1)
{
	tin[v] = timer++;
	fup[v] = tin[v];
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to == p){
			continue;
		}
		if(!used[to])
		{
			dfs(to, v);
			fup[v] = min(fup[v], fup[to]);
			if(fup[to] > tin[v])
			{
				s.insert({v, to});
				s.insert({to, v});
			}
		}
		else
		{
			fup[v] = min(fup[v], tin[to]);
		}
	}
}
vector <int> _sz;
vector <vector <int> > dp;
vector <int> dp_up;
void dfs1(int v, int p = -1)
{
	_sz[v] = cnt1[v];
	if(g1[v].size() == 0 || g1[v].size() == 1 && p != -1)
	{
		dp[v][0] = dp[v][1] = c1[v];
		return;
	}
	for(int i = 0; i < g1[v].size(); i++)
	{
		int to = g1[v][i].first;
		if(to != p)
		{
			dfs1(to, v);
			_sz[v] += _sz[to];
			if(_sz[to] == 0)
			{
				dp[v][1] += dp[to][1];
				dp[v][0] += dp[to][0];
			}
			else if(_sz[to] == k)
			{
				dp[v][1] += dp[to][1];
			}
			else
			{
				dp[v][1] += max(dp[to][1] - g1[v][i].second, 0);
			}
		}
	}
	dp[v][0] += c1[v];
	dp[v][1] += c1[v];
}
vector <int> ans;
void dfs2(int v, int p = -1, int p1 = -1)
{
	int sum = 0;
	if(p != -1)
	{
		if(_sz[v] != k && _sz[v] != 0)
		{
			sum += max(0, dp_up[p] - p1);
		}
		else
		{
			sum += dp_up[p];
		}
	}
	for(int i = 0; i < g1[v].size(); i++)
	{
		int to = g1[v][i].first;
		if(to != p)
		{
			if(_sz[to] == 0 || _sz[to] == k)
			{
				sum += dp[to][1];
			}
			else
			{
				sum += max(dp[to][1] - g1[v][i].second, 0);
			}
		}
	}
	ans[v] = sum + c1[v];
	for(int i = 0; i < g1[v].size(); i++)
	{
		int to = g1[v][i].first;
		if(to != p)
		{
			dp_up[v] = sum + c1[v];
			if(_sz[to] == 0 || _sz[to] == k)
			{
				dp_up[v] -= dp[to][1];
			}
			else
			{
				dp_up[v] -= max(dp[to][1] - g1[v][i].second, 0);
			}
			dfs2(to, v, g1[v][i].second);
		}
	}
}
signed main() {
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	cin >> n >> m >> k;
	g.resize(n);
	g1.resize(n);
	g2.resize(n);
	used.resize(n);
	_sz.resize(n);
	ans.resize(n);
	dp.resize(n, vector <int> (2, 0));
	tin.resize(n);
	fup.resize(n);
	cnt.resize(n);
	cnt1.resize(n);
	c.resize(n);
	c1.resize(n);
	dp_up.resize(n);
	for(int i = 0; i < k; i++)
	{
		int v;
		cin >> v;
		v--;
		cnt[v] = 1;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	vector <int> w(m);
	vector <pair <int, int> > mass(m);
	for(int i = 0; i < m; i++)
	{
		cin >> w[i];
	}
	for(int i = 0; i < m; i++)
	{
		cin >> mass[i].first >> mass[i].second;
		mass[i].first--;
		mass[i].second--;
		g[mass[i].first].push_back(mass[i].second);
		g[mass[i].second].push_back(mass[i].first);
	}
	dfs(0, -1);
	for(int i = 0; i < m; i++)
	{
		if(s.find({mass[i].first, mass[i].second}) == s.end())
		{
			g2[mass[i].first].push_back(mass[i].second);
			g2[mass[i].second].push_back(mass[i].first);
		}
	}
	for(int i = 0; i < n; i++)
	{
		used[i] = 0;
	}
	vector <int> colored(n);
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			queue <int> q;
			q.push(i);
			used[i] = 1;
			while(q.size() != 0){
				int v = q.front();
				q.pop();
				colored[v] = i;
				cnt1[i] += cnt[v];
				c1[i] += c[v];
				for(int j = 0; j < g2[v].size(); j++)
				{
					int to = g2[v][j];
					if(!used[to])
					{
						used[to] = 1;
						q.push(to);
					}
				}
			}
		}
	}
	for(int i = 0; i < m; i++)
	{
		if(s.find({mass[i].first, mass[i].second}) != s.end())
		{
			int a = colored[mass[i].first];
			int b = colored[mass[i].second];
			g1[a].push_back({b, w[i]});
			g1[b].push_back({a, w[i]});
		}
	}
	dfs1(colored[0]);
	dfs2(colored[0]);
	for(int i = 0; i < n; i++)
	{
		ans[i] = ans[colored[i]];
	}
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
  	return 0;
}