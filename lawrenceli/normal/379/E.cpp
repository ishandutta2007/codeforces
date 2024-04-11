#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <complex>

using namespace std;

typedef complex<double> pnt;

const int MAXN = 305;

int n, k;
double y[MAXN];
vector<pnt> line, line2;

double val(pnt a, pnt b, double x) {
    double x1 = a.real(), y1 = a.imag(), x2 = b.real(), y2 = b.imag();
    return y1 + (y2-y1) / (x2-x1) * (x-x1);
}

double cross(pnt a, pnt b) { return imag(conj(a) * b); }

pnt inter(pnt a, pnt b, pnt p, pnt q) {
    double d1 = cross(p - a, b - a), d2 = cross(q - a, b - a);
    return (d1 * q - d2 * p) / (d1 - d2);
}

void go1() {
    double ans = 0;
    for (int i=0; i<=k; i++) line.push_back(pnt(i, y[i]));
    for (int i=1; i<=k; i++)
        ans += (y[i]+y[i-1])/2;
    cout << fixed << setprecision(10) << ans << '\n';
}

void go2() {
    double ans = 0;
    line2.clear();
    int p = 0;
    for (int i=1; i<=k; i++) {
        pnt p1 = pnt(i-1, y[i-1]), p2 = pnt(i, y[i]);
        for (; line[p].real() < i; p++) {
            pnt q1 = line[p], q2 = line[p+1];
            double v1 = val(p1, p2, q1.real()), v2 = val(p1, p2, q2.real());
            line2.push_back(pnt(q1.real(), max(q1.imag(), v1)));
            if (v1>q1.imag() ^ v2>q2.imag()) {
                pnt pi = inter(p1, p2, q1, q2);
                line2.push_back(pi);
                if (v1 > q1.imag())
                    ans += (pi.real()-q1.real()) * (v1-q1.imag()) / 2;
                else
                    ans += (q2.real()-pi.real()) * (v2-q2.imag()) / 2;
            } else {
                if (v1 > q1.imag())
                    ans += (q2.real()-q1.real()) * (v1-q1.imag()+v2-q2.imag()) / 2;
            }
        }
    }
    line2.push_back(pnt(line.back().real(), max(line.back().imag(), y[k])));
    line = line2;
    cout << fixed << setprecision(10) << ans << '\n';
}

int main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=k; j++) cin >> y[j];
        if (i == 0) go1();
        else go2();
    }
    return 0;
}