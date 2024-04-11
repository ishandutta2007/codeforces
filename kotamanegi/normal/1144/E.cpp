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
string summing(string a, string b) {
	string c;
	int now = 0;
	while (now != 0 || a.empty() == false) {
		if (a.empty() == false) {
			now += a.back() + b.back() - (2 * 'a');
			a.pop_back();
			b.pop_back();
		}
		c.push_back(now % 26 + 'a');
		now /= 26;
	}
	reverse(c.begin(), c.end());
	return c;
}
string divi(string a) {
	string c;
	int now = 0;
	for (int i = 0; i < a.length(); ++i) {
		now += a[i] - 'a';
		c.push_back((now / 2) + 'a');
		if (now % 2 == 0) {
			now = 0;
		}
		else {
			now = 26;
		}
	}
	return c;
}
int main() {
	int k;
	cin >> k;
	string a, b;
	cin >> a >> b;
	string c = summing(a,b);
	string d = divi(c);
	if (d.length() != a.length()) {
		d.erase(d.begin());
	}
	cout << d << endl;
}