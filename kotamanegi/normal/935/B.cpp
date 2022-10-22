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
#include <cstdlib>
#define EVAL 1
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 1048576
#define PI 3.1415926535
int main() {
	map<char, int> x, y;
	x['U'] = 1;
	x['D'] = -1;
	y['R'] = 1;
	y['L'] = -1;
	int n;
	cin >> n;
	string s;
	cin >> s;
	int xe = x[s[0]], ye = y[s[0]];
	int over = 1;
	if (s[0] == 'R' || s[0] == 'D') {
		over = 0;
	}
	long long ans = 0;
	for (int i = 1;i < s.length();++i) {
		if (xe == ye) {
			if (s[i] == 'R' || s[0] == 'D') {
				if (over == 1) ans++;
				over = 0;
			}
			else {
				if (over == 0) ans++;
				over = 1;
			}
		}
		xe += x[s[i]];
		ye += y[s[i]];
	}
	cout << ans << endl;
	return 0;
}