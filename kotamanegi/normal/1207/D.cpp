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
int main(){
	long long n;
	cin >> n;
	long long ans = 1;
	vector<pair<long long, long long>> inputs;
	for (long long i = 1; i <= n; ++i) {
		long long a, b;
		cin >> a >> b;
		inputs.push_back(make_pair(a, b));
		ans *= i;
		ans %= MOD;
	}
	sort(inputs.begin(), inputs.end());
	long long cnt = 1;
	long long bo = 1;
	for (int i = 1; i < n; ++i) {
		if (inputs[i - 1].first != inputs[i].first) {
			for (long long q = 1; q <= cnt; ++q) {
				bo *= q;
				bo %= MOD;
			}
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	for (long long q = 1; q <= cnt; ++q) {
		bo *= q;
		bo %= MOD;
	}
	ans -= bo;
	ans %= MOD;
	bo = 1;
	cnt = 1;
	for (int i = 1; i < n; ++i) {
		if (inputs[i-1].second > inputs[i].second) {
			bo = 0;
		}
		else if (inputs[i - 1].first != inputs[i].first || inputs[i - 1].second < inputs[i].second) {
			for (long long q = 1; q <= cnt; ++q) {
				bo *= q;
				bo %= MOD;
			}
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	for (long long q = 1; q <= cnt; ++q) {
		bo *= q;
		bo %= MOD;
	}
	ans += bo;
	ans %= MOD;
	REP(i, n) {
		swap(inputs[i].first, inputs[i].second);
	}
	sort(inputs.begin(), inputs.end());
	cnt = 1;
	bo = 1;
	for (int i = 1; i < n; ++i) {
		if (inputs[i - 1].first != inputs[i].first) {
			for (long long q = 1; q <= cnt; ++q) {
				bo *= q;
				bo %= MOD;
			}
			cnt = 1;
		}
		else {
			cnt++;
		}
	}
	for (long long q = 1; q <= cnt; ++q) {
		bo *= q;
		bo %= MOD;
	}
	ans -= bo;
	ans += 3LL * MOD;
	ans %= MOD;
	cout << ans << endl;
}