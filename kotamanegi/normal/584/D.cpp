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
int ok(int now) {
	if (now <= 1) return 0;
	for (int q = 2; q <= sqrt(now); ++q) {
		if (now % q == 0) return 0;
	}
	return 1;
}
int main() {
	long long n;
	cin >> n;
	if (ok(n)) {
		cout << "1" << endl;
		cout << n << endl;
		return 0;
	}
	for (int i = n - 1; i >= 2; --i) {
		if (ok(i) == 1) {
			int hoge = n - i;
			if (ok(hoge) == 1) {
				cout << "2" << endl;
				cout << i << " " << hoge << endl;
				return 0;
			}
			for (int q = 2; q < hoge; ++q) {
				if (ok(q) == 1) {
					if (ok(hoge - q) == 1) {
						cout << "3" << endl;
						cout << i << " " << hoge-q << " " << q << endl;
						return 0;
					}
				}
			}
		}
	}
}