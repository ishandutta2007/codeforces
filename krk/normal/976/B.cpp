#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m, k;

int main()
{
	cin >> n >> m >> k;
	if (k < n) { printf("%lld 1\n", k + 1); return 0; }
	k -= n;
	ll dv = k / (2 * (m - 1));
	ll r = n - 2 * dv;
	k -= 2ll * (m - 1) * dv;
	if (k < m - 1) { printf("%lld %lld\n", r, 2 + k); return 0; }
	k -= (m - 1);
	r--;
	printf("%lld %lld\n", r, m - k);
	return 0;
}