#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

template<class T>
struct Point {
	T X, Y;
	Point() : X(0), Y(0) {}
	Point(T a, T b) : X(a), Y(b) {}

	Point operator+ (const Point& rhs) const { return Point(X+rhs.X, Y+rhs.Y); }
	Point operator- (const Point& rhs) const { return Point(X-rhs.X, Y-rhs.Y); }
	Point operator- () const { return Point(-X, -Y); }
};
using co = Point<int>;

bool ccw(co a, co b) {
	return (ll)b.X * a.Y < (ll)b.Y * a.X;
}
int ar(co x) {
	if (x.Y>=0&&x.X<0) return 1;
	if (x.X>=0&&x.Y>0) return 2;
	if (x.Y<=0&&x.X>0) return 3;
	return 4;
}

// p1 < p2?
bool cp(const pair<pair<int, co>, int>& p1, const pair<pair<int, co>, int>& p2) {
	if (p1.first.first != p2.first.first) return p1.first.first < p2.first.first;
	else return ccw(p2.first.second, p1.first.second);
}

ll solve(vector<co> pts, co x) {
	int n = pts.size();
	for (co& p : pts) p = p - x;

	vector<pair<pair<int, co>, int>> tmp(2*n);
	for (int i = 0; i < n; ++i) {
		tmp[i] = {{ar(pts[i]), pts[i]}, i};
		tmp[i+n] = {{ar(-pts[i]), -pts[i]}, i+n};
	}
	sort(tmp.begin(), tmp.end(), cp);

	vector<int> ind(2*n, 0);
	for (int i = 0; i < 2*n; ++i) ind[i] = tmp[i].second;

	vector<bool> seen(n, 0);
	for (int i = 0; i < 2*n; ++i) {
		if (ind[i] >= n) {
			if (! seen[ind[i] - n]) ind.push_back(ind[i] + n);
		} else seen[ind[i]] = 1;
		
	}
	int m = ind.size();

	vector<int> rev(3*n, -1);
	for (int i = 0; i < m; ++i) rev[ind[i]] = i;
	for (int i = 0; i < n; ++i) {
		if (rev[i+2*n] == -1) rev[i+2*n] = rev[i+n];
	}

	vector<ll> cou(m, 0);
	for (int i = 0; i < m; ++i) cou[i] = (i > 0 ? cou[i-1] : 0) + (ind[i] < n);

	vector<ll> f1(m+1, 0), f2(m+1, 0), f3(m+1, 0), f4(m+1, 0), f5(m+1, 0);

	for (int i = 0; i < n; ++i) {
		f1[rev[i] + 1] += cou[rev[i]] * cou[rev[i+n]];
		f2[rev[i] + 1] += cou[rev[i]] * cou[rev[i+2*n]];
		f3[rev[i] + 1] += cou[rev[i+n]];
		f4[rev[i] + 1] += cou[rev[i+2*n]];
		f5[rev[i] + 1] += cou[rev[i]];
	}
	for (int i = 1; i <= m; ++i) {
		f1[i] += f1[i-1];
		f2[i] += f2[i-1];
		f3[i] += f3[i-1];
		f4[i] += f4[i-1];
		f5[i] += f5[i-1];
	}

	ll res = 0;
	for (int i = 0; i < n; ++i) {
		// Case 1: Convex angle
		// Pairing with j, add (cou[j] - cou[i] - 1) * (cou[proj2[j]] - cou[proj2[i]])
		//	= cou[j] cou[proj2[j]] - (cou[i] + 1) cou[proj2[j]] - cou[j] cou[proj2[i]]  + (cou[i] + 1) cou[proj2[i]]

		int a = rev[i];
		int b = rev[i+2*n];

		ll count = cou[b] - cou[a];
		ll x = f2[b+1] - f2[a+1];
		ll y = f4[b+1] - f4[a+1];
		ll z = f5[b+1] - f5[a+1];

		res += x - (cou[a] + 1) * y - cou[b] * z + ((cou[a] + 1) * cou[b]) * count;

		if (b == rev[i+n]) {
			// Case 2: Concave angle
			// Pairing with j, add (n - cou[j]) * (cou[proj1[i]] - cou[proj1[j]])
			//	= cou[j] cou[proj1[j]] - n cou[proj1[j]] - cou[j] cou[proj1[i]] + n cou[proj1[i]]

			int c = m-1;
			count = n - cou[b];
			x = f1[c+1] - f1[b+1];
			y = f3[c+1] - f3[b+1];
			z = f5[c+1] - f5[b+1];
			
			res += x - n * y - cou[b] * z + n * cou[b] * count;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Draw line from point x to two pointsx
	// For every point, add its projection to the points we sort by angle.
	// If we pick points i < j, and their projections have indices x and y, then we add
	// (cou[j] - cou[i] - 1) * (cou[proj[j]] - cou[proj[i]])
	// = cou[j] cou[proj[j]] - (cou[i] - 1) cou[proj[j]] - cou[j] cou[proj[i]] + (cou[i] - 1) cou[proj[i]]
	// -> Store range sums of cou[j] * cou[proj[j]], cou[proj[j]] and cou[j]. Then take these sums between
	// i and proj[i], and add to result.

	vector<co> points(n);
	for (int i = 0; i < n; ++i) {
		int x, y;
		cin >> x >> y;
		points[i] = {x, y};
	}

	co act = points.back();
	points.pop_back();
	ll res = 0;
	for (int i = 0; i < n; ++i) {
		res += solve(points, act);
		if (i < n) swap(act, points[i]);
	}
	cout << res << '\n';
}