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

int get_var() {
	int cur;
	cin >> cur;
	int dom = 0;
	if (cur < 0) {
		dom = 1;
		cur = -cur;
	}
	--cur;
	return 2 * cur + dom;
}

int n;
vector <vector<int>> g, gr;
vector<char> used;
vector<int> order;
vector<vector<int>> components;
vector<int> num_comp;

void dfs1(int v) {
	used[v] = true;
	for (size_t i = 0; i<g[v].size(); ++i)
		if (!used[g[v][i]])
			dfs1(g[v][i]);
	order.push_back(v);
}

void dfs2(int v, int col) {
	used[v] = true;
	components[col].push_back(v);
	num_comp[v] = col;
	for (size_t i = 0; i<gr[v].size(); ++i)
		if (!used[gr[v][i]])
			dfs2(gr[v][i], col);
}

void solve_2sat() {
	used.assign(n * 2, false);
	for (int i = 0; i < g.size(); ++i) {
		if (!used[i]) {
			dfs1(i);
		}
	}
	used.assign(n * 2, false);
	int comps = 0;
	components.clear();
	num_comp.clear();
	num_comp.resize(2 * n);
	for (int i = 0; i < order.size(); ++i) {
		int v = order[order.size() - 1 - i];
		if (!used[v]) {
			components.push_back(vector<int>());
			dfs2(v, comps++);
		}
	}
}

void solve() {
	cin >> n;
	vector<int> m(2);
	cin >> m[0] >> m[1];
	vector<vector<pair<int, int>>> dis(2);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < m[i]; ++j) {
			int cur1 = get_var(), cur2 = get_var();
			dis[i].push_back(mp(cur1, cur2));
		}
	}

	for (int bui = 0; bui < 2; ++bui) {
		g.clear();
		gr.clear();
		g.resize(2 * n);
		gr.resize(2 * n);
		for (auto& e : dis[bui]) {
			g[e.first ^ 1].push_back(e.second);
			g[e.second ^ 1].push_back(e.first);
			gr[e.second].push_back(e.first ^ 1);
			gr[e.first].push_back(e.second ^ 1);
		}

		solve_2sat();
		
		int comps = components.size();
		vector<vector<int>> new_g(comps);
		for (int i = 0; i < 2 * n; ++i) {
			for (int to : g[i]) {
				new_g[num_comp[i]].push_back(num_comp[to]);
			}
		}
		for (int i = 0; i < comps; ++i) {
			sort(all(new_g[i]));
			new_g[i].erase(unique(all(new_g[i])), new_g[i].end());
		}
		vector<bitset<2001>> reachable(comps);
		for (int i = comps - 1; i >= 0; --i) {
			reachable[i][i] = 1;
			for (int to : new_g[i]) {
				reachable[i] |= reachable[to];
			}
		}

		bool f = true;
		for (int i = 0; i < n; ++i) {
			if (num_comp[2 * i] == num_comp[2 * i + 1]) {
				f = false;
				break;
			}
		}
		if (!f) {
			continue;
		}

		for (auto& e : dis[bui ^ 1]) {
			int a = e.first, ne_a = e.first ^ 1;
			int b = e.second, ne_b = e.second ^ 1;
			if (reachable[num_comp[ne_a]][num_comp[a]] || reachable[num_comp[ne_b]][num_comp[b]] ||
				(reachable[num_comp[ne_b]][num_comp[a]] && reachable[num_comp[ne_a]][num_comp[b]])) {
			}
			else {
				g[a].push_back(ne_a);
				g[b].push_back(ne_b);
				gr[ne_a].push_back(a);
				gr[ne_b].push_back(b);
				solve_2sat();

				int comps = components.size();
				vector<int> assigned(comps, -1);
				for (int i = comps - 1; i >= 0; --i) {
					if (assigned[i] != -1) {
						continue;
					}
					assigned[i] = 1;
					for (int to : components[i]) {
						assigned[num_comp[to ^ 1]] = 0;
					}
				}

				vector<int> res(2 * n);
				for (int i = 0; i < comps; ++i) {
					for (int v : components[i]) {
						res[v] = assigned[i];
					}
				}
				for (int i = 0; i < n; ++i) {
					cout << res[2 * i] << ' ';
				}

				return;
			}
		}

	}
	
	cout << "SIMILAR\n";

}