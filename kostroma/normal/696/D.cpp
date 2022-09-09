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
/*#ifndef room111
#include <sys/resource.h>
#endif*/
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

const int K = 26;

struct vertex {
	int next[K];
	int p;
	char pch;
	int link;
	int go[K];
	vector<int> leaves;
	int sum_good;
};

const int NMAX = 1000;

vertex t[NMAX + 1];
int sz;

void init() {
	t[0].p = t[0].link = -1;
	memset(t[0].next, 255, sizeof t[0].next);
	memset(t[0].go, 255, sizeof t[0].go);
	sz = 1;
}

void add_string(const string & s, int id) {
	int v = 0;
	for (size_t i = 0; i<s.length(); ++i) {
		char c = s[i] - 'a';
		if (t[v].next[c] == -1) {
			memset(t[sz].next, 255, sizeof t[sz].next);
			memset(t[sz].go, 255, sizeof t[sz].go);
			t[sz].link = -1;
			t[sz].p = v;
			t[sz].pch = c;
			t[v].next[c] = sz++;
		}
		v = t[v].next[c];
	}
	t[v].leaves.push_back(id);
}

int go(int v, char c);

int get_link(int v) {
	if (t[v].link == -1)
		if (v == 0 || t[v].p == 0)
			t[v].link = 0;
		else
			t[v].link = go(get_link(t[v].p), t[v].pch);
	return t[v].link;
}

int go(int v, char c) {
	if (t[v].go[c] == -1)
		if (t[v].next[c] != -1)
			t[v].go[c] = t[v].next[c];
		else
			t[v].go[c] = v == 0 ? 0 : go(get_link(v), c);
	return t[v].go[c];
}

const int L = 50;

void solve() {
	int n, l;
	cin >> n >> l;
	vector<int> a(n);
	vector<string> s(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	init();
	for (int i = 0; i < n; ++i) {
		add_string(s[i], i);
	}

	for (int i = 0; i < sz; ++i) {
		int link = get_link(i);
		while (link) {
			for (int to : t[link].leaves) {
				t[i].leaves.push_back(to);
			}
			link = get_link(link);
		}
		sort(all(t[i].leaves));
		t[i].leaves.erase(unique(all(t[i].leaves)), t[i].leaves.end());
		for (int to : t[i].leaves) {
			t[i].sum_good += a[to];
		}
	}

	vector<vector<vector<int>>> dp(L, vector<vector<int>>(sz, vector<int>(sz, -1e17)));
	for (int i = 0; i < sz; ++i) {
		for (int c = 0; c < 26; ++c) {
			int nex = go(i, c);
			dp[0][i][nex] = max(dp[0][i][nex], t[nex].sum_good);
		}
	}

	for (int i = 0; i + 1 < L; ++i) {
		for (int v = 0; v < sz; ++v) {
			for (int u = 0; u < sz; ++u) {
				for (int w = 0; w < sz; ++w) {
					dp[i + 1][v][u] = max(dp[i + 1][v][u], dp[i][v][w] + dp[i][w][u]);
				}
			}
		}
	}

	vector<int> best(sz, -1e17);
	vector<int> new_best(sz, -1e17);
	best[0] = 0;
	for (int i = 0; i < L; ++i) {
		if (l & 1) {
			new_best.assign(sz, -1e17);
			for (int v = 0; v < sz; ++v) {
				for (int u = 0; u < sz; ++u) {
					new_best[u] = max(new_best[u], best[v] + dp[i][v][u]);
				}
			}
			best.swap(new_best);
		}
		l >>= 1;
	}

	int res = 0;
	for (int to : best) {
		res = max(res, to);
	}

	cout << res << "\n";
	
}