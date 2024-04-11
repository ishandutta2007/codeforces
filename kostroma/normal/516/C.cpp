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

//int mod = 1000000007;

//#define int li

int n;

const int shift = 1 << 18;

struct vertex {
	li maxSegment, maxPref, maxSuff, sum;
	vertex():maxSegment(0), maxPref(0), maxSuff(0), sum(0) {}
	vertex(li maxSegment, li maxPref, li maxSuff, li sum) :maxSegment(maxSegment), maxPref(maxPref), maxSuff(maxSuff), sum(sum) {}
};

vertex merge(const vertex& l, const vertex& r, li middle) {
	vertex res;
	if (l.maxPref == 0) {
		res = r;
		return res;
	}
	if (r.maxPref == 0) {
		res = l;
		return res;
	}
	res.sum = l.sum + r.sum + middle;
	res.maxSegment = max(l.maxSegment, r.maxSegment);
	res.maxPref = max(l.maxPref, r.maxPref + middle + l.sum);
	res.maxSuff = max(r.maxSuff, l.maxSuff + middle + r.sum);

	res.maxSegment = max(res.maxSegment, l.maxSuff + r.maxPref + middle);
	return res;
}

vertex tree[2 * shift + 5];

int h[100500], d[100500];

void build(int v, int l, int r) {
	if (l + 1 == r) {
		tree[v] = vertex(0, 2 * h[l], 2 * h[l], 0);
		return;
	}

	int m = (l + r) / 2;

	build(2 * v, l, m);
	build(2 * v + 1, m, r);
	tree[v] = merge(tree[2 * v], tree[2 * v + 1], d[m - 1]);
}

vertex rmq(int v, int l, int r, int ql, int qr) {
	if (l >= qr || r <= ql)
		return vertex();
	if (ql <= l && r <= qr) {
		return tree[v];
	}

	int m = (l + r) / 2;
	return merge(rmq(2 * v, l, m, ql, qr), rmq(2 * v + 1, m, r, ql, qr), d[m - 1]);
}

void solve() {
	int Q;
	cin >> n >> Q;
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> h[i];
	}

	build(1, 0, n);

	for (int it = 0; it < Q; ++it) {
		int a, b;
		cin >> a >> b;
		--a;
		swap(a, b);
		vertex res;
		if (a <= b) {
			res = rmq(1, 0, n, a, b);
		}
		else {
			res = merge(rmq(1, 0, n, a, n), rmq(1, 0, n, 0, b), d[n - 1]);
		}
		cout << res.maxSegment << "\n";
	}


}