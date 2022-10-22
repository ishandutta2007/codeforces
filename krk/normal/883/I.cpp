#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 300005;

int n, k;
int v[Maxn];
int dp[Maxn];

bool Check(int add)
{
	fill(dp, dp + n + 1, 0);
	dp[0]++; dp[1]--;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		cur += dp[i];
		if (cur > 0) {
			int lef = i + k;
			int rig = upper_bound(v, v + n, v[i] + add) - v + 1;
			if (lef < rig) { dp[lef]++; dp[rig]--; }
		}
	}
	cur += dp[n];
	return cur > 0;
}

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &v[i]);
	sort(v, v + n);
	int lef = 0, rig = 1000000007;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Check(mid)) rig = mid - 1;
		else lef = mid + 1;
	}
	printf("%d\n", rig + 1);
	return 0;
}