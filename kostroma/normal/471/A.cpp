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

int gcd (int q, int w) {
	while(w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

int binpow (int q, int w, int mod) {
	if (!w)
		return 1 % mod;
	if (w & 1) {
		return (q * binpow(q, w - 1, mod)) % mod;
	}
	return binpow((q * q) % mod, w / 2, mod);
}

int l[6];

void solve() {
	for (int i= 0; i < 6; ++i)
		cin >> l[i];

	sort(l, l + 6);

	if (l[0] == l[3] && l[4] == l[5]) {
		cout << "Elephant\n";
		return;
	}

	if (l[2] == l[5] && l[0] == l[1]) {
		cout << "Elephant\n";
		return;
	}
	
	if (l[0] == l[3] && l[4] < l[5] || l[1] == l[4] && l[0] < l[5] || l[2] == l[5] && l[0] < l[1]) {
		cout << "Bear\n";
		return;
	}

	cout << "Alien\n";

}