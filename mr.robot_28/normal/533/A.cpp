#include <bits/stdc++.h>
using namespace std;
vector <int> h;
vector <vector <int> > g;
int h0, v0;
vector <int> val;
int it = 0;
vector <bool> used;
vector <int> treesum,par;
vector <int> treemin;
void update(int v, int l, int r, int ind, int d)
{
	if(l == r)
	{
		treesum[v] += d;
		treemin[v] += d;
		return;
	}
	if(ind <= (r + l) / 2)
	{
		update(v * 2, l, (r + l) / 2, ind, d);
	}
	else
	{
		update(v * 2 + 1, (r + l) / 2 + 1, r, ind, d);
	}
	treesum[v] = treesum[v * 2] + treesum[v * 2 + 1];
	treemin[v] = min(treemin[v * 2], treesum[v * 2] + treemin[v * 2 + 1]);
}
int query(int v, int l, int r, int x)
{
	if(l == r)
	{
		return l;
	}
	if(treemin[v * 2] + x < 0)
	{
		return query(v * 2, l, (r + l) / 2, x);
	}
	return query(v * 2 + 1, (r + l) / 2 + 1, r, treesum[v * 2] + x);
}
void dfs1(int v, int p = -1)
{
	for(int i = 0; i < g[v].size();  i++)
	{
		int to = g[v][i];
		if(to != p)
		{
			val[to] = min(val[v], h[v]);
			par[to] = v;
			dfs1(to, v);
		}
	}
}
vector <int> uniq;
int m;
int mass[1000000];
void dfs2(int v)
{
	mass[++it] = v;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != par[v])
		{
			if(val[to] < h[to])
			{
				dfs2(to);
			}
		}
	}
}
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k;
	cin >> n;
	used.resize(n);
	g.resize(n);
	h.resize(n);
	par.resize(n, -1);
	val.resize(n);
	for(int i = 0; i < n; i++)
	{
		cin >> h[i];
		uniq.push_back(h[i]);
	}
	for(int i = 0; i < n - 1; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	cin >> k;
	vector <int>s(k);
	for(int i = 0; i < k; i++)
	{
		cin >> s[i];
		uniq.push_back(s[i]);
	}
	sort(uniq.begin(), uniq.end());
	m = unique(uniq.begin(), uniq.end()) - uniq.begin();
	treesum.resize(4 * m, 0);
	treemin.resize(4 * m, 0);
	for(int i = 0; i < n; i++)
	{
		h[i] = lower_bound(uniq.begin(), uniq.begin() + m, h[i]) - uniq.begin();
	}
	for(int i = 0; i < k; i++)
	{
		s[i] = lower_bound(uniq.begin(), uniq.begin() + m, s[i]) - uniq.begin();
	}
	val[0] = 1e9;
	dfs1(0);
	for(int i = 0; i < n; i++)
	{
		update(1, 0, m - 1, m - min(val[i], h[i]) - 1, 1);
	}
	for(int i = 0; i < k; i++)
	{
		update(1, 0, m - 1, m - s[i] - 1, -1);
	}
	if(treemin[1] >= 0)
	{
		cout << 0;
		return 0;
	}
	int ans = 1e9;
	vector <int> b(n);
	for(int i = 0; i< n; i++)
	{
		if(h[i] < val[i])
		{
			it = 0;
			dfs2(i);
			update(1, 0, m - 1, m - h[i] - 1, -it);
			int t = m - query(1, 0, m - 1, 0) - 1;
			if(t <= val[i])
			{
				b[i] = t;
				update(1, 0, m - 1, m - t - 1, 1);
				for(int j = 2; j <= it; j++)
				{
					b[mass[j]] = min(h[mass[j]], b[par[mass[j]]]);
					update(1, 0, m - 1, m - b[mass[j]] - 1, 1);
				}
				if(treemin[1] >= 0)
				{
					ans = min(ans, uniq[t] - uniq[h[i]]);
				}
				for(int j = 1; j <= it; j++)
				{
					update(1, 0, m - 1, m - b[mass[j]] - 1, -1);
				}
			}
			update(1, 0, m - 1, m - h[i] - 1, it);
		}
	}
	if(ans == 1e9)
	{
		cout << -1;
	}
	else
	{
		cout << ans;
	}
	return 0;
}