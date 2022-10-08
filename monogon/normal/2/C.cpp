
#include <bits/stdc++.h>

#define ll long long
using namespace std;

#define pt complex<double>
#define x real()
#define y imag()
#define dot(u, v) (conj(u) * (v)).x
#define cross(u, v) (conj(u) * (v)).y

const double EPS = 1e-12;
const pt I(0, 1);

istream &operator>>(istream &is, pt &p) {
    double X, Y;
    is >> X >> Y;
    p = {X, Y};
    return is;
}

pt pjline(pt a, pt b, pt p) {
    b -= a, p -= a;
    return a + b * (p / b).x;
}

bool parallel(pt a, pt b, pt c, pt d) {
    return abs(cross(b - a, d - c)) < EPS;
}
pt lineline(pt a, pt b, pt c, pt d) {
    b -= a, d -= c, c -= a;
    return a + b * cross(c, d) / cross(b, d);
}
vector<pt> linecircle(pt a, pt b, pt c, double r) {
    pt p = pjline(a, b, c) - c;
    if(norm(p) > r * r + EPS) return {};
    pt v = p * I * sqrt(max(r * r / norm(p) - 1, 0.0));
    return {c + p + v, c + p - v};
}
vector<pt> circlecircle(pt a, pt b, double r, double R) {
    double d = abs(b - a);
    if(d > r + R || d + min(r, R) < max(r, R)) return {};
    pt p = (b - a) * (1 + (r * r - R * R) / norm(b - a)) / 2.0;
    pt v = p * I * sqrt(max(r * r / norm(p) - 1, 0.0));
    return {a + p + v, a + p - v};
}

pt p[3];
double r[3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i = 0; i < 3; i++) {
        cin >> p[i] >> r[i];
        r[i] = r[i] * r[i];
    }
    vector<pt> v;
    if(abs(r[1] - r[0]) < EPS) {
        // line 1
        pt a1 = 0.5 * (p[1] - p[0]);
        pt b1 = a1 + p[1] * I;
        if(abs(r[2] - r[0]) < EPS) {
            // line 2
            pt a2 = 0.5 * (p[2] - p[0]);
            pt b2 = a2 + p[2] * I;
            if(!parallel(a1, b1, a2, b2)) {
                v.push_back(lineline(a1, b1, a2, b2));
            }else {
                v.push_back(a1);
            }
        }else {
            //circle 2
            pt c2 = (p[2] - p[0]) * (-r[0]) / (r[2] - r[0]);
            double r2 = (r[0] + r[0] * r[0] / (r[2] - r[0])) * norm(p[2] - p[0]) / (r[2] - r[0]);
            v = linecircle(a1, b1, c2, sqrt(r2));
        }
    }else {
        // circle 1
        pt c1 = (p[1] - p[0]) * (-r[0]) / (r[1] - r[0]);
        double r1 = (r[0] + r[0] * r[0] / (r[1] - r[0])) * norm(p[1] - p[0]) / (r[1] - r[0]);

        if(abs(r[2] - r[0]) < EPS) {
            // line 2
            pt a2 = 0.5 * (p[2] - p[0]);
            pt b2 = a2 + p[2] * I;
            v = linecircle(a2, b2, c1, sqrt(r1));
        }else {
            //circle 2
            pt c2 = (p[2] - p[0]) * (-r[0]) / (r[2] - r[0]);
            double r2 = (r[0] + r[0] * r[0] / (r[2] - r[0])) * norm(p[2] - p[0]) / (r[2] - r[0]);
            v = circlecircle(c1, c2, sqrt(r1), sqrt(r2));
        }
    }
    cout << fixed << setprecision(8);
    bool found = false;
    pt best;
    for(pt q : v) {
        pt q2 = p[0] + q;
        double d0 = abs(q2 - p[0]) / sqrt(r[0]);
        double d1 = abs(q2 - p[1]) / sqrt(r[1]);
        double d2 = abs(q2 - p[2]) / sqrt(r[2]);
        if(abs(d0 - d1) < EPS && abs(d0 - d2) < EPS) {
            if(!found || abs(q) < abs(best)) {
                best = q;
            }
            found = true;
        }
    }
    best = best + p[0];
    if(found) {
        cout << best.x << " " << best.y << endl;
    }
}