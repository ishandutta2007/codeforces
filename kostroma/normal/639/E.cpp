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

#define int li

//const int mod = 1000000007;

bool cmp(const pair<int, int>& q, const pair<int, int>& w) {
	return q.first * w.second > q.second * w.first;
}

bool equal(const pair<int, int>& q, const pair<int, int>& w) {
	return q.first * w.second == q.second * w.first;
}

void solve() {
	int n;
	cin >> n;
	//n = 150000;
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		//a[i].first = i;
		cin >> a[i].first;
	}
	double T = 0;
	for (int i = 0; i < n; ++i) {
		//a[i].second = rand();
		cin >> a[i].second;
		T += a[i].second;
	}
	sort(all(a), cmp);

	ld L = 0, R = 1;
	for (int w = 0; w < 30; ++w) {
		ld c = (L + R) / 2;

		vector<pair<int, ld>> mapa_mx, mapa_mn;
		int pref = 0;
		for (int i = 0; i < n;) {
			int j = i;
			int cur_sum = 0;
			while (j < n && equal(a[i], a[j])) {
				cur_sum += a[j].second;
				++j;
			}
			ld min_time = pref / T;
			ld max_time = (pref + cur_sum) / T;

			for (int r = i; r < j; ++r) {
				mapa_mx.push_back(mp(a[r].first, a[r].first * (1 - c * (min_time + a[r].second / T))));
				mapa_mn.push_back(mp(a[r].first, a[r].first * (1 - c * (max_time))));
			}
			pref += cur_sum;
			i = j;
		}

		sort(all(mapa_mn));
		sort(all(mapa_mx));

		bool good = true;
		ld cur_mx = -100;
		int j = 0;
		for (int i = 0; i < mapa_mn.size(); ++i) {
			while (j < mapa_mx.size() && mapa_mx[j].first < mapa_mn[i].first) {
				cur_mx = max(cur_mx, mapa_mx[j].second);
				++j;
			}
			if (mapa_mn[i].second < cur_mx) {
				good = false;
				break;
			}
		}

		if (good) {
			L = c;
		}
		else {
			R = c;
		}
	}

	cout << L << "\n";

}