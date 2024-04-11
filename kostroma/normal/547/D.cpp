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
		//cout << "Case #" << testNum++ << ":\n";
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

//#define int li

//int mod = 1000000007;

vector<vector<int>> points;

bool cmp(int q, int w) {
	return points[q] < points[w];
}

void solve() {
	int n;
	cin >> n;
	vector<int> coords[2];
	points.resize(n);
	for (int i = 0; i < n; ++i) {
		points[i].resize(2);
		for (int j = 0; j < 2; ++j) {
			cin >> points[i][j];
			coords[j].push_back(points[i][j]);
		}
	}
	for (int i = 0; i < 2; ++i) {
		sort(all(coords[i]));
		coords[i].erase(unique(all(coords[i])), coords[i].end());
	}

	vector<set<int>> has[2];
	for (int i = 0; i < 2; ++i) {
		has[i].resize(coords[i].size());
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j) {
			points[i][j] = lower_bound(all(coords[j]), points[i][j]) - coords[j].begin();
			has[j][points[i][j]].insert(i);
		}
	}



	vector<int> bals[2];
	for (int j = 0; j < 2; ++j) {
		bals[j].assign(coords[j].size(), 0);
	}

	vector<int> perm(n);
	for (int i = 0; i < n; ++i) {
		perm[i] = i;
	}
	sort(all(perm), cmp);

	vector<int> color(n, -1);

	int nexCol = 0;

	for (int ii = 0; ii < n; ++ii) {
		int cur = perm[ii];

		if (color[cur] != -1) {
			continue;
		}

		color[cur] = nexCol;
		nexCol ^= 1;

		/*color[cur] = 0;
		if (bals[0][points[cur][0]] > 0) {
			color[cur] = 1;
		}*/

		for (int j = 0; j < 2; ++j) {
			bals[j][points[cur][j]] += color[cur] ? (-1) : 1;
			has[j][points[cur][j]].erase(cur);
		}

		int nexWay = 1;
		while (!has[nexWay][points[cur][nexWay]].empty()) {
			int nex = *has[nexWay][points[cur][nexWay]].begin();
			color[nex] = color[cur] ^ 1;
			cur = nex;
			for (int j = 0; j < 2; ++j) {
				has[j][points[cur][j]].erase(cur);
				bals[j][points[cur][j]] += color[cur] ? (-1) : 1;
			}
			nexWay ^= 1;
		}
	}

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < bals[i].size(); ++j) {
			if (abs(bals[i][j]) > 1) {

			}
		}
	}

	for (int i = 0; i < n; ++i) {
		assert(color[i] != -1);
		if (color[i])
			cout << 'b';
		else
			cout << 'r';
	}
	cout << "\n";

}