#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

#define sq(n) ((n)*(n))
const ld eps = 1e-15;

bool eq (ld a, ld b) { return abs(a - b) < eps; } 
bool le (ld a, ld b) { return a < b && !eq(a, b); }

struct Point {
	ld x, y;
	Point() : x(0), y(0) {}
	Point(int x, int y) : x(x), y(y) {}
	Point(ld x, ld y) : x(x), y(y) {}

	Point operator + (Point p) { return {x + p.x, y + p.y}; }
	Point operator - (Point p) { return {x - p.x, y - p.y}; }
	Point operator * (ld k) { return {x * k, y * k}; }
	Point operator / (ld k) { return {x / k, y / k}; }
	bool operator == (Point p) { return eq(x, p.x) && eq(y, p.y); }

	ld norm () { return sq(x) + sq(y); }
	Point perp () { return Point(-y, x); }
};

int n, x[3], y[3], r[3];
vector<Point> v, in[3];

vector<Point> inter (Point c1, ld r1, Point c2, ld r2) {
	Point d = c2 - c1;
	ld d2 = d.norm();

	ld pd = (d2 + sq(r1) - sq(r2)) / 2;
	ld h2 = sq(r1) - sq(pd) / d2;

	Point p = c1 + d * pd / d2;
	if (eq(h2, 0)) return {p};
	else if (le(h2, 0)) return {};
	else {
		Point u = d.perp() * sqrt(h2 / d2);
		return {p - u, p + u};
	}
}

void insert (vector<Point> &v, Point p) {
	for (auto q : v) if (p == q) return;
	v.pb(p);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) cin >> x[i] >> y[i] >> r[i];

	forn (i, n) forn (j, i) {
		if (sq(x[i] - x[j]) + sq(y[i] - y[j]) > sq(r[i] + r[j])) continue;
		if (sq(x[i] - x[j]) + sq(y[i] - y[j]) < sq(r[i] - r[j])) continue;

		auto P = inter({x[i], y[i]}, r[i], {x[j], y[j]}, r[j]);
		for (auto p : P) insert(v, p), insert(in[i], p), insert(in[j], p);
	}
	
	int res = 0, f = 0;
	forn (i, n) if (in[i].size()) {
		res += in[i].size();
		if (!f) res += 2;
		f = 1;
	} else {
		res++;
	}

	if (f) res -= v.size();
	else res++;

	cout << res << endl;

	return 0;
}