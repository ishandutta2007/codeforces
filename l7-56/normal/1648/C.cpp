#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll maxn = 2e5 + 10, mod = 998244353;
ll qpow(ll a, ll p) {
	ll ans = 1; a %= mod;
	while (p) {
		if (p & 1) ans = ans * a % mod;
		a = a * a % mod, p >>= 1;
	}
	return ans;
}
ll inv(ll x) { return qpow(x, mod - 2); }
ll fact[maxn],invf[maxn];
ll n,m,d,s[maxn],t[maxn],cnt[maxn],val,ans;
vector <ll> A;

struct BIT {
	ll c[maxn];
	void add(ll pos, ll val) { for (; pos <= d; pos += pos & (-pos)) c[pos] += val; }
	ll ask(ll pos) {
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += c[pos];
		return res;
	}
	ll ask(ll l, ll r) {
		if (l > r) return 0;
		return ask(r) - ask(l - 1);
	}
}T;

int main() {
	fact[0] = invf[0] = 1;
	for (ll i = 1; i <= 200000; ++i) fact[i] = fact[i - 1] * i % mod, invf[i] = inv(fact[i]);
	scanf("%lld%lld", &n, &m);
	for (ll i = 1; i <= n; ++i) scanf("%lld", &s[i]), A.push_back(s[i]);
	for (ll i = 1; i <= m; ++i) scanf("%lld", &t[i]), A.push_back(t[i]);
	sort(A.begin(), A.end());
	A.erase(unique(A.begin(), A.end()), A.end());
	d = A.size();
	for (ll i = 1; i <= n; ++i) {
		s[i] = lower_bound(A.begin(), A.end(), s[i]) - A.begin() + 1;
		cnt[s[i]]++;
	}
	val = fact[n];
	for (ll i = 1; i <= d; ++i) val = val * invf[cnt[i]] % mod, T.add(i, cnt[i]);
	for (ll i = 1; i <= m; ++i) {
		t[i] = lower_bound(A.begin(), A.end(), t[i]) - A.begin() + 1;
		ans = (ans + val * inv(n - i + 1) % mod * T.ask(t[i] - 1) % mod) % mod;
		if (--cnt[t[i]] < 0) {
			if (i == n + 1) ans = (ans + 1) % mod;
			break;
		}
		T.add(t[i], -1); val = val * inv(n - i + 1) % mod * (cnt[t[i]] + 1) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}