#define _USE_MATH_DEFINES
#include<bits/stdc++.h>
using namespace std;

const int COUNTER_CLOCKWISE = +1;
const int CLOCKWISE = -1;
const int ONLINE_BACK = +2;
const int ONLINE_FRONT = -2;
const int ON_SEGMENT = 0;

const double EPS=1e-7;
const double INF=1e10;
const double PI=acos(-1);

typedef complex<double> Point;
typedef complex<double> Vector;
typedef vector<Point> Polygon;

struct Line
{
    Point a, b;
    Line() {}
    Line(const Point &_a, const Point &_b)
    {
        a = _a; b = _b;
    }
};

//Line
struct Segment
{
    Point a, b;
    Segment() {}
    Segment(const Point &_a, const Point &_b)
    {
        a = _a; b = _b;
    }
};

struct Circle
{
    Point c;
    double r;

    Circle() {}

    Circle(const Point &_c, const double &_r)
    {
        c = _c; r = _r;
    }
};

istream& operator >> (istream& is, Point &p)
{
    double x, y;
    is >> x >> y;
    p.real(x); p.imag(y);
    return is;
}

Segment ToSegment(const Line l)
{
    return Segment(l.a, l.b);
}

Line ToLine(const Segment s)
{
    return Line(s.a, s.b);
}

//==
bool equals(const double &a, const double &b);
bool equals(const Vector &a, const Vector &b);

//Point
bool comp(const Point &a, const Point &b);

//
double toRad(double a);
double toDeg(double a);

//
Point rotate(Point p,double d);


//
double dot(const Vector &a, const Vector &b);

//
double cross(const Vector &a, const Vector &b);

//
double GetArea(const Polygon &g);

//(O(1))
//:
int CCW(const Point &p0, const Point &p1, const Point &p2);

//(O(1))
bool IsOrthogonal(const Vector &a, const Vector &b);
bool IsOrthogonal(const Line &l1, const Line &l2);

//(O(1))
bool IsParallel(const Vector &a, const Vector &b);
bool IsParallel(const Line &l1, const Line &l2);

//(O(1))
Point Project(const Line &s, const Point &p);

//(O(1))
Point Reflect(const Line &s, const Point &p);

//
double GetDistance(const Line &l, const Point &p);

//
double GetDistance(const Segment &s, const Point &p);

//
double GetDistance(const Segment &s1, const Segment &s2);

//(O(1))
bool Intersects(const Line &l, const Segment &s);

//
bool Intersects(const Segment &l1, const Segment &l2);

//(O(1))
Point GetIntersection(const Line &l1, const Line &l2);

//
//
//  
vector<Point> GetIntersection(const Circle &c1, const Circle &c2);

//(O(n))
//
//  0:
//  1:
//  2:
int Contains(const Polygon &g, const Point &p);

//(O(n))
//
//  x->y
Polygon AndrewScan(Polygon &s);

//(O(n))
Polygon ConvexCut(const Polygon &g, const Line &l);


//-----------------------------------------------------------

bool equals(const double &a, const double &b)
{
    return abs(a - b) < EPS;
}

bool equals(const Vector &a, const Vector &b)
{
    return equals(a.real(), b.real()) && equals(a.imag(), b.imag());
}

bool comp(const Point &a, const Point &b)
{
    return equals(a.real(), b.real()) ? a.imag() < b.imag() : a.real() < b.real();
}

double dot(const Vector &a, const Vector &b)
{
    return a.real()*b.real() + a.imag()*b.imag();
}

double cross(const Vector &a, const Vector &b)
{
    return a.real()*b.imag() - a.imag()*b.real();
}

double GetArea(const Polygon &g)
{
    if(g.size()<3)return 0;
    double res = 0;
    for (int i = 1; i < g.size() - 1; i++)
    {
        res += cross(g[i] - g[0], g[i + 1] - g[0]);
    }
    return abs(res / 2);
}

int CCW(const Point &p0, const Point &p1, const Point &p2)
{
    Vector v1 = (Vector)(p1 - p0), v2 = p2 - p0;
    if (cross(v1, v2) > EPS) return COUNTER_CLOCKWISE;
    if (cross(v1, v2) < -EPS) return CLOCKWISE;
    if (dot(v1, v2) < -EPS) return ONLINE_BACK;
    if (abs(v1) < abs(v2)) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool IsOrthogonal(const Vector &a, const Vector &b)
{
    return equals(dot(a, b), 0.0);
}
bool IsOrthogonal(const Line &l1, const Line &l2)
{
    return equals(dot(l1.b - l1.a, l2.b - l2.a), 0.0);
}

bool IsParallel(const Vector &a, const Vector &b)
{
    return equals(cross(a, b), 0.0);
}
bool IsParallel(const Line &l1, const Line &l2)
{
    return equals(cross(l1.b - l1.a, l2.b - l2.a), 0.0);
}

Point Project(const Line &s, const Point &p)
{
    Vector v1 = s.b - s.a;
    Vector v2 = p - s.a;
    double r = dot(v1, v2) / norm(v1);
    return s.a + v1 * r;
}

Point Reflect(const Line &s, const Point &p)
{
    return p + (Project(s, p) - p) * 2.0;
}

double GetDistance(const Line &l, const Point &p)
{
    return abs(cross(l.a - l.b, p - l.a) / abs(l.b - l.a));
}

double GetDistance(const Segment &s, const Point &p)
{
    if (dot(s.b - s.a, p - s.a) < 0.0) return abs(p - s.a);
    if (dot(s.a - s.b, p - s.b) < 0.0) return abs(p - s.b);
    return GetDistance(ToLine(s), p);
}

double GetDistance(const Segment &s1, const Segment &s2)
{
    if (Intersects(s1, s2)) return 0.0;
    return min(min(GetDistance(s1, s2.a), GetDistance(s1, s2.b)),
               min(GetDistance(s2, s1.a), GetDistance(s2, s1.b)));
}

bool Intersects(const Line &l, const Segment &s)
{
    return CCW(l.a, l.b, s.a)*CCW(l.a, l.b, s.b) != 1;
}

bool Intersects(const Segment &l1, const Segment &l2)
{
    return CCW(l1.a, l1.b, l2.a)*CCW(l1.a, l1.b, l2.b) <= 0 &&
        CCW(l2.a, l2.b, l1.a)*CCW(l2.a, l2.b, l1.b) <= 0;
}

Point GetIntersection(const Line &l1, const Line &l2)
{
    Vector a1 = l1.b - l1.a, a2 = l2.b - l2.a;
    Vector b1 = l2.a - l1.a, b2 = l1.a - l2.b;
    double s1 = cross(a1, b1) / 2, s2 = cross(a1, b2) / 2;
    return Point(l2.a.real() + a2.real()*s1 / (s1 + s2), l2.a.imag() + a2.imag()*s1 / (s1 + s2));
}

vector<Point> GetIntersection(const Circle &c1, const Circle &c2)
{
    vector<Point> res;
    double d, a, t;
    d = sqrt(norm((c2.c - c1.c)));
    if (d < abs(c1.r - c2.r) || c1.r + c2.r < d) return res; //0
    a = acos((c1.r*c1.r + d*d - c2.r*c2.r) / (2 * c1.r*d));
    t = atan2(c2.c.imag() - c1.c.imag(), c2.c.real() - c1.c.real());
    res.push_back(Point(c1.c.real() + c1.r*cos(t + a), c1.c.imag() + c1.r*sin(t + a)));
    res.push_back(Point(c1.c.real() + c1.r*cos(t - a), c1.c.imag() + c1.r*sin(t - a)));
    if (equals(res[0], res[1])) res.pop_back(); //1
    return res;
}

int Contains(const Polygon &g, const Point &p)
{
    Line l = Line(p, Point(INF, p.imag()));
    int cnt = 0, n = g.size();
    for (int i = 0; i < n; i++)
    {
        Vector a = g[i] - p;
        Vector b = g[(i + 1) % n] - p;
        if (CCW(g[i], g[(i + 1) % n], p) == 0) return 2; //
        if (a.imag() > b.imag()) swap(a, b);
        if (a.imag() <= EPS && EPS < b.imag() && cross(a, b) > EPS) cnt++;
    }
    if ((cnt & 1) == 1) return 1; //
    return 0; //
}

Polygon AndrewScan(Polygon &s)
{
    if (s.size() <= 2) return s;
    sort(s.begin(), s.end(), comp);
    Polygon g;
    for (int i = 0; i < s.size(); i++)
    {
        //CCW==COUNTER_CLOCKWISE
        for (int n = g.size(); n >= 2 && CCW(g[n - 2], g[n - 1], s[i]) != CLOCKWISE; n--)
        {
            g.pop_back();
        }
        g.push_back(s[i]);
    }
    for (int i = s.size() - 2; i >= 0; i--)
    {
        for (int n = g.size(); CCW(g[n - 2], g[n - 1], s[i]) != CLOCKWISE; n--)
        {
            g.pop_back();
        }
        g.push_back(s[i]);
    }
    reverse(g.begin(), g.end());
    g.pop_back();
    return g;
}

Polygon ConvexCut(const Polygon &g, const Line &l)
{
    Polygon res;
    for (int i = 0; i < g.size(); i++)
    {
        Segment s = Segment(g[i], g[(i + 1) % g.size()]);
        if (CCW(l.a, l.b, s.a) != -1) res.push_back(s.a);
        if (CCW(l.a, l.b, s.a)*CCW(l.a, l.b, s.b) == -1)
            res.push_back(GetIntersection(l, ToLine(s)));
    }
    return res;
}


//Latte
double toRad(double a){return a/180.0*PI;}
double toDeg(double a){return a*180.0/PI;}
Point rotate(Point p,double d){
    return Point(p.real()*cos(d)-p.imag()*sin(d),p.real()*sin(d)+p.imag()*cos(d));
}

//Malta

#define rep(i,n) for(int i=0;i<(n);i++)

void get(Point &p){
    double x,y;scanf("%lf%lf",&x,&y);
    p=Point(x,y);
}

int N;
Point p;
Polygon g;

int main(){
    scanf("%d",&N);
    get(p);
    g.resize(N);
    for(int i=0;i<N;i++){
        get(g[i]);
    }

    if(g.size()>=3&&CCW(g[0],g[1],g[2])==CLOCKWISE){
        reverse(g.begin(),g.end());
    }

    if(g.size()>=3&&Contains(g,p)){
        printf("%.20lf\n",0.0);
        return 0;
    }

    double ma=0,mi=1001001001001001001.0;
    for(int i=0;i<N;i++){
        double dx=g[i].real()-p.real(),dy=g[i].imag()-p.imag();
        double d=dx*dx+dy*dy;
        ma=max(ma,d);
        mi=min(mi,d);

        Segment S(g[i],g[(i+1)%N]);
        d=GetDistance(S,p);
        ma=max(ma,d*d);
        mi=min(mi,d*d);
    }
    printf("%.20lf\n",(ma-mi)*PI);
    return 0;
}