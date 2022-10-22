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
	int a, b;
	scanf("%d%d", &a, &b);
	long long ans = 0;
	while (true) {
		if (a <= 1 && b <= 1) break;
		ans++;
		if (a > b) swap(a, b);
		a += 1;
		b -= 2;
		if (a == 0 || b == 0) break;
	}
	cout << ans << endl;
}
//thank you for reading my code!