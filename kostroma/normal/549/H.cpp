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

bool in(ld c, ld a, ld b) {
	return c >= a && c <= b;
}

bool intersect(ld a1, ld a2, ld b1, ld b2) {
	return in(a1, b1, b2) || in(a2, b1, b2) || in(b1, a1, a2) || in(b2, a1, a2);
}

void solve() {
	ld a, b, c, d;
	cin >> a >> b >> c >> d;

	ld L = 0, R = 1e15;
	for (int w = 0; w < 200; ++w) {
		ld K = (L + R) / 2;

		vector<ld> lef;
		for (int i = -1; i < 2; i += 2) {
			for (int j = -1; j < 2; j += 2) {
				lef.push_back((a + i * K) * (d + j * K));
			}
		}
		sort(all(lef));

		vector<ld> rig;
		for (int i = -1; i < 2; i += 2) {
			for (int j = -1; j < 2; j += 2) {
				rig.push_back((b + i * K) * (c + j * K));
			}
		}
		sort(all(rig));

		if (intersect(lef[0], lef.back(), rig[0], rig.back())) {
			R = K;
		}
		else {
			L = K;
		}

	}

	cout << L << "\n";
	
}