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
	long long n;
	cin >> n;
	long long maxi = (n + 1LL) * 9LL - n;
	long long mini = LONG_INF;
	for (long long i = 1; i <= 100000; ++i) {
		if (n % i == 0) {
			long long b = n / i;
			for (long long q = 1; q <= 10000; ++q) {
				if (b % q == 0) {
					long long c = b / q;
					mini = min(mini, min({ (i + 1LL) * (q + 2LL) * (c + 2LL),(i+2LL)*(q+1LL)*(c+2LL),(i+2LL)*(q+2LL)*(c+1LL)})-n);
					maxi = max(maxi, (i + 1LL) * (q + 2LL) * (c + 2LL) - n);
				}
			}
		}
	}
	cout << mini << " " << maxi << endl;
}