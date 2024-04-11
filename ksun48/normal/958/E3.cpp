#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template <class T>
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

typedef Point<double> P;
map<int,int> gg;

const double PI = 4.0 * atan(1.0);
const double EPS = 0.000000001;
void solve(vector<pair<P, int> > a, vector<pair<P, int> > b){
	if(a.size() == 0) return;
	if(a.size() == 1){
		gg[a[0].second] = b[0].second;
		return;
	}
	double v[3];
	for(int i = 0; i < 3; i++){
		v[i] = abs(rand()) + 1;
	}
	P q = (a[0].first * v[0] + a[1].first * v[1] + b[0].first * v[2]) / (v[0] + v[1] + v[2]);
	vector<pair<double, int> > r;
	for(int i = 0; i < a.size(); i++){
		r.push_back({(a[i].first-q).angle(), 1});
		r.push_back({(b[i].first-q).angle(), -1});
	}
	sort(r.begin(), r.end());
	int s = 0;
	int e = 0;
	int sum = 0;
	while(e < r.size() && r[e].first < 0){
		sum += r[e].second;
		e++;
	}
	double ang;
	ang = -PI;
	while(1){
		if(sum == 0) break;
		if(e < r.size() && r[e].first < r[s].first + PI){
			sum += r[e].second;
			ang = r[e].first - PI + EPS;
			e++;
		} else if(r[s].first < 0){
			sum -= r[s].second;
			ang = r[s].first + EPS;
			s++;
		}
	}
	vector<pair<P, int> > a1;
	vector<pair<P, int> > a2;
	vector<pair<P, int> > b1;
	vector<pair<P, int> > b2;
	for(int i = 0; i < a.size(); i++){
		double g = (a[i].first-q).angle();
		if(g >= ang && g <= (ang + PI)){
			a1.push_back(a[i]);
		} else {
			a2.push_back(a[i]);
		}
	}
	for(int i = 0; i < b.size(); i++){
		double g = (b[i].first-q).angle();
		if(g >= ang && g <= (ang + PI)){
			b1.push_back(b[i]);
		} else {
			b2.push_back(b[i]);
		}
	}
	solve(a1, b1);
	solve(a2, b2);
}
int main(){
	int n;
	cin >> n;
	vector<pair<P, int> > a(n);
	vector<pair<P, int> > b(n);
	for(int j = 0; j < n; j++){
		cin >> a[j].first.x >> a[j].first.y;
		a[j].second = j;
	}
	for(int j = 0; j < n; j++){
		cin >> b[j].first.x >> b[j].first.y;
		b[j].second = j;
	}
	random_shuffle(a.begin(), a.end());
	random_shuffle(b.begin(), b.end());
	solve(a, b);
	for(int i = 0; i < n; i++){
		cout << gg[i] + 1 << endl;
	}
}