#include <iostream>
#include <cmath>

using namespace std;

const double eps = 1e-8;


long double sqr(long double a) {
    return a * a;
}

struct point {
    long double x, y;
    point(long double _x = 0, long double _y = 0): x(_x), y(_y) {}
    point operator - (point p) {
        return point(x - p.x, y - p.y);
    }
    long double operator * (point p) {
        return x * p.y - p.x * y;
    }
    void scan() {
        cin >> x >> y;
    }
    long double dist(point p) {
        return sqrt(sqr(x - p.x) + sqr(y - p.y));
    }
};

long double getDist(point a, point b, point p) {
    return fabs((p - a) * (b - a) / a.dist(b));
}

int main() {
    long double y1, y2, yw, r;
    point ball;
    
    cin >> y1 >> y2 >> yw;
    ball.scan();
    cin >> r;
    
    yw -= r;
    
    long double targ = y1 + r;
    double touchX = (yw - targ) / (yw - targ + yw - ball.y) * ball.x;
    
    cout.setf(ios::fixed);
    cout.precision(10);
    
    double dist = getDist(point(0.0, targ), point(touchX, yw), point(0.0, y2));
    if (dist + eps <= r)
        cout << -1;
    else
        cout << touchX;
    
    cin >> r;
    return 0;
}