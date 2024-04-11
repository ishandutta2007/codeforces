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
typedef double ld;

using namespace std;
const int MAXN = 410000;

int n, m;
bitset<60> rmq[MAXN * 4];
int dd[MAXN * 4];
int c[MAXN];
int c2[MAXN];
int was[MAXN];
vector<int> eds[MAXN];
int tin[MAXN];
int tout[MAXN];
int tm;


void dfs(int v) {
	was[v] = 1;
	tin[v] = tm++;
	for (int i = 0; i < (int)eds[v].size(); ++i) {
		int u = eds[v][i];
		if (!was[u])
			dfs(u);
	}
	tout[v] = tm;
}
void push(int v) {
	if (dd[v] == -1)
		return;
	dd[v * 2 + 1] = dd[v];
	rmq[v * 2 + 1] = rmq[v];
	dd[v * 2 + 2] = dd[v];
	rmq[v * 2 + 2] = rmq[v];
	dd[v] = -1;
}


void build(int v, int tl, int tr) {
	dd[v] = -1;
	if (tl + 1 == tr) {
		rmq[v][c2[tl]] = 1;
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = rmq[v * 2 + 1] | rmq[v * 2 + 2];
}

void upd(int v, int tl, int tr, int l, int r, int x) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		rmq[v].reset();
		rmq[v][x] = 1;
		dd[v] = x;
		return;
	}
	push(v);
	int m = (tl + tr) >> 1;
	upd(v * 2 + 1, tl, m, l, r, x);
	upd(v * 2 + 2, m, tr, l, r, x);
	rmq[v] = rmq[v * 2 + 1] | rmq[v * 2 + 2];
}

bitset<60> get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return bitset<60>();
	if (l <= tl && tr <= r)
		return rmq[v];
	push(v);
	int m = (tl + tr) >> 1;
	return get(v * 2 + 1, tl, m, l, r) | get(v * 2 + 2, m, tr, l, r);
}


int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%d", c + i), --c[i];
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		eds[a].push_back(b);
		eds[b].push_back(a);
	}
	dfs(0);
	for (int i = 0; i < n; ++i)
		c2[tin[i]] = c[i];
	build(0, 0, n);
	for (int i = 0; i < m; ++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int v, cc;
			scanf("%d%d", &v, &cc);
			--v;
			--cc;
			upd(0, 0, n, tin[v], tout[v], cc);
		}
		else {
			int v;
			scanf("%d", &v);
			--v;
			printf("%d\n", (int)get(0, 0, n, tin[v], tout[v]).count());
		}
	}
	return 0;
}