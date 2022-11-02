#include <bits/stdc++.h>

using ll = long long;
const int maxn = 1e6 + 222;
int n,a[maxn],rk[maxn];

void solve() {
	ll ans = 0;
	scanf("%d",&n);
	a[0] = a[n + 1] = 0;
	for (int i = 1; i <= n; ++ i) {
		scanf("%d",&a[i]);
		rk[i] = i;
	} std::sort(rk + 1, rk + n + 1,[](int x,int y) { return a[x] > a[y]; });
	for (int i = 1; i <= n; ++ i) {
		int z = rk[i];
		int h = std::max(a[z - 1],a[z + 1]);
		ans += std::max(0,a[z] - h);
		a[z] = std::min(a[z],h);
	} for (int i = 1; i <= n; ++ i) 
		ans += std::max(0,a[i] - a[i - 1]) + std::max(0,a[i] - a[i + 1]);
	printf("%lld\n",ans);
}
	

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}