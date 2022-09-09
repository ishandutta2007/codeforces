#pragma comment (linker, "/STACK:128000000")
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
#include <unordered_map>
#include <unordered_set>
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
	//cout.sync_with_stdio(0);
	//precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
    while (t--) {
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

int n;
int x[200];

bool check (int num) {
	vector<vector<int> > good(num, vector<int>());
	for (int i = 0; i < n; ++i)
		good[i % num].push_back(x[i]);
	for (int i = 0; i < num; ++i)
		for (int j = 0; j < good[i].size(); ++j)
			if (good[i][j] < good[i].size() - j - 1)
				return false;
	return true;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	sort(x, x + n);
	reverse(x, x + n);

	int l = 0, r = 100;
	while (l + 1 < r) {
		int m = (l + r) / 2;
		if (check(m))
			r = m;
		else
			l = m;
	}
	cout << r;
}