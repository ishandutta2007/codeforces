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
int dp[200][10] = {};
int main(){
	int n;
	cin >> n;
	vector<int> a;
	a.push_back('0');
	REP(i, n) {
		int b;
		cin >> b;
		a.push_back(b);
	}
	dp[0][1] = 999999;
	dp[0][2] = 999999;
	for (int i = 1;i <= n;++i) {
		//dp[i-1][0]
		dp[i][0] = min(dp[i - 1][0]+1, min(dp[i - 1][1]+1, dp[i - 1][2]+1));
		if (a[i] == 2 || a[i] == 3) {
			dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
		}
		else {
			dp[i][1] = 999999;
		}
		if(a[i] == 1 || a[i] == 3) {
			dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
		}
		else {
			dp[i][2] = 9999999;
		}
	}
	int ans = min(dp[n][0], min(dp[n][1], dp[n][2]));
	cout << ans << endl;
	return 0;
}