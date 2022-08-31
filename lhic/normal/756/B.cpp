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

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long double ld;

using namespace std;

int n;
int t[120000];
int dp[120000];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", t + i);
	dp[0] = 0;
	int now90 = 0;
	int now1440 = 0;
	for (int i = 0; i < n; ++i) {
		dp[i + 1] = dp[i] + 20;
		while (t[i] - t[now90] >= 90)
			++now90;
		while (t[i] - t[now1440] >= 1440)
			++now1440;
		dp[i + 1] = min(dp[i + 1], dp[now90] + 50);
		dp[i + 1] = min(dp[i + 1], dp[now1440] + 120);
		printf("%d\n", dp[i + 1] - dp[i]);
	}
	return 0;
}