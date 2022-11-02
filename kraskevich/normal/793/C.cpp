#include <bits/stdc++.h>    
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair

ll mabs(ll a) {
    return a > 0 ? a : -a;
}

ll gcd(ll a, ll b) {
    a = mabs(a);
    b = mabs(b);
    if (a == 0 || b == 0)
        return a + b;
    return __gcd(a, b);
}

struct Fraction {
    ll p;
    ll q;

    Fraction(ll a, ll b): p(a), q(b) {
        if (q < 0) {
            q = -q;
            p = -p;
        }
        ll g = gcd(p, q);
        p /= g;
        q /= g;
    }

    Fraction(ll a): Fraction(a, 1) {}

    bool operator<(const Fraction& r) const {
        return p * r.q < q * r.p;
    }

    bool operator==(const Fraction& r) const {
        return p * r.q == q * r.p;
    }
};

#define x1 xx1
#define y1 xx2
#define x2 xx3
#define y2 xx4

ll x1, y1, x2, y2;

struct Event {
    Fraction x;
    int d;

    Event(Fraction x_, int d_): x(x_), d(d_) {}

    bool operator<(const Event& e) const {
        if (!(x == e.x))
            return x < e.x;
        return d < e.d;
    }
};

bool inside(Fraction a, Fraction b, Fraction x) {
    if (b < a)
        swap(a, b);
    return (a < x || a == x) && (x < b || x == b);
}

bool strict(Fraction a, Fraction b, Fraction x) {
    if (b < a)
        swap(a, b);
    return a < x && x < b;
}

struct Point {
    Fraction x;
    Fraction y;

    Point(Fraction x_, Fraction y_): x(x_), y(y_) {}
};

vector<Point> p;

vector<Event> add(ll x0, ll y0, ll vx, ll vy) {
    if (vx == 0 && vy == 0) {
        if (strict(x1, x2, x0) && strict(y1, y2, y0))
            return {Event(Fraction(0), 1)};
        return {};
    }
    vector<Fraction> all;
    for (int i = 0; i < 4; i++) {
        Point a = p[i];
        Point b = p[(i + 1) % 4];
        if (a.x == b.x) {
            if (vx == 0)
                continue;
            Fraction t(a.x.p - x0, vx);
            all.push_back(t);
        } else {
            if (vy == 0)
                continue;
            Fraction t(a.y.p - y0, vy);
            all.push_back(t);
        }
    }
    sort(all.begin(), all.end());
    vector<Event> res;
    for (int i = 0; i + 1 < (int)all.size(); i++) {
        Fraction mid(all[i].p + all[i + 1].p, all[i].q + all[i + 1].q);
        Fraction midx(x0 * mid.q + vx * mid.p, mid.q);
        Fraction midy(y0 * mid.q + vy * mid.p, mid.q);
        if (strict(x1, x2, midx) && strict(y1, y2, midy)) {
            res.push_back(Event(all[i], 1));
            res.push_back(Event(all[i + 1], -1));
        }
    }
    return res;
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cin >> x1 >> y1 >> x2 >> y2;
    p.emplace_back(x1, y1);
    p.emplace_back(x1, y2);
    p.emplace_back(x2, y2);
    p.emplace_back(x2, y1);
    vector<Event> e;
    for (int i = 0; i < n; i++) {
        ll x0, y0, vx, vy;
        cin >> x0 >> y0 >> vx >> vy;
        auto v = add(x0, y0, vx, vy);
        for (auto a : v)
            e.push_back(a);
    }
    sort(e.begin(), e.end());
    cout.setf(ios::fixed);
    cout.precision(10);
    int cur = 0;
    for (int i = 0; i < (int)e.size(); i++) {
        cur += e[i].d;
        if (cur == n) {
            if (e[i].x.p >= 0) {
                cout << e[i].x.p * 1.0 / e[i].x.q << endl;
                return 0;
            }
            if (i + 1 == (int)e.size() || e[i + 1].x.p > 0) {
                cout << 0 << endl;
                return 0;
            }
        }
    }
    cout << -1 << endl;
}