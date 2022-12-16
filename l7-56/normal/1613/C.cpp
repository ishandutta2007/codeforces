#include <bits/stdc++.h>
typedef long long ll;
typedef double db;
using namespace std;

const int maxn = 110;
ll T,n,h,a[maxn];

bool check(ll k) {
	ll tot = 0, lst = -1;
	for(int i = 1; i <= n; ++i) {
		tot += min(a[i] - 1, lst) - a[i - 1] + 1;
		lst = a[i] + k - 1;
		if(tot >= h) return 1;
	}
	tot += k;
	return tot >= h;
}

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld%lld", &n, &h);
		for(int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
		ll l = 1, r = 1e18, mid, ans = 1e18;
		while(l <= r) {
			mid = (l + r) >> 1;
			if(check(mid)) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}