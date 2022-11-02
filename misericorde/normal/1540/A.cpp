#include <bits/stdc++.h>

using ll = long long;
const int maxn = 2e5 + 222;

int n;
ll b[maxn],ans;

void solve() {
	scanf("%d",&n);
	for (int i = 1; i <= n; ++ i)
		scanf("%lld",&b[i]);
	std::sort(b + 1,b + n + 1);
	ll ans = b[n];
	ll sum = 0;
	for (int i = 1; i <= n; ++ i) {
		ans -= b[i] * (i - 1) - sum;
		sum += b[i];
	} printf("%lld\n",ans);
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}