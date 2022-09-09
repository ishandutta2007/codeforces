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

int n, p;
string s;

void solve() {
	cin >> n >> p;
	cin >> s;

	for (int pref = s.length() - 1; pref >= 0; --pref) {
		string q = s.substr(0, pref);

		if (s[pref] == 'a' + p - 1)
			continue;

		for (char cur = s[pref] + 1; cur < 'a' + p; ++cur) {
			q.resize(pref);
			q += cur;
			if (q.size() > 1 && q[q.size() - 2] == q[q.size() - 1])
				continue;

			if (q.size() > 2 && q[q.size() - 3] == q[q.size() - 1])
				continue;

			for (int i = pref + 1; i < n; ++i) {

				for (char nex = 'a'; nex < 'a' + p; ++nex) {
					if (nex != q.back() && (q.size() <= 1 || q[q.size() - 2] != nex)) {
						q += nex;
						break;
					}
				}
			}
			
			if (q.size() == n) {
				cout << q;
				return;
			}

		}

	}

	cout << "NO\n";

}