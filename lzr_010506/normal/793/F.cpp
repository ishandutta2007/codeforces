#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define pb push_back
const int N = 100000 + 10;

int n;

vector< pair<int, int> > q;
int ans[N];

vector<int> pool[N], mem[N];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int t[2 * N];

inline int pos(int l, int r) { return (l + r) | (l != r); }

void apply(int l, int r, int v)
{
	int id = pos(l, r);
	t[id] = min(t[id], v);
}

void release(int l, int r)
{
	int id = pos(l, r), mid = (l + r) >> 1;
	apply(l, mid, t[id]);
	apply(mid + 1, r, t[id]);
}

void update(int l, int r)
{
	int id = pos(l, r), mid = (l + r) >> 1;
	t[id] = max(t[pos(l, mid)], t[pos(mid + 1, r)]);
}

void modify(int l, int r, int p, int q, int v)
{
	if (p <= l && r <= q)
	{
		apply(l, r, v);
		return;
	}
	release(l, r);
	int mid = (l + r) >> 1;
	if (p <= mid) modify(l, mid, p, q, v);
	if (q > mid) modify(mid + 1, r, p, q, v);
	update(l, r);
}

int res;
bool flag;

void query(int l, int r, int p, int q)
{
	if (!flag) return;
	if (l < r) release(l, r);
	int mid = (l + r) >> 1;
	if (p <= l && r <= q)
	{
		int id = pos(l, r);
		if (t[id] <= q + 1) res = r + 1;
		else
		{
			if (l < r) query(l, mid, p, q), query(mid + 1, r, p, q);
			flag = false;
		}
	}
	else
	{
		if (p <= mid) query(l, mid, p, q);
		if (q > mid) query(mid + 1, r, p, q);
	}
	if (l < r) update(l, r);
}

int main()
{
	int m;
	n = read();
	m = read();
	while(m --)
	{
		int l, r;
		l = read();
		r = read();
		if (l < r) pool[l].push_back(r);
	}
	int tot;
	tot = read();
	q.resize(tot);
	for (int i = 0; i < tot; i ++)
	{
	    q[i].X = read();
	    q[i].Y = read();
		if (q[i].X < q[i].Y) mem[q[i].X].push_back(i);
		else ans[i] = q[i].X;
	}
	memset(t, 0x3f, sizeof t);
	for (int i = n; i > 0; i --)
	{
		for (int j = 0; j < pool[i].size(); j ++)
		{
			int k = pool[i][j];
			modify(1, n, i, k - 1, k);
		}
		for (int j = 0; j < mem[i].size(); j ++)
		{
			int k = mem[i][j];
			res = i, flag = true;
			query(1, n, i, q[k].Y - 1);
			ans[k] = res;
		}
	}
	for (int i = 0; i < q.size(); i ++)
		printf("%d\n", ans[i]);
	return 0;
}