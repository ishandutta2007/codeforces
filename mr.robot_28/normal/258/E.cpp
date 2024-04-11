#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
vector <vector <int> > g;
vector <vector <pair <int, int> > > upd;
vector <int> tin, tout;
vector <int> tmin, cntmin, u;
vector <int> ans;
int n;
void build(int v, int l, int r)
{
	if(l == r)
	{
		cntmin[v] = 1;
		tmin[v] = 0;
	}
	else
	{
		build(v * 2, l, (r + l) / 2);
		build(v * 2 + 1, (r + l) / 2 + 1, r);
		tmin[v] = 0;
		cntmin[v] = cntmin[v * 2] + cntmin[v * 2 + 1];
	}
}
void update(int v, int l, int r, int al, int ar, int up)
{
	if(al <= l && r <= ar)
	{
		tmin[v] += up;
		u[v] += up;
	}
	else if(l <= ar && r >= al)
	{
		u[v * 2] += u[v];
		tmin[v * 2] += u[v];
		tmin[v * 2 + 1] += u[v];
		u[v * 2 + 1] += u[v];
		u[v] = 0;
		update(v * 2, l, (r + l) / 2 , al, ar, up);
		update(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, up);
		tmin[v] = min(tmin[v * 2], tmin[v * 2 + 1]);
		if(tmin[v * 2] == tmin[v * 2 + 1])
		{
			cntmin[v] = cntmin[v * 2] + cntmin[v * 2 + 1];
		}
		else if(tmin[v * 2] < tmin[v * 2 + 1])
		{
			cntmin[v] = cntmin[v * 2];
		}
		else
		{
			cntmin[v] = cntmin[v * 2 + 1];
		}
	}
}
int timer = 0;
void dfs(int v, int pred = -1)
{
	tin[v] = timer++;
	for(int i = 0; i < g[v].size(); i++)
	{
		if(g[v][i] != pred){
			dfs(g[v][i], v);
		}
	}
	tout[v] = timer++;
}
void dfs1(int v, int pred = -1, bool flag = false)
{
	for(int i = 0; i < upd[v].size(); i++)
	{
		update(1, 0, n - 1, upd[v][i].first, upd[v][i].second, 1);
	}
	if(upd[v].size() != 0)
	{
		flag = true;
	}
	if(tmin[1] == 0)
	{
	ans[v] = n - cntmin[1];
	if(flag)
	{
		ans[v]--;
	}
	}
	else
	{
		ans[v] = n - 1;
	}
	for(int i = 0; i < g[v].size(); ++i)
	{
		if(g[v][i] != pred)
		{
			dfs1(g[v][i], v, flag);
		}
	}
	for(int i = 0; i < upd[v].size(); i++)
	{
		update(1, 0, n - 1, upd[v][i].first, upd[v][i].second, -1);
	}
}
signed main()
{
	int m;
	cin >> n >> m;
	g.resize(n);
	tin.resize(n);
	tout.resize(n);
	u.resize(4 * n);
	tmin.resize(4 * n);
	ans.resize(n);
	cntmin.resize(4 * n);
	upd.resize(n);
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
	build(1, 0, n - 1);
	vector <pair <int, int> > sorted;
	for(int i = 0; i < n; i++)
	{
		sorted.push_back({tin[i], i});
	}
	sort(sorted.begin(), sorted.end());
	for(int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		int l = 0, r = n;
		while(r - l > 1)
		{
			int midd = (r + l) / 2;
			if(sorted[midd].first > tin[x])
			{
				r = midd;
			}
			else
			{
				l = midd;
			}
		}
		int l1 = l, r1 = n;
		while(r1 - l1 > 1)
		{
			int midd = (r1 + l1) / 2;
			if(tout[sorted[midd].second] > tout[x])
			{
				r1 = midd;
			}
			else
			{
				l1 = midd;
			}
		}
		int l2 = 0, r2 = n;
		while(r2 - l2 > 1)
		{
			int midd = (r2 + l2) / 2;
			if(sorted[midd].first > tin[y]){
				r2 = midd;
			}
			else
			{
				l2 = midd;
			}
		}
		int l3 = l2, r3 = n;
		while(r3 - l3 > 1)
		{
			int midd = (r3 + l3) / 2;
			if(tout[sorted[midd].second] > tout[y])
			{
				r3 = midd;
			}
			else
			{
				l3 = midd;
			}
		}
		upd[x].push_back({l, l1});
		upd[x].push_back({l2, l3});
		upd[y].push_back({l, l1});
		upd[y].push_back({l2, l3});
	}
	dfs1(0);
	for(int i = 0; i < n; i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}