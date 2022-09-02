// TCR
// Computes the convex hull of given set of points in O(n log n)
// Uses Andrew's algorithm
// The points on the edges of the hull are not listed
// Change > to >= in ccw function to list the points on the edges
// Returns points in counterclockwise order
#include <bits/stdc++.h>
#define X real()
#define Y imag()
using namespace std;
typedef long double ld;
typedef long long ll;
const ll INF = 2 * (ll)1e12;
// Coordinate type
typedef ll CT;
typedef complex<CT> co;
bool ccw(co a, co b, co c) {
	return ((c-a)*conj(b-a)).Y>0;
}

vector<co> convexHull(vector<co> ps) {
	auto cmp = [](co a, co b) {
		if (a.X==b.X) return a.Y<b.Y;
		else return a.X<b.X;
	};
	sort(ps.begin(), ps.end(), cmp);
	ps.erase(unique(ps.begin(), ps.end()), ps.end());
	int n=ps.size();
	if (n<=2) return ps;
	vector<co> hull;hull.push_back(ps[0]);
	for (int d=0;d<2;d++) {
		if (d) reverse(ps.begin(), ps.end());
		size_t s=hull.size();
		for (int i=1;i<n;i++) {
			while (hull.size()>s&&!ccw(hull[hull.size()-2],hull.back(),ps[i])) {
				hull.pop_back();
			}
			hull.push_back(ps[i]);
		}
	}
	hull.pop_back();
	return hull;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll max_x = -INF;
	ll min_x = INF;

	int n;
	cin >> n;

	vector<co> points(n);
	for (int i = 0; i < n; ++i) {
		ll x, y;
		cin >> x >> y;
		max_x = max(x, max_x);
		min_x = min(x, min_x);
		points[i] = {x, y - x*x};
	}

	if (min_x == max_x) {
		cout << "0\n";
	} else {
		// Add two points to make sure we only find the upper hull
		points.push_back({min_x, -INF});
		points.push_back({max_x, -INF});
		vector<co> hull = convexHull(points);
		cout << (int)hull.size() - 3 << '\n';
	}
}