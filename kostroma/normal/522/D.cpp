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
	//freopen("c3.out", "w", stdout);
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
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
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

int n, m;

vector<int> a;

struct Query {
	int l, r;
	int id;
	Query() {}
	void scan() {
		cin >> l >> r;
		--l;
		--r;
	}
};

vector<vector<Query>> queries;

vector<int> previous;

const int shift = 1 << 19;

vector<int> tree(2 * shift + 5);

void modify(int v, int val) {
	v += shift;
	tree[v] = min(tree[v], val);
	v /= 2;
	while (v > 0) {
		tree[v] = min(tree[2 * v], tree[2 * v + 1]);
		v /= 2;
	}
}

int rmq(int l, int r) {
	if (l >= r)
		return 1e9;
	if (l & 1) {
		return min(tree[l], rmq(l + 1, r));
	}
	if (r & 1) {
		return min(tree[r - 1], rmq(l, r - 1));
	}
	return rmq(l / 2, r / 2);
}

int getRmq(int l, int r) {
	return rmq(l + shift, r + shift);
}

void solve() {
	cin >> n >> m;
	vector<int> nums;
	a.resize(n);
	queries.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		nums.push_back(a[i]);
	}

	sort(all(nums));
	nums.erase(unique(all(nums)), nums.end());

	vector<int> last(nums.size(), -1);

	previous.resize(n);
	for (int i = 0; i < n; ++i) {
		int curId = lower_bound(all(nums), a[i]) - nums.begin();
		previous[i] = last[curId];
		last[curId] = i;
	}

	for (int i = 0; i < m; ++i) {
		Query cur;
		cur.scan();
		cur.id = i;
		queries[cur.r].push_back(cur);
	}

	vector<int> res(m);

	for (int i = 1; i < shift + n; ++i) {
		tree[i] = 1e9;
	}

	for (int i = 0; i < n; ++i) {
		if (previous[i] != -1) {
			modify(previous[i], i - previous[i]);
		}

		for (Query& item : queries[i]) {
			res[item.id] = getRmq(item.l, item.r + 1);
		}

	}

	for (int i = 0; i < m; ++i) {
		if (res[i] > n)
			res[i] = -1;
		cout << res[i] << "\n";
	}

}