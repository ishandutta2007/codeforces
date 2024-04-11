#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
};

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
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
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};
using ll = long long;
using ld = double;
using P = Point<ld>;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	ll n, k;
	cin >> n >> k;
	vector<P> p(n);
	for(int i = 0; i < n; i++) cin >> p[i].x >> p[i].y;
	ld s = 0;
	ld e = 1e5; // >= k
	for(int _ = 0; _ < 50; _++){
		ld d = (s + e) / 2;
		ll intersect = 0;
		int nleft = n;
		vector<vector<ld> > angs;
		for(P a : p){
			ld q = a.dist();
			if(q <= d){
				nleft -= 1;
				intersect += nleft;
			} else {
				ld theta = acos(d / q);
				ld ang1 = a.rotate(theta).angle();
				ld ang2 = a.rotate(-theta).angle();
				if(ang1 > ang2) swap(ang1, ang2);
				angs.push_back({ang1, ang2});
			}
		}
		if(!angs.empty()){
			int N = (int)angs.size();
			vector<pair<int,int> > inds;
			for(int j = 0; j < N; j++){
				inds.push_back({j, 0});
				inds.push_back({j, 1});
			}
			sort(inds.begin(), inds.end(), [&](pair<int,int> r, pair<int,int> s){
				return angs[r.first][r.second] < angs[s.first][s.second];
			});
			FT ft1(2*N);
			FT ft2(2*N);
			vector<int> when(N, -1);
			for(int t = 0; t < (int)inds.size(); t++){
				int a = inds[t].first;
				if(when[a] == -1){
					when[a] = t;
				} else {
					intersect += ft1.query(when[a]);
					ft1.update(t, 1);
					intersect += ft2.query(2*N) - ft2.query(when[a]);
					ft2.update(when[a], 1);
				}
			}
		}
		if(intersect >= k){
			e = d;
		} else {
			s = d;
		}
	}
	cout << fixed << setprecision(8);
	cout << e << '\n';
}