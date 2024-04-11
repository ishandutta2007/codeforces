#include <bits/stdc++.h>
using namespace std;
vector <int> col, c;
vector <long long> weight, ans;
vector <pair <pair <int, int>, int> > vec;
vector <vector <int> > g;
vector <int> pred;
vector <int> cycle;
vector <bool> used;
void dfs(int v, int cl, int p = -1)
{
	col[v] = cl;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			if(col[to] == -1)
			{
				pred[to] = v;
				dfs(to, 1 - cl, v);
			}
			else if(col[to] == cl && cycle.size() == 0)
			{
				int v1 = v;
				while(v1 != to)
				{
					cycle.push_back(v1);
					v1 = pred[v1];
				}
				cycle.push_back(to);
			}
		}
	}
}
void dfs1(int v, int p = -1)
{
	used[v] = true;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(!used[to])
		{
			dfs1(to, v);
		}
	}
	if(p != -1)
	{
		long long a = c[v] - weight[v];
		weight[p] += a;
		int ind = lower_bound(vec.begin(), vec.end(), make_pair(make_pair(v, p), 0)) - vec.begin();
		ind = vec[ind].second;
		ans[ind] += a;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	weight.resize(n);
	ans.resize(m);
	c.resize(n);
	used.resize(n);
	pred.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> c[i];
	}
	g.resize(n);
	col.resize(n, -1);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
		vec.push_back({{a, b}, i});
		vec.push_back({{b, a}, i});
	}
	sort(vec.begin(), vec.end());
	dfs(0, 0);
	if(cycle.size() == 0)
	{
		dfs1(0);
		if(weight[0] != c[0])
		{
			cout << "NO";
			return 0;
		}
	}
	else
	{
		dfs1(cycle[0]);
		long long q = (c[cycle[0]] - weight[cycle[0]]) / 2;
		int right = 1, left = cycle.size() - 1;
		int sign = 1;
		while(right - 1 <= left)
		{
			if(right - 1 == left)
			{
				int ind = lower_bound(vec.begin(), vec.end(), make_pair(make_pair(cycle[right], cycle[left]), 0)) - vec.begin();
				ind = vec[ind].second;
				ans[ind] += sign * q;
			}
			else
			{
				int ind1 = lower_bound(vec.begin(), vec.end(), make_pair(make_pair(cycle[right - 1], cycle[right]), 0)) - vec.begin();
				ind1 = vec[ind1].second;
				int ind2 = lower_bound(vec.begin(), vec.end(), make_pair(make_pair(cycle[left], cycle[(left + 1) % cycle.size()]), 0)) - vec.begin();
				ind2 = vec[ind2].second;
				ans[ind1] += sign * q;
				ans[ind2] += sign * q;
			}
			right++;
			left--;
			sign = -sign;
		}
	}
	cout << "YES\n";
	for(int i = 0; i < m; i++)
	{
		cout << ans[i] << "\n";
	}
    return 0;
}