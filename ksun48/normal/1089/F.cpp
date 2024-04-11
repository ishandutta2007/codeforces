#include<bits/stdc++.h>
using namespace std;

using ll = long long;

ll inv(ll a, ll m) {
	assert(a >= 0);
	a %= m;
	assert(a);
	if (a == 1) return 1;
	return m - inv(m,a) * m / a;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	ll N; cin >> N;
	for (ll p = 2; p * p <= N; p++) {
		if (N % p != 0) continue;
		ll q = N / p;
		if (__gcd(p, q) != 1) continue;
		cout << "YES\n";
		ll a = (p - inv(q, p)) % p;
		ll b = (q - inv(p, q)) % q;
		cout << 2 << '\n';
		cout << a << ' ' << p << '\n';
		cout << b << ' ' << q << '\n';
		return 0;
	}
	cout << "NO\n";
	return 0;
}