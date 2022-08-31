/*
    author:  Maksim1744
    created: 06.05.2021 03:01:50
*/

#include "bits/stdc++.h"

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key

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

const ld pi = acosl(-1.0l);
const ld eps = 1e-9;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    ll k;
    cin >> n >> k;

    vector<pair<int, int>> pt0(n);
    cin >> pt0;

    ld l = 1e-12, r = 1e12;

    auto calc = [&](const vector<point> &v, ld r) {
        if (r < 1e-9) return 0ll;
        vector<pair<ld, ld>> inseg, outseg;
        for (auto p : v) {
            ld mid = atan2(p.y, p.x);
            if (mid < 0) mid += pi * 2;
            ld dif = acosl(r / p.len());

            pair<ld, ld> seg = {mid - dif, mid + dif};
            if (0 <= seg.first && seg.second <= pi * 2) {
                inseg.pb(seg);
            } else if (seg.second <= pi * 2) {
                seg.first += pi * 2;
                outseg.eb(seg.second, seg.first);
            } else if (0 <= seg.first) {
                seg.second -= pi * 2;
                outseg.eb(seg.second, seg.first);
            } else {
                assert(false);
            }
        }

        ll ans = 0;
        // out with out
        {
            ll cur = 0;
            int id = 0;
            ordered_set<pair<ld, int>> s;
            sort(outseg.begin(), outseg.end());
            for (int i = (int)outseg.size() - 1; i >= 0; --i) {
                cur += s.order_of_key({outseg[i].second, -1});
                s.insert({outseg[i].second, id++});
            }
            ans += cur;
        }
        // in with in
        {
            ll cur = 0;
            ll cur2 = 0;
            int id = 0;
            ordered_set<pair<ld, int>> s;
            sort(inseg.begin(), inseg.end());
            for (int i = (int)inseg.size() - 1; i >= 0; --i) {
                cur += s.order_of_key({inseg[i].second, -1});
                s.insert({inseg[i].second, id++});
                cur2 += inseg.size() - lowb(inseg, mp(inseg[i].second, (ld)-1));
            }
            ans += cur;
            ans += cur2;
        }
        // in with out
        {
            {
                ll cur = 0;
                sort(outseg.begin(), outseg.end());
                for (auto [l, r] : inseg) {
                    cur += outseg.size() - lowb(outseg, mp(r, (ld)-1));
                }
                ans += cur;
                swap(inseg, outseg);
            }
            {
                ll cur = 0;
                sort(outseg.begin(), outseg.end());
                for (auto [l, r] : inseg) {
                    cur += outseg.size() - lowb(outseg, mp(r, (ld)-1));
                }
                ans += cur;
                swap(inseg, outseg);
            }
            {
                vector<pair<pair<ld, ld>, int>> seg;
                for (auto p : inseg)
                    seg.eb(p, 1);
                for (auto p : outseg)
                    seg.eb(p, 2);
                sort(seg.begin(), seg.end(), [&](const auto &a, const auto &b) {
                    return a.first.first < b.first.first;
                });
                int id = 0;
                ll cur = 0;

                ordered_set<pair<ld, int>> s;

                for (auto [lr, who] : seg) {
                    auto [l, r] = lr;
                    if (who == 1) {
                        cur += s.size() - s.order_of_key(mp(r, -1));
                    } else {
                        s.insert({r, id++});
                    }
                }

                ans += cur;
            }
        }

        return ans;
    };

    for (int i = 0; i < 40; ++i) {
        double c = sqrt(l * r);
        ll cur = 0;
        int left = n;
        vector<point> v;
        for (auto [a, b] : pt0) {
            if (a * a + b * b <= c * c) {
                --left;
                cur += left;
            } else {
                v.eb(a, b);
            }
        }

        cur += calc(v, c);
        if (cur < k)
            l = c;
        else
            r = c;
    }

    cout << fixed << setprecision(10) << (l + r) / 2 << '\n';

    return 0;
}