#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
ll sum[Maxn];
ll dp[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); sum[i] = sum[i - 1] + a[i];
	}
	dp[n] = sum[n];
	for (int i = n - 1; i > 1; i--)
		dp[i] = max(dp[i + 1], sum[i] - dp[i + 1]);
	printf("%I64d\n", dp[2]);
	return 0;
}