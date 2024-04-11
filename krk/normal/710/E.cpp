#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair <ll, int> lli;

const int Maxn = 20000005;
const int Maxb = 25;
const ll Inf = 1000000000000000000ll;

int n, x, y;
ll dp[Maxn];

int main()
{
	scanf("%d %d %d", &n, &x, &y);
	dp[1] = x;
	for (int i = 0; i + 1 < Maxb; i++) {
		int a = (1 << i), b = (1 << (i + 1));
		for (int j = a + 1; j <= b; j++)
			dp[j] = j % 2? Inf: dp[j / 2] + y;
		for (int j = a + 1; j <= b; j++)
			dp[j] = min(dp[j], dp[j - 1] + x);
		for (int j = b - 1; j > a; j--)
			dp[j] = min(dp[j], dp[j + 1] + x);
	}
	printf("%I64d\n", dp[n]);
	return 0;
}