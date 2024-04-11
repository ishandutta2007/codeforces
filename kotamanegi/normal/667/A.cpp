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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cstdint>
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
using namespace std;
int main() {
	double a, b, c, d;
	cin >> a >> b >> c >> d;
	a /= 2;
	double menseki = a*a*(3.1415926535);
	double hogee = c - (d*menseki);
	if (hogee < 0.0) {
		cout << "NO" << endl;
	}
	else {
		cout << "YES" << endl;
		printf("%lf", b*menseki / hogee);
	}
}