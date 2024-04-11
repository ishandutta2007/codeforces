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
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(int i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int ans[200000] = {};
int main() {
	int n;
	cin >> n;
	vector<int> a;
	REP(i, n) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	int wa = 0;
	for (int i = n - 1;i >= 0;--i) {
		ans[i] = a[i] - wa;
		wa += ans[i];
		wa *= -1;
	}
	REP(i, n) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}