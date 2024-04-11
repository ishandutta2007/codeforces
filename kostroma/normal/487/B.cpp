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

int n, s, l;
int a[100500];

const int L = 18;

//int mins[100500][L], maxes[100500][L];

enum {
	ADD = 0, ERASE = 1
};

void solve() {
	cin >> n >> s >> l;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		//mins[i][0] = maxes[i][0] = a[i];
	}		

	/*for (int j = 1; j < L; ++j) {
		for (int i = 0; i < n; ++i) {
			if (i + (1 << j) > n)
				break;
			mins[i][j] = min(mins[i][j - 1], mins[i + (1 << (j - 1))][j - 1]);
			maxes[i][j] = max(maxes[i][j - 1], maxes[i + (1 << (j - 1))][j - 1]);
		}
	}*/
	
	int j = 0;

	set<pair<int, int>> numbers;

	vector<int> border(n);

	for (int i = 0; i < n; ++i) {
		while (j < n) {
			numbers.insert(mp(a[j], j));
			int mn = numbers.begin()->first;
			int mx = numbers.rbegin()->first;
			if (mx - mn > s) {
				numbers.erase(mp(a[j], j));
				border[i] = j;
				break;
			}
			++j;
		}
		if (j == n)
			border[i] = j;
		numbers.erase(mp(a[i], i));
	}


	vector<vector<pair<int, pair<int, int>>>> events(n + 1);
	
	vector<int> dp(n + 1, -1);
	dp[0] = 0;

	set<pair<int, int>> dps;

	for (int i = 0; i <= n; ++i) {

		if (i > 0) {
			for (auto item : events[i]) {
				if (item.second.first == ADD) {
					dps.insert(mp(item.first, item.second.second));
				}
				else {
					dps.erase(mp(item.first, item.second.second));
				}
			}
			if (!dps.empty())
				dp[i] = dps.begin()->first;
		}

		//cout << i << ' ' << dp[i] << endl;

		if (i < n && border[i] - i >= l && dp[i] != -1) {
			events[i + l].push_back(mp(dp[i] + 1, mp(ADD, i)));
			if (border[i] < n) {
				events[border[i] + 1].push_back(mp(dp[i] + 1, mp(ERASE, i)));
			}
		}
	}

	cout << dp[n] << "\n";

}