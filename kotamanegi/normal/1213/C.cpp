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
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	int test_case;
	cin >> test_case;
	REP(i, test_case) {
		long long n, m;
		cin >> n >> m;
		long long geko = n / m;
		long long ans = 0;
		long long cnt[20] = {};
		REP(q, 10) {
			if (q != 0) cnt[q] = cnt[q - 1];
			cnt[q] += (m * (q + 1LL)) % 10LL;
		}
		ans = (geko / 10) * cnt[9];
		geko %= 10;
		if (geko != 0) {
			ans += cnt[geko - 1];
		}
		cout << ans << endl;
	}
}