#include <bits/stdc++.h>
using namespace std;
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
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
};


typedef Point<LL> P;
vector<P> r;
vector<double> ang;
bool cmp(const int a, const int b){
    return ang[a] < ang[b];
}

int main(){
    int n;
    cin >> n;
    vector<P> s(n);
    for(int i = 0; i < n; i++){
        cin >> s[i].x >> s[i].y;
    }
    LL ans = 0;
    for(int i = 0; i < n; i++){
        r.clear();
        ang.clear();
        for(int j = 0; j < n; j++){
            if(j != i) r.push_back(s[j] - s[i]);
        }
        vector<int> stuff;
        for(int j = 0; j < r.size(); j++){
            stuff.push_back(j);
            ang.push_back(r[j].angle());
        }
        sort(stuff.begin(), stuff.end(), cmp);
        int z = 0;
        for(int j = 0; j < r.size(); j++){
            if(z == j) z = (z + 1) % r.size();
            while(j != z && r[stuff[j]].cross(r[stuff[z]]) > 0){
                z = (z + 1) % r.size();
            }
            LL z1 = z - j - 1;
            if(z1 < 0) z1 += r.size();
            LL z2 = r.size() - 1 - z1;
            ans += z1 * (z1-1) * z2 * (z2-1) / 4;
        }
    }
    ans /= 2;
    cout << ans << '\n';
}