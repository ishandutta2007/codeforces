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

using ld = long double;
using P = Point<ld>;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	{
		int n, m;
		cin >> n >> m;
	}
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ld A = ld(rng()) / pow(2, 32);
	ld B = ld(rng()) / pow(2, 32);
	assert(A < 1 && A > 0);
	assert(B < 1 && B > 0);
	cout << fixed << setprecision(14);
	for(ld x : {A, B}){
		vector<P> poly;
		for(int j = -2; j <= 102; j += 2){
			poly.push_back(P(-2, x + j));
			poly.push_back(P(102, x + j));
			poly.push_back(P(102, x + j + 1));
			poly.push_back(P(-2, x + j + 1));
		}
		poly.push_back(P(-100, 200));
		poly.push_back(P(-100, -100));
		cout << "? " << poly.size() << '\n';
		for(P p : poly){
			cout << p.y << ' ' << p.x << '\n';
		}
		cout << "? " << poly.size() << '\n';
		for(P p : poly){
			cout << p.x << ' ' << p.y << '\n';
		}
	}
	cout << flush;
	ld res_Ax, res_Ay, res_Bx, res_By;
	cin >> res_Ax >> res_Ay >> res_Bx >> res_By;
	auto getx = [&](ld res_A, ld res_B) -> ld {
		ld best = 100;
		ld x = -1;
		for(ld r : {res_A, 1 - res_A}){
			for(ld s : {res_B, 1 - res_B}){
				ld cost = s + B - r - A;
				while(cost >= 1) cost -= 1;
				while(cost < 0) cost += 1;
				cost = min(cost, 1 - cost);
				if(cost < best){
					best = cost;
					x = s + B;
				}
			}
		}
		while(x >= 1) x -= 1;
		while(x < 0) x += 1;
		assert(best < 1e-10);
		return x;
	};
	ld x = getx(res_Ax, res_Bx) - 1;
	ld y = getx(res_Ay, res_By) - 1;
	P offset(x, y);

	const int N = 105;
	int M1 = 1000;
	int M2 = 1000000;
	vector<P> poly;
	for(int j = 0; j < N; j++){
		poly.push_back(P(0, j));
		poly.push_back(P(N, j));
		ld plus = ld(j + 1) / ld(M1);
		ld tiny = ld(1) / ld(M2);
		poly.push_back(P(N, j + plus + tiny));
		poly.push_back(P(0, j + plus));
	}
	poly.push_back(P(-100, 200));
	poly.push_back(P(-100, -100));
	cout << "? " << poly.size() << '\n';
	for(P p : poly){
		p = p + offset;
		cout << p.x << ' ' << p.y << '\n';
	}
	cout << flush;
	ld res;
	cin >> res;
	int dy = int(res * M1) - 1;
	ld extra = (res - (dy + 1) / ld(M1)) * M2 * N;
	int dx = int(extra);
	assert(dx >= 0 && dx < N);
	assert(dy >= 0 && dy < N);
	assert(abs(extra - dx - 0.5) < 1e-5);
	ld area = ld(dy + 1) / ld(M1) + (ld(dx) + 0.5) / N / M2;
	assert(abs(area - res) < 1e-11);
	cout << "! ";
	cout << (x + dx) << ' ' << (y + dy) << '\n';
	cout << flush;
}