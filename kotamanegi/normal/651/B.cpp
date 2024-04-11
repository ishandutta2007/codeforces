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
int beauty[2000] = {};
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) {
		int a = 0;
		scanf("%d", &a);
		beauty[a]++;
	}
	long long ans = 0;
	for (int i = 0;i < 10000;++i) {
		bool hoge = false;
		for (int q = 0;q < 2000;++q) {
			if (beauty[q] > 0) {
				beauty[q]--;
				if (hoge == false) {
					hoge = true;
				}
				else {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}
//thank you for reading my code!