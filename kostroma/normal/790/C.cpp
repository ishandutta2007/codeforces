#pragma comment(linker, "/STACK:1024000000")
#define _CRT_SECURE_NO_WARNINGS
#undef NDEBUG
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
#include <deque>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <functional>
/*#ifndef room111
#include <sys/resource.h>
#endif*/
#include <unordered_set>
#include <unordered_map>
#include <array>
using namespace std;
#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

bool stress = false;

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
	start = clock();
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	/*#ifndef room111
	const rlim_t kStackSize = 1024L * 1024L * 1024L;   // min stack size = 64 Mb
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0)
	{
	if (rl.rlim_cur < kStackSize)
	{
	rl.rlim_cur = kStackSize;
	result = setrlimit(RLIMIT_STACK, &rl);
	if (result != 0)
	{
	fprintf(stderr, "setrlimit returned result = %d\n", result);
	}
	}
	}
	#endif*/

	//cin >> t;
	int testNum = 1;
	while (t--) {
		//cerr << testNum << endl;
		//cout << "Case #" << testNum++ << ": ";
		solve(true);
		++testNumber;
		//++timer;
	}
#ifdef room1111
	while (true)
		solve(false);
#endif

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}
void precalc() {}

//#define int li

//const int mod = 1000000007;

void relax(int& cur, int val) {
	cur = min(cur, val);
}

void solve(bool read) {
	int n;
	cin >> n;
	//n = 75;
	string s;
	cin >> s;
	/*s = string(n, 'V');
	for (char& c : s) {
		int id = rand() % 3;
		if (id == 0) {
			c = 'K';
		}
		else if (id == 1) {
			c = 'V';
		}
		else {
			c = 'E';
		}
	}*/
	vector<vector<int>> poses(3);
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'V') {
			poses[0].push_back(i);
		}
		else if (s[i] == 'K') {
			poses[1].push_back(i);
		}
		else {
			poses[2].push_back(i);
		}
	}

	vector<vector<vector<vector<int>>>> dp(poses[0].size() + 1, vector<vector<vector<int>>>(poses[1].size() + 1,
		vector<vector<int>>(poses[2].size() + 1, vector<int>(3, 1e9))));
	dp[0][0][0][2] = 0;
	vector<int> a(3), ids(3);
	for (int pref = 0; pref < n; ++pref) {
		for (a[0] = 0; a[0] <= pref; ++a[0]) {
			if (a[0] > poses[0].size()) {
				continue;
			}
			for (a[1] = 0; a[0] + a[1] <= pref; ++a[1]) {
				if (a[1] > poses[1].size()) {
					continue;
				}
				a[2] = pref - a[0] - a[1];
				if (a[2] > poses[2].size()) {
					continue;
				}
				for (int last = 0; last < 3; ++last) {
					//cout << a[0] << " " << a[1] << " " << a[2] << " " << last << " " << /*cur_dp <<*/ endl;
					int cur_dp = dp[a[0]][a[1]][a[2]][last];
					for (int nex = 0; nex < 3; ++nex) {
						if (a[nex] == poses[nex].size()) {
							continue;
						}
						if (last == 0 && nex == 1) {
							continue;
						}
						int next_pos = poses[nex][a[nex]];
						ids = a;
						++ids[nex];
						int add = 0;
						for (int ot = 0; ot < 3; ++ot) {
							if (ot == nex) {
								continue;
							}
							for (int z = 0; z < poses[ot].size(); ++z) {
								if (poses[ot][z] > next_pos && z < a[ot]) {
									++add;
								}
							}
						}
						relax(dp[ids[0]][ids[1]][ids[2]][nex], cur_dp + add);
					}
				}
			}
		}
	}
	
	int ans = 1e9;
	for (int last = 0; last < 3; ++last) {
		ans = min(ans, dp[poses[0].size()][poses[1].size()][poses[2].size()][last]);
	}

	cout << ans << "\n";

}