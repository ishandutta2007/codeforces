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

int MOD = 1000000007;

int c[5010][5010];

//int catalan[200500];

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
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

	for (int i = 0; i < 5010; ++i) {
		c[i][i] = c[i][0] = 1;
		for (int j = 1; j < i; ++j) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
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

struct Fraction {
	int p, q;
	int town;
	Fraction(int p, int q, int town) :p(p), q(q), town(town) {}
	bool operator < (const Fraction& other) const {
		if (p * 1LL * other.q != q * 1LL * other.p) {
			return p * 1LL * other.q < q * 1LL * other.p;
		}
		return town < other.town;
	}
};

void solve() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> g(n);
	vector<int> fortress(n, 0);
	for (int i = 0; i < k; ++i) {
		int cur;
		cin >> cur;
		--cur;
		fortress[cur] = 1;
	}

	vector<Fraction> vals;

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	vector<int> border(n);
	for (int i = 0; i < n; ++i) {
		int good = 0;
		for (int to : g[i]) {
			if (!fortress[to]) {
				++good;
			}
		}
		border[i] = good;
		vals.push_back(Fraction(good, g[i].size(), i));
	}

	set<Fraction> cities;

	vector<int> towns;

	for (int i = 0; i < n; ++i) {
		if (fortress[i]) {
			continue;
		}
		cities.insert(vals[i]);
	}

	Fraction best(-1, 1, -1);
	int pos = -1;

	vector<char> used(n, false);

	for (int i = 0; i < n - k; ++i) {
		auto item = *cities.begin();
		if (best < item) {
			best = item;
			pos = i;
		}

		//cout << item.town + 1 << "\n";

		towns.push_back(item.town);
		used[item.town] = true;
		cities.erase(cities.begin());

		for (int to : g[item.town]) {
			if (!fortress[to] && !used[to]) {
				cities.erase(Fraction(border[to], g[to].size(), to));
				--border[to];
				cities.insert(Fraction(border[to], g[to].size(), to));
			}
		}

	}

	vector<int> res;
	for (int i = pos; i < n - k; ++i) {
		res.push_back(towns[i]);
	}

	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i] + 1 << ' ';
	}


}