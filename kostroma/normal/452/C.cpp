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

//#define int li

double cnt (int n, int m, int k) {
	double res = 1.0;
	vector<int> up, down;

	for (int i = m * n - n; i > m * n - n - m + k; --i)
		up.push_back(i);
	for (int i = n; i > 0; --i)
		up.push_back(i);
	for (int i = m; i > 0; --i)
		up.push_back(i);

	for (int i = m * n; i > m * n - m; --i)
		down.push_back(i);
	for (int i = k; i > 0; --i)
		down.push_back(i);
	for (int i = m - k; i > 0; --i)
		down.push_back(i);
	for (int i = n - k; i > 0; --i)
		down.push_back(i);
	assert(up.size() == down.size());
	for (int i = 0; i < up.size(); ++i) {
		res *= up[i];
		res /= down[i];
	}
	return res;
}

void solve() {
	int n, m;
	cin >> m >> n;
	double ans = 0.0;
	for (int k = 1; k <= min(n, m); ++k) {
		ans += cnt(n, m, k) * k * k / 1.0 / m;
	}

	cout << ans;

}