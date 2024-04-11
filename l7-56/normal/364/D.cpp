#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 1e6 + 10;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll n,a[maxn],d[8010],cnt[8010],tot,ans;
void calc(ll x) {
	tot = 0;
	for (ll i = 1; i * i <= x; ++i)
		if (x % i == 0) {
			d[++tot] = i;
			if (x != i * i) d[++tot] = x / i;
		}
	sort(d + 1, d + tot + 1);
	for (ll i = 1; i <= tot; ++i) cnt[i] = 0;
	for (ll i = 1; i <= n; ++i) {
		ll pos = lower_bound(d + 1, d + tot + 1, gcd(a[i], x)) - d;
		cnt[pos]++;
	}
	for (ll i = 1; i <= tot; ++i)
		for (ll j = i + 1; j <= tot; ++j)
			if (d[j] % d[i] == 0) cnt[i] += cnt[j];
	for (ll i = 1; i <= tot; ++i)
		if (cnt[i] * 2 >= n) ans = max(ans, d[i]);
}

mt19937 rd(time(0));

int main() {
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &a[i]);
	for (ll i = 1; i <= 10; ++i) calc(a[rd() % n + 1]);
	printf("%lld\n", ans);
	return 0;
}