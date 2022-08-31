/*
    author:  Maksim1744
    created: 10.05.2021 14:53:01
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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
    int i;

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

mt19937_64 rng(387246283);
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

const ld pi = acosl(-1.0l);

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int k, n;
    cin >> k >> n;
    vector<point> v(n * k);
    for (int i = 0; i < v.size(); ++i) {
        cin >> v[i].x >> v[i].y;
        v[i].i = i;
    }

    for (int it = 0; it < k; ++it) {
        vector<pair<ld, pair<pair<int, int>, int>>> cands;
        pair<pair<int, int>, int> at_least_something;
        int sz = -1;
        for (int j = 0; j < 100; ++j) {
            ld P = 0;
            for (int i = 0; i < 1000; ++i) {
                point a = v[rnd(v.size())];
                point b = v[rnd(v.size())];
                point c = v[rnd(v.size())];
                for (int i = 0; i < v.size(); ++i) {
                    swap(v[i], v[rnd(i, v.size() - 1)]);
                }
                if (max({a.dist(b), a.dist(c), b.dist(c)}) < 1000) continue;
                if ((a - b).cp(a - c) == 0) continue;
                b = b - a;
                c = c - a;
                ld d = 2 * (b.x * c.y - b.y * c.x);
                point o((c.y * b.slen() - b.y * c.slen()) / d, (b.x * c.slen() - c.x * b.slen()) / d);
                ld r = o.len();
                o = o + a;
                b = b + a;
                c = c + a;
                if (r < 200000 * (1.0 - P) || r > 850000 * (1.0 + P)) continue;
                if (abs(o.x) > 1.1e6 || abs(o.y) > 1.1e6) continue;
                vector<ld> angles;
                for (auto p : v) {
                    if (angles.size() == int(n * 0.9)) break;
                    ld d = o.dist(p);
                    if (d < (0.9 - P) * r) continue;
                    if (d > (1.1 + P) * r) continue;
                    angles.pb(atan2(o.y - p.y, o.x - p.x));
                }
                if ((int)angles.size() > sz) {
                    sz = angles.size();
                    at_least_something = mp(mp(o.x, o.y), r);
                }
                if (angles.size() < n * (0.6)) continue;
                ld mx = 0;
                sort(angles.begin(), angles.end());
                for (int i = 0; i + 1 < angles.size(); ++i)
                    mx = max(mx, angles[i + 1] - angles[i]);
                mx = max(mx, angles[0] - angles.back() + pi * 2);
                // cerr << (int)o.x << ' ' << (int)o.y << ' ' << (int)r << ' ' << angles.size() << ' ' << mx << endl;
                cands.eb(mx, mp(mp(o.x, o.y), r));
            }
            if (!cands.empty()) break;
            P += 0.01;
        }
        if (cands.empty()) cands.eb(0, at_least_something);
        sort(cands.begin(), cands.end());
        for (int i = 0; i < v.size(); ++i) {
            swap(v[i], v[rnd(i, v.size() - 1)]);
        }
        if (cands.empty())
            cout << "0 0 0\n";
        else {
            auto [xy, r] = cands[0].second;
            auto [x, y] = xy;
            cout << x << ' ' << y << ' ' << r << endl;
            set<int> u;
            point o(x, y);
            for (auto p : v) {
                if (u.size() == n) break;
                ld d = o.dist(p);
                if (d < 0.85 * r) continue;
                if (d > 1.15 * r) continue;
                u.insert(p.i);
            }

            vector<point> v2;
            for (auto p : v)
                if (!u.count(p.i))
                    v2.pb(p);
            swap(v, v2);
        }
    }

    return 0;
}