#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
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
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
#include <complex>
using namespace std;
#define eps 0.000001
#define LONG_INF 10000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
long long dp[600][600];
vector<int> gogo;
long long solve(long long left, long long right) {
	if (dp[left][right]) return dp[left][right];
	if (left == right) return dp[left][right] = 1;
	long long ans = 10000;
	ans = min(ans, solve(left, right - 1) + 1);
	ans = min(ans, solve(left + 1, right) + 1);
	if (gogo[left] == gogo[right]) ans = min(ans, solve(left + 1, right - 1) + 1);
	for (int i = left + 1; i < right; ++i) {
		if (gogo[i] == gogo[right]) {
			if (right == i + 1) {
				ans = min(ans, solve(left, i));
			}
			else {
				ans = min(ans, solve(left, i) + solve(i + 1, right - 1));
			}
		}
		if (gogo[i] == gogo[left]) {
			if (left == i - 1) {
				ans = min(ans, solve(i, right));
			}
			else {
				ans = min(ans, solve(left + 1, i - 1) + solve(i, right));
			}
		}
	}
	return dp[left][right] = ans;
}
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	gogo.push_back(s[0] - 'a');
	for (int i = 1; i < s.length(); ++i) {
		if (s[i] != s[i - 1]) {
			gogo.push_back(s[i] - 'a');
		}
	}
	cout << solve(0, gogo.size()-1) << endl;
	return 0;
}