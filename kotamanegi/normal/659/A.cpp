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
	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int ans = a;
	if (b >= 0) {
		for (int i = 0;i < b;++i) {
			ans++;
			if (ans == n + 1) ans = 1;
		}
		printf("%d\n", ans);
	}
	else {
		for (int i = 0;i < -1 * b;++i) {
			ans--;
			if (ans == 0) ans = n;
		}
		printf("%d\n",ans);
	}
}