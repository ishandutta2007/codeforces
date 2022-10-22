#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 11;
const int Maxm = 100005;
const int Maxs = 524288;

struct node {
	int lef[Maxn], rig[Maxn];
	int has;
};

int n, m, q;
int B[Maxn][Maxm];
int par[Maxn * Maxm], siz[Maxn * Maxm];
node st[Maxs];

int getPar(int x) { return par[x] == x? x: par[x] = getPar(par[x]); }

bool unionSet(int a, int b)
{
	a = getPar(a), b = getPar(b);
	if (a == b) return false;
	if (siz[a] >= siz[b]) { siz[a] += siz[b]; par[b] = a; }
	else { siz[b] += siz[a]; par[a] = b; }
	return true;
}

void Init(int v)
{
	par[v] = v; siz[v] = 1;
}

void Union(const node &a, const node &b, int col, node &c)
{
	for (int i = 1; i <= n; i++) {
		Init(a.lef[i]); Init(a.rig[i]);
		Init(b.lef[i]); Init(b.rig[i]);
	}
	c.has = a.has + b.has;
	for (int i = 1; i <= n; i++)
		if (B[i][col] == B[i][col + 1]) c.has -= unionSet(a.rig[i], b.lef[i]);
	for (int i = 1; i <= n; i++) {
		c.lef[i] = getPar(a.lef[i]); c.rig[i] = getPar(b.rig[i]);
	}
}

void Create(int v, int l, int r)
{
	if (l == r) {
		st[v].has = 0;
		for (int i = 1; i <= n; i++)
			if (i == 1 || B[i - 1][l] != B[i][l]) {
				st[v].lef[i] = st[v].rig[i] = (i - 1) * m + (l - 1);
				st[v].has++;
			} else st[v].lef[i] = st[v].rig[i] = st[v].lef[i - 1];
	} else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(st[2 * v], st[2 * v + 1], m, st[v]);
	}
}

void Get(int v, int l, int r, int a, int b, node &res)
{
	if (l == a && r == b) res = st[v];
	else {
		int m = l + r >> 1;
		if (b <= m) Get(2 * v, l, m, a, b, res);
		else if (m + 1 <= a) Get(2 * v + 1, m + 1, r, a, b, res);
		else {
			node res1, res2;
			Get(2 * v, l, m, a, m, res1); Get(2 * v + 1, m + 1, r, m + 1, b, res2);
			Union(res1, res2, m, res);
		}
	}
}

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &B[i][j]);
	Create(1, 1, m);
	node res;
	while (q--) {
		int l, r; scanf("%d %d", &l, &r);
		Get(1, 1, m, l, r, res);
		printf("%d\n", res.has);
	}
	return 0;
}