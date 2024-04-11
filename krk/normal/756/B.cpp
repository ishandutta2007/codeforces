#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int t[Maxn], dp[Maxn];

int main() 
{
	scanf("%d", &n);
	t[0] = -1000000000;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &t[i]);
		dp[i] = dp[i - 1] + 20;
		int ind = upper_bound(t, t + i, t[i] - 90) - t - 1;
		dp[i] = min(dp[i], dp[ind] + 50);
		ind = upper_bound(t, t + i, t[i] - 1440) - t - 1;
		dp[i] = min(dp[i], dp[ind] + 120);
		printf("%d\n", dp[i] - dp[i - 1]);
	}
    return 0;
}