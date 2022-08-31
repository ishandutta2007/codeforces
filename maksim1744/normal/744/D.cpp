/*
    author:  Maksim1744
    created: 14.05.2021 22:32:12
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = double;

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define sum(a)     ( accumulate ((a).begin(), (a).end(), 0ll))
#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

struct point {
    ld x, y;

    point(ld x = 0, ld y = 0): x(x), y(y) {}
    point(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    ld dist(point b) const {
        return sqrt((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
    }
    ld sdist(point b) const {
        return ((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
    }
    ld len() const {
        return sqrt(x * x + y * y);
    }
    ld slen() const {
        return x * x + y * y;
    }
    point ort() const {
        return point(-y, x);
    }
    ld dp(point p) const {
        return x * p.x + y * p.y;
    }
    ld cp(point p) const {
        return x * p.y - y * p.x;
    }

    point operator + (point a) const {
        return point(a.x + x, a.y + y);
    }
    point operator - (point a) const {
        return point(x - a.x, y - a.y);
    }
    point operator * (ld k) const {
        return point(x * k, y * k);
    }
    point operator / (ld k) const {
        return point(x / k, y / k);
    }

    point& norm() {
        ld d = len();
        if (d != 0) {
            x /= d;
            y /= d;
        }
        return *this;
    }
};
ostream& operator << (ostream& o, const point &p) {
    return o << "(" << p.x << ", " << p.y << ")";
}

const ld PI = acosl(-1.0l);

const ld inf = 1e100;
ld ans = 0;

vector<point> red, blue;

struct line {
    long double a, b, c;
    line() {};
    line(long double a, long double b, long double c): a(a), b(b), c(c) {};
    line(point m, point n) {
        a = n.y - m.y;
        b = m.x - n.x;
        c = -a * m.x - b * m.y;
    }
    point intersect(line l) {
        return point((b * l.c - c * l.b) / (a * l.b - b * l.a), (a * l.c - c * l.a) / (b * l.a - a * l.b));
    }
    long double dist(point p) {
        return abs(a * p.x + b * p.y + c) / sqrt(a * a + b * b);
    }

    friend ostream& operator<< (ostream &os, const line & l) {
        if (l.a != 0) {
            os << l.a << "x ";
            if (l.b != 0) {
                if (l.b > 0) {
                    os << "+";
                } else {
                    os << "-";
                }
                os << " " << abs(l.b) << "y ";
            }
        } else {
            os << l.b << "y ";
        }
        if (l.c != 0) {
            if (l.c > 0) {
                os << "+";
            } else {
                os << "-";
            }
            os << " " << abs(l.c) << " ";
        }
        os << "= 0";
        return os;
    }
};

const ld eps = 1e-9;

void check(point a, point b, point c) {
    point ab = (a + b) / 2;
    point bc = (b + c) / 2;
    point vab = (b - a);
    swap(vab.x, vab.y);
    vab.x *= -1;
    point vbc = (b - c);
    if (abs((vab).cp(vbc)) < eps) return;
    swap(vbc.x, vbc.y);
    vbc.x *= -1;

    vab.norm();
    vbc.norm();

    line l1(ab, ab + vab);
    line l2(bc, bc + vbc);
    point o = l1.intersect(l2);
    ld r = o.dist(a);
    if (r < ans + eps) return;
    // for (auto p : blue)
    //     if (p.dist(o) < r - 1e-7) return;
    for (point p : red) {
        if (o.dist(p) <= r + eps) {
            show(a, b, c);
            show(o, r);
            show(p);
            ans = max(ans, r);
            return;
        }
    }
}

void calc(vector<point> v, point shift, bool is_red) {
    shows;
    show(shift, v);
    if (v.size() < 2) return;
    for (int i = 0; i < v.size(); ++i) {
        v[i].x -= shift.x;
        v[i].y -= shift.y;
    }

    map<pair<int, int>, point> clos;
    for (auto p : v) {
        pair<ll, ll> pr = {llround(p.x), llround(p.y)};
        ll d = gcd(abs(pr.first), abs(pr.second));
        pr.first /= d;
        pr.second /= d;
        if (clos.count(pr) && clos[pr].slen() <= p.slen()) continue;
        clos[pr] = p;
    }
    v.clear();
    for (auto [a, b] : clos)
        v.pb(b);

    auto cmp = [&](const point &p1, const point &p2) {
        pair<ll, ll> a = {llround(p1.x), llround(p1.y)};
        pair<ll, ll> b = {llround(p2.x), llround(p2.y)};
        if (a.second > 0) {
            if (b.second < 0) return true;
            if (b.second == 0)
                return b.first < 0;
        } else if (a.second < 0) {
            if (b.second > 0) return false;
            if (b.second == 0)
                return false;
        } else if (a.second == 0) {
            if (a.first > 0) {
                if (b.second != 0) return true;
                if (b.first < 0) return true;
                return abs(a.first) < abs(b.first);
            } else if (a.first < 0) {
                if (b.second > 0) return false;
                if (b.second < 0) return true;
                if (b.first > 0) return false;
                return abs(a.first) < abs(b.first);
            }
        }

        ll cp = (ll)a.first * b.second - (ll)a.second * b.first;
        if (cp == 0)
            return a.first * a.first + a.second * a.second < b.first * b.first + b.second * b.second;
        return cp > 0;
    };

    sort(v.begin(), v.end(), cmp);
    int iclosest = 0;
    int n = v.size();
    for (int i = 0; i < n; ++i) {
        if (v[i].slen() < v[iclosest].slen())
            iclosest = i;
    }
    for (int i = 0; i < iclosest; ++i)
        v.pb(v[i]);
    reverse(v.begin(), v.end());
    for (int i = 0; i < iclosest; ++i) {
        v.pop_back();
    }
    reverse(v.begin(), v.end());
    vector<point> st;
    st.pb(v[0]);
    st.pb(v[1]);

    show(v);

    auto get_ang = [&](point a, point b) {
        return (atan2(a.cp(b), a.dp(b)));
    };

    auto in_circle = [&](point a, point b, point c, point d) {
        double a1 = get_ang(c - b, a - b);
        double a2 = get_ang(a - d, c - d);
        show(a, b, c, d, a1, a2);
        return a1 + a2 > PI;
    };

    for (int i = 2; i < n * 2; ++i) {
        show(st, v[i % n]);
        if (i >= n && !st.empty() && st.back().cp(v[i % n]) <= 0) break;
        while (st.size() >= 2 && in_circle(point(0, 0), st[st.size() - 2], st[st.size() - 1], v[i % n]))
            st.pop_back();
        if (i < n)
            st.pb(v[i]);
    }

    show(st);
    if (st.size() < 2) return;

    for (int i = 0; i < st.size(); ++i) {
        point a(0, 0);
        point b = st[i];
        point c = st[(i + 1) % st.size()];
        if (b.cp(c) < eps) {
            if (is_red) {
                cout << -1 << '\n';
                exit(0);
            }
            else continue;
        }
        check(a + shift, b + shift, c + shift);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    red.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> red[i].x >> red[i].y;
    }
    blue.clear();
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        blue.eb(x, y);
    }

    for (auto p : red) {
        calc(blue, p, true);
    }
    for (int i = 0; i < blue.size(); ++i) {
        auto u = blue;
        u.erase(u.begin() + i);
        calc(u, blue[i], false);
    }

    if (ans < 1e-9) {
        cout << -1 << '\n';
    } else {
        cout << fixed << setprecision(20) << ans << '\n';
    }

    return 0;
}