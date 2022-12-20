#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

ll calc(ll n) {
	ll a = n / 3 + (n % 3 > 0), b = n / 3 + (n % 3 > 1), c = n / 3;
	return (a * b + a * c + b * c) * 2;
}

void work() {
	ll n; scanf("%lld", &n);
	ll l = 2, r = 1e9, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (calc(mid) >= n) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	printf("%lld\n", ans);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}