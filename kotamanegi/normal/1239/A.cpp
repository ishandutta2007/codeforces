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
long long calc[300000];
long long calc_two[300000];
int main() {
	long long n, m;
	cin >> n >> m;
	if (n > m) swap(n, m);
	calc[0] = 1;
	long long now_a = 1;
	long long now_b = 0;
	for (int i = 1; i < 300000; ++i) {
		long long next_a = now_a + now_b;
		long long next_b = now_a;
		now_a = next_a;
		now_b = next_b;
		now_a %= MAX_MOD;
		now_b %= MAX_MOD;
		calc[i] = (now_a + now_b) % MAX_MOD;
	}
	calc_two[0] = 1;
	now_a = 0;
	now_b = 1;
	for (int i = 1; i < 300000; ++i) {
		long long next_a = now_a + now_b;
		long long next_b = now_a;
		now_a = next_a;
		now_b = next_b;
		now_a %= MAX_MOD;
		now_b %= MAX_MOD;
		calc_two[i] = (now_a + now_b) % MAX_MOD;
	}
	long long ans = 0;
	ans += calc[m - 1] + calc[n - 1] - 1;
	ans %= MAX_MOD;
	cout << (ans * 2) % MAX_MOD << endl;
}