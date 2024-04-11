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

int n, k;
int dp[1000010];
vector<int> vv;

int main() {
	cin >> n >> k;
	int mn = 10000;
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		mn = min(mn, a);
		vv.push_back(a);
	}
	for (int i = 0; i < (int)vv.size(); ++i)
		vv[i] -= mn;
	sort(vv.begin(), vv.end());
	vv.resize(unique(vv.begin(), vv.end()) - vv.begin());
	int mx = k * vv.back();
	for (int j = 0; j <= mx; ++j)
		dp[j] = k + 1;
	dp[0] = 0;
	for (int i = 0; i < (int)vv.size(); ++i) {
		int x = vv[i];
		if (x == 0)
			continue;
		for (int j = 0; j <= mx - x; ++j)
			dp[j + x] = min(dp[j + x], dp[j] + 1);
	}
	for (int i = 0; i <= mx; ++i)
		if (dp[i] <= k)
			printf("%d ", mn * k + i);
	return 0;
}