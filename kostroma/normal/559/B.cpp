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

//#define int li

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

//int mod = 1000000007;

set<pair<int, int>> lens[200500];

void fillLens(int l, int r) {
	lens[r - l].insert(mp(l, r));
	if ((r - l) % 2 == 1) {
		return;
	}
	int m = (l + r) / 2;
	fillLens(l, m);
	fillLens(m, r);
}

void solve() {
	string q[2];
	cin >> q[0] >> q[1];

	//q[0] = string(1 << 17, 'a');
	//q[1] = string(1 << 17, 'b');

	string s = q[0] + q[1];

	int n = s.length();

	fillLens(0, n / 2);
	fillLens(n / 2, n);

	map<string, int> classes;

	map<pair<int, int>, int> usedPairs;

	int cl = 0;

	for (int len = 1; len <= n / 2; ++len) {
		for (auto item : lens[len]) {
			int L = item.first, R = item.second;
			if ((R - L) % 2 == 1) {
				if (!classes.count(s.substr(L, R - L))) {
					classes[s.substr(L, R - L)] = cl++;
					continue;
				}
			}
			if ((R - L) % 2 == 0) {
				string first = s.substr(L, (R - L) / 2);
				string second = s.substr(L + (R - L) / 2, (R - L) / 2);
				int g1 = classes[first], g2 = classes[second];
				if (g1 > g2) {
					swap(g1, g2);
				}
				if (usedPairs.count(mp(g1, g2))) {
					classes[s.substr(L, R - L)] = usedPairs[mp(g1, g2)];
				}
				else {
					classes[s.substr(L, R - L)] = cl;
					usedPairs[mp(g1, g2)] = cl++;
				}
			}
		}
	}

	if (classes[q[0]] == classes[q[1]]) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

}