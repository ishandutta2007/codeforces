#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
const ll INF = 7 + (ll)1e18;

struct Point {
	ll x, y, z;

	bool operator<(const Point& rhs) const {
		if (x == rhs.x) {
			if (y == rhs.y) {
				return z < rhs.z;
			} else return y < rhs.y;
		} else return x < rhs.x;
	}
};

ll dist(Point a, Point b) {
	return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	vector<pair<Point, int>> vecs(n);
	for (int i = 0; i < n; ++i) {
		cin >> vecs[i].first.x >> vecs[i].first.y >> vecs[i].first.z;
		vecs[i].second = i + 1;
	}
	sort(vecs.begin(), vecs.end());

	for (int i = 0; i < n; i += 2) {
		if (vecs[i].first.x != vecs[i+1].first.x) {
			int ind = -1;
			ll best = INF;
			for (int j = i+1; j < n; ++j) {
				if (vecs[j].first.x != vecs[i+1].first.x) break;
				ll off = dist(vecs[i].first, vecs[j].first);
				if (off < best) {
					ind = j;
					best = off;
				}
			}
			for (int j = ind; j > i+1; --j) swap(vecs[j], vecs[j-1]);
		} else if (vecs[i].first.y != vecs[i+1].first.y) {
			int ind = -1;
			ll best = INF;
			for (int j = i+1; j < n; ++j) {
				if (vecs[j].first.x != vecs[i+1].first.x || vecs[j].first.y != vecs[i+1].first.y) break;
				ll off = dist(vecs[i].first, vecs[j].first);
				if (off < best) {
					ind = j;
					best = off;
				}
			}
			for (int j = ind; j > i+1; --j) swap(vecs[j], vecs[j-1]);
		} else {
			// x and y are equal, no way anything can be in between
		}
		cout << vecs[i].second << ' ' << vecs[i+1].second << '\n';
	}
}