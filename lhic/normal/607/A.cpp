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
typedef double ld;

using namespace std;

int n;
pair<int, int> arr[300000];
int dp[300000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &arr[i].first, &arr[i].second);
	sort(arr, arr + n);
	dp[0] = 0;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		int x = arr[i].first - arr[i].second;
		int xx = lower_bound(arr, arr + n, make_pair(x, 0)) - arr;
		dp[i + 1] = 1 + dp[xx];
		ans = max(ans, dp[i + 1]);
	}
	cout << n - ans << "\n";

	return 0;
}