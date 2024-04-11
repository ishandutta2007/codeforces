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
map<int, int> hoge;
int main() {
	//ios::sync_with_stdio(false);
	int n, m;
	scanf("%d%d", &n, &m);
	REP(i, n) {
		int a;
		scanf("%d", &a);
		hoge[a]++;
	}
	int ans_num = 0;
	vector<int> ans;
	int now = 0;
	while (m >= 0) {
		now++;
		if (hoge[now] == 0) {
			ans.push_back(now);
			ans_num++;
			m -= now;
		}
	}
	ans_num--;
	printf("%d\n", ans_num);
	for (int i = 0;i < ans_num;++i) {
		if (i != 0) {
			printf(" ");
		}
		printf("%d", ans[i]);
	}
	printf("\n");
	return 0;
}