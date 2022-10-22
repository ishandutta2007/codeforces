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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
long long dp[102][102];
long long next_itr[102][27] = {};
int main() {
#define int long long
	long long n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	REP(i, 101) {
		REP(q, 27) {
			next_itr[i][q] = n+1;
		}
	}
	for (int i = 0; i < s.length(); ++i) {
		for (int q = 0; q < 26; ++q) {
			for (int j = i; j < s.length(); ++j) {
				if (s[j] - 'a' == q) {
					next_itr[i][q] = j + 1;
					break;
				}
			}
		}
	}
	dp[0][0] = 1;
	for (int i = 0; i < s.length(); ++i) {
		for (int j = 0; j <= s.length(); ++j) {
			for (int q = 0; q < 26; ++q) {
				int geko = next_itr[i][q];
				if (geko != n + 1) {
					dp[geko][j + 1] += dp[i][j];
				}
			}
		}
	}
	long long gogo[101] = {};
	for (int i = 0; i <= s.length(); ++i) {
		for (int j = 0; j <= s.length(); ++j) {
			gogo[j] += dp[i][j];
		}
	}
	long long ans = 0;
	for (long long q = 0; q <= s.length();++q) {
		if (k <= gogo[s.length() - q]) {
			ans += k * q;
			cout << ans << endl;
			return 0;
		}
		else {
			k -= gogo[s.length() - q];
			ans += gogo[s.length() - q] * q;
		}
	}
	cout << -1 << endl;
}