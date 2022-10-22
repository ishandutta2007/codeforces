#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 100005;
const int Maxm = 524288;

int n, q;
int a[Maxn];
ld sum[Maxm], mult[Maxm], add[Maxm];
bool flag[Maxm];

void Union(int v)
{
	sum[v] = sum[2 * v] + sum[2 * v + 1];
}

void downOn(int v, int sz, ld m, ld a)
{
	flag[v] = true;
	sum[v] = sum[v] * m + sz * a;
	mult[v] *= m;
	add[v] = add[v] * m + a;
}

void Down(int v, int l, int m, int r)
{
	if (flag[v]) {
		downOn(2 * v, m - l + 1, mult[v], add[v]);
		downOn(2 * v + 1, r - m, mult[v], add[v]);
		mult[v] = 1; add[v] = 0;
		flag[v] = false;
	}
}

void Create(int v, int l, int r)
{
	flag[v] = false; mult[v] = 1; add[v] = 0;
	if (l == r) sum[v] = a[l];
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

ld Get(int v, int l, int r, int a, int b) 
{
	if (l == a && r == b) return sum[v];
	else {
		ld res = 0;
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (a <= m) res += Get(2 * v, l, m, a, min(m, b));
		if (m + 1 <= b) res += Get(2 * v + 1, m + 1, r, max(m + 1, a), b);
		return res;
	}
}

void Change(int v, int l, int r, int a, int b, ld v1, ld v2)
{
	if (l == a && r == b) downOn(v, r - l + 1, v1, v2);
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (a <= m) Change(2 * v, l, m, a, min(m, b), v1, v2);
		if (m + 1 <= b) Change(2 * v + 1, m + 1, r, max(m + 1, a), b, v1, v2);
		Union(v);	
	}
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	Create(1, 1, n);
	while (q--) {
		int typ, l1, r1, l2, r2; scanf("%d %d %d", &typ, &l1, &r1);
		if (typ == 1) {
			scanf("%d %d", &l2, &r2);
			ld res1 = Get(1, 1, n, l1, r1), res2 = Get(1, 1, n, l2, r2);
			ld L1 = (r1 - l1 + 1), L2 = (r2 - l2 + 1);
			Change(1, 1, n, l1, r1, (L1 - 1) / L1, res2 / L2 / L1);
			Change(1, 1, n, l2, r2, (L2 - 1) / L2, res1 / L1 / L2);
		} else printf("%.10lf\n", double(Get(1, 1, n, l1, r1)));
	}
	return 0;
}