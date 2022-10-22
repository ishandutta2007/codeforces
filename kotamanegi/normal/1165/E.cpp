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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
map<pair<long long, long long>, long long> memo;
long long power(long long a,long long now) {
	if (memo[make_pair(a, now)]) return memo[make_pair(a, now)];
	long long ans = 1;
	pair<int, int> base = make_pair(a, now);
	while (now != 0) {
		if (now % 2 == 1) {
			ans *= a;
			ans %= MOD;
		}
		now /= 2;
		a *= a;
		a %= MOD;
	}
	return memo[base] = ans;
}
long long inv(long long a) {
	return power(a, MOD - 2);
}
long long permutation(long long a, long long b) {
	long long ans = 1;
	for (long long i = 0; i < b; ++i) {
		ans *= (a - i);
		ans %= MOD;
	}
	return ans;
}
long long combination(long long a, long long b) {
	long long ans = 1;
	for (long long i = 0; i < b; ++i) {
		ans *= (a - i);
		ans %= MOD;
		ans *= inv(i + 1);
		ans %= MOD;
	}
	return ans;
}
int main() {
	long long n;
	cin >> n;
	long long now_mod = 998244353;
	vector<long long> a, b;
	REP(i, n) {
		long long c;
		cin >> c;
		c *= (n - i);
		c *= (i + 1LL);
		a.push_back(c);
	}
	REP(i, n) {
		long long c;
		cin >> c;
		b.push_back(c);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long ans = 0;
	REP(i, n) {
		ans += (a[i] % now_mod) * b[n - i - 1];
		ans %= now_mod;
	}
	cout << ans << endl;
	return 0;
}