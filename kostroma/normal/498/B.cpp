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

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//int mod = 1000000007;

//ld eps = 1e-9;

int n, T;

ld p[5050];
int t[5050];

ld maxPow[5050];

void solve() {
	cin >> n >> T;
	for (int i = 0; i < n; ++i) {
		cin >> p[i] >> t[i];
		p[i] /= 100.0;

		maxPow[i] = 1.0;
		for (int j = 1; j < t[i]; ++j)
			maxPow[i] = maxPow[i] * (1 - p[i]);
	}

	vector<ld> dp(T + 1, 0);
	dp[0] = 1.0;

	ld ans = 0.0;

	for (int song = 0; song < n; ++song) {
		ld add = 0.0;
		vector<ld> dp1(T + 1, 0);
		for (int i = 1; i <= T; ++i) {
			add = add * (1 - p[song]) + p[song] * dp[i - 1];
			if (i >= t[song]) {
				add -= maxPow[song] * p[song] * dp[i - t[song]];
			}
			dp1[i] = add;
			if (i >= t[song]) {
				dp1[i] += dp[i - t[song]] * maxPow[song];
			}
		}

		dp.swap(dp1);

		ld pr = 1.0;

		for (int i = T; i >= 0; --i) {
			if (song < n - 1 && T - i >= t[song + 1])
				break;
			ans += dp[i] * pr * (song + 1);
			if (song < n - 1) {
				pr *= (1 - p[song + 1]);
			}
		}

		/*for (int i = 0; i <= T; ++i) {
			cout << dp[i] << ' ';
		}
		cout << "\n\n";*/

	}

	cout << ans << "\n";

}