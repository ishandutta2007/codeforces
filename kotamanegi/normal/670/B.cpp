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
long long hoge[1000000] = {};
int main() {
	int n, k;
	scanf("%d%d", &n, &k);
	long long now_hoge = 0;
	for (int i = 0;i < n;++i) {
		scanf("%I64d", &hoge[i]);
	}
	for (int i = 1;i <= n;++i) {
		if (now_hoge + i >= k) {
			k -= now_hoge;
			cout << hoge[k - 1] << endl;
			return 0;
		}
		now_hoge += i;
	}
	
}