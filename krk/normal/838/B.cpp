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

const int Maxn = 200005;
const int Maxm = 2 * Maxn;
const int Maxs = 1048576;

int n, q;
int a[Maxm], b[Maxm], c[Maxm];
vector <int> neigh[Maxn];
int my[Maxn];
int cur, lef[Maxn], rig[Maxn];
ll BIT[Maxn];
ll mn[Maxs], flag[Maxs];

void downOn(int v, ll fl)
{
	mn[v] += fl; flag[v] += fl;
}

void Down(int v)
{
	if (flag[v]) {
		downOn(2 * v, flag[v]);
		downOn(2 * v + 1, flag[v]);
		flag[v] = 0;
	}
}

void Union(int v)
{
	mn[v] = min(mn[2 * v], mn[2 * v + 1]);
}

void Update(int v, int l, int r, int a, int b, ll val)
{
	if (l == a && r == b) downOn(v, val);
	else {
		Down(v);
		int m = l + r >> 1;
		if (a <= m) Update(2 * v, l, m, a, min(m, b), val);
		if (m + 1 <= b) Update(2 * v + 1, m + 1, r, max(m + 1, a), b, val);
		Union(v);
	}
}

void Change(int v, int l, int r, int x, ll val)
{
	if (l == r) { mn[v] = val; flag[v] = 0; }
	else {
		Down(v);
		int m = l + r >> 1;
		if (x <= m) Change(2 * v, l, m, x, val);
		else Change(2 * v + 1, m + 1, r, x, val);
		Union(v);
	}
}

ll Get(int v, int l, int r, int a, int b)
{
	if (l == a && r == b) return mn[v];
	else {
		Down(v);
		int m = l + r >> 1;
		if (b <= m) return Get(2 * v, l, m, a, b);
		if (m + 1 <= a) return Get(2 * v + 1, m + 1, r, a, b);
		return min(Get(2 * v, l, m, a, m), Get(2 * v + 1, m + 1, r, m + 1, b));
	}
}

void Traverse(int v)
{
	lef[v] = ++cur;
	for (int i = 0; i < neigh[v].size(); i++)
		Traverse(neigh[v][i]);
	rig[v] = cur;
}

void Add(int x, ll val)
{
	for (int i = x; i <= n; i += i & -i)
		BIT[i] += val;
}

ll Get(int x)
{
	ll res = 0;
	for (int i = x; i > 0; i -= i & -i)
		res += BIT[i];
	return res;
}

int main()
{
	scanf("%d %d", &n, &q);
	for (int i = 1; i <= 2 * n - 2; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		if (i <= n - 1) neigh[a[i]].push_back(b[i]);
		else my[a[i]] = c[i];
	}
	Traverse(1);
	for (int i = 1; i <= n - 1; i++) {
		int v = b[i];
		Add(lef[v], c[i]); Add(rig[v] + 1, -c[i]);
	}
	for (int i = n; i <= 2 * n - 2; i++)
		Change(1, 1, n, lef[a[i]], Get(lef[a[i]]) + my[a[i]]);
	while (q--) {
		int typ, u, v; scanf("%d %d %d", &typ, &u, &v);
		if (typ == 1)
			if (u <= n - 1) {
				int mod = v - c[u]; c[u] = v;
				Add(lef[b[u]], mod); Add(rig[b[u]] + 1, -mod);
				Update(1, 1, n, lef[b[u]], rig[b[u]], mod);
			} else {
				my[a[u]] = v;
				Change(1, 1, n, lef[a[u]], Get(lef[a[u]]) + my[a[u]]);
			}
		else if (lef[u] <= lef[v] && lef[v] <= rig[u])
				printf("%I64d\n", Get(lef[v]) - Get(lef[u]));
			else printf("%I64d\n", Get(1, 1, n, lef[u], rig[u]) - Get(lef[u]) + Get(lef[v]));
	}
	return 0;
}