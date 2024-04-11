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

using ll = long long;
using P = Point<ll>;

int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	vector<P> pts(n);
	vector<int> label(n);
	vector<int> needed;
	for(int i = 0; i < n; i++){
		auto& p = pts[i];
		cin >> p.x >> p.y;
		cin >> label[i];
		label[i]--;
		if(label[i] != i){
			needed.push_back(i);
		}
	}
	if(needed.empty()){
		cout << 0 << '\n';
		return 0;
	}
	sort(needed.begin(), needed.end(), [&](int a, int b){
		return pts[a].x < pts[b].x;
	});
	int f = needed.front();
	needed.erase(needed.begin());
	sort(needed.begin(), needed.end(), [&](int a, int b){
		return (pts[a] - pts[f]).angle() < (pts[b] - pts[f]).angle();
	});
	vector<pair<int,int> > ops;
	for(int i = 0; i + 1 < needed.size(); i++){
		// if they are not in the same cycle
		int x = needed[i];
		int y = needed[i+1];
		int same = 0;
		int cx = x;
		for(int j = 0; j < n; j++){
			if(cx == y) same = 1;
			cx = label[cx];
		}
		if(!same){
			swap(label[x], label[y]);
			ops.push_back({x, y});
		}
	}
	while(label[f] != f){
		int y = label[f];
		swap(label[f], label[y]);
		ops.push_back({f, y});
	}
	for(int i = 0; i < n; i++){
		assert(label[i] == i);
	}
	cout << ops.size() << '\n';
	for(auto [a, b] : ops){
		cout << (a+1) << ' ' << (b+1) << '\n';
	}
}