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
	start = clock();
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
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

void precalc() {
}

//#define int li

map<int, int> index;

int n;
int p[100500];

int dsu[100500];

int color[100500];

int findSet(int v) {
	if (dsu[v] == v)
		return v;
	return dsu[v] = findSet(dsu[v]);
}

void merge(int q, int w) {
	q = findSet(q);
	w = findSet(w);
	if (rand() & 1)
		dsu[w] = q;
	else
		dsu[q] = w;
}

void printNo() {
	cout << "NO\n";
	exit(0);
}

void solve() {
	int a, b;
	cin >> n >> a >> b;
	for (int i = 0; i < n; ++i) {
		cin >> p[i];
		index[p[i]] = i;
		dsu[i] = i;
	}

	for (auto item : index) {
		int fs = a - item.first, sc = b - item.first;

		int notExist = 0;

		if (!index.count(fs)) {
			if (!index.count(sc))
				printNo();
			if (color[index[sc]] == 1)
				printNo();
			color[item.second] = color[index[sc]] = 2;
			++notExist;
		}
		if (!index.count(sc)) {
			if (!index.count(fs))
				printNo();
			if (color[index[fs]] == 2)
				printNo();
			color[item.second] = color[index[fs]] = 1;
			++notExist;
		}

		if (notExist == 2)
			printNo();

		if (notExist == 0) {
			merge(item.second, index[fs]);
			merge(item.second, index[sc]);
		}

	}

	for (int i = 0; i < n; ++i)
		if (color[i] != 0) {
			int v = findSet(i);
			if (color[v] > 0 && color[v] != color[i])
				printNo();
			color[v] = color[i];
		}
	for (int i = 0; i < n; ++i)
		if (dsu[i] == i && color[i] == 0)
			color[i] = 1;

	cout << "YES\n";

	for (int i = 0; i < n; ++i)
		cout << color[findSet(i)] - 1 << ' ';

}