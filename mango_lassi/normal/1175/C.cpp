#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 1e18;

void solve() {
	int n, k;
	cin >> n >> k;

	vector<ll> points(n);
	for (int i = 0; i < n; ++i) cin >> points[i];
	sort(points.begin(), points.end());

	ll res = INF;
	ll x = -1;
	for (int i = 0; i+k < n; ++i) {
		ll offer = (points[i+k] - points[i] + 1) / 2;
		if (offer < res) {
			res = offer;
			x = (points[i+k] + points[i]) / 2;
		}
	}
	cout << x << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) {
		solve();
	}
}