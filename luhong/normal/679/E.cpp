#include <iostream>
#include <cstdio>
#include <algorithm> 
#define MN 401000

typedef long long ll;
typedef std::pair<int, ll> P;
ll mi[MN], Min[MN], lazy1[MN];
P lazy2[MN], a[MN]; bool sm[MN];
int p[MN];

void add1(int x, ll v) {lazy1[x] += v; Min[x] -= v;}
void add2(int x, P v)
{
	lazy2[x] = v; lazy1[x] = 0;
	p[x] = v.first; sm[x] = 1;
	Min[x] = v.second; 
}

void pushdown(int x)
{
	if(lazy2[x].first) 
	{
		add2(x << 1, lazy2[x]);
		add2(x << 1 | 1, lazy2[x]);
		lazy2[x] = P(0, 0);
	}
	if(lazy1[x])
	{
		add1(x << 1, lazy1[x]);
		add1(x << 1 | 1, lazy1[x]);
		lazy1[x] = 0;
	}
}

bool flag = 0;

void pushup(int x)
{
	Min[x] = std::min(Min[x << 1], Min[x << 1 | 1]);
	if(sm[x << 1] && sm[x << 1 | 1] && p[x << 1] == p[x << 1 | 1] && Min[x << 1] == Min[x << 1 | 1]) sm[x] = 1;
	else sm[x] = 0; 
	p[x] = p[x << 1];
}

void modify1(int x, int l, int r, int L, int R, ll v)
{
	if(l == L && r == R)
	{
		if(v < Min[x]) {add1(x, v); return;}
		if(sm[x])
		{
			ll now = mi[p[x]] - Min[x] + v;
			while(now >= mi[p[x]]) p[x]++;
			Min[x] = mi[p[x]] - now;
			add2(x, P(p[x], Min[x])); 
			if(now == mi[p[x] - 1])	flag = 1;
			return;
		}
		pushdown(x); int mid = l + r >> 1;
		modify1(x << 1, l, mid, L, mid, v); modify1(x << 1 | 1, mid + 1, r, mid + 1, R, v);
		pushup(x);
		return;
	}
	pushdown(x); int mid = l + r >> 1;
	if(R <= mid) modify1(x << 1, l, mid, L, R, v);
	else if(L > mid) modify1(x << 1 | 1, mid + 1, r, L, R, v);
	else modify1(x << 1, l, mid, L, mid, v), modify1(x << 1 | 1, mid + 1, r, mid + 1, R, v);
	pushup(x);
}

void modify2(int x, int l, int r, int L, int R, P v)
{
	if(l == L && r == R) {add2(x, v); return;}
	pushdown(x); int mid = l + r >> 1;
	if(R <= mid) modify2(x << 1, l, mid, L, R, v);
	else if(L > mid) modify2(x << 1 | 1, mid + 1, r, L, R, v);
	else modify2(x << 1, l, mid, L, mid, v), modify2(x << 1 | 1, mid + 1, r, mid + 1, R, v);
	pushup(x);
}

ll query(int x, int l, int r, int k)
{
	if(l == k && r == k) return mi[p[x]] - Min[x];
	pushdown(x); int mid = l + r >> 1;
	if(k <= mid) return query(x << 1, l, mid, k);
	else return query(x << 1 | 1, mid + 1, r, k);
}

void build(int x, int l, int r)
{
	if(l == r) {add2(x, a[l]); return;}
	int mid = l + r >> 1;
	build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
	pushup(x);
}

int main()
{
	mi[0] = 1; for(int i = 1; i <= 11; i++) mi[i] = mi[i - 1] * 42;
	int n, q; scanf("%d%d", &n, &q);
	for(int i = 1; i <= n; i++)
	{
		ll x; scanf("%lld", &x);
		int id = std::upper_bound(mi + 1, mi + 11 + 1, x) - mi;
		a[i] = P(id, mi[id] - x);
	}
	build(1, 1, n);
	for(int i = 1; i <= q; i++)
	{
		int opt, l, r; ll x; scanf("%d%d", &opt, &l);
		if(opt == 1) printf("%lld\n", query(1, 1, n, l));
		if(opt == 2)
		{
			scanf("%d%lld", &r, &x);
			int id = std::upper_bound(mi + 1, mi + 11 + 1, x) - mi;
			P v = P(id, mi[id] - x);
			modify2(1, 1, n, l, r, v);
		}
		if(opt == 3)
		{
			scanf("%d%lld", &r, &x);
			do {
				flag = 0;
				modify1(1, 1, n, l, r, x); 
			} while(flag);
		}
	}
}