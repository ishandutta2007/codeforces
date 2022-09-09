//#pragma comment (linker, "/STACK:128000000")
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

int n, m, q;

string matrix[100500];

const int MAGIC = 100;

enum {
	CHANGE = 0, LOOK = 1
};

struct Query {
	int type;
	int x, y;
	char c;
	Query(int type, int x, int y, char c) :type(type), x(x), y(y), c(c) {}
};

int tim = 1;

int changed[100500][11];

int used[100500][11];

pair<int, int> nex[100500][11];

bool correct(int x, int y) {
	return x >= 0 && y >= 0 && x < n && y < m;
}

int dx[300], dy[300];

pair<int, int> dfs(int x, int y, int px = -1, int py = -1) {
	if (!correct(x, y))
		return mp(x, y);
	if (used[x][y] == tim)
		return nex[x][y];
	if (changed[x][y] == tim)
		return nex[x][y] = mp(x, y);
	used[x][y] = tim;
	int xx = x + dx[matrix[x][y]];
	int yy = y + dy[matrix[x][y]];
	if (xx == px && yy == py) {
		//cout << x << ' ' << y << endl;
		//cout << xx << ' ' << yy << endl;
		return nex[x][y] = mp(-2, -2);
	}
	return nex[x][y] = dfs(xx, yy, x, y);
}

void solve() {

	dx['^'] = -1;
	dy['>'] = 1;
	dy['<'] = -1;

	cin >> n >> m >> q;
	for (int i = 0; i < n; ++i) {
		cin >> matrix[i];
	}

	vector<Query> queries;

	for (int i = 0; i < q; ++i) {
		char type;
		cin >> type;
		if (type == 'C') {
			int x, y;
			char c;
			cin >> x >> y;
			--x;
			--y;
			cin >> c;
			queries.push_back(Query(CHANGE, x, y, c));
		}
		else {
			int x, y;
			cin >> x >> y;
			--x;
			--y;
			queries.push_back(Query(LOOK, x, y, 0));
		}
	}

	for (int i = 0; i < q; ) {
		int j;
		int cnt = 0;
		for (j = i; j < q && cnt <= MAGIC; ++j)
			if (queries[j].type == CHANGE)
				++cnt;

		++tim;
		for (int k = i; k < j; ++k) {
			if (queries[k].type == CHANGE) {
				changed[queries[k].x][queries[k].y] = tim;
			}
		}

		for (int i = n - 1; i >= 0; --i) {
			for (int j = 0; j < m; ++j){
				if (used[i][j] != tim){
					nex[i][j] = dfs(i, j);
				}
			}
		}

		for (int k = i; k < j; ++k) {
			if (queries[k].type == CHANGE) {
				matrix[queries[k].x][queries[k].y] = queries[k].c;
				continue;
			}

			int x = queries[k].x, y = queries[k].y;
			++tim;
			bool notfound = true;
			while (notfound) {
				used[x][y] = tim;
				pair<int, int> nexP = nex[x][y];
				if (!correct(nexP.first, nexP.second)) {
					notfound = false;
					cout << nexP.first + 1 << ' ' << nexP.second + 1 << "\n";
					break;
				}
				
				int xx = nexP.first + dx[matrix[nexP.first][nexP.second]];
				int yy = nexP.second + dy[matrix[nexP.first][nexP.second]];

				if (!correct(xx, yy)) {
					notfound = false;
					cout << xx + 1 << ' ' << yy + 1 << "\n";
					break;
				}

				if (used[xx][yy] == tim)
					break;

				x = xx;
				y = yy;
			}

			if (notfound) {
				cout << "-1 -1\n";
			}

		}

		i = j;
	}

}