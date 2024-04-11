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
bool found[10000][10000] = {};
long long calculating(int a) {
	return a*(a - 1) / 2;
}
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) {
		int x = 0, y = 0;
		scanf("%d%d",&x,&y );
		found[x][y] = true;
	}
	long long ans = 0;
	for (int i = 1;i <= 3000;++i) {
		int counter = 0;
		for (int q = 1;q < 3000;++q) {
			if (i - q + 1 > 0) {
				if (found[q][i - q + 1] == true) {
					counter++;
				}
			}
		}
		ans += calculating(counter);
	}
	for (int i = 1;i <= 1000;++i) {
		int counter = 0;
		for (int q = 1;q <= 1000;++q) {
			if (found[q][i + q-1] == true) {
				counter++;
			}
		}
		ans += calculating(counter);
	}
	for (int i = 2;i <= 1000;++i) {
		int counter = 0;
		for (int q = 1;q <= 1000;++q) {
			if (found[i + q - 1][q] == true) {
				counter++;
			}
		}
		ans += calculating(counter);
	}
	printf("%d", ans);
}
//thank you for reading my code!