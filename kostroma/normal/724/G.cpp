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

const int mod = 1000000007;

const int L = 60;

vector<vector<pair<int, int>>> g;
vector<int> parent;

vector<int> cur_xor;
vector<int> comp;

vector<vector<vector<int>>> parity;

void dfs(int v, int cur_val, int num_comp) {
	cur_xor[v] = cur_val;
	comp[v] = num_comp;
	for (int i = 0; i < L; ++i) {
		int c = 0;
		if (cur_val & (1LL << i)) {
			c = 1;
		}
		++parity[num_comp][i][c];
	}
	for (auto item : g[v]) {
		int to = item.first;
		if (parent[to] == -1) {
			parent[to] = v;
			dfs(to, cur_val ^ item.second, num_comp);
		}
	}
}

void solve(bool read) {
	int n, m;
	cin >> n >> m;
	/*n = 100000;
	m = 0;*/
	g.resize(n);
	vector<pair<pair<int, int>, int>> edges;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		/*a = 1 + rand() % n;
		b = 1 + rand() % n;
		c = abs((rand() * (1LL << 32)) | rand());*/
		--a; --b;
		g[a].push_back({ b, c });
		g[b].push_back({ a, c });
		edges.push_back({ { a, b }, c });
	}
	parent.assign(n, -1);
	cur_xor.resize(n);
	comp.assign(n, -1);
	int cnt_comps = 0;
	for (int i = 0; i < n; ++i) {
		if (parent[i] == -1) {
			parent[i] = i;
			parity.push_back(vector<vector<int>>(L, vector<int>(2, 0)));
			dfs(i, 0, cnt_comps);
			++cnt_comps;
		}
	}

	vector<vector<int>> vecs(cnt_comps);

	for (auto item : edges) {
		int a = item.first.first;
		int b = item.first.second;
		int w = item.second;
		if (parent[a] == b || parent[b] == a) {
			continue;
		}
		vecs[comp[a]].push_back(w ^ cur_xor[a] ^ cur_xor[b]);
	}

	vector<int> good_vecs;
	vector<int> first_bit;
	vector<int> cnt_bits(2, 0);
	vector<int> can(2, 0);
	vector<int> in_comp(2, 0);
	int res = 0;
	//cerr << cnt_comps << endl;

	vector<int> powers(n + 1, 1);
	for (int i = 1; i < powers.size(); ++i) {
		powers[i] = powers[i - 1] * 2 % mod;
	}

	for (int i = 0; i < cnt_comps; ++i) {
		good_vecs.clear();
		first_bit.clear();
		for (int x : vecs[i]) {
			for (int j = 0; j < good_vecs.size(); ++j) {
				if (x & (1LL << first_bit[j])) {
					x ^= good_vecs[j];
				}
			}
			if (x != 0) {
				good_vecs.push_back(x);
				first_bit.push_back(-1);
				for (int r = 0; r < L; ++r) {
					if (x & (1LL << r)) {
						first_bit.back() = r;
						break;
					}
				}
				assert(first_bit.back() != -1);
			}
		}
		for (int j = 0; j < L; ++j) {
			cnt_bits.assign(2, 0);
			for (int x : good_vecs) {
				if (x & (1LL << j)) {
					++cnt_bits[1];
				}
				else {
					++cnt_bits[0];
				}
			}
			can.assign(2, 0);
			can[0] = can[1] = powers[cnt_bits[0]]; //binpow(2LL, cnt_bits[0], mod);
			if (cnt_bits[1] > 0) {
				can[0] = can[0] * powers[cnt_bits[1] - 1] % mod; // binpow(2LL, cnt_bits[1] - 1, mod) % mod;
				can[1] = can[1] * powers[cnt_bits[1] - 1] % mod; // binpow(2LL, cnt_bits[1] - 1, mod) % mod;
			}
			else {
				can[1] = 0;
			}
			in_comp.assign(2, 0);
			in_comp[1] = parity[i][j][0] * parity[i][j][1];
			for (int c = 0; c < 2; ++c) {
				if (parity[i][j][c] > 0) {
					in_comp[0] += parity[i][j][c] * (parity[i][j][c] - 1) / 2;
				}
			}

			int coef = in_comp[0] % mod * can[1] + in_comp[1] % mod * can[0];
			coef %= mod;
			res += powers[j] * coef;
			res %= mod;

			//cout << j << ' ' << coef << ' ' << res << "\n";

		}
	}

	if (res < 0) {
		res += mod;
	}

	cout << res << "\n";

}