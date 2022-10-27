#include <bits/stdc++.h>
using namespace std;
vector <vector <int> > g, pred, rmq, rmq1;
vector <int> h, used;
void dfs(int v, int p = -1)
{
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(to != p && h[to] == -1)
		{
			h[to] = h[v] + 1;
			pred[0][to] = v;
			rmq1[0][to] = to;
			rmq[0][to] = to;
			dfs(to, v);
		}
	}
}
vector <int> minright;
void dfs1(int v, int p = -1)
{
	used[v] = 1;
	for(int i = 0; i < g[v].size(); i++)
	{
		int to = g[v][i];
		if(h[to] < h[v] && to != p)
		{
			int v1 = v;
			int a = 0, b = 1e9;
			for(int j = pred.size() - 1; j >= 0; j--)
			{
				if(pred[j][v1] != -1 && h[pred[j][v1]] >= h[to])
				{
					b = min(b, rmq[j][v1]);
					a = max(a, rmq1[j][v1]);
					v1 = pred[j][v1];
				}
			}
			a = max(a, to);
			b = min(b, to);
			if(a < b)
			{
				exit(0);
			}
			minright[b] = min(minright[b], a);
		}
		if(used[to] == 0)
		{
			dfs1(to, v);
		}
	}
}
vector <long long> treesum, treemin, treemax;
void build(int v, int l, int r)
{
	if(l == r)
	{
		treesum[v] = minright[l];
		treemin[v] = minright[l];
		treemax[v] = minright[l];
	}
	else
	{
		build(v * 2, l, (r + l) / 2);
		build(v * 2 + 1, (r + l) / 2 + 1, r);
		treesum[v] = treesum[v * 2] + treesum[v * 2 + 1];
		treemin[v] = min(treemin[v * 2], treemin[v * 2 + 1]);
		treemax[v] = max(treemax[v * 2], treemax[v * 2 + 1]);
	}
}
long long ans(int v, int l, int r, int al, int ar, int val)
{
	if(l >= al && r <= ar)
	{
		if(treemax[v] <= val)
		{
			return treesum[v];
		}
		else if(treemin[v] >= val)
		{
			return 1LL * (r - l + 1) * val;
		}
		else
		{
			return ans(v * 2,l, (r + l) / 2, al, ar, val) + ans(v * 2 + 1, (r + l) / 2 + 1, r, al, ar, val);
		}
	}
	else if(l <= ar && r >= al)
	{
		return ans(v * 2, l, (r + l) / 2, al, ar, val) + ans(v * 2 + 1, (r + l) /2 + 1, r, al, ar, val);
	}
	else
	{
		return 0;
	}
}
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	g.resize(n);
	minright.resize(n, 1e9);
	used.resize(n, 0);
	h.resize(n, -1);
	int t = log2(n) + 1;
	pred.resize(t, vector <int> (n));
	rmq.resize(t, vector <int> (n, 1e9));
	rmq1.resize(t, vector <int> (n, 0));
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 0; i < n; i++)
	{
		if(h[i] == -1)
		{
			pred[0][i] = -1;
			rmq1[0][i] = -1;
			rmq[0][i] = -1;
			h[i] = 0;
			dfs(i);
		}
	}
	for(int i = 1; i < t; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(pred[i - 1][j] == -1)
			{
				pred[i][j] = pred[i - 1][j];
				rmq[i][j] = rmq[i - 1][j];
				rmq1[i][j] = rmq1[i - 1][j];
				continue;
			}
			pred[i][j] = pred[i - 1][pred[i - 1][j]];
			rmq1[i][j] = max(rmq1[i - 1][j], rmq1[i - 1][pred[i - 1][j]]);
			rmq[i][j] = min(rmq[i - 1][j], rmq[i - 1][pred[i - 1][j]]);
		}
	}
	for(int i = 0; i < n; i++)
	{
		if(used[i] == 0)
		{
			dfs1(i, -1);
		}
	}
	int right = n;
	for(int i = n - 1; i >= 0; i--)
	{
		right = min(right, minright[i]);
		minright[i] = right;
	}
	treesum.resize(4 * n);
	treemax.resize(4 * n);
	treemin.resize(4 * n);
	build(1, 0, n - 1);
	int q;
	cin >> q;
	while(q--)
	{
		int l, r;
		cin >> l >> r;
		l--;
		r--;
		long long sum = ans(1, 0, n - 1, l, r, r + 1);
		sum -= 1LL * (l + r) * (r - l + 1) / 2;
		cout << sum << "\n";
	}
    return 0;
}