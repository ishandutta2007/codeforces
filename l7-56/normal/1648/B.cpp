#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e6 + 10;
ll n,c,a[maxn],sum[maxn];
void work() {
	scanf("%lld%lld", &n, &c);
	for (ll i = 0; i <= c; ++i) sum[i] = 0;
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]), sum[a[i]] = 1;
	sort(a + 1, a + n + 1);
	n = unique(a + 1, a + n + 1) - a - 1;
	for (ll i = 1; i <= c; ++i) sum[i] += sum[i - 1];
	ll cnt = 0;
	for (ll j = 1; j <= c; ++j) {
		if (sum[j] - sum[j - 1] == 0) continue;
		for (ll i = 1; i * j <= c; ++i)
			if (sum[i] - sum[i - 1] > 0) cnt += sum[min((i + 1) * j - 1, c)] - sum[i * j - 1];
	}
	if (cnt == (n + 1) * n / 2) printf("Yes\n");
	else printf("No\n");
}

int main() {
	ll t; scanf("%lld", &t);
	while (t--) work();
	return 0;
}