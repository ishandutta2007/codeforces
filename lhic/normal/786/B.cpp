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
const int MAXN = 110000;
const ll INF = 1e16;

int n, q, s;
int cc;
int gup[MAXN * 4];
int gdw[MAXN * 4];

vector<pair<int, ll> > eds[MAXN * 10];
ll dd[MAXN * 10];
set<pair<int, ll> > ss;

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		gup[v] = gdw[v] = tl;
		return;
	}
	gup[v] = cc++;
	gdw[v] = cc++;
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	eds[gup[v * 2 + 1]].push_back(make_pair(gup[v], 0));
	eds[gup[v * 2 + 2]].push_back(make_pair(gup[v], 0));
	eds[gdw[v]].push_back(make_pair(gdw[v * 2 + 1], 0));
	eds[gdw[v]].push_back(make_pair(gdw[v * 2 + 2], 0));
}

void addt(int v, int tl, int tr, int l, int r, int u, ll w) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		eds[u].push_back(make_pair(gdw[v], w));
		return;
	}
	int m = (tl + tr) >> 1;
	addt(v * 2 + 1, tl, m, l, r, u, w);
	addt(v * 2 + 2, m, tr, l, r, u, w);
}

void addf(int v, int tl, int tr, int l, int r, int u, ll w) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		eds[gup[v]].push_back(make_pair(u, w));
		return;
	}
	int m = (tl + tr) >> 1;
	addf(v * 2 + 1, tl, m, l, r, u, w);
	addf(v * 2 + 2, m, tr, l, r, u, w);
}

int main() {
	scanf("%d%d%d", &n, &q, &s);
	--s;
	cc = n;
	build(0, 0, n);
	for (int i = 0; i < q; ++i) {
		int t;
		scanf("%d", &t);
		if (t == 1) {
			int a, b;
			ll w;
			scanf("%d%d%lld", &a, &b, &w);
			--a, --b;
			eds[a].push_back(make_pair(b, w));
		}
		else if (t == 2) {
			int v, l, r;
			ll w;
			scanf("%d%d%d%lld", &v, &l, &r, &w);
			--l, --v;
			addt(0, 0, n, l, r, v, w);
		}
		else {
			int v, l, r;
			ll w;
			scanf("%d%d%d%lld", &v, &l, &r, &w);
			--l, --v;
			addf(0, 0, n, l, r, v, w);
		}
	}
	for (int i = 0; i < cc; ++i)
		dd[i] = INF;
	dd[s] = 0;
	ss.insert(make_pair(0, s));
	while (!ss.empty()) {
		int x = ss.begin()->second;
		ss.erase(ss.begin());
		for (auto e: eds[x]) {
			int u = e.first;
			if (dd[u] > dd[x] + e.second) {
				if (dd[u] < INF)
					ss.erase(make_pair(dd[u], u));
				dd[u] = dd[x] + e.second;
				ss.insert(make_pair(dd[u], u));
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		if (dd[i] >= INF)
			printf("-1 ");
		else
			printf("%lld ", dd[i]);
	}
	printf("\n");
	return 0;
}