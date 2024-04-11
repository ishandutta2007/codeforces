#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld Inf = 1e100l;
const int Maxn = 105;
const int Maxt = 100;
const ld eps = 1e-15l;

struct point {
    ld x, y, z;
    point(ld x = 0, ld y = 0, ld z = 0): x(x), y(y), z(z) {}
    ld Dist(const point &p) const {
        return sqrt(ld(x - p.x) * (x - p.x) + ld(y - p.y) * (y - p.y) + ld(z - p.z) * (z - p.z));
    }
};

struct edge {
    point s1, s2;
    edge(point s1 = point(), point s2 = point()): s1(s1), s2(s2) {}
    point getPoint(ld t) const {
        return point(s1.x + (s2.x - s1.x) * t, s1.y + (s2.y - s1.y) * t, s1.z + (s2.z - s1.z) * t);
    }
    ld Dist(const point &p) const {
        ld res = Inf;
        ld lef = 0, rig = 1;
        for (int i = 0; i < Maxt; i++) {
            ld q1 = (2 * lef + rig) / 3, q2 = (lef + 2 * rig) / 3;
            ld v1 = p.Dist(getPoint(q1)), v2 = p.Dist(getPoint(q2));
            if (v1 <= v2) { res = min(res, v1); rig = q2; }
            else { res = min(res, v2); lef = q1; }
        }
        return res;
    };
};

point A;
point V;
int R;
int n;
ld res = Inf;

point newA(ld tim)
{
    return point(A.x + V.x * tim, A.y + V.y * tim, A.z + V.z * tim);
}

ld solveSphere(const point &p, int r)
{
    ld res = Inf;
    ld lef = 0, rig = 1000000;
    for (int i = 0; i < Maxt; i++) {
        ld q1 = (2 * lef + rig) / 3, q2 = (lef + 2 * rig) / 3;
        ld d1 = p.Dist(newA(q1)) - R - r, d2 = p.Dist(newA(q2)) - R - r;
        if (d1 - eps <= 0) { res = min(res, q1); rig = q2; }
        else if (d1 <= d2) rig = q2;
        else lef = q1;
    }
    return res;
}

ld solveEdge(const edge &e)
{
    ld res = Inf;
    ld lef = 0, rig = 1000000;
    for (int i = 0; i < Maxt; i++) {
        ld q1 = (2 * lef + rig) / 3, q2 = (lef + 2 * rig) / 3;
        ld d1 = e.Dist(newA(q1)) - R, d2 = e.Dist(newA(q2)) - R;
        if (d1 - eps <= 0) { res = min(res, q1); rig = q2; }
        else if (d1 <= d2) rig = q2;
        else lef = q1;
    }
    return res;
}

int main()
{
    cin >> A.x >> A.y >> A.z >> V.x >> V.y >> V.z >> R;
    cin >> n;
    for (int i = 0; i < n; i++) {
        point O;
        int r, m;
        cin >> O.x >> O.y >> O.z >> r >> m;
        res = min(res, solveSphere(O, r));
        for (int j = 0; j < m; j++) {
            point P; cin >> P.x >> P.y >> P.z;
            P.x += O.x; P.y += O.y; P.z += O.z;
            res = min(res, solveEdge(edge(O, P)));
        }
    }
    if (res >= Inf) printf("-1\n");
    else cout << fixed << setprecision(10) << res << endl;
    return 0;
}