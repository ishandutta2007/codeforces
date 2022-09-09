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

int mod = 1000000007;

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

int n;

int a[100500];

void solve() {
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	vector<int> poses[2];
	for (int i = 0; i < n; ++i) {
		poses[a[i] - 1].push_back(i);
	}

	vector<pair<int, int>> res;

	for (int t = 1; t <= n; ++t) {
		int curPos = -1;
		vector<int> won(2, 0);
		int lastWon = -1;
		bool may = true;
		while (curPos < n - 1) {
			int id[2];
			int nextPos[2];
			for (int w = 0; w < 2; ++w) {
				id[w] = upper_bound(all(poses[w]), curPos) - poses[w].begin();
				nextPos[w] = n;
				if (id[w] + t <= poses[w].size()) {
					nextPos[w] = poses[w][id[w] + t - 1];
				}
			}

			//cerr << curPos << ' ' << nextPos[0] << ' ' << nextPos[1] << "\n";

			if (nextPos[0] < nextPos[1]) {
				++won[0];
				lastWon = 0;
			}
			if (nextPos[0] > nextPos[1]) {
				++won[1];
				lastWon = 1;
			}

			/*for (int w = 0; w < 2; ++w) {
				if (nextPos[w] == n) {
					if (poses[w ^ 1].empty() || nextPos[w ^ 1] != poses[w ^ 1].back()) {
						may = false;
					}
				}
			}*/

			curPos = min(nextPos[0], nextPos[1]);
			if (curPos == n) {
				may = false;
			}
		}

		//cerr << t << ' ' << won[0] << ' ' << won[1] << ' ' << lastWon << ' ' << may << "\n";

		if (may) {
			for (int w = 0; w < 2; ++w) {
				if (won[w] > won[w ^ 1] && lastWon == w) {
					res.push_back(mp(won[w], t));
				}
			}
		}
	}

	sort(all(res));
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); ++i) {
		cout << res[i].first << ' ' << res[i].second << "\n";
	}

}