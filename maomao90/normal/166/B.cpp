// time-limit: 2000
// problem-url: https://codeforces.com/problemset/problem/166/B

// Hallelujah, praise the one who set me free
// Hallelujah, death has lost its grip on me
// You have broken every chain, There's salvation in your name
// Jesus Christ, my living hope
#include <bits/stdc++.h> 
using namespace std;

template <class T>
inline bool mnto(T& a, T b) {return a > b ? a = b, 1 : 0;}
template <class T>
inline bool mxto(T& a, T b) {return a < b ? a = b, 1: 0;}
#define REP(i, s, e) for (int i = s; i < e; i++)
#define RREP(i, s, e) for (int i = s; i >= e; i--)
typedef long long ll;
typedef long double ld;
#define FI first
#define SE second
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef tuple<int, int, int> iii;
#define ALL(_a) _a.begin(), _a.end()
#define pb push_back
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;

#ifndef DEBUG
#define cerr if (0) cerr
#endif

#define INF 1000000005
#define LINF 1000000000000000005ll
#define MAXN 200005

template <class T = int>
struct Point {
    T x, y;
    Point(): x(0), y(0) {
    }
    Point(T x, T y): x(x), y(y) {
    }
    Point<T>& operator+= (const Point<T> &o) {
        x += o.x; y += o.y;
        return *this;
    }
    Point<T> operator+ (const Point<T> &o) const {
        Point<T> res = *this;
        res += o;
        return res;
    }
    Point<T> operator- () const {
        return Point<T>(-x, -y);
    }
    Point<T>& operator-= (const Point<T> &o) {
        return *this += (-o);
    }
    Point<T> operator- (const Point<T> &o) const {
        Point<T> res = *this;
        res -= o;
        return res;
    }
    bool operator< (const Point<T> &o) const {
        if (x == o.x) {
            return y < o.y;
        }
        return x < o.x;
    }
    bool operator== (const Point<T> &o) const {
        return x == o.x && y == o.y;
    }
    friend istream& operator>> (istream &is, Point<T> &o) {
        return is >> o.x >> o.y;
    }
    friend ostream& operator<< (ostream &os, const Point<T> &o) {
        return os << o.x << " " << o.y;
    }
    T dot(const Point<T> &o) const {
        return x * o.x + y * o.y;
    }
    T cross(const Point<T> &o) const {
        return x * o.y - y * o.x;
    }
};
template <class T>
inline T orient(const Point<T> &a, const Point<T> &b, const Point<T> &c) {
    return (b - a).cross(c - a);
}
template <class T>
bool polar_sort(Point<T> l, Point<T> r) {
    int ls = l.y > 0 || (l.y == 0 && l.x > 0),
        rs = r.y > 0 || (r.y == 0 && r.x > 0);
    if (ls != rs) {
        return ls > rs;
    }
    T x = l.cross(r);
    if (x == 0) {
        if (l.x == r.x) {
            return abs(l.y) < abs(r.y);
        } else {
            return abs(l.x) < abs(r.x);
        }
    }
    return l.cross(r) > 0;
}

// strict = 0 means points on the edge of the hull are also part of the hull
// make sure there are no duplicated points
template <class T>
vector<Point<T>> convexHull(vector<Point<T>> pts, bool strict = 1) {
    if (pts.size() == 1) {
        return pts;
    }
    sort(ALL(pts));
    vector<Point<T>> hull;
    int k = 0, prv = 0;
    REP (z, 0, 2) {
        for (Point<T> pt : pts) {
            while (k - prv >= 2 && 
                    ((!strict && orient(hull[k - 2], hull[k - 1], pt) < 0) ||
                     (strict && orient(hull[k - 2], hull[k - 1], pt) <= 0))) {
                hull.pop_back();
                k--;
            }
            hull.pb(pt);
            k++;
        }
        reverse(ALL(pts));
        hull.pop_back();
        k--;
        prv = k;
    }
    return hull;
}

int n, m;
set<Point<ll>> a;
vector<Point<ll>> pts;

int main() {
#ifndef DEBUG
    ios::sync_with_stdio(0), cin.tie(0);
#endif
    cin >> n;
    pts.resize(n);
    REP (i, 0, n) {
        cin >> pts[i];
        a.insert(pts[i]);
    }
    cin >> m;
    pts.resize(n + m);
    bool pos = 1;
    REP (i, n, n + m) {
        cin >> pts[i];
        if (a.count(pts[i])) {
            pos = 0;
        }
    }
    if (!pos) {
        cout << "NO\n";
        return 0;
    }
    vector<Point<ll>> hull = convexHull(pts, 0);
    if (hull.size() != n) {
        cout << "NO\n";
        return 0;
    }
    for (Point<ll> &pt : hull) {
        if (!a.count(pt)) {
            pos = 0;
            break;
        }
    }
    if (pos) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
    return 0;
}