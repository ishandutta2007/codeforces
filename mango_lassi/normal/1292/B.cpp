#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
	return abs(a.first - b.first) + abs(a.second - b.second);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll x0, y0, ax, ay, bx, by;
	cin >> x0 >> y0 >> ax >> ay >> bx >> by;

	ll t;
	pair<ll, ll> ini;
	cin >> ini.first >> ini.second >> t;

	// Coordinates of ith point are at least (2^i, 2^i)
	// -> At most like 2^64 relevant points

	// Optimal order to collect data points is to start from one, then collect the others in order.

	vector<pair<ll, ll>> pts;
	while(x0 <= ini.first + t && y0 <= ini.second + t) {
		pts.push_back({x0, y0});
		x0 = ax * x0 + bx;
		y0 = ay * y0 + by;
	}
	int n = pts.size();

	int res = 0;
	for (int a = 0; a < n; ++a) {
		for (int b = a; b < n; ++b) {
			ll d0 = dist(pts[a], pts[b]);
			ll d1 = dist(ini, pts[a]);
			ll d2 = dist(ini, pts[b]);
			if (d0 + min(d1, d2) <= t) res = max(res, b-a+1);
		}
	}
	cout << res << '\n';
}