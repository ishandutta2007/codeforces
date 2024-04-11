#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}
 
pair<ll, ll> extEucMod(ll a, ll b, ll p) {
	if (b == 0) return {1, 0};
	ll m = a / b;
	auto sub = extEucMod(b, a - b * m, p);
	return {sub.second, (sub.first - m*sub.second) % p};
}
ll modInv(ll a, ll p) {
	ll res = extEucMod(p, a, p).second;
	return (res < 0 ? res + p : res);
}
 
const int N = 5 * (int)1e5 + 10;
int apps[2*N][2];
 
ll calc(ll h, ll n, ll m, int max_c) {
	ll div = gcd(n, m);
	n /= div;
	m /= div;
 
	ll mod = n * m;
	ll x = m * modInv(m, n) % mod;
	ll y = n * modInv(n, m) % mod;
 
	ll base = h / (mod * div);
	h %= (mod * div);
 
	// (i, j) appears before time h IFF div * (ix + jy modulo mod) + rem < h
 
	ll res = 0;
	ll full = 0;
	for (int c = 0; c < max_c; ++c) {
		if (apps[c][0] == -1 || apps[c][1] == -1) continue;
		if (apps[c][0] % div != apps[c][1] % div) continue;
		

		++full;
		ll rem = (apps[c][0] % div);

		ll v0 = apps[c][0] / div;
		ll v1 = apps[c][1] / div;
		
		if (div * ((v0 * x + v1 * y) % mod) + rem < h) ++res;
	}
	
	return base * full + res;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
 
	int n, m;
	ll k;
	cin >> n >> m >> k;
	int div = gcd(n, m);
	
	int h = 2*max(n, m);
	for (int c = 0; c < h; ++c) {
		apps[c][0] = -1;
		apps[c][1] = -1;
	}

	vector<int> as(n), bs(m);
	for (int i = 0; i < n; ++i) {
		cin >> as[i];
		--as[i];
 		apps[as[i]][0] = i;
	}
	for (int i = 0; i < m; ++i) {
		cin >> bs[i];
		--bs[i];
		apps[bs[i]][1] = i;
	}

	ll low = k;
	ll high = 1e18;
	while(low != high) {
		ll mid = (low + high) >> 1;
		if (calc(mid, n, m, h) <= mid - k) high = mid;
		else low = mid + 1;
	}
	cout << low << '\n';
}