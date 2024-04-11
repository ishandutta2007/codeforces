#include <bits/stdc++.h>
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
#define pii pair<int, int>
#define eb emplace_back
using namespace std;
typedef double db;
typedef long long ll;
typedef __int128 LL;
ll p[200], tot = 0;
ll power(ll a, ll b, ll p, ll c = 1) {
	a %= p;
	for(; b; b >>= 1, a = (LL)a * a % p) if(b & 1) c = (LL)c * a % p;
	return c;
}

ll calc(ll mod, ll x) {
	ll Mod = mod;
	for(int i = 1; i <= tot; i++) if(Mod % p[i] == 0) mod /= p[i], mod *= (p[i] - 1);
	ll ans = 1;
	for(int i = 1; i <= tot; i++) {
		if(mod % p[i] == 0) {
			while(mod % p[i] == 0 && power(x, mod / p[i], Mod) == 1) {
				mod /= p[i], ans *= p[i];
			}
		}
	}
	return ans;
}

int main() {
	ll m, x;
	cin >> m >> x;
	ll n = m;
	for(ll i = 2; i * i <= m; i++) {
		if(m % i == 0) {
			p[++tot] = i;
			while(m % i == 0) m /= i;
		}
	}
	if(m > 1) p[++tot] = m;
	int totp = tot;
	for(int i = 1; i <= tot; i++) {
		ll num = p[i] - 1;
		for(ll j = 2; j * j <= num; j++) {
			if(num % j == 0) {
				p[++totp] = j;
				while(num % j == 0) num /= j;
			}
		}
		if(num > 1) p[++totp] = num;
	}
	tot = totp;
	sort(p + 1, p + tot + 1);
	tot = unique(p + 1, p + tot + 1) - (p + 1);
	m = n;
	ll ans = 0;
	for(ll i = 1; i * i <= m; i++) {
		if(m % i == 0) {
			ans += calc(i, x);
			if(i * i != m) ans += calc(m / i, x);
		}
	}
	cout << ans << endl;
	return 0;
}