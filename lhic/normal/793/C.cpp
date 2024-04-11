#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <queue>
#include <functional>

#define mp make_pair
#define pb push_back


typedef long long ll;
typedef long long llong;
typedef long double ld;

using namespace std;

#ifndef LOCAL
#define cerr _cer
struct _cert
{
    template <typename T> _cert& operator << (T) { return *this; }
};
_cert _cer;
#endif

template <typename T> void dprint(T begin, T end) {
    for (auto i = begin; i != end; i++) {
		cerr << (*i) << " ";
    }
    cerr << "\n";
}

ld mnt, mxt;

void slv(ld l, ld x, ld v) {
    if (v == 0) {
        if (x > 0 && x < l)
            return;
        mnt = 1e7;
        return;
    }
    if (v < 0) {
        x = l - x;
        v = -v;
    }
    mnt = max(mnt, (0 - x) / v);
    mxt = min(mxt, (l - x) / v);
}

int n;

const ld eps = 1e-12;

int main() {
    ll x1, y1, x2, y2;
    scanf("%d", &n);
    scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
    ll w = x2 - x1;
    ll h = y2 - y1;
    mnt = 0;
    mxt = 1e6;
    for (int i = 0; i < n; ++i) {
        ll x, y, vx, vy;
        scanf("%lld%lld%lld%lld", &x, &y, &vx, &vy);
        x -= x1;
        y -= y1;
        slv(w, x, vx);
        slv(h, y, vy);
    }
    if (mnt + eps >= mxt) {
        cout << -1 << "\n";
    }
    else {
        cout.setf(ios::fixed);
        cout.precision(20);
        cout << mnt << "\n";
    }
	return 0;
}