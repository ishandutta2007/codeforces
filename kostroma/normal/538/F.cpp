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

//#define int li

vector<int> a;

struct Query {
	int k;
	int l, r;
	int id;
	Query(int k, int l, int r, int id):k(k), l(l), r(r), id(id) {}
	bool operator < (const Query& other) const {
		if (a[id] != a[other.id])
			return a[id] < a[other.id];
		return k > other.k;
	}
};

const int shift = 1 << 18;

int tree[2 * shift + 5];

void modify(int v, int val) {
	v += shift;
	tree[v] += val;
	v /= 2;
	while (v > 0) {
		tree[v] = tree[2 * v] + tree[2 * v + 1];
		v /= 2;
	}
}

int rsq(int l, int r) {
	if (l >= r)
		return 0;
	if (l & 1)
		return tree[l] + rsq(l + 1, r);
	if (r & 1)
		return rsq(l, r - 1) + tree[r - 1];
	return rsq(l / 2, r / 2);
}

int getSum(int l, int r) {
	return rsq(l + shift, r + shift);
}

void solve() {
	
	int n;
	cin >> n;
	a.resize(n);
	vector<int> coords;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		//a[i] = (rand() << 16) | rand();
		coords.push_back(a[i]);
	}
	sort(all(coords));
	coords.erase(unique(all(coords)), coords.end());

	for (int i = 0; i < n; ++i) {
		a[i] = lower_bound(all(coords), a[i]) - coords.begin();
	}

	vector<int> res(n);
	int MAGIC = (int)sqrt(n * log2(n * 1.0)) + 1;

	for (int k = 1; k < MAGIC; ++k) {
		for (int i = 1; i < n; ++i) {
			int prev = (i - 1) / k;
			if (a[prev] > a[i]) {
				++res[k];
			}
		}
	}

	vector<Query> vals;

	for (int k = MAGIC; k < n; ++k) {
		vals.push_back(Query(k, 1, k + 1, 0));
		for (int i = 1; i <= k; ++i) {
			if (i * k + 1 < n) {
				vals.push_back(Query(k, i * k + 1, min((i + 1) * k + 1, n), i));
			}
			else {
				break;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		vals.push_back(Query(-1, -1, -1, i));
	}

	sort(all(vals));


	for (auto item : vals) {
		if (item.k == -1) {
			modify(item.id, 1);
		}
		else {
			res[item.k] += getSum(item.l, item.r);
		}
	}

	for (int k = 1; k < n; ++k) {
		cout << res[k] << ' ';
	}


}