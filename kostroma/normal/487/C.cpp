//#pragma comment (linker, "/STACK:128000000")
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

bool doing = true;

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
	cin.tie(0);
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

#define int li

void precalc() {

}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q *q % mod, w / 2, mod);
}

void solve() {
	int n;
	cin >> n;
	if (n == 4) {
		cout << "YES\n1\n3\n2\n4\n";
		return;
	}

	for (int p = 2; p * p <= n; ++p) {
		if (n % p == 0) {
			cout << "NO\n";
			return;
		}
	}


	vector<int> res;
	res.push_back(1);
	for (int i = 2; i <= n - 1; ++i) {
		int cur = binpow(i - 1, n - 2, n) * i % n;
		res.push_back(cur);
	}
	res.push_back(n);

	cout << "YES\n";
	for (int i = 0; i < n; ++i)
		cout << res[i] << "\n";

	set<int> a;
	for (int i = 0; i < n; ++i)
		a.insert(res[i]);
	assert(a.size() == n);

}