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
long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
int main() {
#define int long long
	long long n;
	cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	long long base = 0;
	vector<int> going;
	for (long long i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			going.push_back(i);
			if (i * i != n) {
				going.push_back(n / i);
			}
		}
	}
	going.push_back(n);
	sort(going.begin(), going.end());
	int now = going.back();
	for (int q = 0; q < going.size(); ++q) {
		now = gcd(now, going[q]);
	}
	cout << now << endl;
}