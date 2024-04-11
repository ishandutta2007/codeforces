#include <bits/stdc++.h>

using namespace std;

const double M_PI = acos(-1);

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

ll sqr(ll a) {
    return a * a;
}

struct Point {  
    ll x;
    ll y;
    
    Point(ll x = 0, ll y = 0): x(x), y(y) {}

    Point operator-(const Point& p) const {
        return Point(x - p.x, y - p.y);
    }

    double dist(const Point& p) const {
        return sqrt(sqr(x - p.x) + sqr(y - p.y));
    }

    ll vec(const Point& p) const {
        return x * p.y - p.x * y;
    }

    ll scalar(const Point& p) const {
        return x * p.x + y * p.y;
    }
};

double maxDist(Point a, Point b, Point p) {
    return max(a.dist(p), b.dist(p));
}

double minDist(Point a, Point b, Point p) {
    if ((b - a).scalar(p - a) < 0)
        return min(a.dist(p), b.dist(p));
    if ((a - b).scalar(p - b) < 0)
        return min(a.dist(p), b.dist(p));
    return fabs((b - a).vec(p - a) / a.dist(b));    
}

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    Point p;
    cin >> n >> p.x >> p.y;
    vector<Point> ps(n);
    for (int i = 0; i < n; i++)
        cin >> ps[i].x >> ps[i].y;
    double min_d = 1e100;
    double max_d = 0;
    for (int i = 0; i < n; i++) {
        Point a = ps[i];
        Point b = ps[(i + 1) % n];
        min_d = min(min_d, minDist(a, b, p));
        max_d = max(max_d, maxDist(a, b, p));
    }        
    cout.setf(ios::fixed);
    cout.precision(15);
    cout << M_PI * (max_d * max_d - min_d * min_d) << endl;
    return 0;
}