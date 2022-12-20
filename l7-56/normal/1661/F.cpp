#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <ll, ll> pll;
template <typename __Tp> void read(__Tp &x) {
	ll f = x = 0; char ch = getchar();
	for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
	for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
	if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &... y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ... y) { write(x), write(y...); }

const ll maxn = 2e5 + 10;
ll n,m,a[maxn];
ll calc(ll len, ll x) { return (x - (len % x)) * (len / x) * (len / x) + (len % x) * ((len / x) + 1) * ((len / x) + 1); }
pll calc(ll k) {
	ll cnt = 0, sum = 0;
	for (ll i = 1; i <= n; ++i) {
		ll l = 2, r = a[i] - a[i - 1], mid, ans = 1;
		while (l <= r) {
			mid = (l + r) >> 1;
			if (calc(a[i] - a[i - 1], mid - 1) - calc(a[i] - a[i - 1], mid) >= k) ans = mid, l = mid + 1;
			else r = mid - 1;
		}
		cnt += ans - 1;
		sum += calc(a[i] - a[i - 1], ans);
	}
	return make_pair(cnt, sum);
}

int main() {
	read(n);
	for (ll i = 1; i <= n; ++i) read(a[i]);
	read(m);
	ll l = 1, r = 1e18, mid, ans = 0;
	while (l <= r) {
		mid = (l + r) >> 1;
		pll p = calc(mid);
		if (p.second <= m) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	pll p = calc(ans);
	write(p.first - (m - p.second) / ans, '\n');
	return 0;
}