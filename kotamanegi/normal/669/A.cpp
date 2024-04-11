#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define  _SCL_SECURE_NO_WARNINGS
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
#include <list>
#include <set>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	int n;
	cin >> n;
	int ans = (n / 3)*2;
	n %= 3;
	if (n == 1 || n == 2) {
		ans++;
	}
	cout << ans << endl;
}