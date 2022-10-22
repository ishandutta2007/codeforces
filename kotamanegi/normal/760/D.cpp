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
#define LONG_INF 8000000000000000000
long long dp[200000] = {};
long long boom[200000][3] = {};
long long ans[200000] = {};
int main() {
#define int long long
	int n;
	cin >> n;
	vector<int> t;
	t.push_back(0);
	REP(i, n) {
		int tmp;
		cin >> tmp;
		t.push_back(tmp);
	}
	t.push_back(LONG_INF);
	for (int i = 0;i < 3;++i) {
		int ticker = 90;
		if (i == 1) ticker = 180;
		else if (i == 2) ticker = 1440;
		int now_look = 1;
		for (int q = 0;q < n;++q) {
			while (true) {
				if (t[now_look] - (t[q+1]-1) > ticker) break;
				now_look++;
			}
			boom[q][i] = now_look-1;
		}
	}
	for (int i = 0;i < 200000;++i) {
		dp[i] = LONG_INF;
	}
	dp[0] = 1;
	for (int i = 1;i <= n;++i) {
		if (dp[i - 1] != 0) {
			dp[i] = min(dp[i], dp[i - 1] + 20);//plan 1
			dp[boom[i-1][0]] = min(dp[boom[i-1][0]],dp[i - 1] + 50);//plan 2
			dp[boom[i - 1][2]] = min(dp[boom[i - 1][2]], dp[i - 1] + 120); // plan3
		}
	}
	long long hoge = dp[n+1];
	ans[n+1] = hoge;
	for (int i = n;i >= 0;--i) {
		hoge = min(hoge, dp[i]);
		ans[i] = hoge;
	}
	for (int i = 1;i <= n;++i) {
		cout << ans[i] - ans[i - 1] << endl;
	}
	return 0;
}