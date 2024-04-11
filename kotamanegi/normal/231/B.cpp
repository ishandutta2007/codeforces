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
pair<int,int> dp[101][20001];
int main(){
	long long n, d, l;
	cin >> n >> d >> l;
	REP(i, 101) {
		REP(q, 20001) {
			dp[i][q] = make_pair(-1,0);
		}
	}
	dp[0][10000] = make_pair(0, 0);
	for (int i = 0; i < n; ++i) {
		for (int q = 10000 - l * i; q <= 10000 + l * i; ++q) {
			if (dp[i][q].first == -1) continue;
			for (int t = 1; t <= l; ++t) {
				long long front = q - 10000;
				long long next = t - front;
				next += 10000;
				dp[i + 1][next] = make_pair(q, t);
			}
		}
	}
	if (dp[n][d + 10000].first == -1) {
		cout << dp[n][d + 10000].first << endl;
	}
	else {
		long long hoge = d + 10000;
		for (int i = n; i >= 1; --i) {
			cout << dp[i][hoge].second << " ";
			hoge = dp[i][hoge].first;
		}
		cout << endl;
	}
}