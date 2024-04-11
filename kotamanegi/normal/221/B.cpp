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
int finds(int a, int b) {
	int cnt[2][10] = {};
	do{
		cnt[0][a % 10] = 1;
		a /= 10;
	} while (a != 0);
	do {
		cnt[1][b % 10] = 1;
		b /= 10;
	} while (b != 0);
	REP(q, 10) {
		if (cnt[0][q] == 1 && cnt[1][q] == 1) return 1;
	}
	return 0;
}
int main() {
	long long x;
	cin >> x;
	int ans = 0;
	for (int i = 1; i * i <= x; ++i) {
		if (x % i == 0) {
			ans += finds(i, x);
			if (i != x / i) {
				ans += finds(x / i, x);
			}
		}
	}
	cout << ans << endl;
}