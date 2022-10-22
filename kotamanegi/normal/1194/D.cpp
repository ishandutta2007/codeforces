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
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 262144
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	int query;
	cin >> query;
	REP(teas, query) {
		long long n, k;
		cin >> n >> k;
		if (n < k) {
			if (n % 3 == 0) {
				cout << "Bob" << endl;
			}
			else {
				cout << "Alice" << endl;
			}
			continue;
		}
		if (k % 3 == 0) {
			long long hoge = (n - k) / (k + 1);
			n -= hoge * (k + 1) + k;
			n += 2;
			if (n % 3 == 0) {
				cout << "Bob" << endl;
			}
			else {
				cout << "Alice" << endl;
			}
			continue;
		}
		if (k % 3 == 1) {
			if (n % 3 == 0) {
				cout << "Bob" << endl;
			}
			else {
				cout << "Alice" << endl;
			}
			continue;
		}
		if (k % 3 == 2) {
			if (n % 3 == 0) {
				cout << "Bob" << endl;
			}
			else {
				cout << "Alice" << endl;
			}
			continue;
		}
	}
}