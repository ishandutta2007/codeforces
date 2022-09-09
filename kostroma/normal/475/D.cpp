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
int a[100500];

int sparse[100500][17];

map<int, li> res;

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		sparse[i][0] = a[i];
	}

	for (int j = 1; j < 17; ++j)
		for (int i = 0; i < n; ++i) {
			if (i + (1 << j) > n)
				sparse[i][j] = sparse[i][j - 1];
			else
				sparse[i][j] = gcd(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
		}

	for (int l = 0; l < n; ++l) {
		int cur = a[l];

		int r = l;
		int oldR = l;
		while (r < n) {
			for (int j = 16; j >= 0; --j)
				if (r + (1 << j) <= n && gcd(cur, sparse[r][j]) == cur)
					r += (1 << j);
			//cout << l << ' ' << r << ' ' << cur << "\n";
			res[cur] += (r - oldR);
			cur = gcd(cur, sparse[r][0]);
			oldR = r;
		}

	}

	int Q;
	cin >> Q;
	while (Q--) {
		int x;
		cin >> x;
		cout << res[x] << "\n";
	}

}