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

typedef Point<ll> P;
pair<vi, vi> ulHull(const vector<P>& S) {
	vi Q(sz(S)), U, L;
	iota(all(Q), 0);                                                                                                                                                                         
	sort(all(Q), [&S](int a, int b){ return S[a] < S[b]; }); 
	trav(it, Q) {
#define ADDP(C, cmp) while (sz(C) > 1 && S[C[sz(C)-2]].cross(\
	S[it], S[C.back()]) cmp 0) C.pop_back(); C.push_back(it);
		ADDP(U, <=); ADDP(L, >=);
	}   
	return {U, L}; 
}

vi convexHull(const vector<P>& S) {
	vi u, l; tie(u, l) = ulHull(S);
	if (sz(S) <= 1) return u;
	if (S[u[0]] == S[u[1]]) return {0};
	l.insert(l.end(), u.rbegin()+1, u.rend()-1);
	return l;
}

const LL MOD = 1001000027;

vector<LL> get_dist(vector<P> p1){
	vector<LL> v;
	for(int i = 0; i < p1.size(); i++){
		P a = p1[i];
		P b = p1[(i+1) % p1.size()];
		v.push_back((a-b).dist2());
	}
	return v;
}

vector<LL> get_dist2(vector<P> p1){
	vector<LL> v;
	for(int i = 0; i < p1.size(); i++){
		P a = p1[(i - 1 + (int)p1.size()) % (int)p1.size()];
		P b = p1[(i + 1) % (int)p1.size()];
		v.push_back((a-b).dist2());
	}
	return v;
}

int solve(vector<P> p1, vector<P> p2){
	if(p1.size() != p2.size()) return 0;
	LL n = p1.size();
	if(n <= 1) return 1;
	vector<LL> d[2] = {get_dist(p1), get_dist(p2)};
	vector<LL> e[2] = {get_dist2(p1), get_dist2(p2)};
	LL h[2];
	LL q[2];
	h[0] = h[1] = 0;
	q[0] = q[1] = 0;
	for(LL i = 0; i < n; i++){
		for(int z = 0; z < 2; z++){
			h[z] *= 3;
			h[z] += d[z][i];
			h[z] %= MOD;
			q[z] *= 7;
			q[z] += e[z][i];
			q[z] %= MOD;
		}
	}
	LL p3 = 1;
	LL p7 = 1;
	for(LL i = 0; i < n; i++){
		p3 = (p3 * 3) % MOD;
		p7 = (p7 * 7) % MOD;
	}
	p3--; p7--;
	for(LL i = 0; i < n; i++){
		if(h[0] == h[1] && q[0] == q[1]){
			// check
			int ok = 1;
			for(int j = 0; j < n; j++){
				if(d[0][j] != d[1][(i+j) % n] || e[0][j] != e[1][(i+j) % n]){
					ok = 0;
					break;
				}
			}
			if(ok) return 1;
		}
		h[1] = (h[1] * 3) % MOD;
		q[1] = (q[1] * 7) % MOD;
		h[1] -= p3 * (d[1][i] % MOD);
		h[1] %= MOD;

		q[1] -= p7 * (e[1][i] % MOD);
		q[1] %= MOD;

		if(h[1] < 0) h[1] += MOD;
		if(q[1] < 0) q[1] += MOD;
	}
	return 0;
}

int main(){
	int n[2];
	cin >> n[0] >> n[1];
	vector<P> pts[2];
	for(int j = 0; j < 2; j++){
		pts[j].resize(n[j]);
		for(int i = 0; i < n[j]; i++){
			cin >> pts[j][i].x >> pts[j][i].y;
		}
		vi z = convexHull(pts[j]);
		vector<P> newpts;
		for(int i : z){
			newpts.push_back(pts[j][i]);
		}
		pts[j] = newpts;
	}
	if(solve(pts[0], pts[1])){
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}