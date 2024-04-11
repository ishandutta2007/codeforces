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

bool dfs(int v, int comp, int new_col, const vector<vector<pair<int, int>>>& g, vector<int>& col, vector<int>& used) {
	used[v] = comp;
	col[v] = new_col;
	for (auto item : g[v]) {
		int to = item.first;
		int next_col = (new_col ^ item.second);
		if (used[to] && col[to] != next_col) {
			return false;
		}
		if (used[to]) {
			continue;
		}
		if (!dfs(to, comp, next_col, g, col, used)) {
			return false;
		}
	}
	return true;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pair<pair<int, int>, int>> edges(m);
	for (int i = 0; i < m; ++i) {
		cin >> edges[i].first.first >> edges[i].first.second;
		--edges[i].first.first;
		--edges[i].first.second;
		char c;
		cin >> c;
		if (c == 'B') {
			edges[i].second = 1;
		}
		else {
			edges[i].second = 0;
		}
	}

	int res = 1e9;
	vector<int> ans;

	for (int need = 0; need < 2; ++need) {
		vector<vector<pair<int, int>>> g(n);
		for (auto e : edges) {
			g[e.first.first].push_back(mp(e.first.second, e.second));
			g[e.first.second].push_back(mp(e.first.first, e.second));
		}

		vector<int> used(n, 0), col(n, -1);
		int comps = 0;
		bool flag = true;
		for (int i = 0; i < n; ++i) {
			if (!used[i]) {
				if (!dfs(i, ++comps, 0, g, col, used)) {
					flag = false;
					break;
				}
			}
		}

		if (!flag) {
			for (int i = 0; i < m; ++i) {
				edges[i].second ^= 1;
			}
			continue;
		}

		vector<vector<vector<int>>> nums(comps, vector<vector<int>>(2));
		for (int i = 0; i < n; ++i) {
			nums[used[i] - 1][col[i]].push_back(i);
		}

		vector<int> cur_res;
		for (int i = 0; i < comps; ++i) {
			int w = 0;
			if (nums[i][w].size() > nums[i][w ^ 1].size()) {
				w ^= 1;
			}
			for (int v : nums[i][w]) {
				cur_res.push_back(v);
			}
		}

		if (res > cur_res.size()) {
			res = cur_res.size();
			ans = cur_res;
		}

		for (int i = 0; i < m; ++i) {
			edges[i].second ^= 1;
		}
	}

	if (res > 1e8) {
		cout << "-1\n";
	}
	else {
		cout << res << "\n";
		for (int v : ans) {
			cout << v + 1 << ' ';
		}
	}

}