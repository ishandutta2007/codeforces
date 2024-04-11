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
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
using namespace std;
#define eps 0.000000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*4
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
#define int long long
	int m;
	int n;
	cin >> n >> m;
	long long ans = 0.0;
	long long aa = n - 1LL;
	REP(i, m) {
		long long a, b;
		cin >> a >> b;
		ans += a*n;
		if (b < 0) {
			long long geko = 0;
			long long hoge = aa / 2;
			geko += hoge * (hoge + 1LL) / 2LL;
			hoge = aa - hoge;
			geko += hoge * (hoge + 1LL) / 2LL;
			ans += b * geko;
		}
		else {
			ans += b * n*(n-1LL)/2LL;
		}
	}
	long double a = ans;
	a /= (long double)n;
	cout <<fixed << setprecision(10) <<  a << endl;
	return 0;
}