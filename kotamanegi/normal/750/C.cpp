#define  _CRT_SECURE_NO_WARNINGS
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
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONG_INF 100000000000000
int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> c;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		c.push_back(make_pair(b, a));
	}
	long long now = 0,ans = 0;
	long long max_div1 = -LONG_INF, max_div2 = -LONG_INF, min_div1 = LONG_INF, min_div2 = LONG_INF;
	for (int i = 0;i < n;++i) {
		if (c[i].first == 1) {
			max_div1 = max(max_div1, now);
			min_div1 = min(min_div1, now);
		}else{
			max_div2 = max(max_div2, now);
			min_div2 = max(min_div2, now);
		}
		now += c[i].second;
	}
	if (min_div1 <= max_div2) {
		cout << "Impossible" << endl;
		return 0;
	}
	if (max_div2 == -LONG_INF) {
		cout << "Infinity" << endl;
		return 0;
	}
	if (c[0].first == 2) {
		ans = 1899 - max_div2 + now;
	}else{
		ans = 1899 - max_div2 + now;
	}
	cout << ans << endl;
	return 0;
}