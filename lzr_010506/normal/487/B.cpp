#include <bits/stdc++.h>
#define N 100010
#define inf 0x3f3f3f3f * 2
using namespace std;
struct Tree1
{
	int l, r, min, max;
}t1[4 * N];
int n, s, l, a[N], maxto[N];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

void Push_up1(int rt)
{
	t1[rt].min = min(t1[rt << 1].min, t1[rt << 1 | 1].min);
	t1[rt].max = max(t1[rt << 1].max, t1[rt << 1 | 1].max);
}

void Build1(int l, int r, int rt)
{
	t1[rt].l = l;
	t1[rt].r = r;
	if(l == r)
	{
		t1[rt].min = t1[rt].max = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	Build1(l, mid, rt << 1);
	Build1(mid + 1, r, rt << 1 | 1);
	Push_up1(rt);
}

int Query1(int rt, int l, int r)
{
	if(l <= t1[rt].l && t1[rt].r <= r) return t1[rt].min;
	int mid = (t1[rt].l + t1[rt].r) >> 1;
	int res = 0x7f7f7f7f;
	if(l <= mid) res = min(res, Query1(rt << 1, l, r));
	if(r > mid) res = min(res, Query1(rt << 1 | 1, l, r));
	return res;
}

int Query2(int rt, int l, int r)
{
	if(l <= t1[rt].l && t1[rt].r <= r) return t1[rt].max;
	int mid = (t1[rt].l + t1[rt].r) >> 1;
	int res = -0x7f7f7f7f;
	if(l <= mid) res = max(res, Query2(rt << 1, l, r));
	if(r > mid) res = max(res, Query2(rt << 1 | 1, l, r));
	return res;
}

int maxsubmin(int x,int y)
{
	return Query2(1, x, y) - Query1(1, x, y);
}

struct Tree2
{
	int l, r, dp, tag;
}t[4 * N];

void Build(int l, int r, int rt)
{
	t[rt].l = l;
	t[rt].r = r;
	t[rt].tag = inf;
	if(l == r)
	{
		if(l == 1) t[rt].dp = 0;
		else t[rt].dp = inf;
		return;
	}
	int mid = (l + r) >> 1;
	Build(l, mid, rt << 1);
	Build(mid + 1, r, rt << 1 | 1);
	t[rt].dp = min(t[rt << 1].dp, t[rt << 1 | 1].dp);
}

void push_down(int rt)
{
	if(t[rt].tag == inf) return;
	t[rt].dp = min(t[rt].dp, t[rt].tag);
	if(t[rt].l == t[rt].r)
	{
		t[rt].tag = inf;
		return;
	}
	t[rt << 1].tag = min(t[rt << 1].tag, t[rt].tag);
	t[rt << 1 | 1].tag = min(t[rt << 1 | 1].tag, t[rt].tag);
	t[rt].tag = inf;
}

void Update(int rt,int l,int r,int val)
{
	if(t[rt].l == l && t[rt].r == r)
	{
		t[rt].tag = min(t[rt].tag, val);
		push_down(rt);
		return;
	}
	push_down(rt);
	int mid = (t[rt].l + t[rt].r) >> 1;
	if(r <= mid) Update(rt << 1, l, r, val);
	else if(mid < l) Update(rt << 1 | 1, l, r, val);
	else
	{
		Update(rt << 1,l, mid, val);
		Update(rt << 1 | 1, mid + 1, r, val);
	}
}

int query(int rt,int l,int r)
{
	if(t[rt].l == l && t[rt].r == r)
	{
		push_down(rt);
		return t[rt].dp;
	}
	push_down(rt);
	int mid = (t[rt].l + t[rt].r) >> 1;
	if(r <= mid) return query(rt << 1, l, r);
	else if(mid < l) return query(rt << 1 | 1, l, r);
	else return min(query(rt << 1, l, mid), query(rt << 1 | 1, mid + 1, r));
}

int main()
{
	n = read();
	s = read();
	l = read();
	if(n < l) {cout << -1; return 0;}
	for(int i = 1; i <= n; i ++)
		a[i] = read();
	Build1(1, n, 1);
	/*for(int i = 1; i <= 20; i ++)
        cout << t1[i].min << " " << t1[i].max << endl;
	while(1)
	{
		int x, y;
		x = read();
		y = read();
		cout << Query1(1, x, y) << " ";
		cout << Query2(1, x, y) << endl;
	}*/
	int to = 1;
	for(int i = 1; i <= n; i ++)
	{
		to = max(to, i);
		while(1)
		{
			if(to == n)
			{
				maxto[i] = to;
				break;
			}
			int t = maxsubmin(i, to + 1);
			if(t <= s) to ++;
			else
			{
				maxto[i] = to;
				break;
			}
		}
	}

	Build(1, n + 1, 1);
	for(int i = 1; i <= n; i ++)
	{
		if(n - i + 1 < l) continue;
		int now = query(1, i, i);
		if(now == inf) continue;
		int to = i + l - 1;
		if(maxto[i] < to) continue;
		Update(1, to + 1, maxto[i] + 1, now + 1);
	}
	int ans = query(1, n + 1, n + 1);
	if(ans == inf) ans = -1;
	printf("%d\n", ans);

	return 0;
}