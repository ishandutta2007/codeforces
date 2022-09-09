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

int p[200500];
int l[200500];

const int shift = 1 << 18;

pair<int, int> tree[2 * shift + 5];

pair<int, int> merge(const pair<int, int>& q, const pair<int, int>& w) {
	pair<int, int> res;
	if (q > w)
		res = q;
	else
		res = w;
	return res;
}

pair<int, int> rmq (int l, int r) {
	if (l + 1 == r)
		return tree[l];
	if (l & 1) {
		return merge(tree[l], rmq(l + 1, r));
	}
	if (r & 1)
		return merge(rmq(l, r - 1), tree[r - 1]);
	return rmq(l / 2, r / 2);
}

const int L = 19;

void modify(int l) {
	l /= 2;
	while (l > 0) {
		tree[l] = merge(tree[2 * l], tree[2 * l + 1]);
		l /= 2;
	}
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> p[i] >> l[i];
	}

	for (int i = n - 1; i >= 0; --i) {
		int last = upper_bound(p, p + n, p[i] + l[i]) - p;
		if (last == i + 1) {
			tree[i + shift] = mp(i + 1, p[i] + l[i]);
			modify(i + shift);
		}
		else {
			tree[i + shift] = rmq(i + 1 + shift, last + shift);
			tree[i + shift].second = max(tree[i + shift].second, p[i] + l[i]);
			modify(i + shift);
		}
	}

	vector<vector<pair<int, int>>> sparse(L, vector<pair<int, int>>(n));
	vector<vector<int>> cost(L, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		sparse[0][i] = tree[i + shift];
		cost[0][i] = 0;
		//cout << i + 1 << ' ' << sparse[0][i].first + 1 << ' ' << sparse[0][i].second << "\n";
	}

	for (int j = 1; j < L; ++j) {
		for (int i = 0; i < n; ++i) {
			int cur = sparse[j - 1][i].first;
			if (cur == n) {
				sparse[j][i] = sparse[j - 1][i];
				cost[j][i] = cost[j - 1][i];
				continue;
			}
			int curSum = p[cur] - sparse[j - 1][i].second;
			int nex = sparse[j - 1][cur].first;
			sparse[j][i] = mp(nex, sparse[j - 1][cur].second);
			cost[j][i] = cost[j - 1][i] + curSum + cost[j - 1][cur];
		}
	}

	int Q;
	cin >> Q;
	for (int it = 0; it < Q; ++it) {
		int x, y;
		cin >> x >> y;
		--x;

		int res = 0;
		for (int j = L - 1; j >= 0; --j) {
			if (sparse[j][x].first >= y)
				continue;
			res += cost[j][x];
			res += p[sparse[j][x].first] - sparse[j][x].second;
			x = sparse[j][x].first;
		}

		cout << res << "\n";

	}

}