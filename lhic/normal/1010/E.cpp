#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/
const int MAXN = 120000;

set<int> rmq[MAXN * 4];

vector<tuple<int, int, int, int> > vvl, vvr;
int xm, ym, zm;

void clear(int v, int tl, int tr) {
	rmq[v].clear();
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	clear(v * 2 + 1, tl, m);
	clear(v * 2 + 2, m, tr);
}

void clear() {
	clear(0, 0, ym);
}

void add(int v, int tl, int tr, int x, int y) {
	rmq[v].insert(y);
	if (tl + 1 == tr)
		return;
	int m = (tl + tr) >> 1;
	if (x < m)
		add(v * 2 + 1, tl, m, x, y);
	else
		add(v * 2 + 2, m, tr, x, y);
}

void add(int x, int y) {
	add(0, 0, ym, x, y);
}


int get(int v, int tl, int tr, int l, int r, int l1, int r1) {
	if (r <= tl || tr <= l)
		return 0;
	if (l <= tl && tr <= r) {
		auto it = rmq[v].lower_bound(l1);
		if (it != rmq[v].end() && *it < r1)
			return 1;
		return 0;
	}
	int m = (tl + tr) >> 1;
	return get(v * 2 + 1, tl, m, l, r, l1, r1) || get(v * 2 + 2, m, tr, l, r, l1, r1);
}

int get(int lx, int rx, int ly, int ry) {
	if (rx < lx)
		swap(lx, rx);
	++rx;
	if (ly > ry)
		swap(ly, ry);
	++ry;
	return get(0, 0, ym, lx, rx, ly, ry);
}

int n, m, k;
int ans[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> xm >> ym >> zm;
	++xm, ++ym, ++zm;
	cin >> n >> m >> k;
	int lx, rx, ly, ry, lz, rz;
	cin >> lx >> ly >> lz;
	rx = lx;
	ry = ly;
	rz = lz;
	for (int i = 1; i < n; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		lx = min(lx, x);
		rx = max(rx, x);
		ly = min(ly, y);
		ry = max(ry, y);
		lz = min(lz, z);
		rz = max(rz, z);
	}
	for (int i = 0; i < m; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		if (lx <= x && x <= rx)
			x = lx;
		if (ly <= y && y <= ry)
			y = ly;
		if (lz <= z && z <= rz)
			z = lz;
		if (lx == x && ly == y && lz == z) {
			cout << "INCORRECT\n";
			return 0;
		}
		if (x < lx) {
			vvl.emplace_back(-x, -1, y, z);
		}
		else {
			if (x == lx)
				vvl.emplace_back(-lx, -1, y, z);
			vvr.emplace_back(x, -1, y, z);
		}
	}
	cout << "CORRECT\n";
	for (int i = 0; i < k; ++i) {
		int x, y, z;
		cin >> x >> y >> z;
		if (lx <= x && x <= rx && ly <= y && y <= ry && lz <= z && z <= rz) {
			ans[i] = 2;
			continue;
		}
		if (x < lx) {
			vvl.emplace_back(-x, i, y, z);
		}
		else {
			vvr.emplace_back(x, i, y, z);
		}
	}
	sort(vvl.begin(), vvl.end());
	clear();
	for (int i = 0; i < vvl.size(); ++i) {
		int x, y, z, t;
		tie(x, t, y, z) = vvl[i];
		if (t == -1) {
			add(y, z);
		}
		else {
			if (get(ly, y, lz, z)) {
				ans[t] = 1;
			}
		}
	}
	sort(vvr.begin(), vvr.end());
	clear();
	for (int i = 0; i < vvr.size(); ++i) {
		int x, y, z, t;
		tie(x, t, y, z) = vvr[i];
		if (t == -1) {
			add(y, z);
		}
		else {
			if (get(ly, y, lz, z)) {
				ans[t] = 1;
			}
		}
	}
	for (int i = 0; i < k; ++i) {
		if (ans[i] == 2)
			cout << "OPEN\n";
		else if (ans[i] == 1)
			cout << "CLOSED\n";
		else
			cout << "UNKNOWN\n";
	}
	return 0;
}