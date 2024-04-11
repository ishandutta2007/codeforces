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

//#define int li

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


int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//#define int li

//const int mod = 1000000007;

const int L = 17;

vector<vector<int>> g;
vector<vector<int>> parent;
vector<vector<vector<int>>> mins;

int tim = 1;

vector<int> tin, tout;

void dfs1(int v, int p = 0) {
	tin[v] = tim++;
	parent[v][0] = p;
	for (int j = 1; j < L; ++j) {
		parent[v][j] = parent[parent[v][j - 1]][j - 1];
	}
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		dfs1(to, v);
	}
	tout[v] = tim++;
}

bool upper(int a, int b) {
	return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca(int a, int b) {
	if (upper(a, b)) {
		return a;
	}
	for (int j = L - 1; j >= 0; --j) {
		if (!upper(parent[a][j], b)) {
			a = parent[a][j];
		}
	}
	return parent[a][0];
}

const int max_size = 10;

vector<int> merge_sort(const vector<int>& a, const vector<int>& b) {
	vector<int> res;
	int j = 0;
	for (int i = 0; i < a.size(); ++i) {
		while (j < b.size() && b[j] < a[i]) {
			res.push_back(b[j]);
			++j;
			if (res.size() == max_size) {
				return res;
			}
		}
		res.push_back(a[i]);
		if (res.size() == max_size) {
			return res;
		}
	}
	while (j < b.size()) {
		res.push_back(b[j]);
		++j;
		if (res.size() == max_size) {
			return res;
		}
	}
	return res;
}

vector<int> get_up(int v, int p) {
	vector<int> res;
	if (p == v) {
		return res;
	}
	for (int j = L - 1; j >= 0; --j) {
		if (!upper(parent[v][j], p)) {
			res = merge_sort(res, mins[v][j]);
			v = parent[v][j];
		}
	}
	res = merge_sort(res, mins[v][0]);
	return res;
}

void solve() {
	int n, m, Q;
	cin >> n >> m >> Q;
	g.resize(n);
	parent.assign(n, vector<int>(L, 0));
	mins.assign(n, vector<vector<int>>(L));
	tin.resize(n);
	tout.resize(n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	dfs1(0);

	for (int i = 0; i < m; ++i) {
		int cur;
		cin >> cur;
		--cur;
		mins[cur][0].push_back(i);
	}
	for (int v = 0; v < n; ++v) {
		sort(all(mins[v][0]));
		if (mins[v][0].size() > max_size) {
			mins[v][0].resize(max_size);
		}
	}

	for (int j = 1; j < L; ++j) {
		for (int v = 0; v < n; ++v) {
			mins[v][j] = merge_sort(mins[v][j - 1], mins[parent[v][j - 1]][j - 1]);
		}
	}

	while (Q--) {
		int u, v, size;
		cin >> u >> v >> size;
		--u; --v;
		int p = lca(u, v);
		vector<int> res = merge_sort(get_up(u, p), get_up(v, p));
		res = merge_sort(res, mins[p][0]);
		if (res.size() > size) {
			res.resize(size);
		}
		cout << res.size();
		for (auto v : res) {
			cout << ' ' << v + 1;
		}
		cout << "\n";
	}

}