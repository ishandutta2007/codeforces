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
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
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
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
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

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 100500;
int powers[2][C];*/

int MOD = 1000000007;

int c[5010][5010];

//int catalan[200500];

//ld doubleC[100][100];

int binpow(int q, int w, int mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

void precalc() {

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

	for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}

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

//int mod = 1000000007;

int getId(char c) {
	if (c == 'V') {
		return 0;
	}
	if (c == 'C') {
		return 1;
	}
}

vector <vector<int>> g, gt;
vector<bool> used;
vector<int> order, comp;

void dfs1(int v) {
	used[v] = true;
	for (size_t i = 0; i<g[v].size(); ++i) {
		int to = g[v][i];
		if (!used[to])
			dfs1(to);
	}
	order.push_back(v);
}

void dfs2(int v, int cl) {
	comp[v] = cl;
	for (size_t i = 0; i<gt[v].size(); ++i) {
		int to = gt[v][i];
		if (comp[to] == -1)
			dfs2(to, cl);
	}
}

bool hasSolution(int n){
	used.assign(n, false);
	order.clear();
	for (int i = 0; i < n; ++i)
		if (!used[i])
			dfs1(i);

	comp.assign(n, -1);
	for (int i = 0, j = 0; i<n; ++i) {
		int v = order[n - i - 1];
		if (comp[v] == -1)
			dfs2(v, j++);
	}

	for (int i = 0; i<n; ++i)
		if (comp[i] == comp[i ^ 1]) {
			return false;
		}
	return true;
}

vector <vector<vector<pair<int, int>>>> edges;

vector<int> newFixed;

bool dfs(int pos, int type) {
	if (newFixed[pos] != -1) {
		return newFixed[pos] == type;
	}
	newFixed[pos] = type;
	bool f = true;
	for (auto item : edges[pos][type]) {
		f &= dfs(item.first, item.second);
	}
	return f;
}

bool getSol(int n) {
	g.clear();
	gt.clear();
	g.resize(2 * n);
	gt.resize(2 * n);
	for (int i = 0; i < n; ++i) {
		if (newFixed[i] != -1) {
			continue;
		}
		for (int curType = 0; curType < 2; ++curType) {
			for (auto item : edges[i][curType]) {
				if (newFixed[item.first] != -1) {
					continue;
				}
				g[i * 2 + curType].push_back(item.first * 2 + item.second);
				gt[item.first * 2 + item.second].push_back(i * 2 + curType);
			}
		}
	}
	return hasSolution(2 * n);
}

void solve() {
	string Type;
	cin >> Type;
	int letters = Type.length();
	vector<int> type(letters);
	for (int i = 0; i < letters; ++i) {
		type[i] = (Type[i] == 'C');
	}
	int n, m;
	cin >> n >> m;
	edges.assign(n, vector<vector<pair<int, int>>>(2));

	for (int i = 0; i < m; ++i) {
		int pos1, pos2;
		char t1, t2;
		cin >> pos1 >> t1 >> pos2 >> t2;
		--pos1; --pos2;
		edges[pos1][getId(t1)].push_back(mp(pos2, getId(t2)));
		edges[pos2][getId(t2) ^ 1].push_back(mp(pos1, getId(t1) ^ 1));
	}

	string s;
	cin >> s;

	vector<int> has(2);
	for (int i = 0; i < letters; ++i) {
		has[type[i]] = 1;
	}
	for (int w = 0; w < 2; ++w) {
		if (!has[w]) {
			for (int pos = 0; pos < n; ++pos) {
				for (auto item : edges[pos][w ^ 1]) {
					if (item.second == w) {
						cout << "-1\n";
						return;
					}
				}
			}
			cout << s;
			return;
		}
	}

	vector<int> fixedType(n, -1);

	int pref = n;

	vector<vector<int>> memorized;

	for (int pos = 0; pos < n; ++pos) {
		memorized.push_back(fixedType);
		newFixed = fixedType;
		if (!dfs(pos, type[s[pos] - 'a'])) {
			pref = pos;
			break;
		}
		else {
			if (!getSol(n)) {
				pref = pos;
				break;
			}
			fixedType.swap(newFixed);
		}
	}

	int good = -1;

	vector<int> res(n, -1);

	if (pref < n) {
		for (int pos = pref; pos >= 0; --pos) {
			fixedType = memorized[pos];

			int checked[2];
			checked[0] = checked[1] = -1;

			bool found = false;

			int start = s[pos] - 'a';

			for (int cur = start + 1; cur < letters; ++cur) {
				if (checked[type[cur]] != -1) {
					continue;
				}
				newFixed = fixedType;
				if (!dfs(pos, type[cur])) {
					checked[type[cur]] = 0;
					continue;
				}

				checked[type[cur]] = getSol(n);

				if (checked[type[cur]]) {
					res[pos] = cur;
					for (int j = pos - 1; j >= 0; --j) {
						res[j] = s[j] - 'a';
					}
					found = true;
					good = pos;
					newFixed.swap(fixedType);
					break;
				}
			}
			if (found) {
				break;
			}
		}

		if (good == -1) {
			cout << "-1\n";
			return;
		}

		for (int pos = good + 1; pos < n; ++pos) {
			if (fixedType[pos] != -1) {
				for (int cur = 0; cur < letters; ++cur) {
					if (type[cur] == fixedType[pos]) {
						res[pos] = cur;
						break;
					}
				}
				continue;
			}
			int checked[2];
			checked[0] = checked[1] = -1;
			for (int cur = 0; cur < letters; ++cur) {
				if (checked[type[cur]] != -1) {
					continue;
				}
				newFixed = fixedType;
				if (!dfs(pos, type[cur])) {
					checked[type[cur]] = 0;
					continue;
				}
				checked[type[cur]] = getSol(n);
				if (checked[type[cur]]) {
					newFixed.swap(fixedType);
					res[pos] = cur;
					break;
				}
			}
			assert(res[pos] != -1);
		}

		for (int pos = 0; pos < n; ++pos) {
			cout << char('a' + res[pos]);
		}

	}
	else {
		cout << s << "\n";
	}

}