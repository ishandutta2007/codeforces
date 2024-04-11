#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>


typedef long long ll;
typedef long double ld;

using namespace std;

int n, t;
vector<int> vv[200];
int dp[20000];

int main() {
	cin >> n >> t;
	for (int i = 0; i < n; ++i) {
		int tt, cc;
		cin >> tt >> cc;
		tt = t - tt;
		vv[tt].push_back(cc);
	}
	for (int i = 0; i <= n; ++i)
		dp[i] = -1200000;
	dp[0] = 0;
	dp[1] = 0;
	for (int i = 0; i < t; ++i) {
	//	for (int i = 0; i <= n; ++i)
	//		cout << dp[i] << " ";
	//	cout << "\n";
		sort(vv[i].rbegin(), vv[i].rend());

		for (int j = 0; j <= n; ++j) {
			int sum = 0;
			for (int j1 = 0; j1 < j && j1 < (int)vv[i].size(); ++j1) {
				sum += vv[i][j1];
				dp[j - j1 - 1] = max(dp[j - j1 - 1], dp[j] + sum);
			}
		}

		for (int j = n; j >= 0; --j)
			dp[j] = dp[j - j / 2];
	}
	int mx = 0;
	for (int i = 0; i <= n; ++i)
		mx = max(mx, dp[i]);
	cout << mx;
	return 0;
}