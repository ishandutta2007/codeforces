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
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
int cnt[2][10];
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	REP(i, s.length()) {
		cnt[i / n][s[i] - '0']++;
	}
	int now = 0;
	int ok = 1;
	for (int i = 0; i < 10; ++i) {
		now -= cnt[1][i];
		if (now < 0) {
			ok = 0;
		}
		now += cnt[0][i];
	}
	if (now != 0) {
		ok = 0;
	}
	if (ok == 0) {
		ok = 1;
		now = 0;
		for (int i = 9; i >= 0; --i) {
			now -= cnt[1][i];
			if (now < 0) {
				ok = 0;
			}
			now += cnt[0][i];
		}
		if (now != 0) {
			ok = 0;
		}
	}
	string ans[2] = { "NO","YES" };
	cout << ans[ok] << endl;
}