#include <bits/stdc++.h>

using ll = long long;

void solve() {
	ll n;scanf("%lld",&n);
	ll now = 2050;
	int sum = 0;
	while (now < n) now *= 10;
	while (n && (now >= 2050)) {
		while (n >= now) { n -= now; sum ++; }
		now /= 10;
	} 
	if (!n) printf("%d\n",sum);
	else puts("-1");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}