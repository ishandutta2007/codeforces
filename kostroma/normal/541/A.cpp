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

struct Segment {
	int l, r, c;
	int id;
	Segment() {}
	Segment(int l, int r, int c, int id) :l(l), r(r), c(c), id(id) {}
	void scan() {
		cin >> l >> r;
	}
	bool operator < (const Segment& other) const {
		return mp(l, -r) < mp(other.l, -other.r);
	}
};

const int shift = 1 << 18;

int tree[2 * shift + 5];

int bestId[2 * shift + 5];

pair<int, int> merge(pair<int, int> q, pair<int, int> w) {
	pair<int, int> res = q;
	if (w.first > res.first) {
		res = w;
	}
	return res;
}

void modify(int v, int val, int id) {
	v += shift;
	tree[v] = val;
	bestId[v] = id;
	v /= 2;
	while (v > 0) {
		auto cur = merge(mp(tree[2 * v], bestId[2 * v]), mp(tree[2 * v + 1], bestId[2 * v + 1]));
		tree[v] = cur.first;
		bestId[v] = cur.second;
		v /= 2;
	}
}

pair<int, int> rmq(int l, int r) {
	if (l >= r)
		return mp(0, -1);
	if (l & 1) {
		return merge(mp(tree[l], bestId[l]), rmq(l + 1, r));
	}
	if (r & 1) {
		return merge(rmq(l, r - 1), mp(tree[r - 1], bestId[r - 1]));
	}
	return rmq(l / 2, r / 2);
}

pair<int, int> getSum(int l, int r) {
	return rmq(l + shift, r + shift);
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<Segment> small(n);
	for (int i = 0; i < n; ++i) {
		small[i].scan();
		small[i].c = 1;
		small[i].id = i;
	}

	sort(all(small));

	vector<Segment> big(m);
	for (int i = 0; i < m; ++i) {
		big[i].scan();
		cin >> big[i].c;
		big[i].id = i;
	}

	vector<Segment> newSmall;
	for (int i = 0; i < n; ) {
		int j = i + 1;
		while (j < n && small[j].r <= small[i].r) {
			++j;
		}
		newSmall.push_back(small[i]);
		i = j;
	}

	newSmall.swap(small);
	n = small.size();

	vector<int> lefts, rights;

	for (int i = 0; i < n; ++i) {
		modify(i, small[i].r - small[i].l, small[i].id);
		lefts.push_back(small[i].l);
		rights.push_back(small[i].r);
	}

	int res = 0;
	int firstId = -1, secondId = -1;

	for (int i = 0; i < m; ++i) {
		int leftId = upper_bound(all(lefts), big[i].l) - lefts.begin();
		--leftId;
		if (leftId >= 0) {
			int cur = min(small[leftId].r, big[i].r) - big[i].l;
			if (cur * big[i].c > res) {
				res = cur * big[i].c;
				firstId = small[leftId].id;
				secondId = big[i].id;
			}
		}
		
		++leftId;
		int rightId = upper_bound(all(rights), big[i].r) - rights.begin();
		auto cur = getSum(leftId, rightId);
		if (cur.first * big[i].c > res) {
			res = cur.first * big[i].c;
			firstId = cur.second;
			secondId = big[i].id;
		}

		if (rightId < n) {
			int cur = big[i].r - max(big[i].l, small[rightId].l);
			if (cur * big[i].c > res) {
				res = cur * big[i].c;
				firstId = small[rightId].id;
				secondId = big[i].id;
			}
		}

	}

	cout << res << "\n";

	if (res > 0) {
		cout << firstId + 1 << ' ' << secondId + 1 << "\n";
	}

}