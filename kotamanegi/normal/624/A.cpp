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
	double a, b, c, d;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	double wow = 1/((c + d) / c);
	double answer = (b * wow) - (wow*a);
	printf("%lf", answer/c);
}