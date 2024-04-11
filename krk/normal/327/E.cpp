#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 24;
const int mod = 1000000007;

int n;
int a[Maxn];
int k;
int num[2];
int ind[1 << Maxn];
ll sum[1 << Maxn];
ll dp[1 << Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	scanf("%d", &k);
	for (int i = 0; i < k; i++) scanf("%d", &num[i]);
	for (int i = 0; i < n; i++) ind[1 << i] = i;
	dp[0] = 1;
	for (int i = 1; i < 1 << n; i++) {
		int b = i & -i;
		sum[i] = sum[i ^ b] + ll(a[ind[b]]);
		int l;
		for (l = 0; l < k; l++) if (sum[i] == num[l]) break;
		if (l < k) continue;
		for (int j = 0; j < n; j++)
			if (i & 1 << j) dp[i] += dp[i ^ 1 << j];
		dp[i] %= mod;
	}
	printf("%d\n", dp[(1 << n) - 1]);
	return 0;
}