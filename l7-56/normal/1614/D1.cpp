#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 1e5 + 10, maxa = 5e6 + 10;
ll a[maxn],c[maxa],dp[maxa],n,mxa;

int main() {
	scanf("%lld", &n);
	for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]), c[a[i]]++, mxa = max(mxa, a[i]);
	for(int i = 1; i <= mxa; ++i)
		for(int j = 2; i * j <= mxa; ++j)
			c[i] += c[i * j];
	for(int i = mxa; i; --i) {
		dp[i] = c[i] * i;
		for(int j = 2; i * j <= mxa; ++j) dp[i] = max(dp[i], dp[i * j] + (c[i] - c[i * j]) * i);
	}
	printf("%lld\n", dp[1]);
	return 0;
}