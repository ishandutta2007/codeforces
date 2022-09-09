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

struct Query {
	vector<int> x, y;
	int id;
	Query() {}
	void scan() {
		x.resize(2);
		y.resize(2);
		cin >> x[0] >> y[0] >> x[1] >> y[1];
		--x[0];
		--y[0];
	}
};

const int shift = 1 << 17;

int tree[2 * shift + 7];

void modify(int v, int val) {
	v += shift;
	tree[v] = val;
	v /= 2;
	while (v > 0) {
		tree[v] = max(tree[2 * v], tree[2 * v + 1]);
		v /= 2;
	}
}

int getRmq(int l, int r) {
	if (l >= r) {
		return 0;
	}
	if (l & 1) {
		return max(tree[l], getRmq(l + 1, r));
	}
	if (r & 1) {
		return max(tree[r - 1], getRmq(l, r - 1));
	}
	return getRmq(l / 2, r / 2);
}

int getMax(int l, int r) {
	return getRmq(l + shift, r + shift);
}

void solve() {
	int n, m, k;
	int q;
	cin >> n >> m >> k >> q;
	vector<pair<int, int>> points(k);
	for (int i = 0; i < k; ++i) {
		cin >> points[i].first >> points[i].second;
		--points[i].first;
		--points[i].second;
	}
	vector<Query> queries(q);
	for (int i = 0; i < q; ++i) {
		queries[i].scan();
		queries[i].id = i;
	}

	vector<int> res(q, 0);

	for (int w = 0; w < 2; ++w) {

		vector<vector<int>> figures(m);
		for (int i = 0; i < k; ++i) {
			figures[points[i].second].push_back(points[i].first);
		}
		for (int i = 0; i < m; ++i) {
			sort(all(figures[i]));
		}
		vector<int> uk(m, 0);

		vector<vector<int>> events(n);
		for (int i = 0; i < k; ++i) {
			events[points[i].first].push_back(points[i].second);
		}

		vector<vector<int>> sortedQ(n);
		for (int i = 0; i < q; ++i) {
			sortedQ[queries[i].x[0]].push_back(i);
		}

		for (int i = 0; i < m; ++i) {
			if (figures[i].empty()) {
				tree[i + shift] = n + 5;
			}
			else {
				tree[i + shift] = figures[i][0];
			}
		}
		for (int i = shift - 1; i >= 0; --i) {
			tree[i] = max(tree[2 * i], tree[2 * i + 1]);
		}

		for (int i = 0; i < n; ++i) {
			for (int queryId : sortedQ[i]) {
				auto& curQuery = queries[queryId];
				int mx = getMax(curQuery.y[0], curQuery.y[1]);
				if (mx < curQuery.x[1]) {
					res[curQuery.id] = 1;
				}
			}

			for (int cur : events[i]) {
				int newVal = n + 5;
				++uk[cur];
				if (uk[cur] < figures[cur].size()) {
					newVal = figures[cur][uk[cur]];
				}
				modify(cur, newVal);
			}

		}


		swap(n, m);
		for (int i = 0; i < k; ++i) {
			swap(points[i].first, points[i].second);
		}
		for (int i = 0; i < q; ++i) {
			swap(queries[i].x, queries[i].y);
		}
	}

	for (int i = 0; i < q; ++i) {
		if (res[i]) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}


}