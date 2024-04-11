#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <ios>
#include <cmath>
#include <cstring>
#include <complex>
#include <iomanip>

using namespace std;

typedef long double ld;
typedef complex<ld> pnt;

const int maxn = 100100;
const ld eps = 1e-9;

int n, p, q;
int a[maxn], b[maxn];
pnt pnts[maxn];

pnt uh[maxn], lh[maxn];
int us, ls;

ld cross(pnt p1, pnt p2) { return imag(conj(p1) * p2); }

bool cmp(pnt p1, pnt p2) { return real(p1) != real(p2) ? real(p1) < real(p2) : imag(p1) < imag(p2); }

void makehull() {
    int ma = 0, mb = 0;
    for (int i = 0; i < n - 3; i++) {
        pnts[i] = pnt(a[i], b[i]);
        ma = max(ma, a[i]);
        mb = max(mb, b[i]);
    }

    pnts[n - 3] = pnt(0, 0);
    pnts[n - 2] = pnt(ma, 0);
    pnts[n - 1] = pnt(0, mb);

    sort(pnts, pnts + n, cmp);

    for (int i = 0; i < n; i++) {
        while (us >= 2 && cross(uh[us - 1] - uh[us - 2], pnts[i] - uh[us - 1]) >= 0) us--;
        uh[us++] = pnts[i];

        while (ls >= 2 && cross(lh[ls - 1] - lh[ls - 2], pnts[i] - lh[ls - 1]) <= 0) ls--;
        lh[ls++] = pnts[i];
    }

/*
    for (int i = 0; i < us; i++) cout << uh[i] << endl;
    cout << endl;
    for (int i = 0; i < ls; i++) cout << lh[i] << endl;
*/
}

bool sameside(pnt p1, pnt p2, pnt q1, pnt q2) {
    return cross(q2 - q1, q1 - p1) * cross(q2 - q1, q1 - p2) >= 0;
}

bool check(ld mid) {
    pnt cen = pnt(0, 0);
    for (int i = 0; i < us; i++) cen += uh[i];
    for (int i = 1; i < ls - 1; i++) cen += lh[i];
    cen *= mid / (us + ls - 2);

    pnt x = pnt(p, q);

    for (int i = 0; i < us - 1; i++)
        if (!sameside(cen, x, uh[i] * mid, uh[i + 1] * mid))
            return 0;

    for (int i = 0; i < ls - 1; i++)
        if (!sameside(cen, x, lh[i] * mid, lh[i + 1] * mid))
            return 0;

    return 1;
}
    
int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> p >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    n += 3;

    makehull();

    ld lo = eps, hi = 1e6;
    while (hi - lo > eps) {
        ld mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid;
    }

    cout << fixed << setprecision(10) << lo << '\n';
}