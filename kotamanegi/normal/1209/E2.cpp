#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
const long double eps = 1e-12;
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
int grid[20][3000] = {};
int dp[30][(1 << 13)] = {};
int memo[(1 << 13)] = {};
int main() {
	int test_case;
	scanf("%d", &test_case);
	REP(i, test_case) {
		int n, m;
		scanf("%d%d", &n, &m);
		REP(i, n) {
			REP(q, m) {
				scanf("%d", &grid[i][q]);
			}
		}
		vector<pair<int, int>> gogo;
		REP(i, m) {
			int now_max = 0;
			REP(q, n) {
				now_max = max(now_max, grid[q][i]);
			}
			gogo.push_back(make_pair(now_max, i));
		}
		sort(gogo.begin(), gogo.end());
		reverse(gogo.begin(), gogo.end());
		m = min((int)gogo.size(), n);
		REP(i, m+1) {
			REP(q, 1 << 13) {
				dp[i][q] = 0;
			}
		}
		for (int tea = 0; tea < m; ++tea) {
			int i = gogo[tea].second;
			for (int q = 0; q < n; ++q) {
				REP(i, 1 << n) {
					memo[i] = dp[tea][i];
				}
				for (int j = 0; j < n; ++j) {
					for (int t = 0; t < (1 << n); ++t) {
						if ((t & (1 << j)) != 0) continue;
						int next_fill = t;
						int go = next_fill + (1 << j);
						memo[go] = max(memo[go], memo[next_fill] + grid[j][i]);
					}
				}
				REP(i, 1 << n) {
					dp[tea + 1][i] = max(dp[tea + 1][i], memo[i]);
				}
				//spinning
				REP(j, n - 1) {
					swap(grid[j][i], grid[j + 1][i]);
				}
			}
			// for sample
			/*
			for (int q = 0; q < (1 << n); ++q) {
				for (int t = 0; t < (1 << n); ++t) {
					if ((q & t) != 0) continue;
					dp[tea + 1][q + t] = max(dp[tea + 1][q + t], dp[tea][q] + memo[t]);
				}
			}
			*/
		}
		cout << dp[m][(1 << n)-1] << endl;
	}
}