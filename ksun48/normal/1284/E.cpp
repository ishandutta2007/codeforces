#include <bits/stdc++.h>
using namespace std;

template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};


template <class P>
bool sameDir(P s, P t) {
	return s.cross(t) == 0 && s.dot(t) > 0;
}
// checks 180 <= s..t < 360?
template <class P>
bool isReflex(P s, P t) {
	auto c = s.cross(t);
	return c ? (c < 0) : (s.dot(t) < 0);
}
// operator < (s,t) for angles in [base,base+2pi)
template <class P>
bool angleCmp(P base, P s, P t) {
	int r = isReflex(base, s) - isReflex(base, t);
	return r ? (r < 0) : (0 < s.cross(t));
}
// is x in [s,t] taken ccw? 1/0/-1 for in/border/out
template <class P>
int angleBetween(P s, P t, P x) {
	if (sameDir(x, s) || sameDir(x, t)) return 0;
	return angleCmp(s, x, t) ? 1 : -1;
}


using ll = long long;
using P = Point<ll>;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<P> p(n);
	for(int i = 0; i < n; i++){
		cin >> p[i].x >> p[i].y;
	}

	ll a = 0;

	for(int i = 0; i < n; i++){
		vector<P> angles;
		for(int j = 0; j < n; j++){
			if(j == i) continue;
			angles.push_back(p[j] - p[i]);
		}
		sort(angles.begin(), angles.end(), [&](P a, P b){
			return angleCmp(P(1, 0), a, b);
		});

		int m = n-1;
		int k = 0;
		int cnt = 0;
		for(int j = 0; j < m; j++){
			while(!isReflex(angles[j], angles[k]) && cnt < m){
				k = (k + 1) % m;
				cnt++;
			}
			cnt--;
			a += 1ll * cnt * (cnt - 1) / 2;
		}
	}
	a = 1ll * n * (n-1) * (n-2) * (n-3) / 6 - a;

	a *= (n-4);
	a /= 2;
	cout << a << '\n';
}