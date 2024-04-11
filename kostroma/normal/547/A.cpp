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
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
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
		//cout << "Case #" << testNum++ << ":\n";
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

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

#define int li

//int mod = 1000000007;


void solve() {
	int m;
	cin >> m;
	int x[2], y[2], h[2], a[2];
	for (int i = 0; i < 2; ++i) {
		cin >> h[i] >> a[i] >> x[i] >> y[i];
	}

	{
		int mx = 2e6;
		int cur[2];
		cur[0] = h[0];
		cur[1] = h[1];
		for (int i = 0; i < mx + 5; ++i) {
			if (cur[0] == a[0] && cur[1] == a[1]) {
				cout << i << "\n";
				return;
			}
			for (int j = 0; j < 2; ++j) {
				cur[j] = (cur[j] * x[j] + y[j]) % m;
			}
		}
	}

	int fs[2], t[2];
	int pos[2];
	pos[0] = pos[1] = -1;

	vector<int> rems[2];

	for (int i = 0; i < 2; ++i) {
		vector<int> used(m);
		int cur = h[i];
		int it = 0;
		while (!used[cur]) {
			rems[i].push_back(cur);
			used[cur] = true;
			++it;
			cur = (cur * x[i] + y[i]) % m;
		}
		for (int j = rems[i].size() - 1; j >= 0; --j) {
			if (rems[i][j] == cur) {
				t[i] = rems[i].size() - j;
				fs[i] = j;
				break;
			}
		}
		for (int j = fs[i]; j < rems[i].size(); ++j) {
			if (rems[i][j] == a[i]) {
				pos[i] = j;
				break;
			}
		}
		if (pos[i] == -1) {
			cout << "-1\n";
			return;
		}
	}

	for (int x = 0; x < 2e6; ++x) {
		int cur = pos[0] + x * t[0];
		if (cur >= pos[1] && (cur - pos[1]) % t[1] == 0) {
			cout << cur << "\n";
			return;
		}
	}
	cout << "-1\n";
}