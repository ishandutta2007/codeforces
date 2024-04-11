#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 3005;

int n;
int a[Maxn], b[Maxn], c[Maxn];
int dp[Maxn][2];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	dp[n - 1][0] = a[n - 1]; dp[n - 1][1] = b[n - 1];
	for (int i = n - 2; i >= 0; i--) {
		dp[i][0] = max(a[i] + dp[i + 1][1], b[i] + dp[i + 1][0]);
		dp[i][1] = max(b[i] + dp[i + 1][1], c[i] + dp[i + 1][0]);
	}
	printf("%d\n", dp[0][0]);
	return 0;
}