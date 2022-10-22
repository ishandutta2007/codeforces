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
	long long n;
	cin >> n;
	long long hoge[1000] = {};
	hoge[0] = 2;
	long long ans = 0;
	REP(i, n) {
		ans += hoge[i];
		hoge[i + 1] = hoge[i] * 2;
	}
	cout << ans  << endl;
}