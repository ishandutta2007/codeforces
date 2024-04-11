#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

typedef complex<double>Point;

struct Segment{
    Point p1,p2;
    Segment(const Point &p1=Point(),const Point &p2=Point()):p1(p1),p2(p2){}
};

struct Circle{
    Point p;
    double r;
    Circle(const Point &p=Point(),double r=0.0):p(p),r(r){}
};

typedef Point Vector;
typedef Segment Line;
typedef vector<Point>Polygon;

const double PI=acos(-1);
const double EPS=1e-8;
const double INF=1e16;
const int COUNTER_CLOCKWISE=1;
const int CLOCKWISE=-1;
const int ONLINE_BACK=2;
const int ONLINE_FRONT=-2;
const int ON_SEGMENT=0;

inline double square(double a){return a*a;}
inline double norm(const Point &a){return square(a.real())+square(a.imag());}
inline double dot(const Point &a,const Point &b){return (conj(a)*b).real();}
inline double cross(const Point &a,const Point &b){return (conj(a)*b).imag();}
inline double toDeg(double t){return t/PI*180.0;}
inline double toRad(double t){return t/180.0*t;}
#define equals(a,b) (fabs((a)-(b))<EPS)

void getPoint(Point &p){
    double x,y;
    scanf("%lf%lf",&x,&y);
    p=Point(x,y);
}

void getSegment(Segment &s){
    getPoint(s.p1);
    getPoint(s.p2);
}

bool isOrthogonal(Vector a,Vector b){
    return equals(dot(a,b),0.0);
}

bool isOrthogonal(Point a1,Point a2,Point b1,Point b2){
    return isOrthogonal(a1-a2,b1-b2);
}

bool isOrthogonal(Segment s1,Segment s2){
    return isOrthogonal(s1.p1-s1.p2,s2.p1-s2.p2);
}

bool isParallel(Vector a,Vector b){
    return equals(cross(a,b),0.0);
}

bool isParallel(Point a1,Point a2,Point b1,Point b2){
    return isParallel(a1-a2,b1-b2);
}

bool isParallel(Segment s1,Segment s2){
    return isParallel(s1.p1-s1.p2,s2.p1-s2.p2);
}

Point project(Segment s,Point p){
    Vector base=s.p2-s.p1;
    double r=dot(p-s.p1,base)/norm(base);
    return s.p1+base*r;
}

Point reflection(Segment s,Point p){
    return p+(project(s,p)-p)*2.0;
}

int ccw(Point p0,Point p1,Point p2){
    Vector a=p1-p0;
    Vector b=p2-p0;
    if(cross(a,b)>EPS)return COUNTER_CLOCKWISE;
    if(cross(a,b)<-EPS)return CLOCKWISE;
    if(dot(a,b)<-EPS)return ONLINE_BACK;
    if(norm(a)<norm(b))return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool isIntersectSS(Point p1,Point p2,Point p3,Point p4){
    return ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0&&
            ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0;
}

bool isIntersectSS(Segment s1,Segment s2){
    return isIntersectSS(s1.p1,s1.p2,s2.p1,s2.p2);
}

Point getCrossPointSS(Segment s1,Segment s2){
    Vector base=s2.p2-s2.p1;
    double d1=abs(cross(base,s1.p1-s2.p1));
    double d2=abs(cross(base,s1.p2-s2.p1));

    double t=d1/(d1+d2);
    return s1.p1+(s1.p2-s1.p1)*t;
}

double getDistancePP(Point a,Point b){
    return abs(a-b);
}

double getDistanceLP(Line l,Point p){
    return fabs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));
}

double getDistanceLL(Line l,Line m){
    if(isParallel(l,m))return getDistanceLP(l,m.p1);
    return 0.0;
}

double getDistanceSP(Segment s,Point p){
    if(dot(s.p2-s.p1,p-s.p1)<0.0)return abs(p-s.p1);
    if(dot(s.p1-s.p2,p-s.p2)<0.0)return abs(p-s.p2);
    return getDistanceLP(s,p);
}

double getDistanceSS(Segment s1,Segment s2){
    if(isIntersectSS(s1,s2))return 0;
    return min(min(getDistanceSP(s1,s2.p1),getDistanceSP(s1,s2.p2)),
               min(getDistanceSP(s2,s1.p1),getDistanceSP(s2,s1.p2)));
}


signed main(){
    int N;cin>>N;
    Polygon g(N);
    rep(i,N)getPoint(g[i]);

    double mi=INF;
    rep(i,N){
        Segment s(g[(i+1)%N],g[(i-1+N)%N]);
        double tmp=getDistanceSP(s,g[i]);
        chmin(mi,tmp/2);
    }
    rep(i,N)rep(j,N)if(i!=j)chmin(mi,abs(g[i]-g[j])/2);
    printf("%.20f\n",mi);
    return 0;
}