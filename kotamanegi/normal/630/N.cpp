#define _CRT_SECURE_NO_WARNINGS
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
#include<map>
#include <list>
#include <typeinfo>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	double a, b, c;
	cin >> a >> b >> c;
	double hoge = b*b - 4 * a*c;
	cout.setf(ios::fixed);
	cout.precision(7);
	cout << max((-1 * b + sqrt(hoge)) / (2 * a), (-1 * b - sqrt(hoge)) / (2 * a)) << endl;
	cout << min((-1 * b + sqrt(hoge))/(2*a),(-1 * b - sqrt(hoge)) / (2 * a)) << endl;
}