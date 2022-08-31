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
const ll MOD = 1e9 + 7;

ll h;
int w, n;

vector<tuple<int, int, int, ll> > vv;

set<tuple<int, int, ll> > ss[MAXN * 4];
vector<tuple<int, int, ll> > vd;

void add(int v, int tl, int tr, int x, int y, ll cnt) {
	ss[v].insert(make_tuple(y, x, cnt));
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	if (x < m)
		add(v * 2 + 1, tl, m, x, y, cnt);
	else
		add(v * 2 + 2, m, tr, x, y, cnt);
}

void get(int v, int tl, int tr, int l, int r, int h) {
	if (tr <= l || r <= tl)
		return;
	if (l <= tl && tr <= r) {
		while (!ss[v].empty() && get<0>(*ss[v].begin()) <= h) {
			vd.push_back(*ss[v].begin());
			ss[v].erase(ss[v].begin());
		}
		return;
	}
	int m = (tl + tr) >> 1;
	get(v * 2 + 1, tl, m, l, r, h);
	get(v * 2 + 2, m, tr, l, r, h);
}

void del(int v, int tl, int tr, tuple<int, int, ll> dl) {
	ss[v].erase(dl);
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	if (get<1>(dl) < m)
		del(v * 2 + 1, tl, m, dl);
	else
		del(v * 2 + 2, m, tr, dl);
}


int main() {
	scanf("%lld%d%d", &h, &w, &n);
	for (int i = 0; i < n; ++i) {
		int l, r;
		ll u, s;
		scanf("%lld%d%d%lld", &u, &l, &r, &s);
		--l, --r;
		vv.push_back(make_tuple(u, l, r, s));
	}
	sort(vv.begin(), vv.end());
	reverse(vv.begin(), vv.end());
	for (int i = 0; i < w; ++i)
		add(0, 0, w, i, h + 1, 1);
	for (int i = 0; i < vv.size(); ++i) {
		ll u, s;
		int l, r;
		tie(u, l, r, s) = vv[i];
		ll rh = u + s;
		vd.clear();
		get(0, 0, w, l, r + 1, rh);
		ll now = 0;
		for (int j = 0; j < vd.size(); ++j)
			now += get<2>(vd[j]), del(0, 0, w, vd[j]), now %= MOD;
		if (l == 0) {
			add(0, 0, w, r + 1, u, (2 * now) % MOD);
		}
		else if (r == w - 1) {
			add(0, 0, w, l - 1, u, (2 * now) % MOD);
		}
		else {
			add(0, 0, w, r + 1, u, now);
			add(0, 0, w, l - 1, u, now);
		}
	}
	ll ans = 0;
	for (auto x: ss[0]) {
		ans += get<2>(x);
		ans %= MOD;
	}
	cout << ans << "\n";
	return 0;
}