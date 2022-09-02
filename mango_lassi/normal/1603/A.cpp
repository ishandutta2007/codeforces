#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAX = (ll)1e9 + 7;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lca(ll a, ll b) {
	return (a / gcd(a, b)) * b;
}

void solve() {
	int n;
	cin >> n;

	bool works = 1;
	ll cur = 1;
	for (int i = 1; i <= n; ++i) {
		if (cur < MAX) cur = lca(cur, i + 1);
		ll a;
		cin >> a;
		if (a % cur == 0) works = 0;
	}
	if (works) cout << "YES\n";
	else cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int q;
	cin >> q;
	for (int qi = 0; qi < q; ++qi) solve();
}