#include <bits/stdc++.h>

using namespace std;

// https://codeforces.com/gym/103261/submission/128001669
template <typename T> struct Point {
public:
	T x, y;
	Point() : x(0), y(0) {}
	Point(T x_, T y_) : x(x_), y(y_) {}
	template <typename U> explicit Point(const Point<U>& p) : x(p.x), y(p.y) {}
	Point(const std::pair<T, T>& p) : x(p.first), y(p.second) {}
	Point(const std::complex<T>& p) : x(real(p)), y(imag(p)) {}
	explicit operator std::pair<T, T> () const { return std::pair<T, T>(x, y); }
	explicit operator std::complex<T> () const { return std::complex<T>(x, y); }
 
	friend std::ostream& operator << (std::ostream& o, const Point& p) { return o << '(' << p.x << ',' << p.y << ')'; }
	friend std::istream& operator >> (std::istream& i, Point& p) { return i >> p.x >> p.y; }
	friend bool operator == (const Point& a, const Point& b) { return a.x == b.x && a.y == b.y; }
	friend bool operator != (const Point& a, const Point& b) { return !(a==b); }
 
	Point operator + () const { return Point(+x, +y); }
	Point operator - () const { return Point(-x, -y); }
 
	Point& operator += (const Point& p) { x += p.x, y += p.y; return *this; }
	Point& operator -= (const Point& p) { x -= p.x, y -= p.y; return *this; }
	Point& operator *= (const T& t) { x *= t, y *= t; return *this; }
	Point& operator /= (const T& t) { x /= t, y /= t; return *this; }
 
	friend Point operator + (const Point& a, const Point& b) { return Point(a.x+b.x, a.y+b.y); }
	friend Point operator - (const Point& a, const Point& b) { return Point(a.x-b.x, a.y-b.y); }
	friend Point operator * (const Point& a, const T& t) { return Point(a.x*t, a.y*t); }
	friend Point operator * (const T& t ,const Point& a) { return Point(t*a.x, t*a.y); }
	friend Point operator / (const Point& a, const T& t) { return Point(a.x/t, a.y/t); }
 
	T dist2() const { return x * x + y * y; }
	auto dist() const { return std::sqrt(dist2()); }
	Point unit() const { return *this / this->dist(); }
	auto angle() const { return std::atan2(y, x); }
 
	T int_norm() const { return __gcd(x,y); }
	Point int_unit() const { if (!x && !y) return *this; return *this / this->int_norm(); }
 
	// Convenient free-functions, mostly for generic interop
	friend auto norm(const Point& a) { return a.dist2(); }
	friend auto abs(const Point& a) { return a.dist(); }
	friend auto unit(const Point& a) { return a.unit(); }
	friend auto arg(const Point& a) { return a.angle(); }
	friend auto int_norm(const Point& a) { return a.int_norm(); }
	friend auto int_unit(const Point& a) { return a.int_unit(); }
 
	Point perp_cw() const { return Point(y, -x); }
	Point perp_ccw() const { return Point(-y, x); }
 
	friend T dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }
	friend T cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }
	friend T cross3(const Point& a, const Point& b, const Point& c) { return cross(b-a, c-a); }
 
	// Complex numbers and rotation
	friend Point conj(const Point& a) { return Point(a.x, -a.y); }
 
	// Returns conj(a) * b
	friend Point dot_cross(const Point& a, const Point& b) { return Point(dot(a, b), cross(a, b)); }
	friend Point cmul(const Point& a, const Point& b) { return dot_cross(conj(a), b); }
	friend Point cdiv(const Point& a, const Point& b) { return dot_cross(b, a) / b.norm(); }
 
	// Must be a unit vector; otherwise multiplies the result by abs(u)
	Point rotate(const Point& u) const { return dot_cross(conj(u), *this); }
	Point unrotate(const Point& u) const { return dot_cross(u, *this); }
 
	friend bool same_dir(const Point& a, const Point& b) { return cross(a,b) == 0 && dot(a,b) > 0; }
 
	// check if 180 <= s..t < 360
	friend bool is_reflex(const Point& a, const Point& b) { auto c = cross(a,b); return c ? (c < 0) : (dot(a, b) < 0); }
 
	// operator < (s,t) for angles in [base,base+2pi)
	friend bool angle_less(const Point& base, const Point& s, const Point& t) {
		int r = is_reflex(base, s) - is_reflex(base, t);
		return r ? (r < 0) : (0 < cross(s, t));
	}
 
	friend auto angle_cmp(const Point& base) {
		return [base](const Point& s, const Point& t) { return angle_less(base, s, t); };
	}
	friend auto angle_cmp_center(const Point& center, const Point& dir) {
		return [center, dir](const Point& s, const Point& t) -> bool { return angle_less(dir, s-center, t-center); };
	}
 
	// is p in [s,t] taken ccw? 1/0/-1 for in/border/out
	friend int angle_between(const Point& s, const Point& t, const Point& p) {
		if (same_dir(p, s) || same_dir(p, t)) return 0;
		return angle_less(s, p, t) ? 1 : -1;
	}
};


int main() {
	ios_base::sync_with_stdio(false); cin.tie(nullptr);
	int N, K; cin >> N >> K; --K;
	vector<Point<int64_t>> P(N);
	for (auto &p : P) cin >> p;

	int outer = -1;
	for (int i = 0; i < 3; ++i) {
		for (int j = i+1; j < 3; ++j) {
			outer = -1;
			for (int k = 0; k < N; ++k) {
				if (cross3(P[i], P[j], P[k])) {
					if (outer == -1) outer = k;
					else goto bad;
				}
			}
			goto found;
bad:;
		}
	}
found:;
	cerr << outer << '\n';

	vector<pair<Point<int64_t>, int>> P0;
	for (int i = 0; i < N; ++i) if (i != outer) P0.push_back({P[i], i});
	sort(P0.begin(), P0.end(), [&](const auto &a, const auto &b) {
		return pair<int64_t, int64_t>(a.first) < pair<int64_t, int64_t>(b.first);
	});

	auto cost = [&](int lo, int hi) {
		if (lo > hi) return double(0);
		double ans = min((P0[lo].first - P[outer]).dist(), (P0[hi].first - P[outer]).dist());
		ans += (P0[lo].first - P0[hi].first).dist();
		return ans;
	};

	if (K == outer) {
		cout << fixed << setprecision(10) << cost(0, N-2) << '\n';
	} else {
		double ans = 1e18;
		int mi = 0;
		while (P0[mi].second != K) mi++;
		for (int mi2 = 0; mi2 < N-1; ++mi2) {
			double cnd = (P0[mi].first - P0[mi2].first).dist();
			cnd += (P0[mi2].first - P[outer]).dist();
			int lo = 0, hi = N-2;
			if (mi2 == N-2) {
				hi = mi - 1;
			} else if (mi2 == 0) {
				lo = mi + 1;
			}
			cnd += cost(lo, hi);
			ans = min(ans, cnd);
			if (mi2 <= mi) {
				// go to N-2 then come back
				double cnd = (P0[mi].first - P0[N-2].first).dist();
				cnd += (P0[mi2].first - P0[N-2].first).dist();
				cnd += (P0[mi2].first - P[outer]).dist();
				cnd += cost(0, mi2 - 1);
				ans = min(ans, cnd);
			} 
			if (mi2 >= mi) {
				double cnd = (P0[mi].first - P0[0].first).dist();
				cnd += (P0[mi2].first - P0[0].first).dist();
				cnd += (P0[mi2].first - P[outer]).dist();
				cnd += cost(mi2 + 1, N-2);
				ans = min(ans, cnd);
			}
		}
		cout << fixed << setprecision(10) << ans << '\n';
	}

}