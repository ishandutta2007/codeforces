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
int cnt[3000000];
int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int now = 0;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] == '(') {
			now++;
		}
		else {
			now--;
		}
	}
	int target = 0;
	if (now == 2) {
		reverse(s.begin(), s.end());
		REP(q, s.length()) {
			if (s[q] == ')') {
				s[q] = '(';
			}
			else s[q] = ')';
		}
	}
	else if (now == -2) {
	}
	else {
		cout << 0 << endl;
		return 0;
	}
	now = 0;
	int ans = 0;
	int border = 1;
	for (int q = 0; q < s.length(); ++q) {
		if (s[q] == '(') {
			now++;
		}
		else {
			now--;
			ans += border;
		}
		
		if (now <= -1) {
			if (border == 0) {
				cout << 0 << endl;
				return 0;
			}
			now += 2;
			border = 0;
		}
	}
	cout << ans << endl;
}