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

int mod = 1000000007;

//ld eps = 1e-9;

typedef vector<vector<int>> matrix;

matrix mult(const matrix& q, const matrix& w) {
	matrix res(q.size(), vector<int>(q[0].size(), 0));
	for (int i = 0; i < q.size(); ++i) {
		for (int k = 0; k < q.size(); ++k) {
			for (int j = 0; j < q.size(); ++j) {
				res[i][j] += q[i][k] * w[k][j];
				res[i][j] %= mod;
			}
		}
	}
	return res;
}

void solve() {
	vector<int> a(7);
	for (int i = 0; i < 7; ++i)
		cin >> a[i];

	vector<int> dp(2);
	dp[0] = 0;
	dp[1] = 1;

	for (int n = 1; n <= 7; ++n) {
		int sz = 1 << n;
		matrix trans(sz, vector<int>(sz, 0));

		vector<int> cur(n + 1);
		for (int mask1 = 0; mask1 < sz; ++mask1) {
			for (int mask2 = 0; mask2 < sz; ++mask2) {
				cur.assign(n + 1, 0);
				cur[0] = 1;
				for (int i = 0; i < n; ++i) {
					cur[i + 1] = cur[i];
					if ((mask1 & (1 << i)) && (mask2 & (1 << i)) || (i == n - 2 && (mask1 & (1 << (i + 1))) && (mask2 & (1 << (i + 1))))) {
						if (!(i == n - 2 && (mask1 & (1 << (i + 1))) && (mask2 & (1 << (i + 1)))))
						if (i > 0) {
							cur[i + 1] += cur[i - 1];
						}
					}
					else {
						cur[i + 1] += cur[i];
					}
					cur[i + 1] %= mod;
				}

				trans[mask1][mask2] = cur[n - 1];

			}
		}

		if (n == 1) {
			trans[1][1] = 0;
		}

		

		vector<matrix> powers(20);
		powers[0] = trans;
		for (int i = 1; i < 20; ++i) {
			powers[i] = mult(powers[i - 1], powers[i - 1]);
		}

		matrix now(sz, vector<int>(sz, 0));
		for (int i = 0; i < sz; ++i) {
			now[i][i] = 1;
		}

		int step = a[n - 1];

		for (int i = 0; i < 30 && step > 0; ++i) {
			if (step & 1) {
				now = mult(now, powers[i]);
			}
			step >>= 1;
		}

		vector<int> dp1(sz);
		for (int i = 0; i < sz; ++i) {
			for (int j = 0; j < sz; ++j) {
				dp1[i] += now[i][j] * dp[j];
				dp1[i] %= mod;
			}
		}

		dp.assign(sz * 2, 0);
		for (int mask = 0; mask < sz; ++mask) {
			dp[mask + sz] = dp1[mask];
		}

		/*for (int i = 0; i < dp.size(); ++i) {
			cout << dp[i] << ' ';
		}
		cout << "\n";
		*/
	}

	int ans = dp[(1 << 8) - 1] % mod;

	cout << ans << "\n";

}