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



void solve() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	vector<vector<int>> a(n, vector<int>(m));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}

	vector<pair<int, int>> masks;

	int uniqMask = 0;
	for (int j = 0; j < m; ++j) {
		vector<pair<char, int>> letters;
		for (int i = 0; i < n; ++i) {
			letters.push_back(mp(s[i][j], i));
		}
		sort(all(letters));
		for (int i = 0; i < letters.size();) {
			int r = i;
			while (r < letters.size() && letters[r].first == letters[i].first) {
				++r;
			}
			if (r == i + 1) {
				uniqMask |= (1 << letters[i].second);
				i = r;
				continue;
			}

			vector<int> costs;
			int sum = 0;
			int curMask = 0;
			for (int k = i; k < r; ++k) {
				costs.push_back(a[letters[k].second][j]);
				curMask |= (1 << letters[k].second);
				sum += a[letters[k].second][j];

				masks.push_back(mp(1 << letters[k].second, a[letters[k].second][j]));
			}
			sort(all(costs));
			sum -= costs.back();

			masks.push_back(mp(curMask, sum));
			i = r;
		}
	}

	li INF = 1000000000000000000LL;
	vector<li> dp(1 << n, INF);
	dp[uniqMask] = 0;
	for (auto item : masks) {
		int addMask = item.first;
		int cost = item.second;
		for (int mask = 0; mask < (1 << n); ++mask) {
			if (dp[mask] == INF)
				continue;
			if (dp[mask] + cost < dp[mask | addMask]) {
				dp[mask | addMask] = dp[mask] + cost;
			}
		}
	}

	cout << dp[(1 << n) - 1] << "\n";

}