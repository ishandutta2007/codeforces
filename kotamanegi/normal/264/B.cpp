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
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
int dp[200000];
int d[200000];
int main(){
	int n;
	cin >> n;
	REP(i, 200000) {
		dp[i] = -1;
	}
	REP(i, n) {
		int a;
		cin >> a;
		dp[a] = 1;
	}
	int ans = 1;
	for (int i = 2; i <= 100000; ++i) {
		if (dp[i] == -1) continue;
		for (int q = 2; q * q <= i; ++q) {
			if (i % q == 0) {
				dp[i] = max({ dp[i],d[q] + 1,d[i/q]+1});
			}
		}
		d[i] = dp[i];
		for (int q = 2; q * q <= i; ++q) {
			if (i % q == 0) {
				d[i / q] = max(d[i / q], dp[i]);
				d[q] = max(d[q], dp[i]);
			}
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << endl;
}