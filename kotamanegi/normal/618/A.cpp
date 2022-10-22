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
	int v;
	scanf("%d", &v);
	int answer[200000] = {};
	REP(i, v) {
		answer[i] = 1;
	}
	bool hoge = true;
	int look_size = v;
	while (hoge == true) {
		hoge = false;
		int cnt = 0;
		for (int i = 0;i < look_size-1;++i) {
			if (answer[i] == answer[i + 1]) {
				cnt++;
				hoge = true;
				answer[i]++;
				answer[i + 1] = 0;
			}
		}
		look_size -= cnt;
		sort(answer, answer + v, greater<int>());
	}
	printf("%d", answer[0]);
	for (int i = 1;i < look_size;++i) {
		printf(" %d", answer[i]);
	}
	printf(" ");
}
//thank you for reading my code!