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
	set<long long> inputs;
	long long sum = 0;
	REP(i, n) {
		long long a;
		cin >> a;
		sum += a;
		inputs.insert(sum);
	}
	long long ans = 0;
	vector<long long> go;
	REP(i, k) {
		long long a;
		cin >> a;
		go.push_back(a);
	}
	for (auto i = inputs.begin(); i != inputs.end(); ++i) {
		long long value = go[0] - *i;
		set<long long> nya;
		for (auto q = inputs.begin(); q != inputs.end(); ++q) {
			nya.insert(value + *q);
		}
		int ok = 1;
		for (int q = 0; q < k; ++q) {
			if (nya.find(go[q]) == nya.end())ok = 0;
		}
		ans += ok;
	}
	cout << ans << endl;
}