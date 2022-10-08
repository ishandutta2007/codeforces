#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

const double eps = 1e-7;

struct Point {
    double x, y;    
    Point() {}
    Point(double x, double y) : x(x), y(y) {}
    
    Point operator+(Point p) {return Point(x+p.x,y+p.y); }
    Point operator-(Point p) {return Point(x-p.x,y-p.y); }
    Point operator*(double d) {return Point(x*d,y*d); }
    Point operator/(double d) {return Point(x/d,y/d); }
    double operator*(Point p) {return x*p.x+y*p.y; }
    
    double len2() { return x*x+y*y; }
    double len() { return sqrt(x*x+y*y); }
    
    Point normal() { return *this / len(); }
    Point vg() { return Point(-y,x); }
    
    bool operator<(Point p)const {
        if(abs(x-p.x) <= eps) {
            if(abs(y-p.y)<=eps) return false;
            else return y < p.y;    
        }   
        else return x < p.x;
    }
    
};

struct Line {
    double a, b, c;
    Line() {}
    Line(Point p, Point v) {
        v = v.normal();
        a = v.x;
        b = v.y;
        c = -(a*p.x+b*p.y);
    }   
};

#define DT(a,b,c,d) ((a)*(d)-(b)*(c))

double fx(Line a, Point p) {
    return a.a * p.x + a.b * p.y + a.c;
}

double afx(Line a, Point p) {
    return abs(fx(a,p));
}

int dir(Line a, Point p) {
    double d = fx(a,p);
    if(abs(d) <= eps) return 0;
    else if(d > 0) return 1;
    else return -1; 
}

int intersection(Line a, Line b, Point &P) {
    double dt = DT(a.a,a.b,b.a,b.b);
    double dx = DT(-a.c,a.b,-b.c,b.b);
    double dy = DT(a.a,-a.c,b.a,-b.c);
    if(abs(dt)<=eps) {
        if(abs(dx) <= eps) return 0;
        else return -1;
    }
    P = Point(dx/dt,dy/dt);
    return 1;
}

Point intersec(Line a, Line b) {
    Point r; intersection(a,b,r);
    return r;
}

Line createLine(Point a, Point b) {
    return Line(a, (b-a).vg()); 
}

double area(vector<Point> &v) {
    double s = 0;
    int j = v.size() - 1;
    Rep(i,v.size()) {
        s += (v[i].x + v[j].x) * (v[i].y - v[j].y);
        j = i;
    }
    return s;
}

int ptdt(Point a, Point b, Point c) {
    double d = (c.x-b.x) * (b.y-a.y) - (c.y-b.y) * (b.x-a.x);
    if(abs(d) <= eps) return 0;
    else if(d>0) return 1;
    else return -1;
}

vector<Point> go(vector<Point> v,int h){
    vector<Point> res;
    int n;
    Rep(i,v.size()){
        while((n=res.size()) >= 2 && ptdt(res[n-2],res[n-1],v[i])!=h)res.pop_back();
        res.pb(v[i]);
    }
    return res;
}

vector<Point> convex(vector<Point> a){
    sort(a.begin(),a.end());
    Point p1 = a[0];
    Point p2 = a[a.size()-1];
    vector<Point> up,down;
    up.pb(p1); down.pb(p1);
    for(int t,i=1;i+1<a.size();++i) {
        if((t=ptdt(p1,p2,a[i])) == -1) up.pb(a[i]);
        if(t==1)down.pb(a[i]);
    }
    up.pb(p2); down.pb(p2);
    vector<Point> tren=go(up,1);
    vector<Point> duoi=go(down,-1);
    vector<Point> res;
    Rep(i,tren.size())res.pb(tren[i]);
    for(int i=(int)duoi.size()-2;i>0;--i)res.pb(duoi[i]);
    return res;
}


int n, h, f;
int L[505], R[505];
Line ds[3030];
int nd;

bool cungphia(Line l, Point z, Point p) {
    int dp = dir(l,p);
    int dz = dir(l,z);
    if(dp == 0) return true;
    if(dp == dz) return true;
    return false;
}



double calc(int i, int j) {
    nd = 0;
    ds[nd++] = Line(Point(0,h), Point(0,1));
    ds[nd++] = Line(Point(0,-h), Point(0,1));
    ds[nd++] = createLine(Point(0,f), Point(L[i],h));
    ds[nd++] = createLine(Point(0,f), Point(R[i],h));
    ds[nd++] = createLine(Point(0,-f), Point(L[j],-h));
    ds[nd++] = createLine(Point(0,-f), Point(R[j],-h));
    
    vector<Point> v;
    Rep(u,nd) Rep(vv,u) {
        Point p;
        int t = intersection( ds[u], ds[vv], p);
        if(t == 1 && -h-eps <= p.y && p.y <= h+eps)  {
            if(cungphia(createLine(Point(0,f), Point(L[i],h)), Point(R[i],h), p)
            && cungphia(createLine(Point(0,f), Point(R[i],h)), Point(L[i],h), p)
            && cungphia(createLine(Point(0,-f), Point(L[j],-h)), Point(R[j],-h), p)
            && cungphia(createLine(Point(0,-f), Point(R[j],-h)), Point(L[j],-h), p)) {
            
                v.pb(p);
//              cout << "here" << endl;
            }
        }   
    }
    
    if(v.size() <= 2) return 0;
    
    v = convex(v);
    return abs(area(v)) / 2;
}   

/*


double dx[3000000];
double len[3000000];
int nx;

Line line[2][2][505];

double calc(double x) {
    Line l = Line(Point(x,0), Point(1,0));
    Rep(i,n) {
        Point p1, p2;
        int t1, t2;
        t1 = intersection(line[0][0][i], l, p1);
        t2 = intersection(line[0][1][i], l, p2);
//      if(t1 != 1) 
    }   
} */

int main() {
    
//  cout << ptdt(Point(0,0), Point(0,1), Point(1,1)) << endl;
    
    scanf("%d%d%d", &n, &h, &f);
    Rep(i,n) {
        scanf("%d%d", &L[i], &R[i]);    
    }
    
    double res = 0;
    
    Rep(i,n) {
        Line l1 = createLine(Point(0,f), Point(L[i],h));
        Line l2 = createLine(Point(0,f), Point(R[i],h));
        Line l = createLine(Point(0,-h), Point(1,-h));
        Point p1 = intersec(l1, l);
        Point p2 = intersec(l2, l);
        vector<Point> v;
        v.pb(Point(L[i],h));
        v.pb(Point(R[i],h));
        v.pb(p2);
        v.pb(p1);
        res += abs(area(v));
        
    }
    
    Rep(i,n)Rep(j,i+1) {
        double d = calc(i,j);
        // cout << d << endl;
        if(i == j) res -= d;
        else res -= 2 * d;  
    }
    
    printf("%.7f\n", res);
    
    /*
    ds[nd++] = Line(Point(0,h), Point(0,1));
    ds[nd++] = Line(Point(0,-h), Point(0,1));
    Rep(i,n) {
        line[0][0][i] = createLine(Point(0,f), Point(L[i],h));
        line[0][1][i] = createLine(Point(0,f), Point(R[i],h));
        line[1][0][i] = createLine(Point(0,-f), Point(L[i],h));
        line[1][1][i] = createLine(Point(0,-f), Point(R[i],h));
        
        ds[nd++] = createLine(Point(0,f), Point(L[i],h));
        ds[nd++] = createLine(Point(0,f), Point(R[i],h));
        ds[nd++] = createLine(Point(0,-f), Point(L[i],-h));
        ds[nd++] = createLine(Point(0,-f), Point(R[i],-h));
    }
    Rep(i,nd) For(j,i+1,nd-1) {
        Point p;
        int z = intersection(ds[i], ds[j], p);
        if(z == 1 && -h-eps <= p.y && p.y <= h+eps) {
            dx[nx++] = p.x;
        }
    }   
    sort(dx, dx+nx);
    Rep(i,nx) {
        len[i] = calc(dx[i]);   
    }
    double res = 0;
    for(int i=0;i+1<nx;++i) {
        res += (dx[i+1] - dx[i]) * (len[i] + len[i+1]) / 2;
    }
    printf("%.7f\n", res); */
    return 0;
}