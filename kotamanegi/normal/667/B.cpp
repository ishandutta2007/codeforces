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
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cstdint>
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
using namespace std;
int l[200000] = {};
int main() {
	int n;
	scanf("%d", &n);
	REP(i, n) scanf("%d", &l[i]);
	long long max_sa = 99999999;
	long long left = 0;
	long long right = 0;
	sort(l, l + n, greater<int>());
	for (int i = 0;i < n;++i) {
		left += l[i];
	}
	max_sa = left;
	for (int i = 0;i < n;++i) {
		right += l[i];
		left -= l[i];
		max_sa = min(max_sa, abs(left - right));
		if (left < right) break;
	}
	max_sa = min(max_sa, abs(left - right));
	cout << max_sa + 1 << endl;
}