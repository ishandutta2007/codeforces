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


void solve() {
	int n;
	string s;
	cin >> n >> s;
	string cur = "RGB";
	vector<int> num(3);
	for (int i = 0; i < s.length(); ++i) {
		for (int j = 0; j < 3; ++j) {
			if (cur[j] == s[i]) {
				++num[j];
			}
		}
	}

	vector<vector<vector<int>>> dp(num[0] + num[1] + num[2] + 1, 
		vector<vector<int>>(num[0] + num[1] + num[2] + 1, vector<int>(num[0] + num[1] + num[2] + 1, 0)));
	dp[num[0]][num[1]][num[2]] = 1;
	vector<int> a(3);
	for (int sum = num[0] + num[1] + num[2]; sum > 0; --sum) {
		for (a[1] = sum; a[1] >= 0; --a[1]) {
			for (a[2] = sum; a[2] >= 0; --a[2]) {
				a[0] = sum - a[1] - a[2];
				if (a[0] < 0 || !dp[a[0]][a[1]][a[2]]) {
					continue;
				}
				auto nex = a;
				for (int j = 0; j < 3; ++j) {
					if (a[(j + 1) % 3] > 0 && a[(j + 2) % 3] > 0) {
						nex = a;
						--nex[(j + 1) % 3];
						--nex[(j + 2) % 3];
						++nex[j];
						dp[nex[0]][nex[1]][nex[2]] = 1;
					}
					if (a[j] > 1) {
						nex = a;
						nex[j]--;
						dp[nex[0]][nex[1]][nex[2]] = 1;
					}
				}
			}
		}
	}

	string res;
	if (dp[1][0][0]) {
		res += cur[0];
	}
	if (dp[0][1][0]) {
		res += cur[1];
	}
	if (dp[0][0][1]) {
		res += cur[2];
	}
	sort(all(res));
	cout << res << endl;

}