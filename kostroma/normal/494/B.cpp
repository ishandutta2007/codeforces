//#pragma comment (linker, "/STACK:128000000")
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

#define int li

void precalc() {

}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int mod = 1000000007;

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}


void solve() {
	string s, t;
	cin >> s >> t;

	string check = t + "#" + s;

	vector<int> p(check.length());
	p[0] = 0;
	for (int i = 1; i < check.length(); ++i) {
		int j = p[i - 1];
		while (j > 0 && check[i] != check[j]) {
			j = p[j - 1];
		}
		if (check[i] == check[j]) {
			++j;
		}
		p[i] = j;
	}

	vector<int> have(s.length());
	for (int i = t.length() + 1; i < check.length(); ++i) {
		if (p[i] == t.length()) {
			have[i - t.length() - 1] = true;
		}
	}

	
	vector<int> dp(s.length() + 1);
	vector<int> pref(s.length() + 1);
	vector<int> Pref(s.length() + 1);
	vector<int> PREF(s.length() + 1);
	dp[0] = 0;
	pref[0] = 0;
	Pref[0] = 0;
	PREF[0] = 0;

	int l = -1;

	for (int i = 0; i < s.length(); ++i) {
		if (have[i]) {
			l = i - t.length() + 1;
		}
		if (l >= 0) {
			dp[i + 1] = (PREF[l] * (l + 1) - Pref[l] + l + 1) % mod;
		}
		pref[i + 1] = (pref[i] + dp[i + 1]) % mod;
		Pref[i + 1] = (Pref[i] + dp[i + 1] * (i + 1)) % mod;
		PREF[i + 1] = (PREF[i] + dp[i + 1]) % mod;
		//cout << i << ' ' << dp[i + 1] << ' ' << pref[i + 1] << ' ' << Pref[i + 1] << ' ' << PREF[i + 1] << "\n";
	}

	int ans = 0;
	for (int i = 0; i <= s.length(); ++i) {
		ans = (ans + dp[i]) % mod;
	}

	cout << (ans + 2 * mod) % mod << "\n";

}