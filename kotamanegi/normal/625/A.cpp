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
	long long n, a, b, c;
	cin >> n >> a >> b >> c;
	long long hoge = b - c;
	long long ans = 0;
	if (hoge < a&&n >= b) {
		ans += (n - b) / hoge;
		if (ans < 0) ans = 0;
		n -= (ans*hoge);
		ans += max((n-b+c)/a+1, n / a);
	}
	else {
		ans = n / a;
		n -= ans*a;
		ans += n / b;
	}
	cout << ans;
	return 0;
}