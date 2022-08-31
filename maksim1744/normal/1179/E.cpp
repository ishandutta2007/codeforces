/*
    author:  Maksim1744
    created: 16.06.2021 11:34:53
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

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    ll lx = 0, rx = 1e18;
    ll ly = 0, ry;
    cin >> ry;

    vector<int> v0(n); iota(v0.begin(), v0.end(), 0);
    vector<pair<ll, ll>> ans(n, {-1, -1});

    map<pair<int, ll>, ll> mem;
    vector<set<pair<ll, ll>>> f(n);

    int que = 0;

    auto ask = [&](int i, ll x) {
        if (mem.count({i, x})) return mem[{i, x}];
        #ifndef HOUSE
        cout << "? " << i + 1 << ' ' << x << endl;
        #endif
        ++que;
        ll res = x;
        #ifndef HOUSE
        cin >> res;
        #endif
        f[i].emplace(x, res);
        return mem[{i, x}] = res;
    };

    for (int i = 0; i < n; ++i) {
        f[i].emplace(0, 0);
        f[i].emplace(rx, ry);
        mem[{0, 0}] = 0;
        mem[{0, rx}] = ry;
    }

    auto ask_geq = [&](int i, ll x, ll y) -> int {
        auto it = f[i].lower_bound({x, -1});
        if (it->first == x) return it->second >= y;
        auto itp = prev(it);
        if (it->second < y) return 0;
        if (itp->second >= y) return 1;
        if (it->second - (it->first - x) >= y) return 1;
        if (itp->second + (x - itp->first) < y) return 0;
        return ask(i, x) >= y;
    };

    y_combinator([&](auto calc, ll lx, ll rx, ll ly, ll ry, vector<int> v) -> void {
        if (v.empty()) return;
        if (v.size() == 1) {
            ans[v[0]] = {lx, rx};
            return;
        }
        ll L = lx - 1, R = rx + 1;
        assert((ry - ly) % v.size() == 0);
        ll my = (ry - ly) / v.size() * (v.size() / 2) + ly;
        while (R - L > 1) {
            ll C = (L + R) / 2;
            int cur = 0;
            int other = 0;
            shuffle(v.begin(), v.end(), rng);
            for (int i : v) {
                if (ask_geq(i, C, my)) {
                    ++cur;
                } else {
                    ++other;
                }
                if (cur >= (v.size() + 1) / 2) break;
                if (n - other < (v.size() + 1) / 2) break;
                // if (cur + other >= 100) break;
            }

            if ((int)((ld)cur / (cur + other) * v.size() + 0.5) >= (v.size() + 1) / 2)
                R = C;
            else
                L = C;
        }
        vector<int> tol, tor;
        vector<pair<ll, int>> byy;
        for (int i : v)
            byy.eb(ask(i, R), i);
        sort(byy.begin(), byy.end());
        for (int i = 0; i < byy.size(); ++i) {
            if (i < (v.size() + 1) / 2)
                tor.pb(byy[i].second);
            else
                tol.pb(byy[i].second);
        }
        show(R, my, tol, tor);
        calc(lx, R, ly, my, tol);
        calc(R, rx, my, ry, tor);
    })(lx, rx, ly, ry, v0);

    cout << '!' << endl;
    for (auto p : ans)
        cout << p << endl;

    cerr << que << endl;

    return 0;
}