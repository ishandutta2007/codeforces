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
const int MAXN = 310000;

int n;
vector<pair<ll, int> > vv;
vector<pair<int, int> > go[MAXN];
ll a[MAXN];
ll ans[MAXN];
int mx[MAXN * 4];
ll mn[MAXN * 4];
ll dd[MAXN * 4];

void build(int v, int tl, int tr) {
	mn[v] = 1e9 + 100;
	mx[v] = -1;
	dd[v] = 1e9 + 100;
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
}

int getmx(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return -1;
	if (l <= tl && tr <= r)
		return mx[v];
	int m = (tl + tr) >> 1;
	return max(getmx(v * 2 + 1, tl, m, l, r), getmx(v * 2 + 2, m, tr, l, r));
}

ll get(int v, int tl, int tr, int x) {
	if (tl + 1 == tr)
		return mn[v];
	int m = (tl + tr) >> 1;
	if (x < m)
		return min(get(v * 2 + 1, tl, m, x), dd[v]);
	else
		return min(get(v * 2 + 2, m, tr, x), dd[v]);
}

void updmn(int v, int tl, int tr, int l, int r, ll x) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		dd[v] = min(dd[v], x);
		mn[v] = min(mn[v], x);
		return;
	}
	int m = (tl + tr) >> 1;
	updmn(v * 2 + 1, tl, m, l, r, x);
	updmn(v * 2 + 2, m, tr, l, r, x);
	mn[v] = min(mn[v * 2 + 1], mn[v * 2 + 2]);
	mn[v] = min(mn[v], dd[v]);
}

void updmx(int v, int tl, int tr, int x, int y) {
	mx[v] = max(mx[v], y);
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	if (x < m)
		updmx(v * 2 + 1, tl, m, x, y);
	else
		updmx(v * 2 + 2, m, tr, x, y);
}

int m;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i), vv.push_back(make_pair(a[i], i));
	sort(vv.begin(), vv.end());
	scanf("%d", &m);
	for (int i = 0; i < m; ++i) {
		int l, r;
		scanf("%d%d", &l, &r);
		--l, --r;
		go[r].push_back(make_pair(l, i));
	}
	build(0, 0, n);
	for (int i = 0; i < n; ++i) {
		int pl = lower_bound(vv.begin(), vv.end(), make_pair(a[i], i)) - vv.begin();
		ll now = 1e9 + 100;
		while (true) {
			int x = lower_bound(vv.begin(), vv.end(), make_pair(a[i] + now + 1, 0)) - vv.begin();
			if (pl + 1 >= x)
				break;
			x = getmx(0, 0, n, pl + 1, x);
			if (x == -1)
				break;
			ll d = a[x] - a[i];
			updmn(0, 0, n, 0, x + 1, d);
			if (d == 0)
				break;
			now = d / 2;
		}
		now = 1e9 + 100;
		while (true) {
			int x = lower_bound(vv.begin(), vv.end(), make_pair(a[i] - now, 0)) - vv.begin();
			if (x >= pl)
				break;
			x = getmx(0, 0, n, x, pl);
			if (x == -1)
				break;
			ll d = a[i] - a[x];
			updmn(0, 0, n, 0, x + 1, d);
			if (d == 0)
				break;
			now = d / 2;
		}
		updmx(0, 0, n, pl, i);
		for (auto q: go[i]) {
			ans[q.second] = get(0, 0, n, q.first);
		}
	}
	for (int i = 0; i < m; ++i)
		printf("%lld\n", ans[i]);
	return 0;
}