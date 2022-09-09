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

void zFunction(const string& s, vector<int>& z) {
	int n = s.length();
	z.resize(n);
	if (n == 0)
		return;
	z[0] = 0;
	int l = 0, r = 0;
	for (int i = 1; i < n; ++i) {
		if (i <= r)
			z[i] = min(z[i - l], r - i + 1);
		while (i + z[i] < n && s[i + z[i]] == s[z[i]])
			++z[i];
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
	}
}

void solve() {
	int n, k;
	string s;
	cin >> n >> k >> s;
	vector<int> z;
	zFunction(s, z);

	vector<int> maxPeriod(n, 0);

	for (int size = 1; size <= n && size * k <= n; ++size) {
		bool f = true;
		for (int i = size, it = 0; i < n && it + 1 < k; i += size, ++it) {
			if (z[i] < size) {
				f = false;
				break;
			}
		}
		if (f) {
			maxPeriod[size * k - 1] = max(maxPeriod[size * k - 1], size);
		}
	}

	vector<int> events(n + 1, 0);

	vector<int> res(n, 0);

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (maxPeriod[i] > 0) {
			int nex = min(maxPeriod[i], z[i + 1]);
			++events[i];
			--events[i + nex + 1];
		}
		cnt += events[i];
		if (cnt > 0) {
			res[i] = 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << res[i];
	}

}