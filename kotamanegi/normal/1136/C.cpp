#define _CRT_SECURE_NO_WARNINGS
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
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
#define LONG_INF 10000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353LL
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a[2000], b[2000];
	REP(i, n) {
		REP(q, m) {
			int d;
			cin >> d;
			a[i + q].push_back(d);
		}
	}
	REP(i, n) {
		REP(q, m) {
			int d;
			cin >> d;
			b[i + q].push_back(d);
		}
	}
	for (int i = 0; i < 2000; ++i) {
		sort(a[i].begin(), a[i].end());
		sort(b[i].begin(), b[i].end());
		if (a[i] != b[i]) {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	return 0;
}