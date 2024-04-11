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
#define LONG_INF 800000000000000000
tuple<long long, long long, long long> dp[2000];
long long appear[3000] = {};
int main() {
#define int long long
	//It's a magic!
	int n;
	string a;
	cin >> n >> a;
	REP(i, 26) {
		cin >> appear[i];
	}
	REP(i,2000) {
		dp[i] = make_tuple(0, -1,LONG_INF);
	}
	get<0>(dp[0]) = 1;
	get<2>(dp[0]) = 0;
	for (int i = 0;i < n;++i) {
		if (get<0>(dp[0]) != -1) {
			long long minimum_fail = LONG_INF;
			for (int q = 0;i + q < n;++q) {
				minimum_fail = min(minimum_fail, appear[a[i + q] - 'a']);
				if (minimum_fail <= q) break;
				get<0>(dp[i + q + 1]) += get<0>(dp[i]);
				get<0>(dp[i + q + 1]) %= MAX_MOD;
				get<1>(dp[i + q + 1]) = max(get<1>(dp[i + q + 1]), max(get<1>(dp[i]),q + 1));
				get<2>(dp[i + q + 1]) = min(get<2>(dp[i + q + 1]),get<2>(dp[i]) + 1);
			}
		}
	}
	cout << get<0>(dp[n]) << endl;
	cout << get<1>(dp[n]) << endl;
	cout << get<2>(dp[n]) << endl;
	return 0;
}