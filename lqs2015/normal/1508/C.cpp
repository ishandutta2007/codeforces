#include <bits/stdc++.h>
using namespace std;
const int maxn = 650;
int n, m, x, y, z, dist[777][777], val[777], used[777], mn, id, xr, u[777][777];
int cnt, xx[222222], yy[222222], zz[222222], deg[222222], all, idx[222222], rr[222222];
vector<int> g[222222], nw;
queue<int> q;
long long ans;
long long calc(int n)
{
	memset(used, 0, sizeof(used));
	used[1] = 1;
	ans = 0;
	for (int i = 1; i <= n; i++) val[i] = dist[1][i];
	for (int i = 2; i <= n; i++)
	{
		mn = 2e9;
		for (int j = 1; j <= n; j++)
		{
			if (!used[j] && val[j] < mn)
			{
				mn = val[j];
				id = j;
			}
		}
		ans += mn;
		used[id] = 1;
		for (int j = 1; j <= n; j++)
		{
			if (!used[j]) val[j] = min(val[j], dist[id][j]);
		}
	}
	return ans;
}
long long solve1()
{
	for (int i = 1; i <= m; i++)
	{
		scanf("%d %d %d", &xx[i], &yy[i], &zz[i]);
		g[xx[i]].push_back(yy[i]);
		g[yy[i]].push_back(xx[i]);
		deg[xx[i]]++;
		deg[yy[i]]++;
	}
	for (int i = 1; i <= n; i++) sort(g[i].begin(), g[i].end());
	while(all < n)
	{
		cnt++;
		mn = 1e9;
		for (int i = 1; i <= n; i++)
		{
			if (!used[i] && deg[i] < mn)
			{
				mn = deg[i];
				id = i;
			} 
		}
		q.push(id); nw.clear(); used[id] = 1;
		for (int i = 0; i < g[id].size(); i++)
		{
			int to = g[id][i];
			if (!used[to])
			{
				nw.push_back(to);
				rr[to] = 1;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (!used[i] && !rr[i]) 
			{
				q.push(i);
				used[i] = 1;
			}
		}
		for (int i = 0; i < g[id].size(); i++)
		{
			int to = g[id][i];
			if (!used[to]) rr[to] = 0;
		}
		while(!q.empty())
		{
			x = q.front(); q.pop();
			all++; idx[x] = cnt;
			for (int i = 0; i < nw.size(); i++)
			{
				int to = nw[i];
				if (used[to]) continue;
				int vv = lower_bound(g[x].begin(), g[x].end(), to) - g[x].begin();
				if (vv == (int)g[x].size() || g[x][vv] != to) 
				{
					used[to] = 1;
					q.push(to);
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (used[i]) continue;
			deg[i] = 0; 
			for (int j = 0; j < g[i].size(); j++)
			{
				int to = g[i][j];
				if (!used[to]) deg[i]++;
			}
		}
	}
	for (int i = 1; i <= cnt; i++)
	{
		for (int j = 1; j <= cnt; j++)
		dist[i][j] = 2e9;
	}
	for (int i = 1; i <= m; i++)
	{
		if (idx[xx[i]] != idx[yy[i]])
		{
			dist[idx[xx[i]]][idx[yy[i]]] = min(dist[idx[xx[i]]][idx[yy[i]]], zz[i]);
			dist[idx[yy[i]]][idx[xx[i]]] = min(dist[idx[yy[i]]][idx[xx[i]]], zz[i]);
		}
	}
	return calc(cnt);
}
long long solve2()
{
	xr = 0;
	for (int i = 1; i <= m; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		xr ^= z;
		dist[x][y] = dist[y][x] = z;
		u[x][y] = u[y][x] = 1;
	}
	long long res = 1e18;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (!u[i][j])
			{
				dist[i][j] = dist[j][i] = xr;
				res = min(res, calc(n));
				dist[i][j] = dist[j][i] = 0;
			}
		}
	}
	return res;
}
int main()
{
	scanf("%d%d", &n, &m);
	if (1ll * n * (n - 1) / 2 - m >= n) 
	{
		printf("%lld\n", solve1());
	}
	else
	{
		printf("%lld\n", solve2());
	}
	return 0;
}