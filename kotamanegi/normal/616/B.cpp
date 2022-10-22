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
using namespace std;
#define REP(a,b) for(int a = 0;a < b;++a)
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	int street = 0;
	for (int i = 0;i < n;++i) {
		int hoge = 1000000001;
		for (int q = 0;q < m;++q) {
			int hogehoge;
			scanf("%d", &hogehoge);
			if (hogehoge < hoge) {
				hoge = hogehoge;
			}
		}
		street = max(hoge, street);
	}
	printf("%d", street);

}