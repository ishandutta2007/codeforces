/*
    author:  Maksim1744
    created: 10.05.2021 00:37:56
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll s;
    cin >> s;

    ll ans = 1;

    const int N = 53;


    for (int a = 1; a < N; ++a) {
        for (int b = 1; b < N; ++b) {
            map<tuple<ll, int, int, int>, ll> mem;
            for (int cacb = 0; cacb <= (a - 1) + (b - 1); ++cacb) {
                ll n = s + cacb - ((1ll << (b)) - 1);
                if (n <= 0) continue;
                ll dv = (1ll << (a + 1)) + (1ll << (b + 1)) - 3;
                ll x = n / dv;
                if (a == 1 && b == 2 && cacb == 0) show(n, dv, x);
                if (x == 0) continue;
                ll y = n % dv;
                if (y % 2) continue;

                ll its = 0;

                auto calc = y_combinator([&](auto calc, ll n, int a, int b, int need) -> ll {
                    ++its;
                    // show(n, a, b, need);
                    if (n == 0) {
                        return (need == 0);
                    }
                    if (need < 0) return 0;
                    if (a == 0 && b == 0) return 0;
                    if (a == 0) {
                        if (n < (1ll << b) && __builtin_popcountll(n) == need) {
                            return 1;
                        }
                        return 0;
                    }
                    if (b == 0) {
                        if (n < (1ll << a) && __builtin_popcountll(n) == need) {
                            return 1;
                        }
                        return 0;
                    }

                    auto t = make_tuple(n, a, b, need);
                    if (mem.count(t)) return mem[t];

                    if (n & 1) {
                        ll ans = calc(n / 2, a - 1, b - 1, need - 1) * 2;
                        return mem[t] = ans;
                    } else {
                        ll ans = calc(n / 2, a - 1, b - 1, need) + calc((n - 2) / 2, a - 1, b - 1, need - 2);
                        return mem[t] = ans;
                    }
                });

                ans += calc(y / 2, a - 1, b - 1, cacb);

                // if (its > 1000)
                //     show(its);

                // for (ll sa = 0; sa <= y; sa += 2) {
                //     ll sb = y - sa;
                //     if (sa >= (1ll << a)) continue;
                //     if (sb >= (1ll << b)) continue;
                //     if (__builtin_popcountll(sa) + __builtin_popcountll(sb) == left) {
                //         show(a, b, cacb, x, y, sa, sb);
                //         ++ans;
                //     }
                // }
            }
        }
    }

    for (int a = 1; a < N; ++a) {
        for (int ca = 0; ca <= a; ++ca) {
            ll n = s + ca;
            ll dv = (1ll << (a + 1)) - 1;
            ll x = n / dv;
            if (x < 1) continue;
            ll y = n % dv;
            if (y % 2) continue;
            if (__builtin_popcountll(y) != ca) continue;
            if (y >= (1ll << (a + 1))) continue;
            show(a, ca, x, y);
            ++ans;
        }
    }

    cout << ans << endl;

    return 0;
}