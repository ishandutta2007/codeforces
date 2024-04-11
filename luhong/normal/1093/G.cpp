#include <iostream>
#include <cstdio>
#define MN 1010000

int l[MN], r[MN], Max[33][MN];

void build(int x, int L, int R, int *Max, int *a)
{
	l[x] = L; r[x] = R;
	if(L == R)
	{
		Max[x] = a[L];
		return;
	}
	int mid = L + R >> 1;
	build(x << 1, L, mid, Max, a);
	build(x << 1 | 1, mid + 1, R, Max, a);
	Max[x] = std::max(Max[x << 1], Max[x << 1 | 1]);
}

void modify(int x, int k, int v, int *Max)
{
	if(l[x] == k && r[x] == k) {Max[x] = v; return;}
	int mid = l[x] + r[x] >> 1;
	if(k <= mid) modify(x << 1, k, v, Max);
	else modify(x << 1 | 1, k, v, Max);
	Max[x] = std::max(Max[x << 1], Max[x << 1 | 1]);
}

int query(int x, int L, int R, int *Max)
{
	if(l[x] == L && r[x] == R) return Max[x];
	int mid = l[x] + r[x] >> 1;
	if(R <= mid) return query(x << 1, L, R, Max);
	else if(L > mid) return query(x << 1 | 1, L, R, Max);
	else return std::max(query(x << 1, L, mid, Max), query(x << 1 | 1, mid + 1, R, Max));
}

int a[33][MN];
int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++)
	{
		int b[6];
		for(int j = 0; j < k; j++) scanf("%d", &b[j]);
		for(int S = 0; S < (1 << k); S++)
		{
			for(int j = 0; j < k; j++)
			{
				if((S >> j) & 1) a[S][i] += -b[j];
				else a[S][i] += b[j];
			}
		}
	}
	for(int S = 0; S < (1 << k); S++) build(1, 1, n, Max[S], a[S]);
	int m; scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int ans = 0;
		int o, l, r; scanf("%d", &o);
		if(o == 2)
		{
			scanf("%d%d", &l, &r);
			for(unsigned S = 0; S < (1 << k); S++)
			{
				int SS = 0;
				for(int j = 0; j < k; j++)
				{
					SS += (((S >> j) & 1) ^ 1) << j;
				}
				ans = std::max(ans, query(1, l, r, Max[S]) + query(1, l, r, Max[SS]));
			}
			printf("%d\n", ans);
		}
		else
		{
			int x; scanf("%d", &x);
			int b[6];
			for(int j = 0; j < k; j++) scanf("%d", &b[j]);
			for(int S = 0; S < (1 << k); S++)
			{
				int sum = 0;
				for(int j = 0; j < k; j++)
				{
					if((S >> j) & 1) sum += -b[j];
					else sum += b[j];
				}
				modify(1, x, sum, Max[S]);
			}
		}
	}
	return 0;
}