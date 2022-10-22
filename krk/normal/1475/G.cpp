#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
int dp[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		fill(dp, dp + Maxn, 0);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		int res = 0;
		for (int i = n - 1; i >= 0; i--) {
			if (dp[a[i]] > 0) dp[a[i]]++;
			else for (int j = a[i]; j < Maxn; j += a[i])
					dp[a[i]] = max(dp[a[i]], dp[j] + 1);
			res = max(res, dp[a[i]]);
		}
		printf("%d\n", n - res);
	}
    return 0;
}