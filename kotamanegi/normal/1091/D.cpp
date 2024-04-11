#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*2
#define REP(i,n) for(long long i = 0;i < n;++i)
long long gyaku(long long a) {
	long long ans = 1;
	long long s = MOD - 2LL;
	while (s != 0) {
		if (s % 2 == 1) {
			ans *= a;
			ans %= MOD;
		}
		s /= 2;
		a *= a;
		a %= MOD;
	}
	return ans;
}
int main() {
	long long n;
	cin >> n;
	long long ans = 0;
	long long geko = 1;
	for (long long i = 1; i <= n; ++i) {
		geko *= i;
		geko %= MOD;
	}
	ans += geko;
	long long bobo = 1;
	long long nya = geko;
	for (long long i = 0; i < n; ++i) { 
		long long hoge = nya * gyaku(n - i);
		hoge %= MOD;
		nya = hoge;
		long long type = geko * gyaku(hoge);
		type %= MOD;
		type -= bobo;
		type += MOD;
		type %= MOD;
		ans += i * type;
		ans %= MOD;
		bobo += type;
		bobo %= MOD;
	}
	cout << ans << endl;
	return 0;
}