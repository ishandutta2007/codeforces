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
#define int long long
	int n, m;
	cin >> n >> m;
	vector<int> a, b;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	REP(i, m) {
		int tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	if (a[a.size() - 1] > b[0]) {
		cout << -1 << endl;
		return 0;
	}
	long long ans = 0;
	for(int i = 0;i < n;++i){
		ans += m * a[i];
	}
	for (int q = 1; q < m; ++q) {
		ans += b[q] - a[a.size() - 1];
	}
	if (n == 1&&b[0] != a[a.size() - 1]) {
		cout << -1 << endl;
		return 0;
	}
	if (a[a.size() - 1] != b[0]) {
		ans += b[0] - a[a.size() - 2];
	}
	cout << ans << endl;
	return 0;
}