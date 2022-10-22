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
const long double eps = 1e-12;
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*4
#define REP(a,b) for(long long a = 0;a < b;++a)
int main(){
	iostream::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	REP(tester, test_case) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int bad = 1;
		for (int mid = 0; mid <= 9; ++mid) {
			string a, b;
			string c;
			for (int q = 0; q < s.length(); ++q) {
				if (s[q] <= '0' + mid) {
					if (s[q] == '0' + mid) {
						if (b.length() == 0 || b.back() == '0' + mid) {
							b.push_back(s[q]);
							c.push_back('2');
							continue;
						}
					}
					c.push_back('1');
					a.push_back(s[q]);
				}
				else {
					c.push_back('2');
					b.push_back(s[q]);
				}
			}
			a += b;
			int ok = 1;
			for (int j = 0; j < a.length() - 1; ++j) {
				if (a[j] > a[j + 1]) {
					ok = 0;
					break;
				}
			}
			if (ok == 1) {
				cout << c << endl;
				bad = 0;
				break;
			}
		}
		if (bad == 1) {
			cout << "-" << endl;
		}
	}
}