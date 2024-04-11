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
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define seg_size 524288
int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (c == 1 && d == a) {
		cout << 0 << endl;
	}
	else if (c == 1) {
		cout << abs(b - d) + 1 << endl;
		return 0;
	}
	else if (d == a) {
		cout << abs(b - c) + 1 << endl;
		return 0;
	}
	else {
		cout << 2 + abs(d - c) + min(abs(b - c), abs(b - d)) << endl;
		return 0;
	}
}