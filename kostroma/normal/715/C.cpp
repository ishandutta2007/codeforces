#pragma comment(linker, "/STACK:1024000000")
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
#include <functional>
/*#ifndef room111
#include <sys/resource.h>
#endif*/
#include <unordered_set>
#include <unordered_map>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

bool stress = false;

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
	/*#ifndef room111
	const rlim_t kStackSize = 128L * 1024L * 1024L;   // min stack size = 64 Mb
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0)
	{
	if (rl.rlim_cur < kStackSize)
	{
	rl.rlim_cur = kStackSize;
	result = setrlimit(RLIMIT_STACK, &rl);
	if (result != 0)
	{
	fprintf(stderr, "setrlimit returned result = %d\n", result);
	}
	}
	}
	#endif*/

	//cin >> t;
	int testNum = 1;
	while (t--) {
		//cerr << testNum << endl;
		//cout << "Case #" << testNum++ << ": ";
		solve(true);
		++testNumber;
		//++timer;
	}
#ifdef room1111
	while (true)
		solve(false);
#endif

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

int M;

vector<vector<pair<int, int>>> g;

int ANS = 0;

vector<int> powers, revpowers;

vector<char> used;
vector<int> cnt;
vector<int> mx_cnt;
vector<int> have;

void dfs(int v, int p) {
	cnt[v] = 1;
	have.push_back(v);
	int mx = 0;
	for (auto item : g[v]) {
		if (item.first == p || used[item.first]) {
			continue;
		}
		dfs(item.first, v);
		cnt[v] += cnt[item.first];
		mx = max(mx, cnt[item.first]);
	}
	mx_cnt[v] = mx;
}

vector<map<int, int>> sum_up;
map<int, int> all_up;

void dfs_up(int v, int p, int sum, int lev) {
	++sum_up.back()[sum];
	++all_up[sum];
	for (auto item : g[v]) {
		int to = item.first, d = item.second;
		if (to == p || used[to]) {
			continue;
		}
		dfs_up(to, v, (sum + d * powers[lev]) % M, lev + 1);
	}
}

void dfs_down(int v, int p, int sum, int id, int lev) {
	int need = ((M - sum) % M) * revpowers[lev] % M;
	if (all_up.count(need)) {
		ANS += all_up[need];
		if (sum_up[id].count(need)) {
			ANS -= sum_up[id][need];
		}
	}
	for (auto item : g[v]) {
		int to = item.first, d = item.second;
		if (to == p || used[to]) {
			continue;
		}
		dfs_down(to, v, (sum * 10 + d) % M, id, lev + 1);
	}
}

void centroid(int v) {
	if (used[v]) {
		return;
	}
	have.clear();
	dfs(v, v);
	int center = -1;
	for (int x : have) {
		if (mx_cnt[x] <= cnt[v] / 2 && cnt[v] - cnt[x] <= cnt[v] / 2) {
			center = x;
			break;
		}
	}
	assert(center != -1);
	sum_up.clear();
	all_up.clear();
	++all_up[0];
	for (auto item : g[center]) {
		int to = item.first;
		if (used[to]) {
			continue;
		}
		sum_up.push_back(map<int, int>());
		dfs_up(to, center, item.second % M, 1);
	}
	ANS += all_up[0] - 1;

	int id = 0;
	for (auto item : g[center]) {
		int to = item.first;
		if (used[to]) {
			continue;
		}
		dfs_down(to, center, item.second % M, id, 1);
		++id;
	}

	//cout << center << ' ' << ANS << endl;

	used[center] = true;
	for (auto item : g[center]) {
		int to = item.first;
		if (used[to]) {
			continue;
		}
		centroid(to);
	}
}

void solve(bool read) {
	int n;
	cin >> n >> M;
	/*n = 100000;
	M = 1e9;*/
	powers.resize(n + 1, 1);
	for (int i = 1; i < powers.size(); ++i) {
		powers[i] = powers[i - 1] * 10 % M;
	}
	revpowers.resize(n + 1);
	int phi = M;
	int CUR = M;
	for (int p = 2; p * p <= CUR; ++p) {
		if (CUR % p == 0) {
			phi = phi / p * (p - 1);
			while (CUR % p == 0) {
				CUR /= p;
			}
		}
	}
	if (CUR > 1) {
		phi = phi / CUR * (CUR - 1);
	}
	for (int i = 0; i < powers.size(); ++i) {
		revpowers[i] = binpow(powers[i], phi - 1, M);
	}
	g.resize(n);
	for (int i = 1; i < n; ++i) {
		int a, b, d;
		cin >> a >> b >> d;
		/*d = rand() % 10;
		a = i - 1;
		b = i;*/
		g[a].push_back({ b, d });
		g[b].push_back({ a, d });
	}

	used.assign(n, false);
	cnt.assign(n, 0);
	mx_cnt.assign(n, 0);
	centroid(0);

	cout << ANS << "\n";

}