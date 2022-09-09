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

#define int li

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

int n, m;

int a[200500], b[200500];

int diffs[200500], ex[200500];

int mod[] = {1000000007, 1000000009};

int pr[] = {432563, 245242};

int powers[2][200500];

int pref[2][200500];

void solve() {
	for (int w = 0; w < 2; ++w) {
		powers[w][0] = 1;
		for (int i = 1; i < 200500; ++i)
			powers[w][i] = (powers[w][i - 1] * pr[w]) % mod[w];
	}
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i< n; ++i)
		diffs[i] = a[i + 1] - a[i];
	for (int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	for (int i = 0; i< m; ++i)
		ex[i] = b[i + 1] - b[i];
	--n;
	--m;

	pref[0][0] = pref[1][0] = 0;
	for (int i = 0; i < n; ++i) {
		for (int w = 0; w < 2; ++w)
			pref[w][i + 1] = (pref[w][i] * pr[w] + diffs[i]) % mod[w];
	}

	int hashes[] = {0, 0};
	for (int i = 0; i < m; ++i)
		for (int w = 0; w < 2; ++w) {
			hashes[w] = (hashes[w] * pr[w] + ex[i]) % mod[w];
			if (hashes[w] < 0)
				hashes[w] += mod[w];
		}

	int ans = 0;

	for (int i = 0; i <= n - m; ++i) {
		int curHashes[2];
		for (int w = 0; w < 2; ++w) {
			curHashes[w] = (pref[w][i + m] - pref[w][i] * powers[w][m]) % mod[w];
			if (curHashes[w] < 0)
				curHashes[w] += mod[w];
		}
		if (hashes[0] == curHashes[0] && hashes[1] == curHashes[1])
			++ans;
	}

	cout << ans;

}