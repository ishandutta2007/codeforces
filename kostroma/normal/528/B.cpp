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
	//freopen("c3.out", "w", stdout);
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

int n;

void solve() {
	cin >> n;
	vector<pair<int, int>> segments(n);
	for (int i = 0; i < n; ++i) {
		int x, w;
		cin >> x >> w;
		segments[i] = mp(x - w, x + w);
	}

	vector<int> coords;
	for (auto item : segments) {
		coords.push_back(item.first);
		coords.push_back(item.second);
	}

	sort(all(coords));
	coords.erase(unique(all(coords)), coords.end());

	for (auto& item : segments) {
		item.first = lower_bound(all(coords), item.first) - coords.begin();
		item.second = lower_bound(all(coords), item.second) - coords.begin();
	}

	vector<int> dp(coords.size() + 1, 0);

	vector<vector<int>> events(coords.size());
	for (auto item : segments) {
		events[item.first].push_back(item.second);
	}

	for (int i = 0; i < coords.size(); ++i) {
		dp[i + 1] = max(dp[i + 1], dp[i]);
		for (int rb : events[i]) {
			dp[rb] = max(dp[rb], dp[i] + 1);
		}
	}

	int ans = 0;
	for (int i = 0; i < dp.size(); ++i) {
		ans = max(ans, dp[i]);
	}

	cout << ans << "\n";

}