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
typedef long long LL;

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
	
	double angle() const { return atan2(y,x); }
	P unit() const { return *this/dist(); }
	P perp() const { return P(-y, x); }
	P normal() const { return perp().unit(); }
	P rotate(double a) const { 
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};

typedef Point<ll> P;
pair<vi, vi> ulHull(const vector<P> & S) {
	vi Q(sz(S)), U, L;
	iota(all(Q), 0);
	sort(all(Q), [&S](int a, int b){ return S[a] < S[b]; });
	trav(it, Q) {
#define ADDP(C, cmp) while (sz(C) > 1 && S[C[sz(C)-2]].cross(S[it], S[C.back()]) cmp 0) C.pop_back(); C.push_back(it);
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

vector<P> pa;
vector<P> pb;
vector<int> degb;

void solve(vector<int>& cura, vector<int>& curb){
	//cout << cura.size() << " " << curb.size() << '\n';
	if(cura.size() + curb.size() <= 1) return;
	{
		vector<int> s;
		{
			vector<P> pts;
			for(int x : cura){
				pts.push_back(pa[x]);
			}
			for(int x : curb){
				pts.push_back(pb[x]);
			}
			s = convexHull(pts);
		}
		int hasred = 0;
		int hasblue = 0;
		for(int i = 0; i < s.size(); i++){
			if(s[i] < cura.size()){
				hasred = 1;
			} else {
				hasblue = 1;
			}
		}
		for(int i = 0; i < s.size(); i++){
			if(s[i] < cura.size() && s[(i+1) % s.size()] >= cura.size()){
				int ai = cura[s[i]];
				int bi = curb[s[(i+1) % s.size()] - cura.size()];
				cout << bi + 1 << " " << ai + 1 << '\n';
				if(degb[bi] == 1){
					vector<int> newb;
					degb[bi]--;
					for(int b : curb){
						if(b == bi) continue;
						newb.push_back(b);
					}
					s.clear();
					s.shrink_to_fit();
					curb.clear();
					curb.shrink_to_fit();
					solve(cura, newb);
					return;
				} else {
					vector<int> newa;
					degb[bi]--;
					for(int a : cura){
						if(a == ai) continue;
						newa.push_back(a);
					}
					s.clear();
					s.shrink_to_fit();
					cura.clear();
					cura.shrink_to_fit();
					solve(newa, curb);
					return;
				}
			}
		}
		assert(hasred == 0 || hasblue == 0);
	}
	vector<pair<P, int> > spoints;
	for(int a : cura){
		spoints.emplace_back(pa[a], a);
	}
	for(int b : curb){
		spoints.emplace_back(pb[b], pa.size() + b);
	}
	sort(spoints.begin(), spoints.end());
	int psum = 0;
	for(int i = 0; i < spoints.size(); i++){
		int newpsum = psum;
		if(spoints[i].second < pa.size()){
			newpsum -= 1;
		} else {
			newpsum += degb[spoints[i].second - pa.size()] - 1;
		}
		if(i > 0 && i + 1 < spoints.size()){
			if(psum >= 0 && newpsum < 0){
				vector<int> lefta, righta, leftb, rightb;
				for(int j = 0; j <= i; j++){
					if(spoints[j].second < pa.size()){
						lefta.push_back(spoints[j].second);
					} else {
						int b = spoints[j].second - pa.size();
						leftb.push_back(b);
					}
				}
				for(int j = i; j < spoints.size(); j++){
					if(spoints[j].second < pa.size()){
						righta.push_back(spoints[j].second);
					} else {
						int b = spoints[j].second - pa.size();
						rightb.push_back(b);
					}
				}
				cura.clear();
				cura.shrink_to_fit();
				curb.clear();
				curb.shrink_to_fit();
				spoints.clear();
				spoints.shrink_to_fit();
				solve(lefta, leftb);
				solve(righta, rightb);
				return;
			}
			if(psum < 0 && newpsum >= 0){
				vector<int> lefta, righta, leftb, rightb;
				for(int j = 0; j <= i; j++){
					if(spoints[j].second < pa.size()){
						lefta.push_back(spoints[j].second);
					} else {
						int b = spoints[j].second - pa.size();
						leftb.push_back(b);
					}
				}
				for(int j = i; j < spoints.size(); j++){
					if(spoints[j].second < pa.size()){
						righta.push_back(spoints[j].second);
					} else {
						int b = spoints[j].second - pa.size();
						rightb.push_back(b);
					}
				}
				int b = spoints[i].second - pa.size();
				int ldeg = -psum;
				int rdeg = newpsum + 1;
				assert(ldeg + rdeg == degb[b]);

				cura.clear();
				cura.shrink_to_fit();
				curb.clear();
				curb.shrink_to_fit();
				spoints.clear();
				spoints.shrink_to_fit();

				degb[b] = ldeg;
				solve(lefta, leftb);
				degb[b] = rdeg;
				solve(righta, rightb);
				return;				
			}
		}
		psum = newpsum;
	}
}

int main(){
	cin.sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int a, b;
		cin >> a >> b;
		degb.resize(b);
		for(int i = 0; i < b; i++){
			cin >> degb[i];
		}
		pa.resize(a);
		pb.resize(b);
		for(int i = 0; i < a; i++){
			cin >> pa[i].x >> pa[i].y;
		}
		for(int i = 0; i < b; i++){
			cin >> pb[i].x >> pb[i].y;
		}
		cout << "YES" << '\n';
		vector<int> cura;
		vector<int> curb;
		for(int i = 0; i < a; i++){
			cura.push_back(i);
		}
		for(int i = 0; i < b; i++){
			curb.push_back(i);
		}
		solve(cura, curb);
	}
}