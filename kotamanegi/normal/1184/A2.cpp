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
using namespace std;
typedef string::const_iterator State;
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
long long ans_tatami[1000];
map<long long, long long> itring;
int itr = 1;
vector<long long> divider;
vector<long long> dp[1000];
string s;
long long solve(long long now,long long back_itr) {
	if (itring.find(now) != itring.end()) return 0;
	itring[now] = itr;
	int now_itr = itr;
	itr++;
	for (int q = 0; q < now; ++q) {
		dp[now_itr].push_back(0);
	}
	for (int q = 0; q < dp[back_itr].size(); ++q) {
		dp[now_itr][q % now] += dp[back_itr][q];
		dp[now_itr][q % now] %= 2;
	}
	ans_tatami[now_itr] = 1;
	for (int q = 0; q < now; ++q) {
		if (dp[now_itr][q] == 1) {
			ans_tatami[now_itr] = 0;
			break;
		}
	}
	for (int q = 0; q < divider.size(); ++q) {
		if (now % divider[q] == 0) {
			solve(now / divider[q], now_itr);
		}
	}
	return 0;
}
int sosuu[300000] = {};
int main() {
	int n;
	cin >> n;
	cin >> s;
	for (int q = 2; q <= n; ++q) {
		if (sosuu[q] == 0) {
			if (n % q == 0) {
				divider.push_back(q);
			}
			for (int j = 2; q * j <= n; ++j) {
				sosuu[q * j] = 1;
			}
		}
	}
	REP(i, s.length()) {
		if (s[i] == '1') {
			dp[0].push_back(1);
		}
		else {
			dp[0].push_back(0);
		}
	}
	solve(n, 0);
	long long ans = 0;
	for (int q = 1; q <= n; ++q) {
		long long geko = gcd(n, q);
		ans += ans_tatami[itring[geko]];
	}
	cout << ans << endl;
}