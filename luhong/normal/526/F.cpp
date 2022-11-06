#include <cstdio>
#include <iostream>
#define MN 301000

int x[MN], y[MN], n;
int q1[MN], h1, t1, a[MN];
int q2[MN], h2, t2, b[MN];
int v[MN];
long long ans = 0;
struct xxx{
	int Min, cnt;
}t[MN * 4];
int lazy[MN * 4];

xxx operator + (xxx a, xxx b)
{
	xxx c; c.cnt = 0;
	c.Min = std::min(a.Min, b.Min);
	if(c.Min == a.Min) c.cnt += a.cnt;
	if(c.Min == b.Min) c.cnt += b.cnt;
	return c;
}

void add(int x, int v) {lazy[x] += v; t[x].Min += v;}

void pushdown(int x)
{
	if(lazy[x])
	{
		add(x << 1, lazy[x]);
		add(x << 1 | 1, lazy[x]);
		lazy[x] = 0;
	}
}

void build(int x, int l, int r)
{
	lazy[x] = 0;
	if(l == r) {t[x].Min = v[l], t[x].cnt = 1; return;}
	int mid = l + r >> 1;
	build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
	t[x] = t[x << 1] + t[x << 1 | 1];
}

void modify(int x, int l, int r, int L, int R, int v)
{
	if(l == L && r == R) {add(x, v); return;}
	pushdown(x); int mid = l + r >> 1;
	if(R <= mid) modify(x << 1, l, mid, L, R, v);
	else if(L > mid) modify(x << 1 | 1, mid + 1, r, L, R, v);
	else modify(x << 1, l, mid, L, mid, v), modify(x << 1 | 1, mid + 1, r, mid + 1, R, v);
	t[x] = t[x << 1] + t[x << 1 | 1]; 
}

void solve(int l, int r)
{
	if(l > r) return;
	int mid = l + r >> 1;
	h1 = 1; t1 = 0; h2 = 1; t2 = 0;
	int p = x[mid], tot = 0;
	while(p <= n)
	{
		if(y[p] < l || y[p] > r) break;
		++tot; 
		if(h1 > t1 || y[p] > a[t1]) q1[++t1] = tot, a[t1] = y[p];
		if(h2 > t2 || y[p] < b[t2]) q2[++t2] = tot, b[t2] = y[p];
		v[tot] = a[t1] - b[t2] - tot + 2;
		p++;
	}
	q1[t1 + 1] = tot + 1; q2[t2 + 1] = tot + 1;
	build(1, 1, tot);
	p = x[mid];
	while(p >= 1)
	{
		if(y[p] < l || y[p] > r) break;
		if(y[p] > a[h1])
		{
			while(h1 <= t1 && y[p] > a[h1])
			{
				modify(1, 1, tot, q1[h1], q1[h1 + 1] - 1, -a[h1]);
				h1++;
			}
			modify(1, 1, tot, 1, q1[h1] - 1, y[p]);
			q1[--h1] = 1; a[h1] = y[p];
		}
		if(y[p] < b[h2])
		{
			while(h2 <= t2 && y[p] < b[h2])
			{
				modify(1, 1, tot, q2[h2], q2[h2 + 1] - 1, b[h2]);
				h2++;
			}
			modify(1, 1, tot, 1, q2[h2] - 1, -y[p]);
			q2[--h2] = 1; b[h2] = y[p];
		}
		modify(1, 1, tot, 1, tot, -1);
		if(t[1].Min == 0) ans += t[1].cnt;
		p--;
	}
	solve(l, mid - 1); solve(mid + 1, r);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
	{
		int A, B; scanf("%d%d", &A, &B);
		x[A] = B; y[B] = A;
	}
	solve(1, n);
	printf("%lld\n", ans); 
}