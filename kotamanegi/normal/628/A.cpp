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
	int n, b, p;
	cin >> n >> b >> p;
	int cloth = n*p;
	int water = 0;
	int water_set = 2 * b+1;
	while (n != 1) {
		int hoge = n / 2;
		n -= hoge;
		water += water_set*hoge;
	}
	cout << water << " " << cloth << endl;
}