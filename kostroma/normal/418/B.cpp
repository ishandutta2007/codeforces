#pragma comment (linker, "/STACK:128000000")
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
	//cout.sync_with_stdio(0);
	//precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
	//int testNum = 1;
    while (t--) {
        solve();
		//cout << "Case #" << testNum++ << ": ";
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

    return 0;
}

//BE CAREFUL: IS INT REALLY INT?

#define int li

struct man {
	int x, k;
	int mask;
	man() {}
	void scan() {
		cin >> x >> k;
		mask = 0;
		int num;
		cin >> num;
		for (int i = 0; i < num; ++i) {
			int cur;
			cin >> cur;
			--cur;
			mask |= (1 << cur);
		}
	}
	bool operator < (const man& other) const { return k < other.k; }
};

int n, m, b;
man friends[200];

int dp[2][1 << 22];

//int bits[1 << 22];

void solve() {
	cin >> n >> m >> b;

	/*for (int mask = 0; mask < (1 << m); ++mask) {
		for (int z = 0; z < m; ++z)
			if (mask & (1 << z))
				++bits[mask];
	}*/

	for (int i = 0; i < n; ++i)
		friends[i].scan();
	sort(friends, friends + n);

	for (int i = 0; i < (1 << m); ++i)
		dp[0][i] = dp[1][i] = 4e18;

	int ans = 4e18;
	int w = 0;
	dp[w][0] = 0;
	for (int i = 0; i < n; ++i) {

		for (int i = 0; i < (1 << m); ++i)
			dp[w ^ 1][i] = dp[w][i];

		for (int mask = 0; mask < (1 << m); ++mask) {
			int newMask = mask | friends[i].mask;
			//int newProblems = friends[i].mask ^ (mask & friends[i].mask);
			dp[w ^ 1][newMask] = min(dp[w ^ 1][newMask], dp[w][mask] + friends[i].x/* * bits[newProblems]*/);
			if (newMask + 1 == (1 << m))
				ans = min(ans, dp[w ^ 1][newMask] + b * friends[i].k);
		}

		w ^= 1;
	}

	if (ans + 1 < 4e18)
		cout << ans;
	else
		cout << -1;
}