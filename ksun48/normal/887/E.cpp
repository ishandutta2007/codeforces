#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

#define EPS 0.0

typedef long double ld;
#define double ld

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
    P inv() const{
        return P(x/dist2(), y/dist2());
    }
};

template <class P>
pair<P,P> circleTangents(const P &p, const P &c, double r) {
    P a = p-c;
    double x = r*r/a.dist2(), y = sqrt(x-x*x);
    return make_pair(c+a*x+a.perp()*y, c+a*x-a.perp()*y);
}

typedef Point<double> pd;

typedef Point<double> P;
double ccRadius(const P& A, const P& B, const P& C) {
    return (B-A).dist()*(C-B).dist()*(A-C).dist()/
            abs((B-A).cross(C-A))/2;
}
P ccCenter(const P& A, const P& B, const P& C) {
    P b = C-A, c = B-A;
    return A + (b*c.dist2()-c*b.dist2()).perp()/b.cross(c)/2;
}

int main(){
    double a,b;
    cin >> a >> b;
    pd p1(a,b);
    cin >> a >> b;
    pd p2(a,b);
    p2 = p2 - p1;
    int n;
    cin >> n;

    double z = p2.angle();
    p2 = p2.rotate(-z);

    p2 = p2.inv();

    vector<pair<double,double> > g;
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        pd px(a,b);
        px = px - p1;
        px = px.rotate(-z);

        double r;
        cin >> r;

        pd new1 = px + P(r,0);
        pd new2 = px + P(-r,0);
        pd new3 = px + P(0,r);

        new1 = new1.inv();
        new2 = new2.inv();
        new3 = new3.inv();

        double newradius = ccRadius(new1, new2, new3);
        pd newcenter = ccCenter(new1, new2, new3);

        pair<pd,pd> ans = circleTangents(p2,newcenter, newradius);
        double ang1 = P(ans.first-p2).angle();
        double ang2 = P(ans.second-p2).angle();
        if(ang1 < 0 || ang2 < 0){
            ang1 += 2.0*asin(1.0);
            ang2 += 2.0*asin(1.0);
        }
        g.push_back(make_pair(ang1, ang2));
    }
    g.push_back(make_pair(0,0));
    g.push_back(make_pair(2*asin(1.0),2*asin(1.0)));
    sort(g.begin(), g.end());
    vector<double> poss;
    double curmax = 0.0;
    for(int i = 0; i + 1 < g.size(); i++){
        curmax = max(curmax, g[i].second);
        if(curmax <= g[i+1].first + EPS){
            // ok
            poss.push_back(curmax);
            if(curmax <= asin(1.0) + EPS){
                if(asin(1.0) + EPS <= g[i+1].first){
                    poss.push_back(asin(1.0));
                }
            }
            poss.push_back(g[i+1].first);
        }
    }

    //p2 = p2.inv();
    double bestang = 100.0;
    for(int i = 0; i < poss.size(); i++){
        bestang = min(bestang, abs(asin(1.0) - poss[i]));
    }
    double dist = p2.dist()*cos(bestang);
    double diam = 1.0/dist;
    printf("%.15Lf\n", diam/2.0);
}