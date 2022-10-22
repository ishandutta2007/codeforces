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
int main(){
	int n;
	cin >> n;
	vector<long long> a, b;
	REP(i, n) {
		long long tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	REP(i, n) {
		long long tmp;
		cin >> tmp;
		b.push_back(tmp);
	}
	if (a[0] != b[0] || a[n - 1] != b[n - 1]) {
		cout << "No" << endl;
		return 0;
	}
	vector<long long> c, d;
	for (int i = 1; i < n; ++i) {
		c.push_back(a[i] - a[i - 1]);
		d.push_back(b[i] - b[i - 1]);
	}
	sort(c.begin(), c.end());
	sort(d.begin(), d.end());
	for (int i = 0; i < c.size(); ++i) {
		if (c[i] != d[i]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}