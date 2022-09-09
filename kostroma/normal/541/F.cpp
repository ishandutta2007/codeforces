#define _CRT_SECURE_NO_WARNINGS
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
#ifdef VK
	freopen("input.txt", "r", stdin);
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

#ifdef VK
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

//#define int li

vector<int> tasks[1010];
int dp[111][1010];

int go(int t, int num) {
	num = min(num, 1000);
	if (dp[t][num] != -1)
		return dp[t][num];
	if (num == 0)
		return 0;
	if (t == 0)
		return 0;

	int cursum = 0;
	int& res = dp[t][num];
	for (int i = 0; i <= tasks[t].size() && i <= num; ++i) {
		res = max(res, go(t - 1, 2 * (num - i)) + cursum) ;
		 if (i != tasks[t].size())
			cursum += tasks[t][i];
	}


	//cout << t << ' ' << num << ' ' << res <<  endl;
	return res;
}

void solve() {
	int n, t;
	cin >> n >> t;


	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		tasks[a].push_back(b);
	}

	for (int i = 1; i <= t; ++i) {
		sort(all(tasks[i]));
		reverse(all(tasks[i]));
	}

	memset(dp, -1, sizeof dp);

	cout << go(t, 1);
}