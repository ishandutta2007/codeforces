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
		//cout << "Case #" << testNum++ << ":\n";
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


void solve() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}

	set<int> got;
	got.insert(-1);
	got.insert(n);

	sort(all(a));
	vector<int> mx(n);
	multiset<int> lens;
	lens.insert(n);

	for (int i = 0; i < n; ++i) {
		mx[i] = *lens.rbegin();
		int id = a[i].second;
		auto leftIt = got.lower_bound(id);
		--leftIt;
		auto rightIt = got.lower_bound(id);

		int lef = *leftIt;
		int rig = *rightIt;

		auto eraseIt = lens.find(rig - lef - 1);
		lens.erase(eraseIt);

		lens.insert(id - lef - 1);
		lens.insert(rig - id - 1);

		got.insert(id);
	}

	vector<int> res(n + 1, 0);
	for (int i = 0; i < n; ++i) {
		int nex = 1;
		if (i + 1 < n) {
			nex = mx[i + 1];
		}
		for (int j = nex; j <= mx[i]; ++j) {
			res[j] = max(res[j], a[i].first);
		}
	}

	for (int i = 1; i <= n; ++i) {
		cout << res[i] << ' ';
	}
	cout << "\n";

}