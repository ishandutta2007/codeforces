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
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
long long diviser[6000000] = {};
long long stock[6000000] = {};
long long solve(long long n) {
	if (stock[n]) return stock[n];
	long long hoge = 0;
	if (diviser[n] == 10000000) {
		hoge = n*(n - 1) / 2;
		hoge %= MAX_MOD;
		return stock[n] = hoge;
	}else{
		hoge = (n / diviser[n]) * diviser[n];
		hoge %= MAX_MOD;
		hoge *= diviser[n] - 1;
		hoge %= MAX_MOD;
		hoge *= 500000004;//inv
		hoge %= MAX_MOD;
		hoge += solve(n / diviser[n]);
		hoge %= MAX_MOD;
		return stock[n] = hoge;
	}
}
int main() {
	long long t, l, r;
	cin >> t >> l >> r;
	for (int i = 1;i <= 5900000;++i) {
		diviser[i] = 10000000;
	}
	for (long long i = 2;i <= 5900000;++i) {
		if (diviser[i] == 10000000) {
			for (int q = 2;i*q <= 5900000;++q) {
				diviser[i*q] = min(diviser[i*q], i);
			}
		}
	}
	long long ans = 0;
	long long gyao = 1;
	for (int i = l;i <= r;++i) {
		ans += solve(i)*gyao;
		ans %= MAX_MOD;
		gyao *= t;
		gyao %= MAX_MOD;
	}
	cout << ans << endl;
	return 0;
}