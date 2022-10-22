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
int main() {
	int query;
	cin >> query;
	REP(i, query) {
		string s;
		cin >> s;
		string a, b;
		REP(i, s.length()) {
			if ((s[i] - '0') % 2 == 0) {
				a.push_back(s[i]);
			}
			else {
				b.push_back(s[i]);
			}
		}
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		for (char i = '0'; i <= '9'; ++i) {
			if ((i - '0') % 2 == 0) {
				//a
				while (a.empty() == false && a.back() <= i) {
					cout << a.back();
					a.pop_back();
				}
			}
			else {
				while (b.empty() == false && b.back() <= i) {
					cout << b.back();
					b.pop_back();
				}
			}
		}
		cout << endl;
	}
}