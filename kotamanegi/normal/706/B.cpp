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
#include <iomanip>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
int main() {
	int n;
	vector<int> x;
	scanf("%d", &n);
	REP(i, n) {
		int a;
		scanf("%d", &a);
		x.push_back(a);
	}
	sort(x.begin(), x.end());
	int q;
	scanf("%d", &q);
	auto hogehoge = x.begin();
	REP(i, q) {
		int hoge;
		scanf("%d", &hoge);
		auto it = lower_bound(x.begin(), x.end(), hoge + 1);
		cout << it - hogehoge << endl;
	}
}