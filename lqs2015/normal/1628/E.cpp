#include <bits/stdc++.h>
using namespace std;
int n, q, x, y, z, dep[333333], tp, l, r, lazy[2222222], wson[333333], pos[333333], head[333333], sub[333333], ct, beg[333333], cnt;
int val[333333], wval[333333], Log[333333], st[22][333333], pa[333333];
vector<pair<int, int> > g[333333];
struct nd
{
	int lc, mx;
	nd()
	{
		lc = 0;
		mx = -1;
	}
}cur, res, tree[2222222], ptree[2222222];
int get(int l, int r)
{
	if (l > r) return -1;
	int x = Log[r - l + 1];
	return max(st[x][l], st[x][r - (1 << x) + 1]);
}
void dfs(int i, int fa)
{
	dep[i] = dep[fa] + 1;
	sub[i] = 1; pa[i] = fa;
	for (int j = 0; j < g[i].size(); j++)
	{
		int to = g[i][j].first;
		if (to == fa) continue;
		dfs(to, i);
		sub[i] += sub[to];
		if (sub[to] > sub[wson[i]])
		{
			wson[i] = to;
			wval[i] = g[i][j].second;
		}
	}
}
void dft(int i, int fa, int vl)
{
	beg[i] = ++cnt;
	val[cnt] = vl;
	pos[i] = ct;
	if (wson[i]) dft(wson[i], i, wval[i]);
	for (int j = 0; j < g[i].size(); j++)
	{
		int to = g[i][j].first, vall = g[i][j].second;
		if (to == fa || to == wson[i]) continue;
		++ct; head[ct] = to;
		dft(to, i, vall); 
	}
}
void merge(nd a, nd b, nd &c)
{
	if (!a.lc)
	{
		c = b;
		return;
	}
	if (!b.lc)
	{
		c = a;
		return;
	}
	x = a.lc; y = b.lc; c.mx = max(a.mx, b.mx);
	while(pos[x] != pos[y])
	{
		if (dep[head[pos[x]]] > dep[head[pos[y]]])
		{
			c.mx = max(c.mx, get(beg[head[pos[x]]], beg[x]));
			x = pa[head[pos[x]]];
		}
		else
		{
			c.mx = max(c.mx, get(beg[head[pos[y]]], beg[y]));
			y = pa[head[pos[y]]];
		}
	}
	if (beg[x] > beg[y]) swap(x, y);
	c.lc = x; c.mx = max(c.mx, get(beg[x] + 1, beg[y]));
}
void build(int l, int r, int node)
{
	if (l == r)
	{
		ptree[node].lc = l;
		return;
	}
	int mid = (l + r) >> 1;
	build(l, mid, node << 1);
	build(mid + 1, r, (node << 1) | 1);
	merge(ptree[node << 1], ptree[(node << 1) | 1], ptree[node]);
}
void pushup(int node)
{
	merge(tree[node << 1], tree[(node << 1) | 1], tree[node]);
}
void push(int node, int x)
{
	lazy[node] = x;
	if (x == 1)
	{
		tree[node] = ptree[node];
	}
	else
	{
		tree[node].mx = -1;
		tree[node].lc = 0;
	}
}
void pushdown(int node)
{
	if (lazy[node])
	{
		push(node << 1, lazy[node]);
		push((node << 1) | 1, lazy[node]);
		lazy[node] = 0;
	}
}
void update1(int beg, int en, int l, int r, int node)
{
	if (l > en || r < beg) return;
	if (l >= beg && r <= en)
	{
		push(node, 1);
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(node);
	update1(beg, en, l, mid, node << 1);
	update1(beg, en, mid + 1, r, (node << 1) | 1);
	pushup(node);
}
void update2(int beg, int en, int l, int r, int node)
{
	if (l > en || r < beg) return;
	if (l >= beg && r <= en)
	{
		push(node, 2);
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(node);
	update2(beg, en, l, mid, node << 1);
	update2(beg, en, mid + 1, r, (node << 1) | 1);
	pushup(node);
}
int main()
{
//	freopen("cin.in", "r", stdin);
//	freopen("cout.out", "w", stdout);
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; i++)
	{
		scanf("%d%d%d", &x, &y, &z);
		g[x].push_back(make_pair(y, z));
		g[y].push_back(make_pair(x, z));
	}
	dfs(1, 0);
	ct = 1; head[1] = 1;
	dft(1, 0, 0);
	for (int i = 2; i <= n; i++) Log[i] = Log[i >> 1] + 1;
	for (int i = 1; i <= n; i++) st[0][i] = val[i];
	for (int i = 1; i <= 18; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			st[i][j] = st[i - 1][j];
			if (j + (1 << (i - 1)) <= n) st[i][j] = max(st[i][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}
	build(1, n, 1);
	while(q--)
	{
		scanf("%d", &tp);
		if (tp == 1)
		{
			scanf("%d%d", &l, &r);
			update1(l, r, 1, n, 1);
		}
		else if (tp == 2)
		{
			scanf("%d%d", &l, &r);
			update2(l, r, 1, n, 1);
		}
		else
		{
			scanf("%d", &x);
			cur.lc = x; cur.mx = -1;
			merge(cur, tree[1], res);
			printf("%d\n", res.mx);
		}
	}
	return 0;
}