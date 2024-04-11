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

const int MAXN = 100010;

int n, MOD;
vector<int> eds[MAXN];
int a[MAXN];
bitset<1001> pp;
bitset<1001> tmp;
int tin[MAXN];
int tout[MAXN];
bitset<1001> rmq[MAXN * 4];
int dd[MAXN * 4];
int tm;
int was[MAXN];
vector<int> gg;

bitset<1001> rot(const bitset<1001> &a, int x) {
	if (x == 0)
		return a;
	bitset<1001> b;
	b |= a << x;
	b |= a >> (MOD - x);
	return b & tmp;
}

void dfs(int v) {
	tin[v] = tm++;
	gg.push_back(v);
	was[v] = 1;
	for (int u: eds[v])
		if (!was[u])
			dfs(u);
	tout[v] = tm;
}


void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v][a[gg[tl]]] = 1;
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = rmq[v * 2 + 1] | rmq[v * 2 + 2];
}

void add(int v, int tl, int tr, int l, int r, int x) {
	if (tr <= l || r <= tl)
		return;
	if (l <= tl && tr <= r) {
		rmq[v] = rot(rmq[v], x);
		dd[v] += x;
		if (dd[v] >= MOD)
			dd[v] -= MOD;
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, x);
	add(v * 2 + 2, m, tr, l, r, x);
	rmq[v] = rot(rmq[v * 2 + 1] | rmq[v * 2 + 2], dd[v]);
}


bitset<1001> get(int v, int tl, int tr, int l, int r) {
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	bitset<1001> ans;
	if (l < m)
		ans |= get(v * 2 + 1, tl, m, l, r);
	if (r > m)
		ans |= get(v * 2 + 2, m, tr, l, r);
	return rot(ans, dd[v]);
}



int main() {
	scanf("%d%d", &n, &MOD);
	for (int i = 0; i < MOD; ++i)
		tmp[i] = 1;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i), a[i] %= MOD;
	for (int i = 2; i < MOD; ++i)
		pp[i] = 1;
	for (int i = 2; i < MOD; ++i) {
		if (pp[i] == 0)
			continue;
		for (int j = i * i; j < MOD; j += i)
			pp[j] = 0;
	}
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		scanf("%d%d", &x, &y);
		--x;
		--y;
		eds[x].push_back(y);
		eds[y].push_back(x);
	}
	dfs(0);
	build(0, 0, n);
	int q;
	scanf("%d", &q);
	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int v, x;
			scanf("%d%d", &v, &x);
			--v;
			x %= MOD;
			add(0, 0, n, tin[v], tout[v], x);
		}
		else {
			int v;
			scanf("%d", &v);
			--v;
			bitset<1001> bb = get(0, 0, n, tin[v], tout[v]);
			printf("%d\n", (int)(bb & pp).count());
		}
	}
	return 0;
}