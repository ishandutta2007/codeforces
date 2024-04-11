#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	ll mult = 1, sum = 0;
	vector<ll> as(n);
	for (ll& a : as) {
		cin >> a;
		while(a % 2 == 0) {
			mult *= 2;
			a /= 2;
		}
		sum += a;
	}
	sort(as.begin(), as.end());
	cout << (sum - as.back()) + as.back() * mult << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}