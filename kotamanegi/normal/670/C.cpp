#define _CRT_SECURE_NO_WARNINGS
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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cstdint>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
map<int, int> a;
pair<int, int> b[300000] = {};
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) {
		int aa;
		scanf("%d", &aa);
		a[aa]++;
	}
	int m;
	scanf("%d", &m);
	REP(i, m) {
		scanf("%d", &b[i].first);
	}
	REP(i, m) {
		scanf("%d", &b[i].second);
	}
	int ans_now = -1;
	for (int i = 0;i < m;++i) {
		if (ans_now < a[b[i].first]) {
			ans_now = a[b[i].first];
		}
	}
	int final_ans = -1;
	int ans_nowmax = -1;
	for (int i = 0; i < m;++i) {
		if (ans_now == a[b[i].first]) {
			if (ans_nowmax < a[b[i].second]) {
				ans_nowmax = a[b[i].second];
				final_ans = i + 1;
			}
		}
	}
	cout << final_ans << endl;
}