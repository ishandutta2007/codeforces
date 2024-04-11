#include <bits/stdc++.h>
using namespace std;

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T _x=0, T _y=0) : x(_x), y(_y) {}
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

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
template<class T>
T polygonArea2(vector<Point<T>>& v) {
	T a = v.back().cross(v[0]);
	rep(i,0,sz(v)-1) a += v[i].cross(v[i+1]);
	return a;
}


using ll = int64_t;
using P = Point<ll>;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n, K;
	cin >> n >> K;
	vector<P> polygon(n);
	for(P& p : polygon){
		cin >> p.x >> p.y;
	}
	ll s = 0;
	ll e = 1e17;
	vector<vector<ll> > area(n, vector<ll>(n));
	for(int j = 0; j < n; j++){
		for(int i = j-1; i >= 0; i--){
			vector<P> pts;
			for(int k = i; k <= j; k++){
				pts.push_back(polygon[k]);
			}
			area[i][j] = polygonArea2(pts);
		}
	}
	while(s + 1 < e){
		ll thresh = (s + e) / 2;
		// can all area <= thresh?
		// max pieces under
		vector<vector<pair<int, ll> > > dp(n, vector<pair<int, ll> >(n, {-1e8, 0}));
		for(int j = 0; j < n; j++){
			for(int i = j-1; i >= 0; i--){
				dp[i][j] = {0, area[i][j]};
				if(area[i][j] >= thresh) dp[i][j] = {1, 0};
				for(int k = i+1; k < j; k++){
					int np = dp[i][k].first + dp[k][j].first;
					ll narea = (polygon[k] - polygon[i]).cross(polygon[j] - polygon[i]) + dp[i][k].second + dp[k][j].second;
					if(narea >= thresh){
						narea = 0;
						np += 1;
					}
					dp[i][j] = max(dp[i][j], {np, narea});
				}
			}
		}
		if(dp[0][n-1].first >= K+1){
			s = thresh;
		} else {
			e = thresh;
		}
	}
	cout << s << '\n';
}