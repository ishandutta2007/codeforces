#include <cstdio>
#include <algorithm>

int Max[20100000], ls[20100000], rs[20100000], tot = 0;
struct xxx{
	int l, r, p;
}b[301000];
int wz[301000], rt[301000];

bool cmp(xxx a, xxx b) {return a.l > b.l;}

int build(int l, int r)
{
	int o = ++tot;
	Max[o] = 2e9;
	if(l == r) return o;
	ls[o] = build(l, l + r >> 1);
	rs[o] = build((l + r >> 1) + 1, r);
	return o;
}

int modify(int x, int l, int r, int k, int v)
{
	int o = ++tot;
	if(l == k && r == k) {Max[o] = std::min(v, Max[x]); return o;}
	int mid = l + r >> 1;
	ls[o] = ls[x]; rs[o] = rs[x];
	if(k <= mid) ls[o] = modify(ls[x], l, mid, k, v);
	else rs[o] = modify(rs[x], mid + 1, r, k, v);
	Max[o] = std::max(Max[ls[o]], Max[rs[o]]);
	return o;
}

int query(int x, int l, int r, int L, int R)
{
	if(l == L && r == R) return Max[x];
	int mid = l + r >> 1;
	if(R <= mid) return query(ls[x], l, mid, L, R);
	else if(L > mid) return query(rs[x], mid + 1, r, L, R);
	else return std::max(query(ls[x], l, mid, L, mid), query(rs[x], mid + 1, r, mid + 1, R));
}

int ef(int x, int k)
{
	int l = 1, r = k + 1;
	while(l < r)
	{
		int mid = l + r >> 1;
		if(wz[mid] >= x) l = mid + 1;
		else r = mid;
	}
	return r - 1;
}

int main()
{
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	rt[0] = build(1, n);
	for(int i = 1; i <= k; i++)
	{
		scanf("%d%d%d", &b[i].l, &b[i].r, &b[i].p);
	}
	std::sort(b + 1, b + k + 1, cmp);
	for(int i = 1; i <= k; i++)
	{
		wz[i] = b[i].l;
		rt[i] = modify(rt[i - 1], 1, n, b[i].p, b[i].r);
	}
	for(int i = 1; i <= m; i++)
	{
		int a, b, x, y;
		scanf("%d%d%d%d", &a, &b, &x, &y);
		int id = ef(x, k);
		if(query(rt[id], 1, n, a, b) <= y) puts("yes");
		else puts("no");
		fflush(stdout);
	}
	return 0;
}

//