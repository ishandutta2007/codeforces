#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <complex>

using namespace std;

typedef complex<double> pnt;

const double EPS = 1e-9;
const double INF = 1e18;
const double MAXC = 1e6 + 5;
const int MAXN = 100100;

int n, m;
pnt p[MAXN], poly[MAXN];
double xsum, ysum, xsq, ysq;

void init() {
    for (int i=0; i<n; i++) {
        xsum += p[i].real();
        ysum += p[i].imag();
        xsq += pow(p[i].real(), 2);
        ysq += pow(p[i].imag(), 2);
    }
}

double evalx(double x) {
    return pow(x, 2) * n - 2 * xsum * x + xsq;
}

double evaly(double y) {
    return pow(y, 2) * n - 2 * ysum * y + ysq;
}

double dot(pnt p1, pnt p2) { return real(conj(p1) * p2); }
double cross(pnt p1, pnt p2) { return imag(conj(p1) * p2); }

int sign(double d) {
    return d < 0 ? -1 : d > 0 ? 1 : 0;
}

bool sameside(pnt a, pnt b, pnt p, pnt q) {
    return sign(cross(p-a, q-p)) == sign(cross(p-b, q-p));
}

bool inpoly(pnt p) {
    pnt cent = pnt(0, 0);
    for (int i=0; i<m; i++) cent += poly[i];
    cent /= m;
    for (int i=0; i<m; i++)
        if (!sameside(p, cent, poly[i], poly[(i+1)%m]))
            return 0;

    return 1;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<n; i++) cin >> p[i].real() >> p[i].imag();
    cin >> m;
    for (int i=0; i<m; i++) cin >> poly[i].real() >> poly[i].imag();

    init();

    double xmin, ymin;
    double lo = -MAXC, hi = MAXC;
    while (hi - lo > 10*EPS) {
        double m1 = lo + (hi - lo) / 3;
        double m2 = lo + 2 * (hi - lo) / 3;
        double v1 = evalx(m1), v2 = evalx(m2);
        if (v1 < v2) hi = m2;
        else lo = m1;
    }
    xmin = lo;

    lo = -MAXC, hi = MAXC;
    while (hi - lo > 10*EPS) {
        double m1 = lo + (hi - lo) / 3;
        double m2 = lo + 2 * (hi - lo) / 3;
        double v1 = evaly(m1), v2 = evaly(m2);
        if (v1 <= v2) hi = m2;
        else lo = m1;
    }
    ymin = lo;

    if (inpoly(pnt(xmin, ymin))) {
        cout << fixed << setprecision(10) << evalx(xmin) + evaly(ymin) << '\n';
        return 0;
    }

    double ans = INF;

    for (int i=0; i<m; i++) {
        pnt p1 = poly[i], p2 = poly[(i+1)%m];
        if (p1.real() > p2.real()) swap(p1, p2);
        if (p1.real() != p2.real()) {
            double slope = (p2.imag() - p1.imag()) / (p2.real() - p1.real());
            lo = p1.real(), hi = p2.real();
            while (hi - lo > 10*EPS) {
                double m1 = lo + (hi - lo) / 3;
                double m2 = lo + 2 * (hi - lo) / 3;
                double y1 = p1.imag() + slope * (m1 - p1.real());
                double y2 = p1.imag() + slope * (m2 - p1.real());
                double v1 = evalx(m1) + evaly(y1);
                double v2 = evalx(m2) + evaly(y2);
                if (v1 < v2) hi = m2;
                else lo = m1;
            }
            double x = lo, y = p1.imag() + slope * (lo - p1.real());
            ans = min(ans, evalx(x) + evaly(y));
        } else {
            double x = p1.real();
            lo = min(p1.imag(), p2.imag()), hi = max(p1.imag(), p2.imag());
            while (hi - lo > 10*EPS) {
                double m1 = lo + (hi - lo) / 3;
                double m2 = lo + 2 * (hi - lo) / 3;
                double v1 = evalx(x) + evaly(m1);
                double v2 = evalx(x) + evaly(m2);
                if (v1 < v2) hi = m2;
                else lo = m1;
            }
            ans = min(ans, evalx(x) + evaly(lo));
        }
    }

    cout << fixed << setprecision(10) << ans << '\n';
    return 0;
}