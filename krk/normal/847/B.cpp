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

const int Maxn = 200005;
const int Maxm = 1048576;

int n;
int a[Maxn];
int mx[Maxm];

void Create(int v, int l, int r)
{
	if (l == r) mx[v] = a[l];
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		mx[v] = max(mx[2 * v], mx[2 * v + 1]);
	}
}

int Get(int v, int l, int r, int x, int val)
{
	if (mx[v] <= val) return -1;
	if (l == r) return l == x? -1: l;
	else {
		int m = l + r >> 1;
		if (x <= m) {
			int got = Get(2 * v, l, m, x, val);
			if (got == -1) return Get(2 * v + 1, m + 1, r, x, val);
			else return got;
		} else return Get(2 * v + 1, m + 1, r, x, val);
	}
}

void Rem(int v, int l, int r, int x)
{
	if (l == r) mx[v] = 0;
	else {
		int m = l + r >> 1;
		if (x <= m) Rem(2 * v, l, m, x);
		else Rem(2 * v + 1, m + 1, r, x);
		mx[v] = max(mx[2 * v], mx[2 * v + 1]);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	Create(1, 1, n);
	int my;
	while ((my = Get(1, 1, n, 0, 0)) != -1) {
		printf("%d", a[my]); Rem(1, 1, n, my);
		while (true) {
			my = Get(1, 1, n, my, a[my]);
			if (my == -1) break;
			printf(" %d", a[my]); Rem(1, 1, n, my);
		}
		printf("\n");
	}
	return 0;
}