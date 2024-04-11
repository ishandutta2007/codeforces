#include <bits/stdc++.h>
using namespace std;
using ll = long long;


template<class T, class TL>
struct Point {
	T x, y;
	
	Point operator+(const Point& rhs) const { return {x + rhs.x, y + rhs.y}; }
	Point operator-(const Point& rhs) const { return {x - rhs.x, y - rhs.y}; }
	Point operator*(const T& v) const { return {x * v, y * v}; }
	Point operator/(const T& v) const { return {x / v, y / v}; }
	TL sqLength() const { return (TL)x*x + (TL)y*y; }

	// Complex operations
	Point conj() const { return {x, -y}; }
	Point inv() const { return conj() / sqLength(); }

	Point operator*(const Point& rhs) const { return {x * rhs.x - y * rhs.y, x * rhs.y + y * rhs.x}; }
	Point operator/(const Point& rhs) const { return *this * rhs.inv(); }
};

template<class T, class TL>
TL dot(const Point<T, TL>& a, const Point<T, TL>& b) { return (TL)a.x * b.x + (TL)a.y * b.y; }
using P = Point<ll, ll>;

bool check(const P& a, const P& b, const P& c) {
	return dot(b - a, c - b) < 0;
}

void solve() {
	int n;
	cin >> n;
	
	vector<P> pts(n);
	for (int i = 0; i < n; ++i) cin >> pts[i].x >> pts[i].y;

	vector<int> ind(n, -1);
	ind[0] = 0;

	for (int i = 0; ind[i] < n-1;) {
		int j = -1;
		for (int t = 0; t < n; ++t) {
			if (ind[t] != -1) continue;
			if (j == -1 || (pts[t] - pts[i]).sqLength() >= (pts[j] - pts[i]).sqLength()) j = t;
		}
		assert(j != -1);
		ind[j] = ind[i] + 1;
		i = j;
	}

	vector<int> ord(n);
	for (int i = 0; i < n; ++i) ord[ind[i]] = i+1;
	for (auto i : ord) cout << i << ' '; cout << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();
}