#include <cstdio>
#include <iostream>
#define MN 1200100

int l[MN], r[MN];
int c[MN], d[MN];
struct xxx{long long ls, rs, sum, s;} t[MN];
int st[MN], top = 0;

xxx pushup(xxx a, xxx b)
{
	xxx c;
	c.ls = std::max(a.ls, a.s + b.ls);
	c.rs = std::max(b.rs, b.s + a.rs);
	c.sum = std::max(std::max(a.sum, b.sum), a.rs + b.ls);
	c.s = a.s + b.s;
	return c;
}

void build(int x, int L, int R)
{
	if(L == R) {t[x].ls = t[x].rs = t[x].sum = t[x].s = c[L]; return;}
	int mid = L + R >> 1;
	build(x << 1, L, mid); build(x << 1 | 1, mid + 1, R);
	t[x] = pushup(t[x << 1], t[x << 1 | 1]);
}

xxx query(int x, int L, int R, int l, int r)
{
	if(L == l && R == r) return t[x];
	int mid = L + R >> 1;
	if(r <= mid) return query(x << 1, L, mid, l, r);
	else if(l > mid) return query(x << 1 | 1, mid + 1, R, l, r);
	else return pushup(query(x << 1, L, mid, l, mid), query(x << 1 | 1, mid + 1, R, mid + 1, r));
}

int main()
{
	long long ans = 0;
	int n, a; scanf("%d%d", &n, &a);
	for(int i = 1; i <= n; i++)
	{
		scanf("%d%d", &d[i], &c[i]);
		c[i] = a - c[i];
		ans = std::max(ans, (long long)c[i]);
	}
	for(int i = 1; i < n; i++) d[i] = d[i + 1] - d[i];
	for(int i = 1; i < n; i++)
	{
		while(top && d[st[top]] <= d[i]) top--;
		l[i] = st[top] + 1; st[++top] = i;
	}
	top = 0;
	for(int i = 1; i < n; i++)
	{
		while(top && d[st[top]] < d[i]) r[st[top--]] = i - 1;
		st[++top] = i;
	}
	while(top) r[st[top--]] = n - 1;
	build(1, 1, n);
	for(int i = 1; i < n; i++)
		ans = std::max(ans, query(1, 1, n, l[i], r[i] + 1).sum - 1ll * d[i] * d[i]);
	printf("%lld\n", ans);
	return 0;
}