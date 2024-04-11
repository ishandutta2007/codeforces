/*
    author:  Maksim1744
    created: 16.04.2021 19:28:37
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
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

struct point {
    ll x, y;
    int i;
    int a;

    point(ll x = 0, ll y = 0): x(x), y(y) {}
    point(point a, point b) {
        x = b.x - a.x;
        y = b.y - a.y;
    }

    ll dist(point b) const {
        return sqrt((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
    }
    ll sdist(point b) const {
        return ((b.x - x) * (b.x - x) + (b.y - y) * (b.y - y));
    }
    ll len() const {
        return sqrt(x * x + y * y);
    }
    ll slen() const {
        return x * x + y * y;
    }
    point ort() const {
        return point(-y, x);
    }
    ll dp(point p) const {
        return x * p.x + y * p.y;
    }
    ll cp(point p) const {
        return x * p.y - y * p.x;
    }

    point operator + (point a) const {
        return point(a.x + x, a.y + y);
    }
    point operator - (point a) const {
        return point(x - a.x, y - a.y);
    }
    point operator * (ll k) const {
        return point(x * k, y * k);
    }
    point operator / (ll k) const {
        return point(x / k, y / k);
    }

    point& norm() {
        ll d = len();
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

struct DSU {
    vector<int> rk;
    vector<int> p;
    int n;

    DSU(int n = 1) : n(n) {
        reset(n);
    }

    void reset(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        rk.assign(n, 1);
    }

    int par(int v) {
        return v == p[v] ? v : p[v] = par(p[v]);
    }

    bool un(int u, int v) {
        u = par(u);
        v = par(v);
        if (u == v) return false;
        if (rk[u] > rk[v]) swap(u, v);
        p[u] = v;
        rk[v] += rk[u];
        return true;
    }

    bool check(int u, int v) {
        return par(u) == par(v);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<point> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i].x >> v[i].y;
        cin >> v[i].a;
        --v[i].a;
        v[i].i = i;
    }

    sort(v.begin(), v.end(), [&](const point &a, const point &b) {
        return mp(a.x, a.y) < mp(b.x, b.y);
    });

    reverse(v.begin(), v.end());
    while (!v.empty() && v.back().i == v.back().a)
        v.pop_back();
    reverse(v.begin(), v.end());

    if (v.empty()) {
        cout << 0 << '\n';
        return 0;
    }
    DSU d(n);
    for (int i = 0; i < v.size(); ++i) {
        d.un(v[i].i, v[i].a);
    }

    assert(v[0].i != v[0].a);
    auto p0 = v[0];
    v.erase(v.begin());
    for (int i = 0; i < v.size(); ++i) {
        v[i].x -= p0.x;
        v[i].y -= p0.y;
    }
    sort(v.begin(), v.end(), [&](const point &a, const point &b) {
        return a.cp(b) < 0;
    });

    vector<pair<int, int>> ans;

    for (int i = 0; i + 1 < v.size(); ++i) {
        if (!d.check(v[i].i, v[i + 1].i)) {
            ans.eb(v[i].i, v[i + 1].i);
            swap(v[i].a, v[i + 1].a);
            d.un(v[i].i, v[i + 1].i);
        }
    }

    while (p0.a != p0.i) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i].i == p0.a) {
                ans.eb(p0.i, v[i].i);
                swap(p0.a, v[i].a);
            }
        }
    }

    // vector<pair<int, int>> todo;
    // vector<pair<int, int>> ans;
    // int i = 0;
    // while (i < v.size()) {
    //     if (p0.i == v[i].a) {
    //         if (i + 1 == v.size()) {
    //             todo.eb(p0.i, v[i].i);
    //             break;
    //         }
    //         todo.eb(v[i].i, v[i + 1].i);
    //         ++i;
    //         continue;
    //     }
    //     ans.eb(p0.i, v[i].i);
    //     swap(p0.a, v[i].a);
    //     ++i;
    // }
    // for (auto [a, b] : todo) {
    //     ans.eb(a, b);
    // }
    cout << ans.size() << '\n';
    for (auto [a, b] : ans) {
        cout << a + 1 << ' ' << b + 1 << '\n';
    }

    return 0;
}