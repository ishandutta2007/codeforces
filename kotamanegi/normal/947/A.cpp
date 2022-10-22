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
#include <cstdlib>
#include <unordered_map>
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int griding[20000000];
int main() {
#define int long long
	long long a;
	cin >> a;
	vector<long long> primes;
	for (int i = 2; i <= 2000000; ++i) {
		if (griding[i] == 0) {
			primes.push_back(i);
			for (int q = 1; i*q <= 2000000; ++q) {
				griding[i*q] = 1;
			}
		}
	}
	long long maximum_geko = 0;
	for (int i = 0; i < primes.size()&&a >= primes[i]; ++i) {
		if (a % primes[i] == 0) {
			maximum_geko = max(maximum_geko, primes[i]);
		}
	}
	long long ans = a;
	long long bot = a - maximum_geko + 1;
	long long top = a;
	for (int i = 0; i < primes.size(); ++i) {
		long long hoge = (bot + primes[i] - 1) / primes[i];
		hoge *= primes[i];
		if (hoge == primes[i]) break;
		if (hoge >= bot && hoge <= top) {
			ans = min(ans, hoge - primes[i] + 1);
		}
	}
	cout << ans << endl;
	return 0;
}