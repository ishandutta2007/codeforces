//J^!w

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
vector<pair<long double, long double>> inputs;
bool solve(long double now) {
	long double hoge = LONG_INF;
	REP(i, inputs.size()) {
		hoge = min(hoge, inputs[i].first + inputs[i].second * now);
	}
	REP(i, inputs.size()) {
		if (inputs[i].first - inputs[i].second * now > hoge) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int n;
	cin >> n;
	REP(i, n) {
		long double a;
		cin >> a;
		inputs.push_back(make_pair(a, 0));
	}
	REP(i, n) {
		cin >> inputs[i].second;
	}
	long double bot = 0;
	long double top = 1e9;
	REP(q, 100) {
		long double mid = (bot + top) / 2.0;
		if (solve(mid) == true) {
			top = mid;
		}
		else bot = mid;
	}
	cout << fixed << setprecision(10);
	cout << bot << endl;
}