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
int main(){
	long long n, k;
	cin >> n >> k;
	vector<long long> inputs;
	REP(i, n) {
		long long a;
		cin >> a;
		inputs.push_back(a);
	}
	sort(inputs.begin(), inputs.end());
	int ans = inputs.back() - inputs[0];
	for (long long i = 1; i < inputs.size(); ++i) {
		long long diff = inputs[i] - inputs[i - 1];
		if (diff * i <= k) {
			k -= diff * i;
			ans -= diff;
		}
		else {
			ans -= k / i;
			break;
		}
		diff = inputs[inputs.size()-i] - inputs[inputs.size() - i - 1];
		if (diff * i <= k) {
			k -= diff * i;
			ans -= diff;
		}
		else {
			ans -= k / i;
			break;
		}
	}
	cout << max(ans, 0) << endl;
	return 0;
}