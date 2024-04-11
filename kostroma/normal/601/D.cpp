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

//#define int li

int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 300500;
int powers[2][C];

//int MOD = 1000000007;

//int c[5010][5010];

//int catalan[200500];

//ld doubleC[100][100];

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

//const int mod = 1000000007;

string letters;

vector<vector<int>> g;

vector<int> tin, tout;

int tim = 0;

vector<int> order;

vector<li> v_hashes;

void dfs(int v, int p, vector<int> hashes) {
	for (int i = 0; i < 2; ++i) {
		hashes[i] = (hashes[i] * 1LL * pr[i] + letters[v]) % mods[i];
	}
	v_hashes[v] = (hashes[0] * (1LL << 32)) | hashes[1];
	tin[v] = tim++;
	order.push_back(v);
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		dfs(to, v, hashes);
	}
	order.push_back(v);
	tout[v] = tim++;
}

const int shift = 1 << 20;

int tree[2 * shift + 5];

void modify(int v, int val) {
	v += shift;
	tree[v] += val;
	v /= 2;
	while (v) {
		tree[v] = tree[2 * v] + tree[2 * v + 1];
		v /= 2;
	}
}

int rsq(int l, int r) {
	if (l >= r) {
		return 0;
	}
	if (l & 1) {
		return tree[l] + rsq(l + 1, r);
	}
	if (r & 1) {
		return rsq(l, r - 1) + tree[r - 1];
	}
	return rsq(l / 2, r / 2);
}

int get_sum(int l, int r) {
	return rsq(l + shift, r + shift);
}

void solve() {
	int n;
	cin >> n;
	vector<int> adds(n);
	for (int i = 0; i < n; ++i) {
		cin >> adds[i];
	}
	cin >> letters;
	g.resize(n);
	for (int i = 1; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	tin.resize(n);
	tout.resize(n);
	v_hashes.resize(n);
	dfs(0, -1, vector<int>(2, 0));

	vector<li> ordered = v_hashes;
	sort(all(ordered));
	ordered.erase(unique(all(ordered)), ordered.end());

	vector<int> num(n);
	for (int i = 0; i < n; ++i) {
		num[i] = lower_bound(all(ordered), v_hashes[i]) - ordered.begin();
	}

	vector<int> res(n);

	vector<vector<pair<int, int>>> queries(order.size());
	vector<vector<int>> poses(ordered.size());
	for (int i = 0; i < n; ++i) {
		queries[tin[i]].push_back(mp(tout[i], i));
	}
	for (int i = 0; i < order.size(); ++i) {
		poses[num[order[i]]].push_back(i);
	}

	vector<int> uk(ordered.size());
	for (int i = 0; i < ordered.size(); ++i) {
		if (uk[i] < poses[i].size()) {
			modify(poses[i][uk[i]], 1);
			++uk[i];
		}
	}
	
	for (int i = 0; i < order.size(); ++i) {
		for (auto item : queries[i]) {
			res[item.second] = get_sum(i, item.first);
		}
		int cur_num = num[order[i]];
		if (uk[cur_num] < poses[cur_num].size()) {
			modify(poses[cur_num][uk[cur_num]], 1);
			++uk[cur_num];
		}
	}

	int mx = 0;
	for (int i = 0; i < n; ++i) {
		res[i] += adds[i];
		mx = max(mx, res[i]);
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (res[i] == mx) {
			++cnt;
		}
	}
	cout << mx << "\n";
	cout << cnt << "\n";

}