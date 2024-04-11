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

vector<pair<int, int>> answer;
bool swapped = false;

void print() {
	if (swapped)
		for (int i = 0; i < answer.size(); ++i)
			swap(answer[i].first, answer[i].second);
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i].first << ' ' << answer[i].second << "\n";
}

void solve() {
	int n, m;
	cin >> n >> m;
	if (n > m) {
		swap(n, m);
		swapped = true;
	}

	if (n > 0) {
		answer.push_back(mp(1,0));
		answer.push_back(mp(n,m));
		answer.push_back(mp(0,0));
		answer.push_back(mp(n-1,m));
	}
	else {
		answer.push_back(mp(0,1));
		answer.push_back(mp(0,m));
		answer.push_back(mp(0,0));
		answer.push_back(mp(0,m-1));
	}

	double res = 0;
	for (int i = 0; i < 3; ++i)
		res += sqrt(1.0 * ( (answer[i + 1].first - answer[i].first) * (answer[i + 1].first - answer[i].first) + 
		(answer[i + 1].second - answer[i].second) * (answer[i + 1].second - answer[i].second) ));

	if (n > 0 && res < m + 2 * sqrt(1.0 * (n * n + m * m))) {
		answer.clear();
		answer.push_back(mp(0,0));
		answer.push_back(mp(n,m));
		answer.push_back(mp(n,0));
		answer.push_back(mp(0,m));
	}

	print();

}