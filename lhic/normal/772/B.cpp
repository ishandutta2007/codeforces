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

struct point {
    ld x, y;
    point(ld X = 0, ld Y = 0) {
        x = X, y = Y;
    }
    ld operator*(point a) {
        return x * a.y - y * a.x;
    }
    ld len() {
        return sqrt(x * x + y * y);
    }
    point operator-(point a) {
        return point(x - a.x, y - a.y);
    }
};

int n;
point p[1200];

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> p[i].x >> p[i].y;
    p[n] = p[0];
    p[n + 1] = p[1];
    ld mx = 1e10;
    for (int i = 1; i <= n; ++i) {
        ld h = (p[i] - p[i - 1]) * (p[i + 1] - p[i - 1]) / (p[i + 1] - p[i - 1]).len();
        h = abs(h);
        mx = min(mx, h);
    }
    cout.setf(ios::fixed);
    cout.precision(20);
    cout << mx / 2 << "\n";
	return 0;
}