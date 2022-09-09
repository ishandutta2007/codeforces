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

int primes[] = {2,3,5,7};

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<int> step(4, 0);
	for (int i = 0; i < n; ++i) {
		int cur = s[i] - '0';
		if (cur == 0)
			continue;
		for (int j = cur - 1; j > 0; --j) {
			cur *= j;
		}
		for (int j = 0; j < 4; ++j) {
			while (cur % primes[j] == 0) {
				++step[j];
				cur /= primes[j];
			}
		}
	}

	vector<int> res;

	for (int j = 3; j >= 0; --j) {
		while (step[j] > 0) {
			res.push_back(primes[j]);
			--step[j];
			if (j == 3) {
				--step[2];
				step[1] -= 2;
				step[0] -= 4;
			}
			if (j == 2) {
				step[0] -= 3;
				step[1] -= 1;
			}
			if (j == 1) {
				step[0] -= 1;
			}
		}
	}

	for (int i = 0; i < res.size(); ++i)
		cout << res[i];

}