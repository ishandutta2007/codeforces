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

int gcd (int q, int w) {
	while(w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

int binpow (int q, int w, int mod) {
	if (!w)
		return 1 % mod;
	if (w & 1) {
		return (q * binpow(q, w - 1, mod)) % mod;
	}
	return binpow((q * q) % mod, w / 2, mod);
}

int n, m;
vector<string> s;

int cnt = 0;

enum {
	DOWN = 0,
	RIGHT = 1
};

void printNo() {
	cout << "-1\n";
	exit(0);
}

bool correct(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

bool process(int x, int y, int h, int w) {
	int curCnt = 0;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j) {
			int X = x + i, Y = y + j;
			if (!correct(X, Y))
				return false;
			if (s[X][Y] != '#')
				return false;
			++curCnt;
		}
	while (true) {
		if (correct(x, y + w) && s[x][y + w] == '#') {
			for (int i = x; i < x + h; ++i) {
				if (s[i][y + w] != '#')
					return false;
				++curCnt;
			}
			++y;
			continue;
		}
		if (correct(x + h, y) && s[x + h][y] == '#') {
			for (int i = y; i < y + w; ++i) {
				if (s[x + h][y] != '#')
					return false;
				++curCnt;
			}
			++x;
			continue;
		}
		return curCnt == cnt;
	}
}

void solve() {
	cin >> n >> m;
	s.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> s[i];
		for (int j = 0; j < m; ++j)
			if (s[i][j] == 'X') {
				cnt++;
				s[i][j] = '#';
			}
	}

	int ans = n * m + 1;

	for (int it = 0; it < 2; ++it) {

		vector<vector<char>> used(n, vector<char>(m, false));

		int row = -1, lef, rig;


		for (int i = 0; i < n && row == -1; ++i)
			for (int j = 0; j < m; ++j) {
				if (s[i][j] == '#') {
					row = i;
					lef = j;
					rig = lef;
					used[i][lef] = true;
					while(rig + 1 < m && s[i][rig + 1] == '#') {
						++rig;
						used[i][rig] = true;
					}
					break;
				}
			}

		vector<int> moves;
		int cntDown = 0;
		int lastDown = row;
		int firstRight = -1;


		int firstRightDown = -1;

		for (int i = row + 1; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (s[i][j] == '#') {

					lastDown = i;

					int curLef = j;

					if (curLef != lef && firstRightDown == -1) {
						firstRightDown = i;
					}

					used[i][curLef] = true;
					int curRig = j;
					while(curRig + 1 < m && s[i][curRig + 1] == '#') {
						++curRig;
						used[i][curRig] = true;
					}

					//cout << i << ' ' << curLef << ' ' << curRig << "\n";

					if (curRig == rig) {
						moves.push_back(DOWN);
						++cntDown;
					}
					for (int r = rig; r < curRig; ++r) {
						if (firstRight == -1)
							firstRight = i;
						moves.push_back(RIGHT);
					}

					break;
				}


		if (firstRight != -1 && firstRightDown == -1)
			firstRightDown = lastDown + 1;

		
		if (firstRight != -1 && firstRightDown != -1) {
			int height = firstRightDown - firstRight;
			if (process(row, lef, height, rig - lef + 1))
				ans = min(ans, height * (rig - lef + 1));
		}


		if (firstRight == -1) {
			if (process(row, lef, 1, rig - lef + 1))
				ans = min(ans, (rig - lef + 1));
		}


		vector<string> newS(m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				newS[j].push_back(s[i][j]);
		swap(s, newS);
		swap(n, m);
	}

	if (ans > n * m)
		ans = -1;

	cout << ans << "\n";

}