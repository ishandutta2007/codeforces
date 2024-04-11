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

void zFunction(const string& s, vector<int>& z) {
	int n = s.length();
	if (n == 0)
		return;
	z.resize(n);
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
	int n, m;
	string p;
	cin >> n >> m >> p;
	vector<int> poses(m);
	for (int i = 0; i < m; ++i) {
		cin >> poses[i];
		--poses[i];
	}

	string s(n, 0);
	for (int i = 0; i < m; ++i) {
		int curPos = poses[i];
		while (curPos < n && curPos - poses[i] < p.length()) {
			if (i + 1 < m && curPos == poses[i + 1]) {
				break;
			}
			s[curPos] = p[curPos - poses[i]];
			++curPos;
		}
	}

	vector<int> z;
	zFunction(p + '#' + s, z);

	for (int i = 0; i < m; ++i) {
		int pos = poses[i] + p.length() + 1;
		if (z[pos] != p.length()) {
			cout << "0\n";
			return;
		}
	}

	li ans = 1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 0) {
			ans = ans * 26 % 1000000007;
		}
	}

	cout << ans << "\n";

}