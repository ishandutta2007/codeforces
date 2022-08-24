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

const int MAXN = 31000;
const int SQ = 250;
const int SZ = 40000;

int n, m;

int fb5[SZ * 2];
int *fb;
vector<int> vv;

int ad[MAXN * 4];
pair<int, int> rmq[MAXN * 4];

int a[MAXN];
int ql[MAXN];
int qr[MAXN];
set<int> ss;
map<int, int> mm;
vector<pair<int, int> > qu;
int q;
map<pair<int, int>, int> ans;

bool cmp(pair<int, int> a, pair<int, int> b) {
	return make_pair(a.first / SQ, a.second) < make_pair(b.first / SQ, b.second);
}

int df(int l, int r, int nl, int nr) {
	return abs(l - nl) + abs(r - nr);
}

int nm(int a) {
	return (a >= m ? a - m : a);
}

pair<int, int> operator+(pair<int, int> a, pair<int, int> b) {
	return make_pair(nm(a.first + b.first), nm(a.second + b.second));
}

inline void mlt(pair<int, int> &a, int b) {
	a = make_pair((fb[b - 1] * a.first + fb[b] * a.second) % m, (fb[b] * a.first + fb[b + 1] * a.second) % m);
}

void mult(int v, int tl, int tr, int l, int r, int d) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		ad[v] += d;
		if (d == 1)
			rmq[v] = make_pair(rmq[v].second, nm(rmq[v].first + rmq[v].second));
		else
			rmq[v] = make_pair(nm(m + rmq[v].second - rmq[v].first), rmq[v].first);
		return;
	}
	int mid = (tl + tr) >> 1;
	mult(v * 2 + 1, tl, mid, l, r, d);
	mult(v * 2 + 2, mid, tr, l, r, d);
	rmq[v] = rmq[v * 2 + 1] + rmq[v * 2 + 2];
	if (ad[v])
		mlt(rmq[v], ad[v]);
}

void upd(int v, int tl, int tr, int x, pair<int, int> y) {
	if (tl + 1 == tr) {
		rmq[v] = y;
		mlt(rmq[v], ad[v]);
		return;
	}
	int mid = (tl + tr) >> 1;
	if (x < mid)
		upd(v * 2 + 1, tl, mid, x, y);
	else
		upd(v * 2 + 2, mid, tr, x, y);
	rmq[v] = rmq[v * 2 + 1] + rmq[v * 2 + 2];
	if (ad[v])
		mlt(rmq[v], ad[v]);
}

void add(int x) {
	int p = lower_bound(vv.begin(), vv.end(), x) - vv.begin();
	mult(0, 0, (int)vv.size(), p + 1, (int)vv.size(), 1);
	pair<int, int> go = make_pair(x % m, x % m);
	upd(0, 0, (int)vv.size(), p, go);
}

void del(int x) {
	int p = lower_bound(vv.begin(), vv.end(), x) - vv.begin();
	mult(0, 0, (int)vv.size(), p + 1, (int)vv.size(), -1);
	upd(0, 0, (int)vv.size(), p, make_pair(0, 0));
}

int main() {
	fb = fb5 + SZ;
	scanf("%d%d", &n, &m);
	fb[0] = 0;
	fb[1] = 1;
	for (int i = 2; i < SZ; ++i)
		fb[i] = (fb[i - 2] + fb[i - 1]) % m;
	for (int i = -1; i >= -SZ; --i)
		fb[i] = (fb[i + 2] - fb[i + 1] + m) % m;
	for (int i = 0; i < n; ++i)
		scanf("%d", a + i), vv.push_back(a[i]);
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%d%d", ql + i, qr + i);
		--ql[i];
		--qr[i];
		qu.push_back(make_pair(ql[i], qr[i]));
	}
	sort(qu.begin(), qu.end());
	qu.resize(unique(qu.begin(), qu.end()) - qu.begin());
	sort(qu.begin(), qu.end(), cmp);
	int l = -1;
	int r = -1;
	for (int i = 0; i < (int)qu.size(); ++i) {
		int nl = qu[i].first;
		int nr = qu[i].second;
		if (l == -1 || df(l, r, nl, nr) >= r - l + 1 + nr - nl + 1) {
			if (l != -1) {
				for (int j = l; j <= r; ++j) {
					int nw = --mm[a[j]];
					if (nw == 0)
						del(a[j]);
				}
			}
			mm.clear();
			for (int j = nl; j <= nr; ++j) {
				++mm[a[j]];
				if (mm[a[j]] == 1)
					add(a[j]);
			}
		}
		else {
			while (r < nr) {
				++r;
				int nw = ++mm[a[r]];
				if (nw == 1)
					add(a[r]);
			}
			while (l > nl) {
				--l;
				int nw = ++mm[a[l]];
				if (nw == 1)
					add(a[l]);
			}
			while (r > nr) {
				int nw = --mm[a[r]];
				if (nw == 0)
					del(a[r]);
				--r;
			}
			while (l < nl) {
				int nw = --mm[a[l]];
				if (nw == 0)
					del(a[l]);
				++l;
			}
		}
		ll sum = rmq[0].first % m;
		ans[make_pair(nl, nr)] = sum;
		l = nl;
		r = nr;
	}
	for (int i = 0; i < q; ++i)
		printf("%d\n", ans[make_pair(ql[i], qr[i])]);
	return 0;
}