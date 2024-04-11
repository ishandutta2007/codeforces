/*
    author:  Maksim1744
    created: 10.10.2020 18:49:38
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll x;
    cin >> x;

    vector<pair<string, pair<ll, ll>>> ans;

    if ((x >> 1) & 1) {
        ans.eb(" + ", mp(x, x));
        ans.eb(" ^ ", mp(x, x * 2));
        x = (x ^ (x * 2));
    }
    assert(!((x >> 1) & 1));

    ll val = x;
    for (int i = 1; i < 25; ++i) {
        // cout << (x << (i - 1)) << " + " << (x << (i - 1)) << '\n';
        ans.eb(" + ", mp(x << (i - 1), x << (i - 1)));
        if ((val >> i) & 1) {
            ans.eb(" ^ ", mp(val, x << i));
            val ^= (x << i);
        }
    }

    ans.eb(" + ", mp(val, x));
    ll val2 = val + x;
    ans.eb(" ^ ", mp(val, val2));
    ll y = (val ^ val2);

    // show(val, val2);
    // show(x, y);

    assert((x ^ y) == 2);

    ans.eb(" ^ ", mp(x, y));

    for (int i = 1; x != 1; ++i) {
        ans.eb(" + ", mp(1 << i, 1 << i));
        if (x & (1 << i)) {
            ans.eb(" ^ ", mp(x, 1 << i));
            x ^= (1 << i);
        }
    }

    cout << ans.size() << '\n';
    for (auto [s, p] : ans) {
        cout << p.first << s << p.second << '\n';
    }

    return 0;
}