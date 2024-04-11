#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

ll lca(ll a, ll b) {
	return a*b / gcd(a, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// GCD of LCMs
	// -> Prime power appears if it is in all but at most one number

	int n;
	cin >> n;

	ll r0 = 0, r1 = 0;
	for (int i = 0; i < n; ++i) {
		ll v;
		cin >> v;
		r1 = lca(r0, gcd(r1, v));
		r0 = gcd(r0, v);
	}
	cout << r1 << '\n';
}