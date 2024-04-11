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

struct Edge {
	int a, b;
	int id;
	int w;
};

vector<vector<Edge>> g;

vector <Edge> edges;

int dijkstra(int s, int t, int n) {
	vector<int> dp(n, 2e9);
	dp[s] = 0;
	set<pair<int, int>> a;
	a.insert({ dp[s],  s });
	while (!a.empty()) {
		auto item = *a.begin();
		a.erase(a.begin());
		int v = item.second;
		for (Edge e : g[v]) {
			int id = e.id;
			int next_len = dp[v] + edges[id].w;
			int to = e.b;
			if (dp[to] > next_len) {
				a.erase({ dp[to], to });
				dp[to] = next_len;
				a.insert({ dp[to], to });
			}
		}
	}
	return dp[t];
}

void solve(bool read) {
	int n, m, L, s, t;
	cin >> n >> m >> L >> s >> t;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		Edge cur;
		cin >> cur.a >> cur.b >> cur.w;
		cur.id = i;
		edges.push_back(cur);
		g[cur.a].push_back(cur);
		swap(cur.a, cur.b);
		g[cur.a].push_back(cur);
	}
	vector<vector<int>> dp(n, vector<int>(n, 2e9));
	vector<vector<int>> pred(n, vector<int>(n, -1));
	dp[s][0] = 0;
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> a;
	a.push({ dp[s][0], { s, 0 } });
	while (!a.empty()) {
		auto item = a.top();
		int v = item.second.first;
		int skip = item.second.second;
		a.pop();
		if (item.first != dp[v][skip]) {
			continue;
		}
		for (Edge e : g[v]) {
			int next_skip = skip;
			int next_len = dp[v][skip];
			int to = e.b;
			if (e.w == 0) {
				++next_skip;
				++next_len;
			}
			else {
				next_len += e.w;
			}
			if (next_skip < n && dp[to][next_skip] > next_len) {
				//a.erase({ dp[to][next_skip], { to, next_skip } });
				dp[to][next_skip] = next_len;
				pred[to][next_skip] = e.id;
				a.push({ dp[to][next_skip], { to, next_skip } });
			}
		}
	}

	for (int skip = 0; skip < n; ++skip) {
		if (dp[t][skip] <= L) {
			if (skip == 0 && dp[t][skip] < L) {
				cout << "NO\n";
				return;
			}
			cout << "YES\n";
			int cur = t;
			int rest = L - dp[t][skip];
			while (cur != s) {
				int id = pred[cur][skip];
				if (edges[id].w == 0) {
					--skip;
					if (skip == 0) {
						edges[id].w = rest + 1;
					}
					else {
						edges[id].w = 1;
					}
				}
				cur = ((edges[id].a == cur) ? edges[id].b : edges[id].a);
			}
			assert(cur == s && skip == 0);

			for (int i = 0; i < m; ++i) {
				if (edges[i].w == 0) {
					edges[i].w = 2e9;
				}
			}

			//cout << dijkstra(s, t, n) << endl;
			//assert(dijkstra(s, t, n) == L);

			for (int i = 0; i < m; ++i) {
				cout << edges[i].a << ' ' << edges[i].b << ' ' << edges[i].w << "\n";
			}

			return;
		}
	}

	cout << "NO\n";

}