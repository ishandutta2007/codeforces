#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <algorithm>
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
#define REP(a,b) for(int a = 0;a < b;++a)
int dp[1000000] = {0};
int setting(int b) {
	dp[0] = 6;dp[1] = 2;dp[2] = 5;dp[3] = 5;dp[4] = 4;dp[5] = 5;dp[6] = 6;dp[7] = 3;dp[8] = 7;dp[9] = 6;
	for (int i = 10;i <= b;++i) {
		dp[i] = dp[i % 10] + dp[i / 10];
	}
	return 0;
}
int main() {
	int a, b;
	scanf("%d%d",&a,&b);
	setting(b);
	int num = 0;
	for (int i = a;i <= b;++i) {
		num += dp[i];
	}
	printf("%d", num);
}