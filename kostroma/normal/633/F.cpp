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

vector<int> a;

vector<vector<int>> g;

vector < vector<pair<int, int>> > down_best;

vector<int> best_both;

vector < vector<pair<int, int>> > down_both;

const int DOWN_BEST = 3;

const int DOWN_BOTH = 2;

void dfs_down(int v, int p) {
	if (v != p && g[v].size() == 1) {
		down_best[v].push_back(mp(a[v], v));
		down_both[v].push_back(mp(a[v], v));
		best_both[v] = a[v];
		return;
	}
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		dfs_down(to, v);
		down_best[v].push_back(mp(down_best[to][0].first + a[v], to));
		down_both[v].push_back(mp(best_both[to], to));
		best_both[v] = max(best_both[v], best_both[to]);
	}
	sort(all(down_best[v]));
	reverse(all(down_best[v]));
	if (down_best[v].size() > DOWN_BEST) {
		down_best[v].resize(DOWN_BEST);
	}
	if (down_best[v].size() > 1) {
		best_both[v] = max(best_both[v], down_best[v][0].first + down_best[v][1].first - a[v]);
	}
	else {
		best_both[v] = max(best_both[v], down_best[v][0].first);
	}
	sort(all(down_both[v]));
	reverse(all(down_both[v]));
	if (down_both[v].size() > DOWN_BOTH) {
		down_both[v].resize(DOWN_BOTH);
	}
}

vector<int> best_up;

void dfs_up(int v, int p, int cur_res) {
	best_up[v] = cur_res;
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		int push_res = cur_res + a[v];
		for (auto item : down_best[v]) {
			if (item.second != to) {
				push_res = max(push_res, item.first);
			}
		}
		dfs_up(to, v, push_res);
	}
}

int ANS = 0;

void dfs_kill(int v, int p, int other_both, int max_maxup) {
	ANS = max(ANS, other_both + best_both[v]);
	ANS = max(ANS, max_maxup + best_both[v]);
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		int new_both = other_both;
		for (auto item : down_both[v]) {
			if (item.second != to) {
				new_both = max(new_both, item.first);
			}
		}
		for (int i = 0; i < down_best[v].size(); ++i) {
			if (down_best[v][i].second == to) {
				continue;
			}
			ANS = max(ANS, down_best[v][i].first + best_both[to]);
			new_both = max(new_both, down_best[v][i].first + best_up[v]);
			for (int j = i + 1; j < down_best[v].size(); ++j) {
				if (down_best[v][j].second == to) {
					continue;
				}
				ANS = max(ANS, down_best[v][i].first + down_best[v][j].first - a[v] + best_both[to]);
				new_both = max(new_both, down_best[v][i].first + down_best[v][j].first - a[v]);
			}
		}
		int new_maxup = max(max_maxup, best_up[to]);
		dfs_kill(to, v, new_both, new_maxup);
	}
}

void solve() {
	int n;
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	g.resize(n);
	for (int i = 1; i < n; ++i) {
		int u, v;
		cin >> u >> v;
		--u; --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	down_best.resize(n);
	best_both.resize(n);
	down_both.resize(n);
	dfs_down(0, 0);

	best_up.resize(n);
	dfs_up(0, 0, 0);

	dfs_kill(0, 0, 0, 0);

	cout << ANS << "\n";

}