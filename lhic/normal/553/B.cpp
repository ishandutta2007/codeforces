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

int n;
ll k;

int ans[100];
ll dp[100];
const ll INF = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 1000ll + 200ll;

int main() {
	cin >> n >> k;
	dp[0] = 1;
	dp[1] = 1;
	for (int i = 2; i < 52; ++i) {
		dp[i] = min(INF, dp[i - 1] + dp[i - 2]);
	}
	for (int i = 0; i < n; ++i) {
		if (ans[i])
			continue;
		int xx = n - i;
		if (dp[xx - 1] >= k)
			ans[i] = i + 1;
		else {
			ans[i] = i + 2;
			ans[i + 1] = i + 1;
			k -= dp[xx - 1];
		}
	}
	for (int i = 0; i < n; ++i)
		cout << ans[i] << " ";
	return 0;
}