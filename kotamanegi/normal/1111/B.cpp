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
int main() {
#define int long long
	int n, k, m;
	cin >> n >> k >> m;
	vector<long double> inputs;
	REP(i, n) {
		long double a;
		cin >> a;
		inputs.push_back(a);
	}
	sort(inputs.begin(), inputs.end());
	long long hoge = 0;
	REP(q, inputs.size()) {
		hoge += inputs[q];
	}
	long double ans = -1.0;
	for (long long i = 0; i < inputs.size(); ++i) {
		long double now_move = 0.0;
		now_move += min(m, k* (long long)((long long)inputs.size() - i));
		now_move += hoge;
		now_move /= (long double)((long long)inputs.size() - (long long)i);
		ans = max(ans, now_move);
		hoge -= inputs[i];
		m--;
		if (m < 0) break;
	}
	cout << fixed << setprecision(40);
	cout << ans << endl;
}