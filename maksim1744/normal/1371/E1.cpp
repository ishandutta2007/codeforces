/*
    author:  Maksim1744
    created: 01.07.2020 17:05:36
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
#define showm(...)       42;
#define showt(...)       42;
#define printTree(...)   42;
#define printGraph(...)  42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#define printWGraph(...) 42;
#define debug     if (false)
#endif

const ll inf = 1e9 * 2;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n, p;
    cin >> n >> p;
    vector<ll> a(n);
    cin >> a;
    sort(a.begin(), a.end());
    vector<pair<pair<ll, ll>, ll>> ck;
    ll last = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 || a[i] != a[i - 1]) {
            ck.eb(mp(last, a[i] - 1), i % p);
            last = a[i];
        }
    }
    show(a);
    ck.eb(mp(last, inf - 1), n % p);
    show(ck);
    vector<pair<ll, ll>> bads;
    for (auto [lr, rem] : ck) {
        // int l = lr.first - rem;
        // int r = lr.second - rem;
        // if ((r - l + 1) >= p) {
        //     cout << 0 << '\n';
        //     return 0;
        // }
        // l %= p;
        // r %= p;
        // if (l < r)
        //     bads.eb(l, r);
        // else {
        //     bads.eb(l, p - 1);
        //     bads.eb(0, r);
        // }
        while (rem < n) {
            // if (lr.second < 0) break;
            bads.eb(lr.first - rem, lr.second - rem);
            rem += p;
            // lr.first -= p;
            // lr.second -= p;
        }
    }
    bads.eb(0, 0);
    sort(bads.begin(), bads.end());
    show(bads);
    ll R = 0;
    vector<ll> ans;
    for (auto [l, r] : bads) {
        for (ll x = R + 1; x < l; ++x)
            ans.pb(x);
        R = max(R, r);
    }
    cout << ans.size() << '\n';
    cout << ans << '\n';

    return 0;
}