#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
struct Point {
    int64_t x, y;
};

inline bool operator<(const Point &a, const Point &b) {
    return make_pair(a.x, a.y) < make_pair(b.x, b.y);
}

struct Vector {
    int64_t A, B;

    inline void normalize() {
        if (B < 0) {
            A *= -1;
            B *= -1;
        }
    }
};

inline bool operator<(Vector a, Vector b) {
    a.normalize();
    b.normalize();
    int64_t deg = a.A * b.B - a.B * b.A;
    if (deg == 0 && b.B == 0) {
        return (a.B > 0) < (b.B > 0);
    }
    return deg < 0;
}

inline int64_t getC(const Vector &v, const Point &p) {
    return p.x*v.A + p.y*v.B;
}

signed main() {
//    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<Point> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y;
    }
    sort(v.begin(), v.end());

    vector<int> p(n), r(n);
    iota(p.begin(), p.end(), 0);
    iota(r.begin(), r.end(), 0);

    vector< tuple<Vector, int, int> > ln;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            ln.emplace_back(Vector {v[j].y - v[i].y, v[i].x - v[j].x}, i, j);
        }
    }
    sort(ln.begin(), ln.end());

    ll ans = (1LL * n * (n - 1) * (n - 2) * (n - 3)) / 24;
    ll ans2 = 0;
    for (auto it: ln) {

        Vector dir; int ia, ib; tie(dir, ia, ib) = it;
        int a = r[ia], b = r[ib];
        if (getC(dir, v[0]) > getC(dir, v.back())) {
            dir.A *= -1;
            dir.B *= -1;
        }

        auto find = [&](int64_t nc) {
            auto iter = lower_bound(v.begin(), v.end(), Point {nc, LLONG_MIN}, [&](const Point &a, const Point &b) {
                assert(b.y == LLONG_MIN);
                return getC(dir, a) < b.x;
            });
            assert(iter != v.end() && iter+1 != v.end());
            int64_t l = iter - v.begin();
            int64_t r = n - l - 2;
            ans2 += l * r;
        };

        assert(getC(dir, v[a]) == getC(dir, v[b]));
        find(getC(dir, v[a]));

        swap(v[a], v[b]);
        swap(p[a], p[b]);
        swap(r[ia], r[ib]);
    }
    ll triangles = ans2 - 2 * ans;
    ll quads = ans - triangles;
    cout << ((triangles * (n - 4))) / 2;

    return 0;
}