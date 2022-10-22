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
int graph[1000][1000] = {};
int main() {
	int n,k;
	scanf("%d%d", &n, &k);
	int hogehoge = n*n;
	for (int i = n - 1;i >= 0;--i) {
		for (int q = n - 1;q >= k -1;--q) {
			graph[i][q] = hogehoge;
			hogehoge--;
		}
	}
	for (int i = n-1;i >= 0;--i) {
		for (int q = k - 2;q >= 0;--q) {
			graph[i][q] = hogehoge;
			hogehoge--;
		}
	}
	long long ans = 0;
	for (int i = 0;i < n;++i) {
		ans += graph[i][k - 1];
	}
	printf("%d\n", ans);
	for (int i = 0;i < n;++i) {
		printf("%d", graph[i][0]);
		for (int q = 1;q < n;++q) {
				printf(" %d", graph[i][q]);
		}
		if(i != n-1)printf("\n");
	}
}