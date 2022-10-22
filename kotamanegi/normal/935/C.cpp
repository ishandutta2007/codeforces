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
	long double r, x1, y1, x2, y2;
	cin >> r >> x1 >> y1 >> x2 >> y2;
	cout << fixed << setprecision(10);
	if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) >= r*r) {
		cout << x1 << " " << y1 << " " << r << endl;
		return 0;
	}
	if (x1 == x2&&y1 == y2) {
		cout << x1 << " " << (2*y1 + r) / (long double)2.0<<" " << r / (long double)2.0 << endl;
		return 0;
	}
	long double hoge = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
	hoge = sqrt(hoge);
	double bee = hoge;
	hoge += r;
	hoge /= (long double)2.0;
	//hoge is R
	double x = x2, y = y2;
	x += (x1 - x2) * hoge / bee;
	y += (y1 - y2) * hoge / bee;
	cout << x << " " << y << " " << hoge << endl;
	return 0;
}