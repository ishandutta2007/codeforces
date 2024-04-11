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
#define LONG_INF 10000000000000000
long long a[300000] = {};
vector<int> tree[300000];
long long tree_sum[300000] = {};
long long ans = -LONG_INF;
long long calculate(int now_here,int back) {
	long long ans = a[now_here];
	for (int i = 0;i < tree[now_here].size();++i) {
		if (tree[now_here][i] != back) {
			ans += calculate(tree[now_here][i], now_here);
		}
	}
	tree_sum[now_here] = ans;
	return ans;
}
long long dp(int now_here, int back) {
	long long maxer = -LONG_INF;
	long long second_maxer = -LONG_INF;
	for (int i = 0;i < tree[now_here].size();++i) {
		if (tree[now_here][i] != back) {
			long long hoge = dp(tree[now_here][i], now_here);
			if (hoge > maxer) {
				second_maxer = maxer;
				maxer = hoge;
				if (second_maxer != -LONG_INF) {
					ans = max(ans, second_maxer + maxer);
				}
			}
			else if (hoge > second_maxer) {
				second_maxer = hoge;
				if (maxer != -LONG_INF) {
					ans = max(ans, second_maxer + maxer);
				}
			}
		}
	}
	return max(maxer,tree_sum[now_here]);
}
int main() {
	long long n;
	cin >> n;
	REP(i, n) {
		cin >> a[i + 1];
	}
	REP(i, n - 1) {
		int c, d;
		cin >> c >> d;
		tree[c].push_back(d);
		tree[d].push_back(c);
	}
	calculate(1,0);
	//sum is calculated
	dp(1, 0);
	if (ans == -LONG_INF) {
		cout << "Impossible" << endl;
		return 0;
	}
	if (ans != -LONG_INF) {
		cout << ans << endl;
	}
	else cout << "-1" << endl;
	return 0;
}