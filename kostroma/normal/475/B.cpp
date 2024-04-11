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

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int visited[2][22][22];

int n, m;

bool correct (int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

string hor, ver;

set<pair<int, int>> aa[2];

void dfs(int x, int y, int way) {
	if (visited[way][x][y])
		return;
	visited[way][x][y] = 1;
	aa[way].insert(mp(x, y));
	for (int dir = 0; dir < 4; ++dir) {

		bool flag = true;

		if (dir == 2 && ver[y] == '^' || dir == 3 && ver[y] == 'v')
			flag = false;
		if (dir == 0 && hor[x] == '<' || dir == 1 && hor[x] == '>')
			flag = false;

		if (way)
			flag ^= 1;

		if (!flag)
			continue;

		int X = x + dx[dir];
		int Y = y + dy[dir];
		if (!correct(X, Y))
			continue;
		dfs(X, Y, way);
	}
}

void solve() {
	cin >> n >> m;
	cin >> hor >> ver;
	dfs(0, 0, 0);
	dfs(0, 0, 1);
	
	if (aa[0].size() == n * m && aa[1].size() == n * m)
		cout << "YES\n";
	else
		cout << "NO\n";

}