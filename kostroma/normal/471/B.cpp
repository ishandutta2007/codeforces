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
	precalc();
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

void precalc() {
	
}

int gcd (int q, int w) {
	while(w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

int binpow (int q, int w, int mod) {
	if (!w)
		return 1 % mod;
	if (w & 1) {
		return (q * binpow(q, w - 1, mod)) % mod;
	}
	return binpow((q * q) % mod, w / 2, mod);
}

int n;
vector<int> indices[2010];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int cur;
		cin >> cur;
		indices[cur].push_back(i);
	}

	bool flag = false;

	vector<int> a[3];
	for (int i = 0; i < 2010; ++i) {

		if (indices[i].size() >= 3 && !flag) {
			a[0].push_back(indices[i][0]);
			a[0].push_back(indices[i][1]);
			a[0].push_back(indices[i][2]);

			a[1].push_back(indices[i][2]);
			a[1].push_back(indices[i][1]);
			a[1].push_back(indices[i][0]);

			a[2].push_back(indices[i][1]);
			a[2].push_back(indices[i][0]);
			a[2].push_back(indices[i][2]);
			flag = true;

			for (int j = 3; j < indices[i].size(); ++j)
				for (int w = 0; w < 3; ++w)
					a[w].push_back(indices[i][j]);
		}
		else 
		for (int id : indices[i])
			for (int w = 0; w < 3; ++w)
				a[w].push_back(id);
	}

	if (!flag) {
		int cnt = 0;
		for (int w = 0; w < 3; ++w)
			a[w].clear();

		for (int i = 0; i < 2010; ++i) {

			if (indices[i].size() == 2 && cnt < 2) {

				if (cnt == 0) {
					a[0].push_back(indices[i][0]);
					a[0].push_back(indices[i][1]);

					a[1].push_back(indices[i][0]);
					a[1].push_back(indices[i][1]);

					a[2].push_back(indices[i][1]);
					a[2].push_back(indices[i][0]);
				}

				if (cnt == 1) {
					a[0].push_back(indices[i][0]);
					a[0].push_back(indices[i][1]);

					a[1].push_back(indices[i][1]);
					a[1].push_back(indices[i][0]);

					a[2].push_back(indices[i][1]);
					a[2].push_back(indices[i][0]);
				}


				++cnt;
			}
			else 
			for (int id : indices[i])
				for (int w = 0; w < 3; ++w)
					a[w].push_back(id);
		}

		if (cnt < 2) {
			cout << "NO\n";
			return;
		}

	}

	cout << "YES\n";
	for (int w = 0; w < 3; ++w) {
		for (int i = 0; i< a[w].size(); ++i)
			cout << a[w][i] + 1 << ' ';
		cout << endl;
	}

}