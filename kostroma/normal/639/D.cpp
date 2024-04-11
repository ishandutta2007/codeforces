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

int n, k, b, c;

int dist(int from, int to) {
	int res = 0;
	int rest_from = ((from % 5) + 5) % 5, rest_to = ((to % 5) + 5) % 5;
	if (rest_from <= rest_to) {
		from += rest_to - rest_from;
		return (rest_to - rest_from) * c + (to - from) / 5 * b;
	}
	else {
		from += rest_to - rest_from + 5;
		return (rest_to - rest_from + 5) * c + (to - from) / 5 * b;
	}
}

void solve() {
	vector<int> a;
	cin >> n >> k >> b >> c;
	b = min(b, 5 * c);
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(all(a));
	vector<vector<int>> check_vals(5);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 5; ++j) {
			int cur = (a[i] + j) % 5;
			if (cur < 0) {
				cur += 5;
			}
			check_vals[cur].push_back(a[i] + j);
		}
	}
	int ans = 4e18 + 5;
	for (int i = 0; i < 5; ++i) {
		sort(all(check_vals[i]));
		vector<queue<int>> vals(5);
		int cur_sum = 0;
		int cur_cnt = 0;
		int last = -2e9 - 10;
		int uk = 0;
		for (int candy : check_vals[i]) {
			if (last > -2e9) {
				cur_sum += cur_cnt * (candy - last) / 5 * b;
			}
			last = candy;
			while (uk < a.size() && a[uk] <= candy) {
				vals[((a[uk] % 5) + 5) % 5].push(a[uk]);
				++cur_cnt;
				cur_sum += dist(a[uk], candy);
				++uk;
			}
			while (cur_cnt > k) {
				int erase_from = -1;
				int max_dist = -1;
				for (int j = 0; j < 5; ++j) {
					if (!vals[j].empty()) {
						int cur_dist = dist(vals[j].front(), candy);
						if (cur_dist > max_dist) {
							max_dist = cur_dist;
							erase_from = j;
						}
					}
				}
				--cur_cnt;
				cur_sum -= dist(vals[erase_from].front(), candy);
				vals[erase_from].pop();
			}
			if (cur_cnt >= k) {
				ans = min(ans, cur_sum);
			}
		}
	}
	cout << ans << "\n";
}