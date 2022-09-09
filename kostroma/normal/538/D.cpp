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

//#define int li

void solve() {
	
	int n;
	cin >> n;
	set<pair<int, int>> turns;
	for (int i = -n + 1; i <= n - 1; ++i) {
		for (int j = -n + 1; j <= n - 1; ++j) {
			if (i != 0 || j != 0) {
				turns.insert(mp(i, j));
			}
		}
	}

	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (s[i][j] == '.') {

				for (int x = 0; x < n; ++x) {
					for (int y = 0; y < n; ++y) {
						if (s[x][y] == 'o') {
							turns.erase(mp(i - x, j - y));
						}
					}
				}

			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (s[i][j] == 'x') {

				bool f = false;
				for (int x = 0; x < n; ++x) {
					for (int y = 0; y < n; ++y) {
						if (s[x][y] == 'o') {
							if (turns.count(mp(i - x, j - y))) {
								f = true;
								break;
							}
						}
					}
				}

				if (!f) {
					cout << "NO\n";
					return;
				}

			}
		}
	}

	cout << "YES\n";
	
	for (int i = -n + 1; i <= n - 1; ++i) {
		for (int j = -n + 1; j <= n - 1; ++j) {
			if (i != 0 || j != 0) {
				if (turns.count(mp(i, j))) {
					cout << "x";
				}
				else {
					cout << ".";
				}
			}
			else {
				cout << "o";
			}
		}
		cout << "\n";
	}

}