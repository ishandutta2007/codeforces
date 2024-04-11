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

const int C = 500500;

int lp[C];

void precalc() {
	for (int i = 2; i < C; ++i) {
		if (lp[i] != 0)
			continue;
		lp[i] = i;
		for (li j = i * 1LL * i; j < C; j += i) {
			if (lp[j] == 0) {
				lp[j] = i;
			}
		}
	}
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

//int mod = 1000000007;

int divisors[C];

void solve() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	vector<vector<pair<int, int>>> dels(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		int cur = 1;
		vector<int> ps;
		while (a[i] > 1) {
			int p = lp[a[i]];
			a[i] /= p;
			while (a[i] > 1 && lp[a[i]] == p) {
				a[i] /= p;
			}
			cur *= p;
			ps.push_back(p);
		}
		a[i] = cur;
		for (int mask = 0; mask < (1 << ps.size()); ++mask) {
			int del = 1;
			int cnt = 0;
			for (int z = 0; z < ps.size(); ++z) {
				if (mask & (1 << z)) {
					del *= ps[z];
					++cnt;
				}
			}
			dels[i].push_back(mp(del, cnt & 1));
		}
	}

	vector<int> into(n, 0);
	int curAns = 0;
	while (q--) {
		int cur;
		cin >> cur;
		--cur;
		if (into[cur]) {
			for (auto item : dels[cur]) {
				--divisors[item.first];
			}
		}

		int res = 0;
		for (auto item : dels[cur]) {
			if (item.second)
				res -= divisors[item.first];
			else
				res += divisors[item.first];
		}

		if (into[cur]) {
			curAns -= res;
			into[cur] = 0;
		}
		else {
			curAns += res;
			into[cur] = 1;
			for (auto item : dels[cur]) {
				++divisors[item.first];
			}
		}

		cout << curAns << "\n";

	}

}