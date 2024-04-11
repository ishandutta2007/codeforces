/*

This Submission is to determine how many 120/240 min const. delivery point there are.

//info
120 req. steps <= 5
*/
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
#define eps 0.00000001
#define LONG_INF 1e18
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 1000000007
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)

unsigned long xor128() {
	static unsigned long x = time(NULL), y = 362436069, z = 521288629, w = 88675123;
	unsigned long t = (x ^ (x << 11));
	x = y; y = z; z = w;
	return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}

int main() {
	int n;
	cin >> n;
	if (n % 2 == 0) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		vector<long long> ans;
		ans.push_back(1);
		for (int q = 4; q < 2 * n; q += 4) {
			ans.push_back(q);
			ans.push_back(q + 1);
		}
		for (int q = 2; q < 2 * n; q += 4) {
			ans.push_back(q);
			ans.push_back(q + 1);
		}
		ans.push_back(2 * n);
		REP(i, ans.size()) {
				cout << ans[i] << " ";
		}
		cout << endl;
	}
}