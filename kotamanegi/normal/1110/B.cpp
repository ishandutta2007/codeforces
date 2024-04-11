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
	long long n, m, k;
	cin >> n >> m >> k;
	vector<long long> geko;
	REP(i, n) {
		long long a;
		cin >> a;
		geko.push_back(a);
	}
	sort(geko.begin(), geko.end());
	vector<long long> gogo;
	long long ans = n;
	for (int i = 1; i < n; ++i) {
		gogo.push_back(geko[i] - geko[i - 1]);
	}
	sort(gogo.begin(), gogo.end());
	for (int i = 0; i < n - k; ++i) {
		ans += gogo[i] - 1;
	}
	cout << ans << endl;
	return 0;
}