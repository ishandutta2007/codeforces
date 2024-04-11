#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll recGCD(ll a, ll b) {
	if (b == 0) return a;
	return recGCD(b, a % b);
}

ll gcd(ll a, ll b) {
	if (a < 0) a *= -1;
	if (b < 0) b *= -1;
	return recGCD(a, b);
}

void solve() {
	int n;
	ll k;
	cin >> n >> k;

	ll gd = 0;
	vector<ll> xs(n);
	for (int i = 0; i < n; ++i) {
		cin >> xs[i];
		if (i > 0) gd = gcd(gd, xs[i-1] - xs[i]);
	}

	ll t = k % gd;
	if (t < 0) t += gd;
	for (int i = 0; i < n; ++i) {
		ll a = xs[i] % gd;
		if (a < 0) a += gd;
		if (a == t) {
			cout << "YES\n";
			return;
		}
	}
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}