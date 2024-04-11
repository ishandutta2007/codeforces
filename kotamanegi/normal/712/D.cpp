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
long long dp[2][110][240000] = {};
int main() {
	int a, b, k, t;
	cin >> a >> b >> k >> t;
	dp[0][0][110000 + a] = 1;
	dp[1][0][110000 + b] = 1;
	for (int i = 1;i <= t;++i) {
		long long tmp[2] = {};
		for (int q = 0;q < 230000;++q) {
			tmp[0] += dp[0][i-1][q+k];
			tmp[1] += dp[1][i-1][q + k];
			dp[0][i][q] += tmp[0];
			dp[1][i][q] += tmp[1];
			dp[0][i][q] %= MAX_MOD;
			dp[1][i][q] %= MAX_MOD;
			if (q-k >= 0) {
				tmp[0] -= dp[0][i-1][q - k];
				tmp[1] -= dp[1][i-1][q - k];
			}
		}
	}
	long long ans = 0;
	long long tmp = 0;
	for (int i = 0;i < 230000;++i) {
		tmp += dp[0][t][i];
		tmp %= MAX_MOD;
	}
	for (int i = 0;i < 230000;++i) {
		ans += dp[1][t][i] * tmp;
		ans %= MAX_MOD;
		tmp -= dp[0][t][i+1] - MAX_MOD;
		tmp %= MAX_MOD;
	}
	cout << ans << endl;
	return 0;
}