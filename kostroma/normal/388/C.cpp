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
vector<int> numbers[200];

void solve() {
	cin >> n;
	int sum1 = 0, sum2 = 0;
	vector<int> rest;
	for (int i = 0; i < n; ++i) {
		int k; cin >> k;
		numbers[i].resize(k);
		for (int j = 0; j < k; ++j)
			cin >> numbers[i][j];
		if (k % 2 == 0) {
			for (int j = 0; j < k / 2; ++j)
				sum1 += numbers[i][j];
			for (int j = k / 2; j < k; ++j)
				sum2 += numbers[i][j];
		}
		else {
			for (int j = 0; j < k / 2; ++j)
				sum1 += numbers[i][j];
			for (int j = k / 2 + 1; j < k; ++j)
				sum2 += numbers[i][j];
			rest.push_back(numbers[i][k / 2]);
		}
	}
	sort(all(rest));
	reverse(all(rest));
	for (int i = 0; i < rest.size(); ++i) {
		if (i % 2 == 0)
			sum1 += rest[i];
		else
			sum2 += rest[i];
	}
	cout << sum1 << ' ' << sum2 << "\n";
}