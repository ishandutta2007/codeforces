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

//int mod = 1000000007;

int k;

vector<int> has[2];

int timer = 1;

vector<int> rems[2];

vector<int> a;

vector<pair<int, int>> parts[2];

int cnt = 0;

li rec(int l, int r) {
	if (l + 1 >= r) {
		return 0;
	}

	++timer;

	/*++cnt;
	if (cnt % 100 == 0) {
		cout << l << ' ' << r << "\n";
	}*/

	int middle = (l + r) / 2;
	li res = 0;

	res += rec(l, middle);
	res += rec(middle, r);

	parts[0].clear();
	parts[1].clear();

	parts[0].push_back(mp(a[middle], a[middle] % k));

	int sum = a[middle] % k;
	int mx = a[middle];
	for (int i = middle + 1; i < r; ++i) {
		sum = (sum + a[i]) % k;
		assert(sum < k && sum >= 0);
		mx = max(mx, a[i]);
		parts[0].push_back(mp(mx, sum));
	}

	sum = 0;
	mx = 0;
	for (int i = middle - 1; i >= l; --i) {
		sum = (sum + a[i]) % k;
		assert(sum < k && sum >= 0);
		mx = max(mx, a[i]);
		parts[1].push_back(mp(mx, sum));
	}

	for (int i = 0; i < 2; ++i) {
		sort(all(parts[i]));
	}


	for (int w = 0; w < 2; ++w) {
		++timer;
		int j = 0;
		for (int i = 0; i < parts[w].size(); ++i) {
			while (j < parts[w ^ 1].size() && mp(parts[w ^ 1][j].first, w ^ 1) < mp(parts[w][i].first, w)) {
				if (has[w ^ 1][parts[w ^ 1][j].second] != timer) {
					has[w ^ 1][parts[w ^ 1][j].second] = timer;
					rems[w ^ 1][parts[w ^ 1][j].second] = 0;
				}
				++rems[w ^ 1][parts[w ^ 1][j].second];
				++j;
			}
			int need = (k - parts[w][i].second + (parts[w][i].first % k)) % k;
			if (has[w ^ 1][need] == timer) {
				res += rems[w ^ 1][need];
			}
		}
	}

	return res;
}

void solve() {
	int n;
	cin >> n >> k;

	//n = 300000;
	//k = 1000000;

	for (int i = 0; i < 2; ++i) {
		rems[i].assign(k, 0);
		has[i].assign(k, 0);
	}

	a.resize(n);
	for (int i = 0; i < n; ++i) {
		//a[i] = (rand() << 12) | rand();
		cin >> a[i];
	}

	cout << rec(0, n);

}