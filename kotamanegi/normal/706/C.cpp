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
long long dp[200000][2] = {};
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	vector<int> hogee;
	REP(i, n) {
		int a;
		cin >> a;
		hogee.push_back(a);
	}
	for (int i = 0;i < 200000;++i) {
		dp[i][1] = 9999999999999999;
		dp[i][0] = 9999999999999999;
	}
	vector<string> listing;
	vector<string> riv_listing;
	REP(i, n) {
		string rever;
		cin >> rever;
		string hoge = rever;
		reverse(rever.begin(), rever.end());
		listing.push_back(hoge);
		riv_listing.push_back(rever);
		if (i == 0) {
			dp[i][0] = 0;
			dp[i][1] = hogee[i];
		}
		else 
		{
			if (riv_listing[i - 1] <= listing[i]&&dp[i-1][1] != 9999999999999999) {
				dp[i][0] = min(dp[i - 1][1], dp[i][0]);
			}
			if (riv_listing[i - 1] <= riv_listing[i]&&dp[i-1][1] != 9999999999999999) {
				dp[i][1] = min(dp[i - 1][1] + hogee[i], dp[i][1]);
			}
			if (listing[i - 1] <= listing[i]&&dp[i-1][0] != 9999999999999999) {
				dp[i][0] = min(dp[i - 1][0], dp[i][0]);
			}
			if (listing[i - 1] <= riv_listing[i]&&dp[i-1][0] != 9999999999999999) {
				dp[i][1] = min(dp[i - 1][0]+hogee[i], dp[i][1]);
			}
		}
	}
	long long ans = min(dp[n - 1][0], dp[n - 1][1]);
	if (ans != 9999999999999999) {
		cout << ans << endl;
	}
	else {
		cout << "-1" << endl;
	}
}