#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 100000 + 10, M = 12;

int n, q;
ll is[M];
bool flag[2 * N];
ll mn[2 * N], tag[2 * N], val[2 * N];

inline int pos(int l, int r) { return (l + r) | (l != r); }

void push_down(int l, int r)
{
	int id = pos(l, r), mid = (l + r) / 2;
	int lch = pos(l, mid), rch = pos(mid + 1, r);
	if (flag[id])
	{
		flag[lch] = flag[rch] = true;
		mn[lch] = mn[rch] = mn[id];
		val[lch] = val[rch] = val[id];
		tag[id] = 0;
		flag[id] = false;
	}
	if (tag[id])
	{
		tag[lch] += tag[id];
		tag[rch] += tag[id];
		mn[lch] -= tag[id];
		mn[rch] -= tag[id];
		tag[id] = 0;
	}
}

void update(int l, int r)
{
	int id = pos(l, r), mid = (l + r) / 2;
	int lch = pos(l, mid), rch = pos(mid + 1, r);
	mn[id] = min(mn[lch], mn[rch]);
}

bool get(ll x, ll &a, ll &b)
{
	int i = 0;
	while(1)
	{
		if(x < is[i])
		{
			b = (a = is[i]) - x;
			return x == is[i - 1];
		}
		i ++;
	}
}

void build(int l, int r)
{
	int id = pos(l, r);
	if (l == r)
	{
		int x;
		scanf("%d", &x);
		get(x, val[id], mn[id]);
		flag[id] = true;
		return;
	}
	int mid = (l + r) / 2;
	build(l, mid);
	build(mid + 1, r);
	update(l, r);
}

ll query(int l, int r, int p)
{
	int id = pos(l, r);
	if (flag[id]) return val[id] - mn[id];
	int mid = (l + r) >> 1;
	push_down(l, r);
	ll res = (p <= mid ? query(l, mid, p) : query(mid + 1, r, p));
	update(l, r);
	return res;
}

void modify(int l, int r, int p, int q, ll a, ll b)
{
	int id = pos(l, r);
	if (p <= l && r <= q)
	{
		flag[id] = true;
		val[id] = a;
		mn[id] = b;
		tag[id] = 0;
		return;
	}
	push_down(l, r);
	int mid = (l + r) >> 1;
	if (p <= mid) modify(l, mid, p, q, a, b);
	if (q > mid) modify(mid + 1, r, p, q, a, b);
	update(l, r);
}

bool add(int l, int r, int p, int q, int x)
{
	int id = pos(l, r);
	if (p <= l && r <= q && (x < mn[id] || flag[id]))
	{
		tag[id] += x;
		mn[id] -= x;
		bool res = false;
		if (mn[id] <= 0) res = get(val[id] - mn[id], val[id], mn[id]);
		return res;
	}
	int mid = (l + r) / 2;
	push_down(l, r);
	bool res = false;
	if (p <= mid) res |= add(l, mid, p, q, x);
	if (q > mid) res |= add(mid + 1, r, p, q, x);
	update(l, r);
	return res;
}

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int main()
{
	n = read();
	q = read();
	is[0] = 1;
	for (int i = 1; i < M; i ++) is[i] = 42 * is[i - 1];
	build(1, n);
	while (q --)
	{
		int op;
		op = read();
		if (op == 1)
		{
			int x;
			x = read();
			printf("%lld\n", query(1, n, x));
		}
		else
		{
			int l, r, x;
			l = read();
			r = read();
			x = read();
			if (op == 2)
			{
				ll a, b;
				get(x, a, b);
				modify(1, n, l, r, a, b);
			}
			else while (add(1, n, l, r, x));
		}
	}
	return 0;
}