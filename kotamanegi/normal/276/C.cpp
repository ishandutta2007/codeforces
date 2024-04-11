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
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
long long imos[3000000];
int main() {
	int n, query;
	cin >> n >> query;
	vector<long long> a, b;
	REP(i, n) {
		long long c;
		cin >> c;
		a.push_back(c);
	}
	REP(i, query) {
		int a, b;
		cin >> a >> b;
		imos[a - 1]++;
		imos[b]--;
	}
	for (int q = 0; q < n; ++q) {
		imos[q + 1] += imos[q];
		b.push_back(imos[q]);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long ans = 0;
	REP(i, a.size()) {
		ans += a[i] * b[i];
	}
	cout << ans << endl;
}