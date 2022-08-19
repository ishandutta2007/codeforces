#include <bits/stdc++.h>
using namespace std;
 
using ld = double;
 
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
	ld dist() const { return sqrt((ld)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	ld angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(ld a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};
 
 
using P = Point<ld>;
 
bool cmp(const P a, const P b){
	return a.angle() < b.angle();
}
 
ld get(ld x){
	return P(1, 0).rotate(x).angle();
}
 
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<P> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i].x >> a[i].y;
if(a[i].x == 0 && a[i].y == 0){
cout << 0 << '\n'; return 0;}
	}
	sort(a.begin(), a.end(), cmp);
 
	ld s = 1e-8;
	ld e = 1e12;
	for(int i = 0; i < n; i++){
		e = min(e, a[i].dist() * (1 - 1e-8));
	}
	for(int _ = 0; _ < 50; _++){
		ld r = (s + e) / 2.0;
		vector<pair<ld, pair<int,int> > > f;
		for(int i = 0; i < n; i++){
			ld spr = acos(r / a[i].dist());
			f.emplace_back(get(a[i].angle() - spr), pair<int,int>({i, 0}));
			f.emplace_back(get(a[i].angle() + spr), pair<int,int>({i, 1}));
		}
		sort(f.begin(), f.end());
 
		int tot = (int)f.size();
		assert(tot == 2 * n);
 
		vector<pair<int,int> > pos(n);
		for(int i = 0; i < (int)f.size(); i++){
			if(f[i].second.second == 0){
				pos[f[i].second.first].first = i;
			} else {
				pos[f[i].second.first].second = i;
			}
		}
		sort(pos.begin(), pos.end());
		for(int i = 0; i < (int)pos.size(); i++){
			if(pos[i].second < pos[i].first) pos[i].second += tot;
		}
		vector<pair<int,int> > newpos;
		for(pair<int,int> q : pos){
			while(!newpos.empty() && q.second < newpos.back().second){
				newpos.pop_back();
			}
			newpos.push_back(q);
		}
		while(newpos.front().second + tot < newpos.back().second){
			newpos.pop_back();
		}
 
		/*cout << r << '\n';
		for(pair<int,int> q : newpos){
			cout << q.first<< " " << q.second << '\n';
		}
		cout << '\n';*/
 
		const int MAXJ = 20;
 
		int x = (int)newpos.size();
		vector<vector<int> > jump(MAXJ, vector<int>(x, 0));
		int jlen = 0;
		int ZZ = 0;
		int cur = 0;
		for(int i = 0; i < x; i++){
			while(jlen == 0 || (jlen < x && (newpos[cur].first + ZZ) < newpos[i].second)){
				jlen += 1;
				cur += 1;
				if(cur == x){
					cur = 0;
					ZZ = tot;
				}
			}
			jump[0][i] = jlen;
			jlen -= 1;
		}
		for(int j = 1; j < MAXJ; j++){
			for(int i = 0; i < x; i++){
				jump[j][i] = min(x, jump[j-1][(i + jump[j-1][i]) % x] + jump[j-1][i]);
			}
		}
		vector<int> curlen(x, 0);
		int ans = 0;
		for(int j = MAXJ - 1; j >= 0; j--){
			bool done = false;
			for(int i = 0; i < x; i++){
				if(curlen[i] + jump[j][(i + curlen[i]) % x] >= x) done = true;
			}
			if(!done){
				ans += (1 << j);
				for(int i = 0; i < x; i++){
					curlen[i] = curlen[i] + jump[j][(i + curlen[i]) % x];
				}
			}
		}
		ans += 1;
		if(ans <= m){
			s = r;
		} else {
			e = r;
		}
	}
	ld ans = (s + e) / 2.0;
	cout << fixed << setprecision(12);
	cout << ans << '\n';
}