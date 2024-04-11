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
int ans[40];
int main() {
	long long m, n;
	cin >> m >> n;
	REP(q, n) {
		cout << m << endl;
		int a;
		cin >> a;
		if (a == 0) {
			return 0;
		}
		if (a == -1) {
			ans[q] = 0;
		}
		else {
			ans[q] = 1;
		}
	}
	int now_itr = 0;
	long long bot = 1;
	long long top = m;
	while (top - bot > 1) {
		long long mid = (top + bot) / 2;
		cout << mid << endl;
		int cnt = 0;
		cin >> cnt;
		if (cnt == 0) {
			return 0;
		}
		if (ans[now_itr] == 1) {
			if (cnt == -1) {
				cnt = 1;
			}
			else {
				cnt = -1;
			}
		}
		if (cnt == -1) {
			top = mid;
		}
		else {
			bot = mid;
		}
		now_itr++;
		now_itr %= n;
	}
	cout << bot << endl;
	return 0;
}