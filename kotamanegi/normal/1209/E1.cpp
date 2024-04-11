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
int dp[3000][(1 << 13)] = {};
int main() {
	iostream::sync_with_stdio(false);
	cin.tie(0);
	int test_case;
	cin >> test_case;
	REP(i, test_case) {
		int n, m;
		cin >> n >> m;
		REP(i, n) {
			REP(q, m) {
				cin >> grid[i][q];
			}
		}
		REP(i, m+1) {
			REP(q, 1 << 13) {
				dp[i][q] = 0;
			}
		}
		for (int i = 0; i < m; ++i) {
			int memo[100] = {};
			for (int q = 0; q < n; ++q) {
				for (int t = 1; t < (1 << n); ++t) {
					int hoge = 0;
					REP(j, n) {
						if (((1 << j) & t) != 0) {
							hoge += grid[j][i];
						}
					}
					memo[t] = max(memo[t], hoge);
				}
				//spinning
				REP(j, n - 1) {
					swap(grid[j][i], grid[j + 1][i]);
				}
			}
			for (int q = 0; q < (1 << n); ++q) {
				for (int t = 0; t < (1 << n); ++t) {
					if ((q & t) != 0) continue;
					dp[i + 1][q + t] = max(dp[i + 1][q + t], dp[i][q] + memo[t]);
				}
			}
		}
		cout << dp[m][(1 << n)-1] << endl;
	}
}