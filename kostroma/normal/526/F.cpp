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

//int mod = 1000000007;

//#define int li

struct treap{
	typedef struct _node{
		int key;
		int prior;
		int cnt;
		_node* l;
		_node* r;
		_node(int key) :key(key) { prior = (rand() << 16) | rand(); l = 0; r = 0; cnt = 1; }
		void recalc() {
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

	void insert(int key) {
		node l, r;
		split(root, key, l, r);
		root = merge(l, merge(new _node(key), r));
	}

	int getVal(int key) {
		node l, r;
		split(root, key, l, r);
		int res = Cnt(r);
		root = merge(l, r);
		return res;
	}

};

li solve(vector<int>& points) {
	if (points.empty()) {
		return 0;
	}
	if (points.size() == 1) {
		return 1;
	}

	int M = points.size() / 2;
	auto first = vector<int>(points.begin(), points.begin() + M);
	auto second = vector<int>(points.begin() + M, points.end());
	li res = solve(first) + solve(second);

	vector<pair<int, int>> vals[2];
	int curMx = 0, curMn = 1e9;
	for (int i = M; i < points.size(); ++i) {
		curMx = max(curMx, points[i]);
		curMn = min(curMn, points[i]);
		vals[0].push_back(mp(curMn, curMx));
	}
	curMx = 0, curMn = 1e9;
	for (int i = M - 1; i >= 0; --i) {
		curMx = max(curMx, points[i]);
		curMn = min(curMn, points[i]);
		vals[1].push_back(mp(curMn, curMx));
	}

	for (int w = 0; w < 2; ++w) {
		for (int i = 0; i < vals[w].size(); ++i) {
			int another = vals[w][i].second - vals[w][i].first - i - 1;
			if (another >= 0 && another < vals[w ^ 1].size() && vals[w ^ 1][another].second < vals[w][i].second && vals[w ^ 1][another].first > vals[w][i].first) {
				++res;
			}
		}
	}

	for (int w = 0; w < 2; ++w) {
		map<int, treap> fromDiffs;

		vector<pair<int, int>> indices(vals[w].size());
		for (int i = 0; i < vals[w].size(); ++i) {
			indices[i] = mp(vals[w][i].first, i);
		}
		sort(all(indices));
		reverse(all(indices));

		int j = 0;
		for (int id = 0; id < vals[w].size(); ++id) {
			int i = indices[id].second;
			int mn = indices[id].first;
			while (j < vals[w ^ 1].size() && vals[w ^ 1][j].first > mn) {
				fromDiffs[vals[w ^ 1][j].second - (j + 1)].insert(vals[w ^ 1][j].second);
				++j;
			}
			int need = i + mn;
			if (!fromDiffs.count(need)) {
				continue;
			}
			treap& cur = fromDiffs[need];
			res += cur.getVal(vals[w][i].second);
		}

	}

	return res;
}

void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> points(n);
	for (int i = 0; i < n; ++i) {
		cin >> points[i].first >> points[i].second;
	}
	sort(all(points));

	li res = 0;
	for (int i = 0; i < n;) {
		int j;
		for (j = i + 1; j < n; ++j) {
			if (points[j].first > points[j - 1].first + 1) {
				break;
			}
		}
		vector<int> now;
		for (int k = i; k < j; ++k) {
			now.push_back(points[k].second);
		}
		res += solve(now);
		i = j;
	}

	cout << res << "\n";

}