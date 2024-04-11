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
long long ans[200000];
int main() {
	long long n, k;
	cin >> n >> k;
	for (long long q = 0; q < k; ++q) {
		ans[q] = q + 1;
		n -= q + 1;
	}
	if (n < 0) {
		cout << "NO" << endl;
		return 0;
	}
	for (long long q = 0; q < k; ++q) {
		ans[q] += n / k;
	}
	n %= k;
	REP(i, 20) {
		for (int q = k - 1; q >= 1; --q) {
			long long go = ans[q - 1] * 2;
			if (q != k - 1) {
				go = min(go, ans[q + 1] - 1);
			}
			go -= ans[q];
			if (go > n) {
				ans[q] += n;
				n = 0;
			}
			else {
				ans[q] += go;
				n -= go;
			}
		}
	}
	if (n != 0) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	REP(i, k) {
		cout << ans[i] << " ";
	}
	cout << endl;
}