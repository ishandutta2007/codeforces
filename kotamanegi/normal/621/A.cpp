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
	long long ans = 0;
	vector<long long> hoge;
	int n;
	scanf("%d", &n);
	int counter = 0;
	REP(i, n) {
		long long b = 0;
		scanf("%I64d", &b);
		if (b % 2 == 0) {
			ans += b;
		}
		else {
			counter++;
			hoge.push_back(b);
		}
	}
	sort(hoge.begin(), hoge.end(), greater<long long>());
	for (int i = 0;i < (counter / 2)*2;++i) {
		ans += hoge[i];
	}
	printf("%I64d", ans);
}
//thank you for reading my code!