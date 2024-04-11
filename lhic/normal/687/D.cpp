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

const int MAXN = 1010;
const int MAXM = 600000;

vector<int> rmq[MAXM * 4];

int sz[MAXN];
int p[MAXN];
int ch[MAXN];
int was[MAXN];
int cl[MAXN];
int n, m, q;
int a[MAXM];
int b[MAXM];
int c[MAXM];
vector<int> eds[MAXN];

void clear() {
	fill(sz, sz + n, 1);
	for (int i = 0; i < n; ++i)
		p[i] = i, ch[i] = 0;
}

pair<int, int> get(int v) {
	if (p[v] == v)
		return make_pair(v, 0);
	pair<int, int> gg = get(p[v]);
	p[v] = gg.first;
	ch[v] ^= gg.second;
	return make_pair(p[v], ch[v]);
}

int add(int a, int b) {
	pair<int, int> a1 = get(a);
	pair<int, int> b1 = get(b);
	if (a1.first == b1.first) {
		if (a1.second == b1.second)
			return 2;
		else
			return 0;
	}
	a = a1.first;
	b = b1.first;
	if (sz[a] < sz[b])
		swap(a, b);
	sz[a] += sz[b];
	p[b] = a;
	ch[b] ^= 1 ^ a1.second ^ b1.second;
	return 1;
}

bool cmp(int x, int y) {
	return c[x] > c[y];
}

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v].push_back(tl);
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	vector<int> tmp(rmq[v * 2 + 1].size() + rmq[v * 2 + 2].size());
	merge(rmq[v * 2 + 1].begin(), rmq[v * 2 + 1].end(), rmq[v * 2 + 2].begin(), rmq[v * 2 + 2].end(), tmp.begin(), cmp);
	clear();
	for (int i = 0; i < (int)tmp.size(); ++i) {
		int x = add(a[tmp[i]], b[tmp[i]]);
		if (x == 1 || x == 2)
			rmq[v].push_back(tmp[i]);
		if (x == 2)
			break;
	}
}

void get2(int v, int tl, int tr, int l, int r, int x) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		for (int i = 0; i < (int)rmq[v].size(); ++i)
			if (c[rmq[v][i]] > x)
				eds[a[rmq[v][i]]].push_back(b[rmq[v][i]]), eds[b[rmq[v][i]]].push_back(a[rmq[v][i]]);
		return;
	}
	int m = (tl + tr) >> 1;
	get2(v * 2 + 1, tl, m, l, r, x);
	get2(v * 2 + 2, m, tr, l, r, x);
}

int dfs(int v, int c) {
	cl[v] = c;
	was[v] = 1;
	for (int u: eds[v]) {
		if (!was[u]) {
			if (!dfs(u, c ^ 1))
				return 0;
		}
		else if (cl[v] == cl[u]) {
			return 0;
		}
	}
	return 1;
}


int check(int l, int r, int x) {
	for (int i = 0; i < n; ++i)
		eds[i].clear();
	memset(was, 0, sizeof(was[0]) * n);
	fill(cl, cl + n, -1);
	get2(0, 0, m, l, r, x);
	for (int i = 0; i < n; ++i)
		if (!was[i]) {
			if (!dfs(i, 0))
				return 0;
		}
	return 1;
}

vector<int> gg;

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < m; ++i)
		scanf("%d%d%d", a + i, b + i, c + i), --a[i], --b[i], gg.push_back(c[i]);
	build(0, 0, m);
	sort(gg.begin(), gg.end());
	gg.resize(unique(gg.begin(), gg.end()) - gg.begin());
	for (int i = 0; i < q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		int lb = -2;
		int rb = gg.size() - 1;
		while (rb - lb > 1) {
			int mid = (lb + rb) >> 1;
			int go = 0;
			if (mid == -1)
				go = -1;
			else
				go = gg[mid];
			if (check(l, r, go))
				rb = mid;
			else
				lb = mid;
		}
		if (rb == -1)
			printf("-1\n");
		else
			printf("%d\n", gg[rb]);
	}
	return 0;
}