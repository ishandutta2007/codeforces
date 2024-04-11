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

const int C = 200500;
vector<int> dels[C];

void solve() {
	for (int d = 1; d < C; ++d) {
		for (int j = d; j < C; j += d) {
			dels[j].push_back(d);
		}
	}

	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> last_mult(C, n);
	vector<char> have(C, false);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<int> suf_gcd(n + 1, 0);
	for (int i = n - 1; i >= 0; --i) {
		suf_gcd[i] = suf_gcd[i + 1];
		if (have[a[i]]) {
			suf_gcd[i] = max(suf_gcd[i], a[i]);
			continue;
		}
		have[a[i]] = true;
		for (int d : dels[a[i]]) {
			if (last_mult[d] == n) {
				last_mult[d] = i;
			}
			else {
				suf_gcd[i] = max(suf_gcd[i], d);
			}
		}
	}
	have.assign(C, false);

	set<pair<int, int>> maxes;
	vector<int> left_border(n + 1, n);
	left_border[n] = 0;
	maxes.insert({n, 0});
	li cur_sum = 0;
	for (int i = n - 1; i >= 0; --i) {
		maxes.insert({ i, suf_gcd[i] });
		left_border[i] = i - 1;
		cur_sum += suf_gcd[i] * 1LL * (i - left_border[i]);
	}
	
	li ans = 0;
	int pref_gcd = 0;
	vector<char> have_pref(C);
	for (int i = 0; i < n; ++i) {
		while (maxes.begin()->first <= i) {
			auto it = maxes.begin();
			cur_sum -= it->second * 1LL * (it->first - left_border[it->first]);
			maxes.erase(it);
		}
		{
			auto it = maxes.begin();
			cur_sum += it->second * 1LL * left_border[it->first];
			left_border[it->first] = 0;
		}
		//cout << cur_sum << ' ' << cur_sum - maxes.begin()->second * 1LL * i << '\n';
		ans += cur_sum - maxes.begin()->second * 1LL * i;

		int cur = a[i];
		if (!have[cur]) {
			have[cur] = true;
			for (int d : dels[cur]) {
				if (have_pref[d]) {
					pref_gcd = max(pref_gcd, d);
				}
				have_pref[d] = true;
				int pos = last_mult[d];
				if (pos == n || pos == i) {
					continue;
				}
				auto it = maxes.lower_bound({ pos, 0 });
				if (it->second >= d) {
					continue;
				}
				cur_sum -= it->second * 1LL * (it->first - left_border[it->first]);
				left_border[it->first] = pos;
				cur_sum += it->second * 1LL * (it->first - left_border[it->first]);
				it = maxes.lower_bound({ pos + 1, 0 });
				int new_border = 0;
				if (it != maxes.begin()) {
					--it;
					bool halt = false;
					while (it->second <= d) {
						cur_sum -= it->second * 1LL * (it->first - left_border[it->first]);
						auto prev = it;
						if (it == maxes.begin()) {
							halt = true;
						}
						if (!halt) {
							--it;
						}
						maxes.erase(prev);
						if (halt) {
							break;
						}
					}
					if (!halt) {
						new_border = it->first;
					}
				}
				left_border[pos] = new_border;
				cur_sum += d * 1LL * (pos - left_border[pos]);
				maxes.insert({ pos, d });
			}
		}
		else {
			pref_gcd = max(pref_gcd, cur);
		}

		while (!maxes.empty()) {
			auto it = maxes.end();
			--it;
			if (it->second <= pref_gcd) {
				cur_sum -= it->second * 1LL * (it->first - left_border[it->first]);
			}
			else {
				break;
			}
			maxes.erase(it);
		}

		int new_border = 0;
		if (!maxes.empty()) {
			auto it = maxes.end();
			--it;
			new_border = it->first;
		}
		left_border[n] = new_border;
		cur_sum += pref_gcd * 1LL * (n - left_border[n]);
		maxes.insert({ n, pref_gcd });
	}

	cout << ans << "\n";	

}