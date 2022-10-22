#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxm = 10005;
const int Maxn = 5005;
const int mod = 1000000007;

int n;
int a[Maxn];
int has[Maxn];
int dp[Maxm], ndp[Maxm];
int res[Maxm];

int main()
{
	scanf("%d", &n);
	has[1] = 1;
	for (int i = 1; i < n; i++) {
		scanf("%d", &a[i]);
		has[i + 1] = ll(has[i]) * a[i] % mod;
	}
	for (int i = 1; i <= n; i++) {
		int cur = has[i];
		for (int j = i + 1; j <= n; j++) {
			cur = ll(cur) * a[j - 1] % mod;
			res[j - i] = (res[j - i] + cur) % mod;
		}
	}
	for (int i = n - 1; i > 0; i--) {
		fill(ndp, ndp + Maxm, 0);
		int my = 1;
		for (int j = 1; i + j <= n; j++) {
			ndp[1 + j] = (ndp[1 + j] + (j == 1? 1: 2) * my) % mod;
			my = ll(my) * a[i + j] % mod;
		}
		int mult = ll(a[i]) * (a[i] - 1) / 2 % mod * has[i] % mod;
		for (int j = 0; j < Maxm; j++) {
			if (dp[j] != 0)
				ndp[j + 2] = (ndp[j + 2] + ll(dp[j]) * a[i + 1] % mod * a[i + 1]) % mod;
			res[j] = (res[j] + ll(mult) * ndp[j]) % mod;
			dp[j] = ndp[j];
		}
	}
	for (int i = 1; i <= 2 * n - 2; i++)
		printf("%d%c", res[i], i + 1 <= 2 * n - 2? ' ': '\n');
	return 0;
}