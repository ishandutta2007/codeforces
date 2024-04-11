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
#define int long long
	int n;
	string s;
	cin >> n >> s;
	long long ans = 0;
	REP(tea, 2) {
		int stock = 0;
		int going = n;
		for (long long i = n - 1; i >= 0; --i) {
			if (s[i] == 'B') {
				stock = 1;
			}
			else if(s[i] == 'A'){
				if (i != n - 1) {
					if (s[i + 1] == 'A') {
						long long now = n - i - 1 - stock;
						ans += now;
					}
					else {
						long long now = n - going;
						ans += now;
					}
				}
				going = i;
			}
		}
		REP(q, s.length()) {
			if (s[q] == 'A') {
				s[q] = 'B';
			}
			else {
				s[q] = 'A';
			}
		}
	}
	cout << ans << endl;
}