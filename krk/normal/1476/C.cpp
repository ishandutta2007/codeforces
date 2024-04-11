#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;
const ll Inf = 1000000000000000000ll;

int T;
int n;
int c[Maxn];
int a[Maxn];
int b[Maxn];
ll dp[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &c[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		for (int i = 1; i <= n; i++)
			scanf("%d", &b[i]);
		ll res = 0;
		dp[1] = -Inf;
		for (int i = 2; i <= n; i++) {
			dp[i] = 2 + abs(a[i] - b[i]);
			if (a[i] != b[i])
				dp[i] = max(dp[i], 1ll + ll(min(a[i], b[i])) + ll(c[i - 1]) - ll(max(a[i], b[i])) + dp[i - 1]);
			res = max(res, dp[i] + c[i] - 1ll);
		}
		printf("%I64d\n", res);
	}
    return 0;
}