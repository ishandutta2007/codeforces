//J^!w

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
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
long long a[400000];
long long b[400000];
long long dp[3][400000];
int main(){
	iostream::sync_with_stdio(false);
	int query;
	cin >> query;
	REP(i, query) {
		int n;
		cin >> n;
		vector<int> inputs;
		REP(i, n) {
			cin >> a[i] >> b[i];
		}
		dp[0][0] = 0;
		dp[1][0] = b[0];
		dp[2][0] = b[0] * 2LL;
		for (int i = 1; i < n; ++i) {
			for (long long t = 0; t < 3; ++t) {
				dp[t][i] = LONG_INF;
				REP(j, 3) {
					if (a[i - 1] + j != a[i] + t) {
						dp[t][i] = min(dp[t][i], dp[j][i - 1] + t * b[i]);
					}
				}
			}
		}
		cout << min({ dp[0][n - 1],dp[1][n - 1],dp[2][n - 1] }) << endl;
	}
}