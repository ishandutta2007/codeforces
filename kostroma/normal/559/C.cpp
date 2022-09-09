#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:128000000")
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>
#include <sstream>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)

typedef long long li;
typedef long long i64;
typedef double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();

void precalc();

int TESTNUM = 0;
#define FILENAME ""

int main() {
	string s = FILENAME;
#ifdef AIM
	//assert(!s.empty());
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//cerr<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout); 
	cin.tie(0);
#endif
	cout.sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	precalc();
	int t = 1;
	//cin >> t;
	while (t--) {
		++TESTNUM;
		solve();
	}
#ifdef AIM
	cerr << "\n\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n\n";
#endif
	return 0;
}

#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;
int powers[2][C];*/

int MOD = 1000000007;

//int c[5010][5010];

//int catalan[200500];

//ld doubleC[100][100];

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
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

int mod = 1000000007;

vector<int> fact, revfact;

const int C = 200500;

int getC(int n, int k) {
	int res = fact[n] * revfact[k] % mod * revfact[n - k] % mod;
	return res;
}

void solve() {
	fact.resize(C);
	revfact.resize(C);
	fact[0] = 1;
	revfact[0] = 1;
	for (int i = 1; i < C; ++i) {
		fact[i] = fact[i - 1] * i % mod;
		revfact[i] = binpow(fact[i], mod - 2, mod);
	}

	int h, w;
	cin >> h >> w;

	int n;
	cin >> n;
	vector<pair<int, int>> points;
	points.push_back(mp(0, 0));
	for (int i = 0; i < n; ++i) {
		pair<int, int> cur;
		cin >> cur.first >> cur.second;
		--cur.first;
		--cur.second;
		points.push_back(cur);
	}
	points.push_back(mp(h - 1, w - 1));

	sort(all(points));

	n += 2;

	vector<int> dp(n);
	dp[0] = 1;

	for (int i = 1; i < n; ++i) {
		dp[i] = getC(points[i].first + points[i].second, points[i].first);
		for (int last = 1; last < i; ++last) {
			int x = points[i].first - points[last].first;
			int y = points[i].second - points[last].second;
			if (x >= 0 && y >= 0) {
				dp[i] -= getC(x + y, x) * dp[last];
				dp[i] %= mod;
			}
		}
	}

	int res = dp[n - 1];
	while (res < 0) {
		res += mod;
	}

	cout << res << "\n";


}