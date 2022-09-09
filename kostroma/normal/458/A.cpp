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

string s[2];
vector<int> a[2];

void solve() {
	cin >> s[0] >> s[1];
	pair<int, int> comb[2];
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < s[i].length(); ++j)
			a[i].push_back(s[i][j] - '0');
		
		reverse(all(a[i]));

		for (int j = 0; j + 1 < a[i].size(); ++j) {
			if (a[i][j] == 0)
				continue;
			if (a[i][j + 1] == 0)
				continue;
			int cur = j;
			while (cur + 1 < a[i].size() && a[i][cur + 1] == 1)
				++cur;

			if (a[i].size() == cur + 1)
				a[i].push_back(0);

			for (int id = cur; id > j; id -= 2) {

				

				a[i][id - 1] = a[i][id] = 0;
				a[i][id + 1] = 1;

			}

		}


		while(a[i].size() > 1 && a[i].back() == 0)
			a[i].pop_back();

		

	}

	if (a[0].size() > a[1].size()) {
		cout << ">";
		return;
	}

	if (a[0].size() < a[1].size()) {
		cout << "<";
		return;
	}

	for (int j = a[0].size() - 1; j >= 0; --j) {
		if (a[0][j] > a[1][j]) {
			cout << ">";
			return;
		}
		if (a[0][j] < a[1][j]) {
			cout << "<";
			return;
		}
	}

	cout << "=";

}