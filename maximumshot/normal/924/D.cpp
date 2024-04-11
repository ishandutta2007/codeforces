#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 1e5 + 5;

ll gcd(ll x, ll y) {
    return !x ? y : gcd(y % x, x);
}

struct Q {
    ll u, v;

    ll _abs(ll x) {
        return x >= 0 ? x : -x;
    }

    void norm() {
        if(v < 0) {
            v = -v;
            u = -u;
        }
        ll g = gcd(_abs(u), _abs(v));
        u /= g;
        v /= g;
    }

    Q(): u(0), v(1)
    { }

    Q(ll x, ll y = 1):
        u(x), v(y) {
        norm();
    }

    bool operator<(const Q& o) const {
        return u * o.v < v * o.u;
    }

    bool operator>(const Q& o) const {
        return u * o.v > v * o.u;
    }

    bool operator==(const Q& o) const {
        return u * o.v == v * o.u;
    }

    bool operator<=(const Q& o) const {
        return u * o.v <= v * o.u;
    }

    bool operator>=(const Q& o) const {
        return u * o.v >= v * o.u;
    }

    void print() {
        cout << 1.0 * u / v << " ";
    }
};

int n, w;
int x[N];
int v[N];
pair< Q, Q > seg[N];
Q crd[N];
int sz;
int fen[N];

int get(int s) {
    int res = 0;
    for(int cur = N - 1;cur >= 0;cur = (cur & (cur + 1)) - 1) {
        res += fen[cur];
    }
    for(int cur = s - 1;cur >= 0;cur = (cur & (cur + 1)) - 1) {
        res -= fen[cur];
    }
    return res;
}

void add(int p) {
    for(int cur = p;cur < N;cur |= (cur + 1)) {
        fen[cur]++;
    }
}

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &w);

    for(int i = 1;i <= n;i++) {
        scanf("%d %d", &x[i], &v[i]);
        seg[i] = make_pair(
            Q(-x[i], v[i] + w),
            Q(-x[i], v[i] - w)
        );
        crd[sz++] = seg[i].second;
    }

    ll res = 0;

    sort(crd, crd + sz);
    sz = unique(crd, crd + sz) - crd;

    sort(seg + 1, seg + n + 1);

    for(int i = 1;i <= n;i++) {
        int i2 = i;
        while((i2 < n) && (seg[i].first == seg[i2 + 1].first)) {
            i2++;
        }
        int len = i2 - i + 1;
        res += 1ll * len * (len - 1) / 2;
        for(int q = i;q <= i2;q++) {
            int pos = lower_bound(crd, crd + sz, seg[q].second) - crd;
            res += get(pos);
        }
        for(int q = i;q <= i2;q++) {
            int pos = lower_bound(crd, crd + sz, seg[q].second) - crd;
            add(pos);
        }
        i = i2;
    }

    cout << res << "\n";

    return 0;
}