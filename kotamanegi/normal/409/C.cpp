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
#include <list>
#include <set>
using namespace std;
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	int a[5];
	REP(i, 5) scanf("%d", &a[i]);
	int ans = 0;
	while (a[0] >= 0 && a[1] >= 0 && a[2] >= 0 && a[3] >= 0 && a[4] >= 0) {
		ans++;
		a[0] -= 1;
		a[1] -= 1;
		a[2] -= 2;
		a[3] -= 7;
		a[4] -= 4;
	}
	cout << ans - 1 << endl;
}