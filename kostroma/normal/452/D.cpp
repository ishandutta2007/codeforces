#define _CRT_SECURE_NO_WARNINGS
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
//void precalc();
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
	//precalc();
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

#define int li

int k, n[3], t[3];

queue<pair<int, int>> appliances[3];

void solve() {
	cin >> k;
	for (int i = 0; i < 3; ++i) {
		cin >> n[i];
		for (int j = 0; j < n[i]; ++j)
			appliances[i].push(mp(0, j));
	}
	for (int i = 0; i < 3; ++i)
		cin >> t[i];

	int ans = 0;

	for (int cur = 0; cur < k; ++cur) {
		pair<int, int> it1 = appliances[0].front();
		pair<int, int> it2 = appliances[1].front();
		pair<int, int> it3 = appliances[2].front();

		int tim = max(it1.first + t[0] + t[1] + t[2], 0LL);

		tim = max(tim, it2.first + t[1] + t[2]);
		tim = max(tim, it3.first + t[2]);

		ans = max(ans, tim);

		tim -= t[0] + t[1] + t[2];

		for (int i = 0; i < 3; ++i)
			appliances[i].pop();
		appliances[0].push(mp(tim + t[0], it1.second));
		appliances[1].push(mp(tim + t[0] + t[1], it2.second));
		appliances[2].push(mp(tim + t[0] + t[1] + t[2], it3.second));

	}

	cout << ans;
}