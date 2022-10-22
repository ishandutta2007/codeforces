#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

ll gcd(ll x, ll y) {
    return x == 0 ? y : gcd(y % x, x);
}

struct rat {
    ll u, v;
    rat() : u(0), v(1) { }
    rat(ll uu, ll vv) : u(uu), v(vv) {
        if(v < 0) {
            u = -u;
            v = -v;
        }
        ll g = gcd(u >= 0 ? u : -u, v);
        u /= g;
        v /=  g;
    }
    bool operator < (rat const & b) const {
        return u * b.v < b.u * v;
    }
    bool operator > (rat const & b) const {
        return u * b.v > b.u * v;
    }
    bool operator == (rat const & b) const {
        return u * b.v == b.u * v;
    }
};

double const eps = 1e-9;

int main() {

    int n;

    scanf("%d", &n);

    int x1, y1, x2, y2;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if(x1 == x2 || y1 == y2) {
        puts("-1");
        return 0;
    }

    vec< pii > r(n);
    vec< pii > v(n);

    rat ql(0, 1);
    rat qr(1000000, 1);

    for(int i = 0;i < n;i++) {
        scanf("%d %d", &r[i].first, &r[i].second);
        scanf("%d %d", &v[i].first, &v[i].second);

        if(v[i].first == 0) {
            if(x1 < r[i].first && r[i].first < x2) { }
            else {
                puts("-1");
                return 0;
            }
        }else if(v[i].first > 0) {
            ql = max(ql, rat(x1 - r[i].first, v[i].first));
            qr = min(qr, rat(x2 - r[i].first, v[i].first));
        }else {
            ql = max(ql, rat(x2 - r[i].first, v[i].first));
            qr = min(qr, rat(x1 - r[i].first, v[i].first));
        }

        if(v[i].second == 0) {
            if(y1 < r[i].second && r[i].second < y2) { }
            else {
                puts("-1");
                return 0;
            }
        }else if(v[i].second > 0) {
            ql = max(ql, rat(y1 - r[i].second, v[i].second));
            qr = min(qr, rat(y2 - r[i].second, v[i].second));
        }else {
            ql = max(ql, rat(y2 - r[i].second, v[i].second));
            qr = min(qr, rat(y1 - r[i].second, v[i].second));
        }
    }

    if(!(ql < qr)) {
        puts("-1");
        return 0;
    }else {
        printf("%.20lf\n", 1.0 * ql.u / ql.v + 1e-9);
    }

    return 0;
}