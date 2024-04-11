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
//void precalc();
clock_t start;
//int timer = 1;


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
	//precalc();
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

int mod = 1000000007;

int n;

int color[100500];

vector<int> g[100500];

int dp[100500][2];

int binpow (int q, int w) {
	if (!w)
		return 1;
	if (w & 1)
		return (q * binpow(q, w - 1)) % mod;
	return binpow((q * q) % mod, w / 2);
}

void dfs(int v) {

	for (int to : g[v])
		dfs(to);

	int res = 1;

	for (int to : g[v]) {
		res *= (dp[to][0] + dp[to][1]);
		res %= mod;
	}
	if (color[v])
		dp[v][1] = res;
	else {
		dp[v][0] = res;

		for (int to : g[v]) {
			 int now = (res * dp[to][1] % mod) * binpow(dp[to][0] + dp[to][1], mod - 2) % mod;
			 dp[v][1] += now;
			 dp[v][1] %= mod;
		}
	}

	//cout << v << ' ' << dp[v][0] << ' ' << dp[v][1] << endl;

}

void solve() {
	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int cur;
		cin >> cur;
		g[cur].push_back(i + 1);
	}

	for (int i = 0; i < n; ++i)
		cin >> color[i];

	dfs(0);

	cout << dp[0][1] % mod;

}