
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define pt complex<double>
#define x real()
#define y imag()
#define cross(u, v) (conj(u) * (v)).y

istream &operator>>(istream &is, pt &p) {
    double X, Y;
    is >> X >> Y;
    p = {X, Y};
    return is;
}

const double EPS = 1e-5;
const pt I(0, 1);

pt p1, p2, p3;

pt lineline(pt a, pt b, pt c, pt d) {
    b -= a, d -= c, c -= a;
    return a + b * cross(c, d) / cross(b, d);
}
pt circumcenter(pt a, pt b, pt c) {
    b = 0.5 * (a + b);
    c = 0.5 * (a + c);
    return lineline(b, b + (b - a) * I, c, c + (c - a) * I);
}
bool good(double d, int i) {
    return abs(i / d - round(i / d)) < EPS;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> p1 >> p2 >> p3;
    pt c = circumcenter(p1, p2, p3);
    double ang1 = 2 * M_PI / arg(conj(p1 - c) * (p2 - c));
    double ang2 = 2 * M_PI / arg(conj(p1 - c) * (p3 - c));
    for(int i = 3; i <= 100; i++) {
        if(good(ang1, i) && good(ang2, i)) {
            double area = 0.5 * i * norm(p1 - c) * sin(2 * M_PI / i);
            cout << fixed << setprecision(8) << area << endl;
            return 0;
        }
    }
}