#define  _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
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
#include <map>
#include <fstream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <assert.h>
#include <complex>
using namespace std;
#define eps 0.000001
#define LONG_INF 10000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD 998244353
#define seg_size 65536*16
#define REP(i,n) for(long long i = 0;i < n;++i)
int main() {
	int s;
	cin >> s;
	vector<string> bobo;
	REP(i, s) {
		string a;
		cin >> a;
		bobo.push_back(a);
	}
	int xe[5] = { 0,1,1,-1,-1 };
	int ye[5] = { 0,1,-1,1,-1 };
	int ans = 0;
	for (int i = 1; i < s - 1; ++i) {
		for (int q = 1; q < s - 1; ++q) {
			int ok = 1;
			REP(t, 5) {
				int x = i + xe[t];
				int y = q + ye[t];
				if (bobo[x][y] == '.') ok = 0;
			}
			ans += ok;
		}
	}
	cout << ans << endl;
	return 0;
}