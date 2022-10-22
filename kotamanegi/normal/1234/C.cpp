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
#define LONG_INF 1000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	int query;
	cin >> query;
	REP(i, query) {
		int n;
		cin >> n;
		string a, b;
		cin >> a >> b;
		for (int i = 0; i < a.size(); ++i) {
			if (a[i] <= '2') {
				a[i] = '0';
			}
			else {
				a[i] = '1';
			}
			if (b[i] <= '2') {
				b[i] = '0';
			}
			else {
				b[i] = '1';
			}
		}
		int now = 0;
		for (int i = 0; i < n; ++i) {
			if (now == 0) {
				if (a[i] == '1') {
					if (b[i] == '0') {
						now = 0;
						break;
					}
					now = 1;
				}
			}
			else {
				if (b[i] == '1') {
					if (a[i] == '0') {
						now = 0;
						break;
					}
					now = 0;
				}
			}
		}
		if (now == 1) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}