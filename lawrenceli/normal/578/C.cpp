#include <cstdio>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstring>

using namespace std;

typedef long double ld;

const int maxn = 200100;
const ld inf = 1e15;
const ld eps = 1e-15;

int n, a[maxn];

ld dabs(ld d) { if (d<0) return d*-1; else return d; }

ld go(ld k) {
    ld mi = 0, ma = 0, cur = 0;
    ld ans = 0;

    for (int i=0; i<n; i++) {
        cur += a[i] - k;
        ans = max(ans, max( dabs(cur-mi), dabs(cur-ma) ));
        mi = min(mi, cur);
        ma = max(ma, cur);
    }

    return ans;
}

int main() {
    cin >> n;
    for (int i=0; i<n; i++) cin >> a[i];

    ld lo = -10005, hi = 10005;
    while (hi-lo > eps) {
        ld m1 = lo + (hi-lo)/3, m2 = lo + 2*(hi-lo)/3;

        if (go(m1) < go(m2)) hi = m2;
        else lo = m1;
    }

    cout << fixed << setprecision(10) << go(lo) << '\n';
}