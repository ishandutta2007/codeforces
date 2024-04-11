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



void solve() {
	int n;
	cin >> n;
	if (n <= 3) {
		cout << "NO\n";
		return;
	}

	cout << "YES\n";

	int cnt = 0;

	while (n >= 6) {
		cout << n << " - " << n - 1 << " = 1\n";
		++cnt;
		n -= 2;
	}

	if (n == 5) {
		cout << "5 - 1 = 4\n";
		cout << "4 - 2 = 2\n";
		cout << "2 * 3 = 6\n";
		cout << "6 * 4 = 24\n";
	}

	if (n == 4) {
		cout << "1 * 2 = 2\n";
		cout << "2 * 3 = 6\n";
		cout << "6 * 4 = 24\n";
	}

	while(cnt--)
		cout << "24 * 1 = 24\n";

}