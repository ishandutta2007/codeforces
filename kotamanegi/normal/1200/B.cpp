
/*

This Submission is to determine how many 120/240 min const. delivery point there are.

*/
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
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 1000000007
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
int main() {
	iostream::sync_with_stdio(false);
	int test;
	cin >> test;
	REP(i, test) {
		long long n, m, k;
		cin >> n >> m >> k;
		long long a;
		cin >> a;
		int ok = 1;
		REP(i, n - 1) {
			long long b;
			cin >> b;
			long long target = b - k;
			target = max(target, 0LL);
			if (a < target) {
				m -= target - a;
				a = target;
				if (m < 0) {
					ok = 0;
				}
			}
			else {
				m += a - target;
				a = target;
			}
			a = b;
		}
		if (ok == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}