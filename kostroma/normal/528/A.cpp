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

#define int li


void solve() {
	int w, h, n;
	cin >> w >> h >> n;

	map<int, int> sides[2];
	sides[0][-w] = 1;
	sides[1][-h] = 1;

	set<int> got[2];
	got[0].insert(0);
	got[0].insert(w);

	got[1].insert(0);
	got[1].insert(h);

	for (int i = 0; i < n; ++i) {
		char c;
		int pos;
		cin >> c >> pos;
		int id;
		if (c == 'V') {
			id = 0;
		}
		else {
			id = 1;
		}
		int nex = *got[id].upper_bound(pos);
		int prev = *(--got[id].upper_bound(pos));
		++sides[id][prev - pos];
		++sides[id][pos - nex];
		--sides[id][prev - nex];

		got[id].insert(pos);

		int res = 1;
		for (int j = 0; j < 2; ++j) {
			while (sides[j].begin()->second == 0) {
				sides[j].erase(sides[j].begin());
			}
			res *= sides[j].begin()->first;
		}

		cout << res << "\n";

	}

}