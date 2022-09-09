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

#define int li

int a;

int powers[100500];

int mulmod (int q, int w) {
	if (!w)
		return 0;
	if (w & 1)
		return (mulmod(q, w - 1) + q) % a;
	return mulmod((q + q) % a, w / 2);
}

void solve() {
	cin >> a;

	int cur = 0;
	for (int l = 1000; l <= 1000999; ++l) {
		int L = l;
		while(L) {
			cur += L % 10;
			L /= 10;
		}
	}
	//cout << cur << ' ' << cur % a << "\n";


	powers[0] = 1;
	for (int i = 1; i < 100500; ++i)
		powers[i] = mulmod(powers[i - 1], 10);

	int A = a;
	int cnt = 0;
	while (A) {
		++cnt;
		A /= 10;
	}

	cnt += 2;

	for (int k = cnt; ; ++k) {
		int cur = mulmod(k, mulmod(powers[k - 1], 45));

		int b = a - cur - 1;

		int curCnt = 0;
		int B = b;
		while(B) {
			++curCnt;
			B /= 10;
		}
		if (curCnt < k - 1) {
			cout << b + 1 << "\n";
			vector<int> res;
			while(b) {
				res.push_back(b % 10);
				b /= 10;
			}
			while (res.size() < k)
				res.push_back(0);
			res.push_back(1);
			reverse(all(res));
			for (int i = 0; i < res.size(); ++i)
				cout << res[i];
			cout << "\n";
			return;
		}
	}
	assert(false);
}