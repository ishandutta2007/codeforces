#include<bits/stdc++.h>
typedef long long ll;
typedef long double ld;
typedef double db;
using namespace std;

ll T,n;
ll query(ll l, ll r) {
	printf("? %lld %lld\n", l, r);
	fflush(stdout);
	ll x;
	scanf("%lld", &x);
	if(x == -1) exit(0);
	return x;
}

void print(ll i, ll j, ll k) {
	printf("! %lld %lld %lld\n", i, j, k);
	fflush(stdout);
}

int main() {
	scanf("%lld", &T);
	while(T--) {
		scanf("%lld", &n);
		ll i, j, k, all = query(1, n);
		ll l = 1, r = n, mid;
		while(l <= r) {
			mid = (l + r) >> 1;
			if(query(mid, n) == all) i = mid, l = mid + 1;
			else r = mid - 1;
		}
		ll x = all - query(i + 1, n) + 1;
		j = i + x;
		ll y = query(j, n) - query(j + 1, n) + 1;
		k = j + y - 1;
		print(i, j, k);
	}
	return 0;
}