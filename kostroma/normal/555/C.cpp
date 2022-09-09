#pragma comment (linker, "/STACK:128000000")
#define _CRT_SECURE_NO_WARNINGS
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
#include <deque>
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

bool todo = true;

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

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;

int powers[2][C];*/

int MOD = 1000000007;

//int c[5010][5010];

//int catalan[200500];

//ld doubleC[100][100];

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

void precalc() {

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/

	/*catalan[0] = 1;
	for (int n = 0; n < 200500 - 1; ++n) {
		catalan[n + 1] = catalan[n] * 2 * (2 * n + 1) % MOD * binpow(n + 2, MOD - 2, MOD) % MOD;
	}*/

	/*for (int i = 0; i < 5010; ++i) {
		c[i][i] = c[i][0] = 1;
		for (int j = 1; j < i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}*/

	/*for (int i = 0; i < 100; ++i) {
		doubleC[i][i] = doubleC[i][0] = 1.0;
		for (int j = 1; j < i; ++j) {
			doubleC[i][j] = doubleC[i - 1][j - 1] + doubleC[i - 1][j];
		}
	}*/
}


int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//#define int li

//int mod = 1000000007;

struct node {
	int val;
	int settedVal;
	node() :val(0), settedVal(-1) {}
	node(int val) :val(val), settedVal(-1) {}
};

const int shift = 1 << 18;

node tree[2][2 * shift + 5];

int getId(int id, int v) {
	v += shift;
	int val = max(tree[id][v].val, tree[id][v].settedVal);
	while (v > 0) {
		if (tree[id][v].settedVal != -1) {
			val = max(tree[id][v].settedVal, val);
		}
		v /= 2;
	}
	return val;
}

void modify(int id, int l, int r, int val) {
	if (l >= r)
		return;
	if (l & 1) {
		tree[id][l].settedVal = max(val, tree[id][l].settedVal);
		modify(id, l + 1, r, val);
		return;
	}
	if (r & 1) {
		tree[id][r - 1].settedVal = max(val, tree[id][r - 1].settedVal);
		modify(id, l, r - 1, val);
		return;
	}
	modify(id, l / 2, r / 2, val);
}

void update(int id, int l, int r, int val) {
	l += shift;
	r += shift;
	modify(id, l, r, val);
}

void solve() {
	int n;
	cin >> n;
	int Q;
	cin >> Q;
	vector<pair<pair<int, int>, char>> q(Q);

	vector<int> coords[2];

	for (int i = 0; i < Q; ++i) {
		int x, y;
		cin >> x >> y;
		char c;
		cin >> c;

		q[i] = mp(mp(x, y), c);

		coords[0].push_back(x);
		coords[1].push_back(y);

		/*if (c == 'L') {
			int res = x;
			res -= treeX.query(x + 1);
			
			treeY.insert(y);
			sum += res;
			cout << res << "\n";
		}
		else {
			int res = y;
			res -= treeY.query(y + 1);
			
			treeX.insert(x);
			sum += res;
			cout << res << "\n";
		}*/
	}

	for (int w = 0; w < 2; ++w) {
		sort(all(coords[w]));
		coords[w].erase(unique(all(coords[w])), coords[w].end());
	}

	set<pair<int, int>> gone;

	for (auto item : q) {
		int x = item.first.first, y = item.first.second;
		if (gone.count(mp(x, y))) {
			cout << "0\n";
			continue;
		}
		gone.insert(mp(x, y));
		if (item.second == 'L') {
			int prevX = getId(1, lower_bound(all(coords[1]), y) - coords[1].begin());
			cout << x - prevX << "\n";
			int L = lower_bound(all(coords[0]), prevX) - coords[0].begin();
			int R = lower_bound(all(coords[0]), x) - coords[0].begin();
			update(0, L, R, y);
		}
		else {
			int prevY = getId(0, lower_bound(all(coords[0]), x) - coords[0].begin());
			cout << y - prevY << "\n";
			int L = lower_bound(all(coords[1]), prevY) - coords[1].begin();
			int R = lower_bound(all(coords[1]), y) - coords[1].begin();
			update(1, L, R, x);
		}
	}

}