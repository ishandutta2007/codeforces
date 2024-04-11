#pragma comment (linker, "/STACK:128000000")
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
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
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

bool doing = true;

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

void precalc() {


}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

//int mod = 1000000007;

//#define int li

int n, m;

string s[2010];

bool good(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && s[x][y] == '.';
}

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int sos[2010][2010];

void fillAns(pair<int, int> cur, pair<int, int> nex) {
	if (cur > nex)
		swap(cur, nex);
	if (cur.first == nex.first) {
		s[cur.first][cur.second] = '<';
		s[nex.first][nex.second] = '>';
	}
	else {
		s[cur.first][cur.second] = '^';
		s[nex.first][nex.second] = 'v';
	}
}

void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	int cnt = 0;
	queue<pair<int, int>> q;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (!good(i, j))
				continue;
			++cnt;
			for (int dir = 0; dir < 4; ++dir) {
				int X = i + dx[dir], Y = j + dy[dir];
				if (good(X, Y))
					++sos[i][j];
			}
			if (sos[i][j] == 0) {
				cout << "Not unique\n";
				return;
			}
			if (sos[i][j] == 1) {
				q.push(mp(i, j));
			}
		}
	}

	if (q.empty()) {
		if (cnt)
			cout << "Not unique\n";
		else {
			for (int i = 0; i < n; ++i)
				cout << s[i] << "\n";
		}
		return;
	}

	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		if (!good(cur.first, cur.second))
			continue;

		pair<int, int> nex(-1, -1);
		for (int dir = 0; dir < 4; ++dir) {
			int X = cur.first + dx[dir], Y = cur.second + dy[dir];
			if (good(X, Y)) {
				nex = mp(X, Y);
				break;
			}
		}

		if (!good(nex.first, nex.second)) {
			cout << "Not unique\n";
			return;
		}

		fillAns(cur, nex);

		for (int dir = 0; dir < 4; ++dir) {
			int X = cur.first + dx[dir], Y = cur.second + dy[dir];
			if (good(X, Y)) {
				--sos[X][Y];
				if (sos[X][Y] == 1)
					q.push(mp(X, Y));
			}
		}
		for (int dir = 0; dir < 4; ++dir) {
			int X = nex.first + dx[dir], Y = nex.second + dy[dir];
			if (good(X, Y)) {
				--sos[X][Y];
				if (sos[X][Y] == 1)
					q.push(mp(X, Y));
			}
		}

	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == '.') {
				cout << "Not unique\n";
				return;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		cout << s[i] << "\n";
	}

}