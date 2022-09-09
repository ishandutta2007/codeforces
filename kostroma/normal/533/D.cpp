
#pragma comment (linker, "/STACK:128000000")
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

bool doing = true;

int main() {
#ifdef room111
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
	int testNum = 1;
	while (t--) {
		//cout << "Case #" << testNum++ << ": ";
		solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

void precalc() {
}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

#define int li

const int INF = 100100000000;

struct treap{
	typedef struct _node{
		int key;
		int prior;
		int cnt;
		_node* l;
		_node* r;
		int val;
		int mx;
		_node(int key, int val) :key(key), val(val), mx(mx) { prior = (rand() << 16) | rand(); l = 0; r = 0; cnt = 1; }
		void recalc() {
			mx = val;
			if (l) {
				mx = max(mx, l->mx);
			}
			if (r) {
				mx = max(mx, r->mx);
			}
			cnt = 1 + Cnt(l) + Cnt(r);
		}
	}*node;

	static int Cnt(node v) {
		if (!v)
			return 0;
		return v->cnt;
	}

	node root;

	size_t Size;

	node merge(node l, node r) {
		if (!l)
			return r;
		if (!r)
			return l;
		if (l->prior < r->prior) {
			l->r = merge(l->r, r);
			l->recalc();
			return l;
		}
		else {
			r->l = merge(l, r->l);
			r->recalc();
			return r;
		}
	}

	void split(node v, int key, node& l, node& r) {
		l = r = 0;
		if (!v)
			return;
		if (v->key < key) {
			l = v;
			split(l->r, key, l->r, r);
			l->recalc();
		}
		else {
			r = v;
			split(r->l, key, l, r->l);
			r->recalc();
		}
	}

	treap() {
		root = 0;
	}

	void insert(int key, int val) {
		node l, r;
		split(root, key, l, r);
		root = merge(l, merge(new _node(key, val), r));
	}

	int getVal(int key) {
		node l, r;
		split(root, key, l, r);
		int res = Cnt(r);
		root = merge(l, r);
		return res;
	}

	int getMax(int L) {
		node l, r;
		split(root, L, l, r);
		int res = r ? r->mx : -INF;
		root = merge(l, r);
		return res;
	}

};

void solve() {
	int n;
	cin >> n;
	n += 2;
	vector<int> x(n), d(n);
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	for (int i = 1; i + 1 < n; ++i) {
		cin >> d[i];
	}
	d[0] = d[n - 1] = INF;
	int len = x[n - 1];

	vector<int> borders[2];

	for (int w = 0; w < 2; ++w) {
		treap dps;
		dps.insert(0, INF);
		vector<int> rightBorder(n);
		rightBorder[0] = INF;

		for (int i = 1; i < n; ++i) {
			int l = 0;
			int r = i;
			while (l + 1 < r) {
				int m = (l + r) / 2;
				if (dps.getMax(x[m]) >= x[i]) {
					l = m;
				}
				else {
					r = m;
				}
			}
			rightBorder[i] = 2 * d[i] - (x[i] - x[l]) + x[i];
			if (rightBorder[i] <= x[i]) {
				rightBorder[i] = -INF;
			}
			else {
				dps.insert(x[i], rightBorder[i]);
			}
		}


		reverse(all(d));
		reverse(all(x));
		for (int i = 0; i < n; ++i) {
			x[i] = len - x[i];
		}
		if (w) {
			reverse(all(rightBorder));
			for (int i = 0; i < n; ++i) {
				rightBorder[i] = len - rightBorder[i];
			}
		}
		borders[w] = rightBorder;
	}

	int ans = INF;

	treap dp;
	for (int i = 0; i < n; ++i) {
		if (i > 0 && borders[1][i] <= x[i]) {
			int l = 0;
			int r = i;
			while (l + 1 < r) {
				int m = (l + r) / 2;
				if (dp.getMax(x[m]) >= borders[1][i]) {
					l = m;
				}
				else {
					r = m;
				}
			}

			if (x[l] >= borders[1][i] && x[i] <= borders[0][l] && (i != n - 1 || l != 0)) {
				//cout << l << ' ' << i << "\n";
				ans = 0;
			}
			else {
				if (borders[1][i] <= borders[0][l]) {
					ans = min(ans, x[i] - x[l]);
					/*if (x[i] - x[l] == 2) {
						cout << l << ' ' << i << "\n";
					}*/
				}
			}

		}

		if (borders[0][i] >= x[i]) {
			dp.insert(x[i], borders[0][i]);
		}
	}

	double res = ans / 2.0;
	cout << res << "\n";
}