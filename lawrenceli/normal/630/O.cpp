#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

#define A first
#define B second

typedef long double ld;
typedef pair<ld, ld> pnt;

ld px, py, vx, vy, a, b, c, d;
pnt ar[10]; 

pnt rot(pnt p, ld t) {
    pnt cen = pnt(px, py);
    p = pnt(p.A - cen.A, p.B - cen.B);
    return pnt(cen.A + p.A * cos(t) - p.B * sin(t), cen.B + p.A * sin(t) + p.B * cos(t));
}

int main() {
    cin >> px >> py >> vx >> vy >> a >> b >> c >> d;
    ar[0] = pnt(px, py + b);
    ar[1] = pnt(px - a / 2, py);
    ar[2] = pnt(px - c / 2, py);
    ar[3] = pnt(px - c / 2, py - d);
    ar[4] = pnt(px + c / 2, py - d);
    ar[5] = pnt(px + c / 2, py);
    ar[6] = pnt(px + a / 2, py);

    double t = atan2(-vx, vy);
    for (int i = 0; i < 7; i++)
        ar[i] = rot(ar[i], t);

    for (int i = 0; i < 7; i++)
        cout << fixed << setprecision(20) << ar[i].A << ' ' << ar[i].B << '\n';
}