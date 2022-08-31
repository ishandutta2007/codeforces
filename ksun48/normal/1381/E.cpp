#include <bits/stdc++.h>
using namespace std;

using ld = long double;

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
using Pl = Point<ll>;
using P = Point<ld>;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

template<class P>
pair<int, P> lineInter(P s1, P e1, P s2, P e2) {
	auto d = (e1 - s1).cross(e2 - s2);
	if (d == 0) // if parallel
		return {-(s1.cross(e1, s2) == 0), P(0, 0)};
	auto p = s2.cross(e1, e2), q = s2.cross(e2, s1);
	return {1, (s1 * p + e1 * q) / d};
}

vector<P> cut(const vector<P>& poly, P s, P e) {
	vector<P> res;
	rep(i,0,sz(poly)) {
		P cur = poly[i], prev = i ? poly[i-1] : poly.back();
		bool side = s.cross(e, cur) < 0;
		if (side != (s.cross(e, prev) < 0))
			res.push_back(lineInter(s, e, cur, prev).second);
		if (side)
			res.push_back(cur);
	}
	return res;
}


int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int n;
	cin >> n;
	int q;
	cin >> q;
	vector<Pl> pts(n);
	for(int i = 0; i < n; i++){
		cin >> pts[i].x >> pts[i].y;
	}
	ld tot = 0;
	for(int i = 0; i < n; i++) tot += pts[i].cross(pts[(i+1)%n]);
	if(tot < 0) reverse(pts.begin(), pts.end());
	int h = 0, l = 0;
	for(int i = 0; i < n; i++){
		if(pts[i].y > pts[h].y) h = i;
		if(pts[i].y < pts[l].y) l = i;
	}
	vector<Pl> b1, b2;
	for(int r = l; ; r = (r + n- 1) % n){
		b1.push_back(pts[r]);
		if(r == h) break;
	}
	for(int r = l; ; r = (r + 1) % n){
		b2.push_back(pts[r]);
		if(r == h) break;
	}
	ll cy = b1.front().y;
	int i1 = 0;
	int i2 = 0;

	ld sep_area = 0;
	vector<pair<ld, vector<ld> > > dels;
	while(cy != b1.back().y){
		ll ny = min(b1[i1+1].y, b2[i2+1].y);
		assert(ny > cy);
		ld botx1 = ld(cy - b1[i1].y) / (b1[i1+1].y - b1[i1].y) * (b1[i1+1].x - b1[i1].x) + b1[i1].x;
		ld topx1 = ld(ny - b1[i1].y) / (b1[i1+1].y - b1[i1].y) * (b1[i1+1].x - b1[i1].x) + b1[i1].x;
		ld botx2 = ld(cy - b2[i2].y) / (b2[i2+1].y - b2[i2].y) * (b2[i2+1].x - b2[i2].x) + b2[i2].x;
		ld topx2 = ld(ny - b2[i2].y) / (b2[i2+1].y - b2[i2].y) * (b2[i2+1].x - b2[i2].x) + b2[i2].x;

		ld carea = (ny - cy) * (botx2 - botx1 + topx2 - topx1);
		sep_area += carea;
		vector<ld> xp = {botx1, topx1, botx2, topx2};
		vector<ld> br;
		for(int i = 0; i < 4; i++){
			for(int j = 0; j <= i; j++){
				br.push_back((xp[i] + xp[j]) / 2);
			}
		}
		sort(br.begin(), br.end());
		ld A = 0, B = 0, C = 0;
		for(int i = 0; i + 1 < (int)br.size(); i++){
			ld spl = br[i];
			ld spr = br[i+1];
			ld spm = (spl + spr) / 2;
			if(abs(spl - spr) < 1e-9) continue;

			auto area = [&](ld x) -> ld {
				vector<P> poly = {P(botx1, cy), P(botx2, cy), P(topx2, ny), P(topx1, ny)};
				poly = cut(poly, P(x + x - botx2, cy), P(x + x - topx2, ny));
				poly = cut(poly, P(x + x - topx1, ny), P(x + x - botx1, cy));
				ld a = 0;
				for(int i = 0; i < (int)poly.size(); i++){
					a += poly[i].cross(poly[(i+1)%poly.size()]);
				}
				return a / 2;
			};
			ld fl = area(spl);
			ld fm = area(spm);
			ld fr = area(spr);
			// cerr << "HERE ";
			// cerr << fl << " " << fm << " " << fr << endl;
			ld sA = (fr + fl - fm - fm) / 2; 
			ld sB = (fr - fl) / 2;
			ld sC = fm;

			ld G = 1 / (spr - spm);
			ld H = -spm * G;
			ld nA = sA * G * G, nB = 2 * sA * G * H + sB * G, nC = sA * H * H + sB * H + sC;
			// cerr << spl << " " << spr << " " << nA << " " << nB << " " << nC << endl;
			// cerr << nA * spl * spl + nB * spl + nC << " " ;
			// cerr << nA * spm * spm + nB * spm + nC << " " ;
			// cerr << nA * spr * spr + nB * spr + nC << " " ;
			// cerr << endl;
			dels.push_back({spl, {nA - A, nB - B, nC - C}});
			A = nA, B = nB, C = nC;
		}
		dels.push_back({br.back(), {-A, -B, -C}});
		cy = ny;
		if(b1[i1+1].y == cy) i1++;
		if(b2[i2+1].y == cy) i2++;
	}
	sort(dels.begin(), dels.end());
	vector<ll> query(q);
	for(ll& x : query) cin >> x;
	vector<ld> ans(q);
	vector<int> ord(q);
	for(int i = 0; i < q; i++) ord[i] = i;
	sort(ord.begin(), ord.end(), [&](int a, int b) -> bool { return query[a] < query[b]; } );
	ld cA = 0, cB = 0, cC = 0;
	int di = 0;
	for(int i : ord){
		while(di < (int)dels.size() && dels[di].first < query[i]){
			cA += dels[di].second[0];
			cB += dels[di].second[1];
			cC += dels[di].second[2];
			di++;
		}
		ans[i] = cA * query[i] * query[i] + cB * query[i] + cC;
	}
	cout << fixed << setprecision(12);
	for(ld r : ans){
		cout << (sep_area - r)/2 << '\n';
	}
}