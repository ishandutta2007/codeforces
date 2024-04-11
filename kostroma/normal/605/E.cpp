#pragma comment (linker, "/STACK:1280000000")
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
#include <unordered_map>
#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <complex>
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

int testNumber = 1;

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
	start = clock();
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	int testNum = 1;
	while (t--) {
		//cout << "Case #" << testNum++ << ": ";
		solve();
		++testNumber;
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

const int C = 300500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

//int catalan[200500];

//ld doubleC[100][100];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

/*int curMod = 1000000009;

int fact[100500], revfact[100500];

int getC(int n, int k) {
int res = fact[n] * revfact[n - k] % curMod * revfact[k] % curMod;
return res;
}*/

//const int C = 500500;

//int least_prime[C];

void precalc() {

	/*for (int i = 2; i < C; ++i) {
		if (!least_prime[i]) {
			least_prime[i] = i;
			for (li j = i * 1LL * i; j < C; j += i) {
				least_prime[j] = i;
			}
		}
	}*/

	/*fact[0] = revfact[0] = 1;
	for (int i = 1; i < 100500; ++i) {
	fact[i] = fact[i - 1] * i % curMod;
	revfact[i] = binpow(fact[i], curMod - 2, curMod);
	}*/

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

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}


//#define int li

//const int mod = 1000000007;

typedef double ldd;

#define double ld

double get_real_dp(double cur_dp, double cur_prob) {
	double real_dp = cur_dp / cur_prob + (1 / cur_prob - 1);
	return real_dp;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<double>> matrix(n, vector<double>(n));
	vector <vector<pair<int, double>>> g(n);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			int cur;
			cin >> cur;
			matrix[i][j] = cur / 100.0;
			if (i != j && cur != 0) {
				double p = cur / 100.0;
				g[i].push_back(mp(j, p));
			}
		}
	}

	vector<double> cur_dp(n, 1e18);
	//vector<double> cur_turns(n, 1e18);
	vector<double> cur_prob(n, 0);
	cur_dp[n - 1] = 0;
	cur_prob[n - 1] = 1;
	//cur_turns[n - 1] = 0;

	vector<char> filled(n, false);
	
	for (int w = 0; w < n; ++w) {
		int cur = -1;
		double min_dp = 1e18;
		for (int i = 0; i < n; ++i) {
			if (!filled[i] && cur_prob[i] > 1e-9) {
				double real_dp = get_real_dp(cur_dp[i], cur_prob[i]);
				if (real_dp < min_dp) {
					min_dp = real_dp;
					cur = i;
				}
			}
		}
		if (cur == -1) {
			break;
		}

		filled[cur] = true;

		cur_dp[cur] = min_dp;
		
		for (int j = 0; j < n; ++j) {
			if (filled[j]) {
				continue;
			}
			if (matrix[j][cur] < 1e-9) {
				continue;
			}
			if (cur_prob[j] < 1e-9) {
				cur_dp[j] = (cur_dp[cur] + 1) * matrix[j][cur];
				cur_prob[j] = matrix[j][cur];
				continue;
			}

			double dp_nex = cur_dp[j] + (1 - cur_prob[j]) * (cur_dp[cur] + 1) * matrix[j][cur];
			double next_prob = cur_prob[j] + (1 - cur_prob[j]) * matrix[j][cur];

			if (get_real_dp(dp_nex, next_prob) < get_real_dp(cur_dp[j], cur_prob[j])) {
				cur_dp[j] = dp_nex;
				cur_prob[j] = next_prob;
			}
		}
	}

	if (cur_dp[0] > 1e17) {
		cout << "-1\n";
	}
	else {
		cout << (ldd)cur_dp[0] << "\n";
	}

}