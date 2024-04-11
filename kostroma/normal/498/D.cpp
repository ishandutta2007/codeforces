//#pragma comment (linker, "/STACK:128000000")
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
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
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

#define int li

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

//int mod = 1000000007;

//ld eps = 1e-9;

int n;

int a[100500];

const int mod = 60;

const int shift = 1 << 17;

struct vertex {
	vector<int> minTime;
	vertex() {
		minTime.assign(mod, 0);
	}
	vertex(int period) {
		minTime.assign(mod, 0);
		for (int i = 0; i < mod; ++i) {
			minTime[i] = 1;
			if (i % period == 0)
				minTime[i] = 2;
		}
	}
};

vertex merge(const vertex& l, const vertex& r) {
	vertex res;
	for (int i = 0; i < mod; ++i) {
		int cur = (l.minTime[i] + i) % mod;
		res.minTime[i] = l.minTime[i] + r.minTime[cur];
	}
	return res;
}

vertex tree[2 * shift + 5];

void modify(int l, int val) {
	tree[l] = vertex(val);
	l /= 2;
	while (l > 0) {
		tree[l] = merge(tree[2 * l], tree[2 * l + 1]);
		l /= 2;
	}
}

vertex rmq(int l, int r) {
	if (l > r)
		return vertex();
	if (l & 1) {
		return merge(tree[l], rmq(l + 1, r));
	}
	if (!(r & 1)) {
		return merge(rmq(l, r - 1), tree[r]);
	}
	return rmq(l / 2, r / 2);
}

int ask(int l, int r) {
	return rmq(l, r).minTime[0];
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n; ++i) {
		tree[shift + i] = vertex(a[i]);
	}
	for (int i = shift - 1; i >= 0; --i) {
		tree[i] = merge(tree[2 * i], tree[2 * i + 1]);
	}

	int Q;
	cin >> Q;
	for (int w = 0; w < Q; ++w) {
		char c;
		cin >> c;
		if (c == 'A') {
			int x, y;
			cin >> x >> y;
			--x; --y;
			int res = ask(x + shift, y - 1 + shift);
			cout << res << "\n";
		}
		else {
			int x, y;
			cin >> x >> y;
			--x;
			a[x] = y;
			modify(x + shift, y);
		}
	}

}