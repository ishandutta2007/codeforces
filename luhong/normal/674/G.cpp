#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MN 601000

int n, q, p; 
struct xxx{
	int a[5], b[5];
};
typedef std::pair<int, int> P; 

xxx t[MN]; int lazy[MN];

void add(int x, int v, int len)
{
	for(int i = 0; i < p; i++) t[x].b[i] = 0;
	t[x].a[0] = v; t[x].b[0] = len;
	lazy[x] = v;
}

void pushdown(int x, int l, int r)
{
	if(lazy[x])
	{
		int mid = l + r >> 1;
		add(x << 1, lazy[x], mid - l + 1);
		add(x << 1 | 1, lazy[x], r - mid);
		lazy[x] = 0;
	}
}

xxx pushup(xxx A, xxx B)
{
	P a[10]; memset(a, 0, sizeof(a));
	for(int i = 0; i < p; i++) a[i].first = A.a[i], a[i].second = A.b[i];
	for(int i = 0; i < p; i++) a[i + p].first = B.a[i], a[i + p].second = B.b[i];
	std::sort(a, a + p + p); 
	P b[10]; memset(b, 0, sizeof(b));
	int j = 0;
	for(int i = 0; i < p + p; i++)
		if(i && a[i].first == a[i - 1].first) b[j - 1].first += a[i].second;
		else b[j].first = a[i].second, b[j].second = a[i].first, j++; 
	std::sort(b, b + j);
	for(int i = 0; i < j - p; i++)
		for(int k = i + 1; k <= i + p; k++)
			b[k].first -= b[i].first;
	xxx C; memset(C.a, 0, sizeof(C.a)); memset(C.b, 0, sizeof(C.b));
	for(int i = j - 1; i >= std::max(0, j - p); i--)
		C.a[j - i - 1] = b[i].second, C.b[j - i - 1] = b[i].first;
	return C;
}

void modify(int x, int l, int r, int L, int R, int v)
{
	if(l == L && r == R) {add(x, v, r - l + 1); return;}
	pushdown(x, l, r); int mid = l + r >> 1;
	if(R <= mid) modify(x << 1, l, mid, L, R, v);
	else if(L > mid) modify(x << 1 | 1, mid + 1, r, L, R, v);
	else modify(x << 1, l, mid, L, mid, v), modify(x << 1 | 1, mid + 1, r, mid + 1, R, v);
	t[x] = pushup(t[x << 1], t[x << 1 | 1]);
}

xxx query(int x, int l, int r, int L, int R)
{
	if(l == L && r == R) return t[x];
	pushdown(x, l, r); int mid = l + r >> 1;
	if(R <= mid) return query(x << 1, l, mid, L, R);
	else if(L > mid) return query(x << 1 | 1, mid + 1, r, L, R);
	else return pushup(query(x << 1, l, mid, L, mid), query(x << 1 | 1, mid + 1, r, mid + 1, R));
}

int main()
{
	scanf("%d%d%d", &n, &q, &p);
	p = 100 / p;
	for(int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		modify(1, 1, n, i, i, x);
	}
	for(int i = 1; i <= q; i++)
	{
		int opt, l, r, id; scanf("%d%d%d", &opt, &l, &r);
		if(opt == 1) 
		{
			scanf("%d", &id);
			modify(1, 1, n, l, r, id);
		}
		else
		{
			xxx ans = query(1, 1, n, l, r);
			printf("%d ", p);
			for(int j = 0; j < p; j++) printf("%d ", ans.a[j] ? ans.a[j] : 1);
			puts("");
		}
	}
}