#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ios>
#include <iomanip>
#include <complex>

using namespace std;

#define px real()
#define py imag()

typedef long double ld;
typedef complex<ld> pnt;

const int maxn = 100100;
const int inf = 1e9;
const ld PI = acos(-1.0);
const ld eps = 1e-9;

int n;
pnt cen, far;
pnt p[maxn];
ld mi = 1e100, ma = 0;

ld cross(pnt p1, pnt p2) { return imag(conj(p1) * p2); }
ld dot(pnt p1, pnt p2) { return real(conj(p1) * p2); }

//actually not same side
int sameside(pnt p1, pnt p2, pnt q1, pnt q2) {
    ld a = cross(q2 - q1, q1 - p1), b = cross(q2 - q1, q1 - p2);
    return (a > 0) != (b > 0);
}

int calc() {
    int num = 0;
    for (int i = 0; i < n; i++) {
        pnt q = p[(i + 1) % n];
        int res = sameside(p[i], q, cen, far);
        int res2 = sameside(cen, far, p[i], q);
        if (abs(cross(far - cen, cen - p[i])) < eps || abs(cross(far - cen, cen - q)) < eps) return 2;
        if (res && res2) num++;
    }
    return num % 2;
}

pnt prj(pnt x, pnt a, pnt b) {
    ld d = dot(x - a, b - a);
    return a + (b - a) * d / norm(b - a);
}

int main() {
    ios_base::sync_with_stdio(0);

    int x, y;
    cin >> n >> x >> y;
    cen = pnt(x, y);
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        p[i] = pnt(x, y);
        ld d = norm(p[i] - cen);
        mi = min(mi, d);
        ma = max(ma, d);
    }

    for (int i = 0; i < n; i++) {
        pnt q = p[(i + 1) % n];
        if (abs(q - p[i]) < eps) continue;
        pnt r = prj(cen, p[i], q);
        //cout << i << ' ' << r << endl;
        if (abs(r - p[i]) + abs(q - r) - abs(q - p[i]) < eps) {
            //cout << i << endl;
            mi = min(mi, pow(abs(cross(cen - p[i], q - p[i]) / abs(q - p[i])), 2));
        }
    }

    far = pnt(inf, 0);
    bool in = 0;
    while (!in) {
        int res = calc();
        if (res < 2) {
            in = res;
            break;
        }
        far = pnt(far.px, far.py + 1e-6);
    }

    //cout << in << endl;

    if (in) {
        cout << fixed << setprecision(10) << PI * ma << '\n';
    } else {
        cout << fixed << setprecision(10) << PI * (ma - mi) << '\n';
    }
}