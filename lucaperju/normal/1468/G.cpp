#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define pb push_back
#define dbg(x) cerr << #x << " " << x << "\n"

struct Point {
    double x;
    double y;
};
const int MAX_N = 2e5;
Point eye, poly[1 + MAX_N];
const double EPS = 1e-16;
double dist (Point a, Point b) {
    double d =  (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    if (d < -EPS)
        d = 0;
    return sqrtl (d);
}

struct Segment {
    Point a;
    Point b;
    double length;
    double m;
    double start;
    Segment (Point a, Point b) {
        this->a = a;
        this->b = b;
        length = dist (a, b);
        m = (b.y - a.y) / (b.x - a.x);
        start = a.y - a.x * m;
    }
};
double polarAngle (Point A, Point B) {
    return (A.y - B.y) / (A.x - B.x);
}

double intersect (Segment s1, Segment s2) {
    if (s1.m == s2.m) {
        if (s1.start == s2.start)
            return s1.length;
        return 0;
    }
    double a = s1.m, b = s2.m, c = s1.start, d = s2.start;
    Point common = {(d - c) / (a - b), a * (d - c) / (a - b) + c};
    if (common.x - s1.b.x > EPS) {
        if (s1.m - s2.m > EPS)
            return 0;
        return s1.length;
    }
    else if (common.x - s1.a.x < -EPS) {
        if (s1.m - s2.m > EPS)
            return s1.length;
        return 0;
    }
    else {
        if (s1.m - s2.m < -EPS) {
            return dist (s1.a, common);
        }
        else
            return dist (s1.b, common);
    }
}
int main () {
    ios::sync_with_stdio (false);
    cin.tie (0); cout.tie (0);
    int n;
    double H;
    cin >> n >> H;
    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        poly[i] = {x, y};
    }
    eye = {poly[n].x, poly[n].y + H};
    int maxPos = -1;
    double ans = 0;
    for (int i = n; i > 1; i--) {
        Segment l (poly[i - 1], poly[i]);
        if (i < n && (maxPos == -1 || polarAngle(eye, poly[i]) - polarAngle(eye, poly[maxPos]) < -EPS))
            maxPos = i;
    //    dbg (maxPos);
        if (i == n)
            ans += l.length;
        else {
            Segment view (poly[maxPos], eye);
            double c = intersect (l, view);
         //   cout << c << "\n";
            ans += c;
        }
    }
    cout << fixed << setprecision (7) << ans << "\n";
    return 0;
}