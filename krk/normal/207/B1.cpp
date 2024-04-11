#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 305;
const int Inf = 1000000000;

int n;
int a[Maxn];
int dp[Maxn];
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		fill(dp, dp + n, Inf); dp[0] = 0;
		for (int j = 0; j < n; j++)
			for (int k = j + 1; k < n; k++) if (j >= k - a[(i + k) % n])
				dp[k] = min(dp[k], dp[j] + 1);
		res += dp[n - 1];
	}
	printf("%I64d\n", res);
	return 0;
}