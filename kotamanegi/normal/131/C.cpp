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
long long comb(long long a, long long b) {
	long long ans = 1;
	for (long long i = 1; i <= b; ++i) {
		ans *= (a - i + 1);
		ans /= i;
	}
	return ans;
}
int main() {
	long long n, m, t;
	cin >> n >> m >> t;
	long long ans = 0;
	for (long long i = 4; i <= n; ++i) {
		long long going = t - i;
		if (going < 1 || going > m) continue;
		ans += comb(n, i) * comb(m, going);
	}
	cout << ans << endl;
}