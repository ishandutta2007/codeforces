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
int dp[100][16] = {};
int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0;i < 100;++i) {
		for (int q = 0;q < 16;++q) {
			dp[i][q] = 10000000;
		}
	}
	dp[0][0] = 0;
	for (int i = 0;i < n;++i) {
		string s;
		cin >> s;
		int shorter[4] = {10000,10000,10000,10000};
		for (int q = 0;q < m;++q) {
			if (s[q] >= '0' && s[q] <= '9') {
				shorter[1] = min(min(q, m - q),shorter[1]);
			}else if(s[q] >= 'a' && s[q] <= 'z'){
				shorter[2] = min(shorter[2], min(q, m - q));
			}
			else {
				shorter[3] = min(shorter[3], min(q, m - q));
			}
		}
		for (int q = 1;q <= 3;++q) {
			for (int j = 0;j <= 7;++j) {
				int hoge = (1 << (q - 1));
				dp[i + 1][hoge | j] = min(dp[i + 1][hoge | j], dp[i][j] + shorter[q]);
			}
		}
	}
	cout << dp[n][7] << endl;
	return 0;
}