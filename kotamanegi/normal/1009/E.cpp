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
	long long n;
	scanf("%lld", &n);
	vector<long long> b;
	b.reserve(n);
	REP(i, n) {
		long long a;
		scanf("%lld", &a);
		b.push_back(a);
	}
	long long bobo = 1;
	long long ans = b[b.size() - 1];
	long long pepe = 1;
	for (int i = b.size() - 2; i >= 0; --i) {
		long long gogo = bobo * (pepe + 2LL);
		gogo %= MOD;
		ans += b[i] * gogo;
		ans %= MOD;
		pepe++;
		bobo *= 2LL;
		bobo %= MOD;
	}
	cout << ans << endl;
	return 0;
}