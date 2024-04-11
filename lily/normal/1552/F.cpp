#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 5;
const int MOD = 998244353;

int n;
int X[N], Y[N], S[N];
LL sum [N], cur[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", X + i, Y + i, S + i);
	}
	LL ans  = (X[n] + 1) % MOD;
	for (int i = 1; i <= n; i++) {
		int p = int(lower_bound(X + 1, X + n + 1, Y[i]) - X);
		cur[i] = (X[i] - Y[i] + sum[i - 1] - sum[p - 1]) % MOD;
		sum[i] = (sum[i - 1] + cur[i]) % MOD;
		if (S[i] == 1) (ans += cur[i]) %= MOD;
	}
	printf("%lld\n", (ans % MOD + MOD) % MOD);
}