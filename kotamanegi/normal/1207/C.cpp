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
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	int test_case;
	cin >> test_case;
	REP(te, test_case) {
		long long n, a, b;
		cin >> n >> a >> b;
		string s;
		cin >> s;
		s += "0";
		long long dp_a = b;
		long long dp_b = LONG_INF;
		for (int i = 0; i < s.length()-1; ++i) {
			long long next_a = LONG_INF;
			long long next_b = LONG_INF;
			if (s[i] == '0'&&s[i+1] == '0') {
				next_a = min(dp_a + a, dp_b + 2*a) + b;
			}
			next_b = min(dp_a + 2 * a, dp_b + a) + 2 * b;
			dp_a = next_a;
			dp_b = next_b;
		}
		cout << dp_a << endl;
	}
}