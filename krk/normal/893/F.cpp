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

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxm = 524288;
const int Inf = 1000000007;

int n, r;
int a[Maxn];
vector <int> neigh[Maxn];
int cur, lef[Maxn], rig[Maxn];
int realval[Maxn];
int L[Maxn];
vector <ii> st[Maxm];
int m;

void Traverse(int v, int p)
{
	cur++; lef[v] = cur; realval[cur] = v;
	for (int i = 0; i < neigh[v].size(); i++) {
		int u = neigh[v][i];
		if (u == p) continue;
		L[u] = L[v] + 1;
		Traverse(u, v);
	}
	rig[v] = cur;
}

void Create(int v, int l, int r)
{
	if (l == r) st[v].push_back(ii(L[realval[l]], a[realval[l]]));
	else {
		int m = l + r >> 1;
		int lc = 2 * v, rc = 2 * v + 1;
		Create(lc, l, m); Create(rc, m + 1, r);
		int i = 0, j = 0;
		int mn = Inf;
		while (i < st[lc].size() || j < st[rc].size())
			if (i < st[lc].size() && (j >= st[rc].size() || st[lc][i].first < st[rc][j].first)) {
				mn = min(mn, st[lc][i].second);
				st[v].push_back(ii(st[lc][i].first, mn)); i++;
			} else if (j < st[rc].size() && (i >= st[lc].size() || st[rc][j].first < st[lc][i].first)) {
				mn = min(mn, st[rc][j].second);
				st[v].push_back(ii(st[rc][j].first, mn)); j++;
			} else {
				mn = min(mn, min(st[lc][i].second, st[rc][j].second));
				st[v].push_back(ii(st[lc][i].first, mn)); i++; j++;
			}
	}
}

int Get(int v, int l, int r, int a, int b, int al)
{
	if (l == a && r == b) {
		int ind = lower_bound(st[v].begin(), st[v].end(), ii(al + 1, 0)) - st[v].begin() - 1;
		return ind >= 0? st[v][ind].second: Inf;
	} else {
		int m = l + r >> 1;
		if (b <= m) return Get(2 * v, l, m, a, b, al);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b, al);
		return min(Get(2 * v, l, m, a, m, al), Get(2 * v + 1, m + 1, r, m + 1, b, al));
	}
}

int main()
{
	scanf("%d %d", &n, &r);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n - 1; i++) {
		int a, b; scanf("%d %d", &a, &b);
		neigh[a].push_back(b);
		neigh[b].push_back(a);
	}
	Traverse(r, 0);
	Create(1, 1, n);
	int lst = 0;
	scanf("%d", &m);
	while (m--) {
		int x, y; scanf("%d %d", &x, &y);
		x = (x + lst) % n + 1, y = (y + lst) % n;
		lst = Get(1, 1, n, lef[x], rig[x], L[x] + y);
		printf("%d\n", lst);
	}
	return 0;
}