#pragma comment (linker, "/STACK:1280000000")
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
#include <deque>
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

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

//int catalan[200500];

//ld doubleC[100][100];

int binpow(int q, int w, int mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

void precalc() {

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/

	/*catalan[0] = 1;
	for (int n = 0; n < 200500 - 1; ++n) {
	catalan[n + 1] = catalan[n] * 2 * (2 * n + 1) % MOD * binpow(n + 2, MOD - 2, MOD) % MOD;
	}*/

	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/

	/*for (int i = 0; i < 100; ++i) {
	doubleC[i][i] = doubleC[i][0] = 1.0;
	for (int j = 1; j < i; ++j) {
	doubleC[i][j] = doubleC[i - 1][j - 1] + doubleC[i - 1][j];
	}
	}*/
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

const int C = 2000005;

bool good(int cur) {
	vector<int> now;
	while (cur) {
		now.push_back(cur % 10);
		cur /= 10;
	}
	for (int i = 0; i < now.size(); ++i) {
		if (now[i] != now[now.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}

void solve() {
	int p, q;
	cin >> p >> q;

	vector<int> isPrime(C, 1);
	for (int i = 2; i < C; ++i) {
		if (!isPrime[i]) {
			continue;
		}
		for (li j = i * 1LL * i; j < C; j += i) {
			isPrime[j] = 0;
		}
	}

	vector<int> sum(C, 0);
	for (int i = 2; i < C; ++i) {
		sum[i] = sum[i - 1] + isPrime[i];
	}

	vector<int> sumPal(C, 0);
	for (int i = 1; i < C; ++i) {
		sumPal[i] = sumPal[i - 1];
		if (good(i)) {
			++sumPal[i];
		}
	}

	int res = 1;
	for (int i = 1; i < C; ++i) {
		if (sum[i] * q <= p * sumPal[i]) {
			res = i;
		}
	}

	cout << res << "\n";

}