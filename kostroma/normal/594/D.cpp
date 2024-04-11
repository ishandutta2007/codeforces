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

#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

//int catalan[200500];

//ld doubleC[100][100];

int binpow(int q, int w, int mod) {
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

const int mod = 1000000007;

const int C = 1000500;

int least_prime[C];

const int shift = 1 << 18;
pair<int, int> tree[2 * shift];

pair<int, int> operator * (pair<int, int> q, pair<int, int> w) {
	return mp(q.first * w.first % mod, q.second * w.second % mod);
}

void modify(int v, pair<int, int> val) {
	v += shift;
	tree[v] = tree[v] * val;
	v /= 2;
	while (v) {
		tree[v] = tree[2 * v] * tree[2 * v + 1];
		v /= 2;
	}
}

pair<int, int> rmq(int l, int r) {
	if (l >= r) {
		return mp(1, 1);
	}
	if (l & 1) {
		return tree[l] * rmq(l + 1, r);
	}
	if (r & 1) {
		return rmq(l, r - 1) * tree[r - 1];
	}
	return rmq(l / 2, r / 2);
}

pair<int, int> get_product(int l, int r) {
	return rmq(l + shift, r + shift);
}

void solve() {
	vector<int> primes;
	for (int i = 2; i < C; ++i) {
		if (least_prime[i] == 0) {
			primes.push_back(i);
			least_prime[i] = i;
			for (li j = i * i; j < C; j += i) {
				least_prime[j] = i;
			}
		}
	}

	int n;
	cin >> n;
	vector<int> a(n);

	vector<int> pref_product(n + 1, 1);

	vector<vector<int>> poses(primes.size());

	vector<vector<int>> cur_primes(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		int cur = a[i];
		int pr = 1;
		while (cur > 1) {
			int p = least_prime[cur];
			int p_id = lower_bound(all(primes), p) - primes.begin();
			cur_primes[i].push_back(p_id);
			poses[p_id].push_back(i);
			while (cur % p == 0) {
				cur /= p;
				pr *= p;
			}
		}
		pref_product[i + 1] = pref_product[i] * pr % mod;
	}

	int Q;
	cin >> Q;

	vector<vector<pair<int, int>>> ask(n);

	vector<int> res(Q);
	for (int i = 0; i < Q; ++i) {
		int l, r;
		cin >> l >> r;
		--l;
		ask[l].push_back(mp(r, i));
		res[i] = pref_product[r] * binpow(pref_product[l], mod - 2, mod) % mod;
	}

	for (int i = 0; i < shift + n; ++i) {
		tree[i] = mp(1, 1);
	}

	vector<int> uk(primes.size(), 0);

	for (int i = 0; i < primes.size(); ++i) {
		if (uk[i] < poses[i].size()) {
			modify(poses[i][uk[i]], mp(primes[i], primes[i] - 1));
			++uk[i];
		}
	}

	for (int l = 0; l < n; ++l) {
		for (auto item : ask[l]) {
			pair<int, int> ans = get_product(l, item.first);
			res[item.second] = res[item.second] * binpow(ans.first, mod - 2, mod) % mod * 
				ans.second % mod;
		}
		for (int p_id : cur_primes[l]) {
			if (uk[p_id] < poses[p_id].size()) {
				modify(poses[p_id][uk[p_id]], mp(primes[p_id], primes[p_id] - 1));
				++uk[p_id];
			}
		}
	}

	for (int i = 0; i < Q; ++i) {
		cout << res[i] << "\n";
	}

}