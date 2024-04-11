#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long ll;
using namespace std;
typedef pair <int, int> ii;
typedef vector <ii> vii;
typedef vector <int> vi;

const double INF = 1e9;

double X, Y, o1, o2;
double V, T;
double ux, uy, wx, wy;

double sq(double m) { return m * m; }

bool check(double x, double y, double t, double vx, double vy) {
    if (t == 0) return (x == 0 && y == 0);
    double ax = x / t - vx, ay = y / t - vy;
    return sq(ax) + sq(ay) <= sq(V);
}

double f(double vx, int neg = 0) {
    double vy = sqrt(sq(V) - sq(vx));
    if (neg & 1) vy = -vy;
    if (neg & 2) vx = -vx;
    double l = 0, r = INF;
    double newX = X - T * (ux + vx), newY = Y - T * (uy + vy);
    ff(i, 1, 500) {
        double mid = (l + r) / 2;
        if (check(newX, newY, mid, wx, wy)) r = mid; else l = mid;
    }
    return l;
}

int main(void) {
    cin >> X >> Y >> o1 >> o2; X = o1 - X; Y = o2 - Y;
    cin >> V >> T;
    cin >> ux >> uy >> wx >> wy;
    if (X < 0) { X = -X; ux = -ux; wx = -wx; }
    if (Y < 0) { Y = -Y; uy = -uy; wy = -wy; }
    if (check(X, Y, T, ux, uy)) {
        double l = 0, r = T;
        ff(i, 1, 500) {
            double mid = (l + r) / 2;
            if (check(X, Y, mid, ux, uy)) r = mid; else l = mid;
        }
        cout << setprecision(15) << fixed << l << endl;
        return 0;
    }
    double x = V / 2, r = V / 2;
    ff(i, 1, 500) {
        double f0 = f(x - r), f1 = f(x), f2 = f(x + r);
        if (f0 < f1) { if (f0 < f2) x -= r; } else if (f1 > f2) x += r;
        r /= 2;
    }
    double res = T + f(x);
    ff(o, 1, 3) {
        x = V / 2, r = V / 2;
        ff(i, 1, 500) {
            double f0 = f(x - r, o), f1 = f(x, o), f2 = f(x + r, o);
            if (f0 < f1) { if (f0 < f2) x -= r; } else if (f1 > f2) x += r;
            r /= 2;
        }
        res = min(res, T + f(x, o));
    }
    cout << setprecision(15) << fixed << res << endl;
    return 0;
}