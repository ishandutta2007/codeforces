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
#define seg_size 65536*16
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	long long n;
	cin >> n;
	vector<long long> a;
	REP(i, n) {
		long long tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	long long ans = 0;
	for (int i = 0; i < a.size() / 2 - 1; ++i) {
		ans += (a[i] + a[a.size() - i - 1]) * (a[i] + a[a.size() - i - 1]);
	} 
	long long geko = 0;
	geko = a[a.size() / 2 - 1] + a[a.size() / 2];
	if (a.size() % 2 == 1) {
		geko += a[a.size() / 2 + 1];
	}
	ans += geko * geko;
	cout << ans << endl;
	return 0;
}