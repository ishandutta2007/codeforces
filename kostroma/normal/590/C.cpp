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

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int n, m;

vector<string> s;

bool correct(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '#';
}

bool correct(pair<int, int> cur) {
	return correct(cur.first, cur.second);
}

void solve() {
	cin >> n >> m;
	s.resize(n);
	vector < vector<pair<int, int>>> cells(3);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < m; ++j) {
			if (s[i][j] >= '1' && s[i][j] <= '3') {
				cells[s[i][j] - '1'].push_back(mp(i, j));
			}
		}
	}

	vector<vector<vector<int>>> dist(3);
	for (int i = 0; i < 3; ++i) {
		dist[i].assign(n, vector<int>(m, -1));
		queue<pair<int, int>> q;
		for (auto item : cells[i]) {
			q.push(item);
			dist[i][item.first][item.second] = 0;
		}

		while (!q.empty()) {
			auto cur = q.front();
			q.pop();

			for (int k = 0; k < 4; ++k) {
				pair<int, int> nex = mp(cur.first + dx[k], cur.second + dy[k]);
				if (correct(nex) && dist[i][nex.first][nex.second] == -1) {
					dist[i][nex.first][nex.second] = dist[i][cur.first][cur.second] + 1;
					q.push(nex);
				}
			}
		}

	}

	int ans = -1;

	vector<vector<int>> distances(3, vector<int>(3, -1));
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (i != j) {
				for (auto item : cells[j]) {
					if (dist[i][item.first][item.second] != -1) {
						if (distances[i][j] == -1 || distances[i][j] > dist[i][item.first][item.second]) {
							distances[i][j] = dist[i][item.first][item.second];
						}
					}
				}
			}
		}
	}

	for (int i = 0; i < 3; ++i) {
		bool flag = true;
		int sum = 0;
		for (int j = 0; j < 3; ++j) {
			if (i != j) {
				if (distances[i][j] == -1) {
					flag = false;
					break;
				}
				sum += distances[i][j] - 1;
			}
		}
		if (flag) {
			if (ans == -1 || ans > sum) {
				ans = sum;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			bool flag = true;
			int sum = 0;
			for (int k = 0; k < 3; ++k) {
				if (dist[k][i][j] == -1) {
					flag = false;
					break;
				}
				sum += dist[k][i][j] - 1;
			}
			if (flag) {
				if (ans == -1 || ans > sum + 1) {
					ans = sum + 1;
				}
			}
		}
	}

	cout << ans << "\n";

}