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
int main() {
	int n;
	scanf("%d", &n);
	int hoge[10000] = {};
	REP(i, n) {
		scanf("%d", &hoge[i]);
	}
	long long ans = 1;
	int count = 0;
	bool hogehoge = false;
	for (int i = 0;i < n;++i) {
		if (hogehoge == false) {
			if (hoge[i] == 1) {
				hogehoge = true;
			}
		}
		else {
			count++;
			if (hoge[i] == 1) {
				ans = ans * count;
				count = 0;
			}
		}
	}
	if (hogehoge == true) {
		printf("%I64d\n", ans);
	}
	else {
		printf("0\n");
	}
}
//thank you for reading my code!