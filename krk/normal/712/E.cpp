#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long double ld;
typedef pair <ld, ld> ldld;

const int Maxn = 100005;
const int Maxm = 524288;
const ld eps = 1e-15l;

int n, q;
int a[Maxn], b[Maxn];
ldld st[Maxm];

ldld Union(const ldld &a, const ldld &b)
{
	ldld c;
	c.first = a.first * b.first / (1.0l - (1.0l - b.first) * a.second);
	c.second = b.second + ((1.0l - b.second) * a.second * b.first) / (1.0l - (1.0l - b.first) * a.second);
	return c;
}

void Create(int v, int l, int r)
{
	if (l == r) { st[v].first = st[v].second = ld(a[l]) / ld(b[l]); }
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		st[v] = Union(st[2 * v], st[2 * v + 1]);
	}
}

void Update(int v, int l, int r, int ind)
{
	if (l == r) { st[v].first = st[v].second = ld(a[l]) / ld(b[l]); }
	else {
		int m = l + r >> 1;
		if (ind <= m) Update(2 * v, l, m, ind);
		else Update(2 * v + 1, m + 1, r, ind);
		st[v] = Union(st[2 * v], st[2 * v + 1]);
	}
}

ldld Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return st[v];
	else {
		int m = l + r >> 1;
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		return Union(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
	}
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i], &b[i]);
	Create(1, 1, n);
	while (q--) {
		int typ; scanf("%d", &typ);
		if (typ == 1) {
			int ind, nwa, nwb; scanf("%d %d %d", &ind, &nwa, &nwb);
			a[ind] = nwa; b[ind] = nwb;
			Update(1, 1, n, ind);
		} else if (typ == 2) {
			int l, r; scanf("%d %d", &l, &r);
			ldld got = Get(1, 1, n, l, r);
			printf("%.10lf\n", double(got.first));
		}
	}
	return 0;
}