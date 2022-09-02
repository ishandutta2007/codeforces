#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;

ld getX(ll a, ll b, ll c, ll y) {
	return (ld)(-c - b*y) / a;
}

ld getY(ll a, ll b, ll c, ll x) {
	return (ld)(-c - a*x) / b;
}

ld getDist(pair<ld, ld> p1, pair<ld, ld> p2) {
	return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll a, b, c;
	ll x1, y1, x2, y2;

	cin >> a >> b >> c;
	cin >> x1 >> y1 >> x2 >> y2;

	// case 0: don't use the avenue
	ld res = abs(x1 - x2) + abs(y1 - y2);

	// Find points of collision of the avenue with the box
	// min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2)
	// ax + by = c

	if (a != 0 && b != 0) {
		vector<pair<ld, ld>> points;

		points.push_back({x1, getY(a, b, c, x1)});
		points.push_back({x2, getY(a, b, c, x2)});
		points.push_back({getX(a, b, c, y1), y1});
		points.push_back({getX(a, b, c, y2), y2});

		for (int i = 0; i < points.size(); ++i) {
			for (int j = 0; j < points.size(); ++j) {
				ld offer = 0;
				offer += getDist({x1, y1}, points[i]);
				offer += getDist({x2, y2}, points[j]);
				
				ld dx = points[i].first - points[j].first;
				ld dy = points[i].second - points[j].second;
				
				offer += sqrt(dx * dx + dy * dy);

				res = min(res, offer);
			}
		}
	}

	cout << fixed << setprecision(10) << res << '\n';
}