#include <cstdio>
#include <algorithm>
#define MN 4010000

long long Max[MN], lazy[MN];
int l[MN], r[MN];
long long c[MN];
int n = 1e6;

void add(int x, int v) {for(int i = x; i <= n; i += i & -i) c[i] += v;}
long long Qu(int x) {long long ans = 0; for(int i = x; i; i -= i & -i) ans += c[i]; return ans;}

void build(int x, int l, int r)
{
	::l[x] = l; ::r[x] = r;
	if(l == r) {Max[x] = l; return;}
	int mid = l + r >> 1;
	build(x << 1, l, mid);
	build(x << 1 | 1, mid + 1, r);
	Max[x] = std::max(Max[x << 1], Max[x << 1 | 1]);
}

void pushdown(int x)
{
	if(lazy[x])
	{
		Max[x << 1] += lazy[x];
		lazy[x << 1] += lazy[x];
		Max[x << 1 | 1] += lazy[x];
		lazy[x << 1 | 1] += lazy[x];
		lazy[x] = 0;
	}
}

void modify(int x, int L, int R, int v)
{
	if(l[x] == L && r[x] == R) {Max[x] += v, lazy[x] += v; return;}
	pushdown(x); int mid = l[x] + r[x] >> 1; 
	if(R <= mid) modify(x << 1, L, R, v);
	else if(L > mid) modify(x << 1 | 1, L, R, v);
	else modify(x << 1, L, mid, v), modify(x << 1 | 1, mid + 1, R, v);
	Max[x] = std::max(Max[x << 1], Max[x << 1 | 1]);
}

long long query(int x, int L, int R)
{
	if(l[x] == L && r[x] == R) return Max[x];
	pushdown(x); int mid = l[x] + r[x] >> 1; 
	if(R <= mid) return query(x << 1, L, R);
	else if(L > mid) return query(x << 1 | 1, L, R);
	else return std::max(query(x << 1, L, mid), query(x << 1 | 1, mid + 1, R));
}

int t[MN], d[MN];
int main()
{
	build(1, 1, n);
	int m; scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		char c[2]; scanf("%s", c);
		if(c[0] == '?')
		{
			int t; scanf("%d", &t);
			printf("%lld\n", query(1, 1, t) - t - (Qu(n) - Qu(t)));
		}
		if(c[0] == '+')
		{
			scanf("%d%d", &t[i], &d[i]);
			modify(1, 1, t[i], d[i]);
			add(t[i], d[i]);
		}
		if(c[0] == '-')
		{
			int j; scanf("%d", &j);
			modify(1, 1, t[j], -d[j]);
			add(t[j], -d[j]);
		}
	}
	return 0;
}