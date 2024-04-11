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
map<long long, long long> memorize;
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
int main() {
	long long geko;
	cin >> geko;
	memorize[1] = 0;
		memorize[3] = 1;
		memorize[7] = 1;
		memorize[15] = 5;
		memorize[31] = 1;
		memorize[63] = 21;
		memorize[127] = 1;
		memorize[255] = 85;
		memorize[511] = 73;
		memorize[1023] = 341;
	memorize[2047] = 89;
		memorize[4095] = 1365;
		memorize[8191] = 1;
		memorize[16383] = 5461;
		memorize[32767] = 4681;
		memorize[65535] = 21845;
		memorize[131071] = 1;
		memorize[262143] = 87381;
		memorize[524287] = 1;
		memorize[1048575] = 349525;
		memorize[2097151] = 299593;
		memorize[4194303] = 1398101;
		memorize[8388607] = 178481;
		memorize[16777215] = 5592405;
		memorize[33554431] = 1082401;
	REP(i, geko) {
		long long a;
		cin >> a;
		long long nya = 1;
		long long cnt = 0;
		while (nya <= a) {
			nya *= 2;
			cnt++;
		}
		if (nya - 1 == a) {
			/*
			for (int j = 1; j < 26; ++j) {
				long long bobo = 1 << j;
				bobo--;
				cout << "memorize[" << bobo << "] = ";
				long long ans = 0;
				for (long long q = 1; q <= bobo - 1; ++q) {
					long long b = bobo ^ q;
					long long c = bobo & q;
					ans = max(ans, gcd(b, c));
				}
				cout << ans << endl;
			}
			long long ans = 1;
			for (long long q = 2; q <= cnt - 1; ++q) {
				if (cnt % q == 0) {
					long long nya = 1;
					long long geko = 1;
					for (int t = 0; t < q; ++t) {
						geko *= 2;
					}
					ans = 0;
					for (int j = 0; j < cnt / q; ++j) {
						ans += nya;
						nya *= geko;
					}
					break;
				}
			}
			cout << ans << endl;
			*/
			cout << memorize[a] << endl;
		}
		else {
			cout << nya - 1 << endl;
		}
	}
	return 0;
}