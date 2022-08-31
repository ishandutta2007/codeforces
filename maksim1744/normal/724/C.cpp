/*
    author:  Maksim1744
    created: 20.06.2021 23:20:19
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

// finds x and y such that a * x + b * y = c
template<typename T>
pair<T, T> egcd(T a, T b, T c) {
    if (a == 0) {
        // b * y = c
        assert(c % b == 0);
        return {0, c / b};
    }
    // a * x + b * y = c
    // a * x + (b % a + (b/a) * a) * y = c
    // a * (x + (b/a) * y) + (b % a) * y = c
    auto [y0, x0] = egcd(b % a, a, c);
    T y = y0;
    T x = x0 - (b / a) * y;
    return {x, y};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    const ll inf = 2e18;

    auto calc = [&](ll a, ll b, ll n, ll m) -> ll {
        // t = nx + a = my + b
        ll g = gcd(n, m);
        if (a % g != b % g) return inf;
        auto [x, y] = egcd(n, -m, b - a);
        ll t = n * x + a;
        ll lc = n * m / g;
        t = (t % lc + lc) % lc;
        return t;
    };

    int k;
    cin >> k;
    while (k--) {
        ll x, y;
        cin >> x >> y;

        ll ans = min({
            calc(x, y, n * 2, m * 2),
            calc(n * 2 - x, y, n * 2, m * 2),
            calc(n * 2 - x, m * 2 - y, n * 2, m * 2),
            calc(x, m * 2 - y, n * 2, m * 2),
        });

        if (ans == inf) ans = -1;
        cout << ans << '\n';
    }

    return 0;
}