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
const int MAXN = 210000;
const int MAX = 1000100;
const ll MOD = 1000000007;

ll rmq[MAXN * 4];

void build(int v, int tl, int tr) {
	rmq[v] = 1;
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
}

void mult(int v, int tl, int tr, int l, int r, ll c) {
	if (tr <= l || r <= tl)
		return;
	if (l <= tl && tr <= r) {
		rmq[v] = (rmq[v] * c) % MOD;
		return;
	}
	int m = (tl + tr) >> 1;
	mult(v * 2 + 1, tl, m, l, r, c);
	mult(v * 2 + 2, m, tr, l, r, c);
}


ll get(int v, int tl, int tr, int x) {
	if (tl + 1 == tr)
		return rmq[v];
	int m = (tl + tr) >> 1;
	if (x < m)
		return (get(v * 2 + 1, tl, m, x) * rmq[v]) % MOD;
	else
		return (get(v * 2 + 2, m, tr, x) * rmq[v]) % MOD;
}


int dd[MAX];
int n;
int a[MAXN];
int q;
vector<pair<int, int> > qq[MAXN];
int lst[MAX];
int ans[MAXN];


int main() {
	for (int i = 0; i < MAX; ++i)
		dd[i] = i;
	for (int i = 2; i * i < MAX; ++i) {
		if (dd[i] != i)
			continue;
		for (int j = i * i; j < MAX; j += i)
			dd[j] = min(dd[j], i);
	}
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i);
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l;
		--r;
		qq[r].push_back(make_pair(l, i));
	}

	for (int i = 0; i < MAX; ++i)
		lst[i] = -1;

	build(0, 0, n);
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		while (x != 1) {
			int d = dd[x];
			int cnt = 0;
			while (x % d == 0)
				x /= d, ++cnt;
			int c = 1;
			for (int i = 0; i < cnt; ++i)
				c *= d;
			mult(0, 0, n, 0, lst[d] + 1, c);
			c = d - 1;
			for (int i = 0; i < cnt - 1; ++i)
				c *= d;
			mult(0, 0, n, lst[d] + 1, i + 1, c);
			lst[d] = i;
		}
		for (int j = 0; j < (int)qq[i].size(); ++j) {
			int l, g;
			l = qq[i][j].first;
			g = qq[i][j].second;
			ans[g] = get(0, 0, n, l);
		}
	}
	for (int i = 0; i < q; ++i)
		printf("%d\n", ans[i]);
	return 0;
}