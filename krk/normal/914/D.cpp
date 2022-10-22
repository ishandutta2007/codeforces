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

const int Maxn = 500005;
const int Maxm = 2097152;

int n;
int a[Maxn];
int st[Maxm];
int q;

int gcd(int x, int y) { return x? gcd(y % x, x): y; }

void Create(int v, int l, int r)
{
	if (l == r) st[v] = a[l];
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m);
		Create(2 * v + 1, m + 1, r);
		st[v] = gcd(st[2 * v], st[2 * v + 1]);
	}
}

void Update(int v, int l, int r, int x, int val)
{
	if (l == r) st[v] = val;
	else {
		int m = l + r >> 1;
		if (x <= m) Update(2 * v, l, m, x, val);
		else Update(2 * v + 1, m + 1, r, x, val);
		st[v] = gcd(st[2 * v], st[2 * v + 1]);
	}
}

int getLeft(int v, int l, int r, int R, int x)
{
	if (st[v] % x == 0) return l - 1;
	if (l == r) return l;
	else {
		int m = l + r >> 1;
		if (R > m) {
			int g = getLeft(2 * v + 1, m + 1, r, R, x);
			if (g <= m) return getLeft(2 * v, l, m, m, x);
			else return g;
		} else return getLeft(2 * v, l, m, R, x);
	}
}

int getRight(int v, int l, int r, int L, int x)
{
	if (st[v] % x == 0) return r + 1;
	if (l == r) return r;
	else {
		int m = l + r >> 1;
		if (L <= m) {
			int g = getRight(2 * v, l, m, L, x);
			if (g >= m + 1) return getRight(2 * v + 1, m + 1, r, m + 1, x);
			else return g;
		} else return getRight(2 * v + 1, m + 1, r, L,  x);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	Create(1, 1, n);
	scanf("%d", &q);
	while (q--) {
		int typ, a, b, c; scanf("%d %d %d", &typ, &a, &b);
		if (typ == 1) {
			scanf("%d", &c);
			int got = getRight(1, 1, n, a, c);
			if (got > b) printf("YES\n");
			else {
				int got2 = getLeft(1, 1, n, b, c);
				if (got == got2) printf("YES\n");
				else printf("NO\n");
			}
		} else Update(1, 1, n, a, b);
	}
	return 0;
}