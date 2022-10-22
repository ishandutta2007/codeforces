//J^!w

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
	int query;
	cin >> query;
	REP(i, query) {
		long long n;
		cin >> n;
		long long tmp[60] = {};
		for (int i = 0; i < 60; ++i) {
			tmp[i] = n % 3;
			n /= 3;
		}
		long long bobo = 1;
		for (int i = 0; i < 60; ++i) {
			if (tmp[i] == 2) {
				for (int j = 0; j <= i; ++j) {
					tmp[j] = 0;
				}
				tmp[i + 1]++;
			}
			else if (tmp[i] == 3) {
				for (int j = 0; j <= i; ++j) {
					tmp[j] = 0;
				}
				tmp[i + 1]++;
			}
		}
		for (int i = 0; i < 60; ++i) {
			n += tmp[i] * bobo;
			bobo *= 3;
			if (bobo > 3e18) {
				break;
			}
		}
		cout << n << endl;
	}
}