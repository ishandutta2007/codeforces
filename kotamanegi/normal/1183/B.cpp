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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define REP(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main(){
	int query;
	cin >> query;
	REP(i, query) {
		long long n, k;
		cin >> n >> k;
		vector<long long> input;
		REP(i, n) {
			long long a;
			cin >> a;
			input.push_back(a);
		}
		sort(input.begin(), input.end());
		long long top = input[0] + k;
		long long bot = input[input.size() - 1] - k;
		if (bot <= top) {
			cout << top << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}