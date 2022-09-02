#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	cin >> n;

	vector<ll> as(n);
	for (ll& a : as) cin >> a;
	sort(as.begin(), as.end());
	cout << as[n-2] + as[n-1] << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}