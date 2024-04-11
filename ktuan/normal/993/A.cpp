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
using namespace std;

#define Rep(i,n) for(int i=0;i<(n);++i)
#define Repd(i,n) for(int i=((int)(n))-1;i>=0;--i)
#define For(i,a,b) for(int i=(a);i<=(b);++i)
#define Ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fi first
#define se second
#define pb push_back
#define MP make_pair

typedef pair<int,int> PII;
typedef vector<int> VI;

#define debug cout << "Here " << __LINE__ << endl;
template <typename T1, typename T2> ostream& operator<<(ostream &os, pair<T1, T2> p) { os << "(" << p.fi << ", " << p.se << ")"; return os; }
template <typename T> ostream& operator<<(ostream &os, vector<T> v) { Rep(i, v.size()) os << v[i] << " "; os << endl; return os; }
void verify(bool condition) { if (!condition) cerr << "WRONG WRONG" << endl; }

struct Point {
    double x, y;
    Point(): x(0), y(0) {}
    Point(double x, double y): x(x), y(y) {} 
    Point operator+(Point p) {
        return Point(x + p.x, y + p.y);
    }
    Point operator-(Point p) {
        return Point(x - p.x, y - p.y);
    }
    Point operator*(double d) {
        return Point(x * d, y * d);
    }
    Point operator/(double d) {
        return Point(x / d, y / d);
    }
};

Point a[4];
Point b[4];

double inf = 10000;
const double eps = 1e-7;

bool insidea(Point *a, Point p) {
    double minx = inf, maxx = -inf;
    double miny = inf, maxy = -inf;
    Rep(i, 4) {
        minx = min(minx, a[i].x);
        miny = min(miny, a[i].y);
        
        maxx = max(maxx, a[i].x);
        maxy = max(maxy, a[i].y);
    }
    return minx <= p.x + eps && p.x - eps <= maxx && miny <= p.y + eps && p.y - eps <= maxy;
}

bool insideb(Point p) {
    // int minsub = inf, maxsub = -inf;
    // int minplus = inf, maxplus = -inf;
    // Rep(i, 4) {
    //     minsub = min(minsub, b[i].x - b[i].y);
    //     minplus = min(minplus, b[i].x + b[i].y);
        
    //     maxsub = max(maxsub, b[i].x - b[i].y);
    //     maxplus = max(maxplus, b[i].x + b[i].y);
    // }
    
    // int sub = p.x - p.y;
    // int plus = p.x + p.y;
    
    // return minsub <= sub && sub <= maxsub && minplus <= plus && plus <= maxplus;
    
    Point c[4];
    double t = sqrt(0.5);
    Rep(i, 4) {
        c[i].x = t * b[i].x - t * b[i].y;
        c[i].y = t * b[i].x + t * b[i].y;
    }
    
    Point p2;
    p2.x = t * p.x - t * p.y;
    p2.y = t * p.x + t * p.y;
    
    return insidea(c, p2);
}

bool check() {
    Rep(i, 4) if (insidea(a, b[i])) return true;
    Rep(i, 4) if (insideb(a[i])) return true;
    if (insidea(a, (b[0] + b[1] + b[2] + b[3]) / 4)) return true;
    if (insideb((a[0] + a[1] + a[2] + a[3]) / 4)) return true;
    return false;
}

int main() {
    Rep(i, 4) cin >> a[i].x >> a[i].y;
    Rep(i, 4) cin >> b[i].x >> b[i].y;
    if (check()) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}