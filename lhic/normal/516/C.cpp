#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 220000;

struct hh
{
	ll ml, mr, sm, mm;
};

hh rmq[MAXN * 4];
ll d[MAXN * 4];
ll h[MAXN * 4];
int n, m;

inline hh merge(const hh& a, const hh& b)
{
	hh x;
	x.ml = max(a.ml, b.ml + a.sm);
	x.mr = max(a.mr + b.sm, b.mr);
	x.sm = a.sm + b.sm;
	x.mm = max(a.mr + b.ml, max(a.mm, b.mm));
	return x;
}


hh get(int v, int tl, int tr, int l, int r)
{
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	if (r <= m)
		return get(v * 2 + 1, tl, m, l, r);
	if (l >= m)
		return get(v * 2 + 2, m, tr, l, r);
	return merge(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r));
}

inline ll solve(int l, int r)
{
	return get(0, 0, 2 * n, l, r).mm;
}

void build(int v, int tl, int tr)
{
	if (tl + 1 == tr)
	{
		rmq[v].sm = d[tl];
		rmq[v].mm = 0;
		rmq[v].mr = h[tl] + d[tl];
		rmq[v].ml = h[tl];
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = merge(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
	{
	//	int a;
		scanf("%I64d", &d[i]);
		//d[i] = a;
	}
	for (int i = 0; i < n; ++i)
	{
		//int a;
		scanf("%I64d", &h[i]);
		h[i] *= 2;
	}
	memcpy(d + n, d, sizeof(d[0]) * n);
	memcpy(h + n, h, sizeof(h[0]) * n);
	build(0, 0, 2 * n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		if (a <= b)
		//	cout << solve(b + 1, a + n) << "\n";
			printf("%I64d\n", solve(b + 1, a + n));
		else
		//	cout << solve(b + 1, a) << "\n";
			printf("%I64d\n", solve(b + 1, a));
	}
	return 0;
}