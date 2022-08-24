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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

struct st {
	int l, r;
	int ans;
	int sz;
	int a[10];
};

int tmp[21];

int get(int x) {
	if (tmp[x] == x)
		return x;
	return tmp[x] = get(tmp[x]);
}
const int MAXN = 120000;

st rmq[MAXN * 4];
vector<int> edl[MAXN];

st mrg(st a, st b) {
	if (a.sz == 0)
		return b;
	if (b.sz == 0)
		return a;
	for (int i = 0; i < a.sz; ++i)
		tmp[i] = a.a[i];
	for (int i = 0; i < b.sz; ++i)
		tmp[i + a.sz] = b.a[i] + a.sz;
	for (int i = 0; i < min(5, b.sz); ++i) {
		for (int j: edl[b.l + i]) {
			if (j < a.r && j >= a.l) {
				int k = a.sz - (a.r - j);
				int l = a.sz + i;
				k = get(k);
				l = get(l);
				tmp[l] = k;
			}
		}
	}
	if (a.sz + b.sz <= 10) {
		a.sz = a.sz + b.sz;
		a.r = b.r;
		a.ans += b.ans;
		for (int i = 0; i < a.sz; ++i)
			a.a[i] = tmp[i];
		return a;
	}
	a.sz += b.sz;
	for (int i = 0; i < 5; ++i) {
		int x = get(i);
		if (x >= 5 && x < a.sz - 5) {
			tmp[x] = i;
			tmp[i] = i;
		}
	}
	for (int i = a.sz - 5; i < a.sz; ++i) {
		int x = get(i);
		if (x >= 5 && x < a.sz - 5) {
			tmp[x] = i;
			tmp[i] = i;
		}
	}
	for (int i = 0; i < 5; ++i)
		get(i);
	for (int i = a.sz - 5; i < a.sz; ++i)
		get(i);
	for (int i = 0; i < 5; ++i)
		a.a[i] = tmp[i];
	for (int i = a.sz - 5; i < a.sz; ++i)
		if (tmp[i] < 5)
			a.a[5 + i - (a.sz - 5)] = tmp[i];
		else
			a.a[5 + i - (a.sz - 5)] = tmp[i] - (a.sz - 10);
	a.ans += b.ans;
	for (int i = 5; i < a.sz - 5; ++i)
		if (tmp[i] == i)
			++a.ans;
	a.r = b.r;
	a.sz = 10;
	return a;
}

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		rmq[v].l = tl;
		rmq[v].r = tr;
		rmq[v].ans = 0;
		rmq[v].sz = 1;
		rmq[v].a[0] = 0;
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	rmq[v] = mrg(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

st a;

void get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r){
		a = mrg(a, rmq[v]);
		return;
	}
	int m = (tl + tr) >> 1;
	get(v * 2 + 1, tl, m, l, r);
	get(v * 2 + 2, m, tr, l, r);
}

int n, k;

int main() {
	scanf("%d%d", &n, &k);
	int m;
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		if (a > b)
			swap(a, b);
		edl[b].push_back(a);
	}
	build(0, 0, n);
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		a.sz = 0;
		get(0, 0, n, l, r);
		int ans = a.ans;
		for (int j = 0; j < a.sz; ++j)
			if (a.a[j] == j)
				++ans;
		printf("%d\n", ans);
	}
	return 0;
}