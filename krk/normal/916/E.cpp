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
#pragma comment(linker, "/STACK:16000000")
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const int Maxm = 20;
const int Maxs = 524288;

int n, q;
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int L[Maxn], P[Maxn][Maxm];
int my[Maxn], myval[Maxn];
ll G;
ll sum[Maxs], flag[Maxs];
int root;

void downOn(int v, int sz, ll val)
{
	sum[v] += val * ll(sz); flag[v] += val;
}

void Down(int v, int l, int m, int r)
{
	if (flag[v]) {
		downOn(2 * v, m - l + 1, flag[v]);
		downOn(2 * v + 1, r - m, flag[v]);
		flag[v] = 0;
	}
}

void Union(int v)
{
	sum[v] = sum[2 * v] + sum[2 * v + 1];
}

void Create(int v, int l, int r)
{
	if (l == r) sum[v] = myval[l];
	else {
		int m = l + r >> 1;
		Create(2 * v, l, m); Create(2 * v + 1, m + 1, r);
		Union(v);
	}
}

void Add(int v, int l, int r, int a, int b, ll val)
{
	if (l == a && r == b) downOn(v, r - l + 1, val);
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (a <= m) Add(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Add(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		Union(v);
	}
}

ll Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return sum[v];
	else {
		int m = l + r >> 1;
		Down(v, l, m, r);
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		return Get(2 * v, l, m, a, m) + Get(2 * v + 1, m + 1, r, m + 1, b);
	}
}

void Traverse(int v)
{
	lef[v] = ++cur; myval[lef[v]] = my[v];
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (P[v][0] == u) continue;
		L[u] = L[v] + 1; P[u][0] = v;
		Traverse(u);
	}
	rig[v] = cur;
}

int getLCA(int a, int b)
{
	if (L[a] < L[b]) swap(a, b);
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) >= L[b])
			a = P[a][i];
	if (a == b) return a;
	for (int i = Maxm - 1; i >= 0; i--)
		if (P[a][i] != P[b][i])
			a = P[a][i], b = P[b][i];
	return P[a][0];
}

int goUp(int a, int b)
{
	for (int i = Maxm - 1; i >= 0; i--)
		if (L[a] - (1 << i) > L[b])
			a = P[a][i];
	return a;
}

bool Has(int v, int u) { return lef[v] <= lef[u] && rig[u] <= rig[v]; }

void Add(int u, int v, int val)
{
	int lca = getLCA(u, v);
	if (lca == root) { G += val; return; }
	if (Has(root, lca)) { Add(1, 1, n, lef[lca], rig[lca], val); return; }
	int ulca = getLCA(root, u);
	int vlca = getLCA(root, v);
	if (L[lca] > L[ulca] && L[lca] > L[vlca]) { Add(1, 1, n, lef[lca], rig[lca], val); return; }
	int C = L[ulca] > L[vlca]? ulca: vlca;
	if (C == root) { G += val; return; }
	int lst = goUp(root, C);
	G += val;
	Add(1, 1, n, lef[lst], rig[lst], -val);
}

ll Get(int v)
{
	if (root == v) return G * ll(n) + sum[1];
	int lca = getLCA(root, v);
	if (Has(root, v) || v != lca) return G * ll(rig[v] - lef[v] + 1) + Get(1, 1, n, lef[v], rig[v]); 
	int lst = goUp(root, v);
	return G * ll(n - (rig[lst] - lef[lst] + 1)) + (sum[1] - Get(1, 1, n, lef[lst], rig[lst]));
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= n; i++)
		scanf("%d", &my[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	root = 1; Traverse(1);
	for (int j = 1; j < Maxm; j++)
		for (int i = 1; i <= n; i++)
			P[i][j] = P[P[i][j - 1]][j - 1];
	Create(1, 1, n);
	while (q--) {
		int typ, a, b, c; scanf("%d %d", &typ, &a);
		if (typ == 1) root = a;
		else if (typ == 2) {
			scanf("%d %d", &b, &c);
			Add(a, b, c);
		} else if (typ == 3)
			printf("%I64d\n", Get(a));
	}
	return 0;
}