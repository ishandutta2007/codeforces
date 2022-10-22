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
	int a, x, y;
	cin >> a >> x >> y;
	int ans = 1;
	if (y == 0) {
		cout << -1 << endl;
		return 0;
	}
	y -= a;
	if (y < 0) {
		if (x*2 > -a && x*2 < a) {
			cout << ans << endl;
		}
		else {
			cout << -1 << endl;
		}
		return 0;
	}
	ans += 3 * (y / (2 * a));
	y %= 2 * a;
	if (y > 0 && y < a) {
		if (x*2 > -a && x*2 < a) {
			cout << ans+1 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	else if (y > a&& y < 2 * a) {
		if (x > -a && x < 0) {
			cout << ans + 2 << endl;
		}
		else if (x > 0 && x < a) {
			cout << ans + 3 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	else {
		cout << -1 << endl;
	}
}