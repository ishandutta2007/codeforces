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
long long cnt[300000];
int main() {
	cnt[0] = 1;
	for (int q = 0; q < 200000; ++q) {
		cnt[q] %= MAX_MOD;
		cnt[q + 1] += cnt[q];
		cnt[q + 2] += cnt[q];
	}
	string s;
	cin >> s;
	long long ans = 1;
	long long cnter = 1;
	for (int q = 1; q < s.length(); ++q) {
		if (s[q - 1] != s[q]) {
			if (s[q - 1] == 'n' || s[q - 1] == 'u') {
				ans *= cnt[cnter];
				ans %= MAX_MOD;
			}
			cnter = 1;
		}
		else {
			cnter++;
		}
	}
	if (s.back() == 'n' || s.back() == 'u') {
		ans *= cnt[cnter];
		ans %= MAX_MOD;
	}
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == 'm' || s[i] == 'w') ans = 0;
	}
	cout << ans << endl;
}