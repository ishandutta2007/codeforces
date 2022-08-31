/*
    author:  Maksim1744
    created: 20.06.2019 18:35:53
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

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

template<typename T>             vector<T>& operator--            (vector<T>& v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T>& v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
#else
#define showl            42;
#define shows            42;
#define show(...)        42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#endif

int main() {
    int T;
    cin >> T;
    while (T--) {
        ll a, b, p, q;
        cin >> a >> b >> p >> q;
        ll t = min(b - a + 1, (ll)sqrt(b - a) + 5);
        vector<pair<ll, int>> v;
        auto g = [&](ll x) {
            return p * x * 2 % (q * 2);
        };
        auto f = [&](ll x) {
            // show(x);
            return abs(g(x) - q);
        };
        show(f(761), f(1034));
        for (int i = 0; i < t; ++i) {
            v.eb(g(i), i);
        }
        ll ans = a;
        sort(v.begin(), v.end());
        show(v, f(a));
        for (ll i = a; i + t <= b + 1; i += t) {
            ll need = (q - g(i) + q * 2) % (q * 2);
            int ind = lowb(v, mp(need, -1));
            for (int j = ind - 3; j <= ind + 3; ++j) {
                int k = (j + v.size()) % v.size();
                ll fn = f(i + v[k].second);
                if (fn < f(ans) || (fn == f(ans) && i + v[k].second < ans))
                    ans = i + v[k].second;
            }
            ind = uppb(v, mp(need, -1));
            for (int j = ind - 3; j <= ind + 3; ++j) {
                int k = (j + v.size()) % v.size();
                ll fn = f(i + v[k].second);
                if (fn < f(ans) || (fn == f(ans) && i + v[k].second < ans))
                    ans = i + v[k].second;
            }
        }
        for (ll i = b; i >= max(b - t - 5, a); --i) {
            ll fn = f(i);
            if (fn < f(ans) || (fn == f(ans) && i < ans))
                ans = i;
        }
        cout << ans << '\n';
    }
    return 0;
}