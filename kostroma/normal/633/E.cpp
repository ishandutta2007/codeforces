#pragma comment(linker, "/STACK:512000000")
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
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
//#include <unordered_map>
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
		//cerr << testNum << endl;
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

/*const int C = 7000500;

int least_prime[C];*/

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
	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
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

const int L = 20;

vector<vector<int>> v, c;

int get_val(int l, int r) {
	++r;
	int max_v = 0, min_c = 2e9;
	for (int j = L - 1; j >= 0; --j) {
		if (l + (1 << j) <= r) {
			max_v = max(max_v, v[j][l]);
			min_c = min(min_c, c[j][l]);
			l += (1 << j);
		}
	}
	return min(max_v, min_c);
}

const int C = 1000500;
ld log_fact[C];

void solve() {
	log_fact[0] = 0;
	for (int i = 1; i < C; ++i) {
		log_fact[i] = log_fact[i - 1] + log(i);
	}

	int k, n;
	cin >> n >> k;
	v.resize(L, vector<int>(n));
	c.resize(L, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		cin >> v[0][i];
		v[0][i] *= 100;
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[0][i];
	}

	for (int i = 0; i + 1 < L; ++i) {
		for (int j = 0; j < n; ++j) {
			v[i + 1][j] = v[i][j];
			if (j + (1 << i) < n) {
				v[i + 1][j] = max(v[i + 1][j], v[i][j + (1 << i)]);
			}
		}
	}
	for (int i = 0; i + 1 < L; ++i) {
		for (int j = 0; j < n; ++j) {
			c[i + 1][j] = c[i][j];
			if (j + (1 << i) < n) {
				c[i + 1][j] = min(c[i + 1][j], c[i][j + (1 << i)]);
			}
		}
	}

	vector<int> result(n, 0);
	for (int i = 0; i < n; ++i) {
		int pos = i;
		for (int j = L - 1; j >= 0; --j) {
			if (v[j][pos] <= c[j][pos]) {
				pos += (1 << j);
				if (pos >= n) {
					pos = n - 1;
					break;
				}
			}
		}
		for (int cur_pos = max(pos - 1, i); cur_pos <= pos + 1 && cur_pos < n; ++cur_pos) {
			int cur_val = get_val(i, cur_pos);
			result[i] = max(result[i], cur_val);
		}
	}

	ld ans = 0;
	sort(all(result));

	for (int i = 0; i + k <= result.size(); ++i) {
		int rest = n - i - 1;
		ld coef = exp( log_fact[rest] - log_fact[rest - k + 1] - log_fact[k - 1] - log_fact[n] + log_fact[k] + log_fact[n - k]);
		ans += coef * result[i];
	}

	cout << ans << "\n";

}