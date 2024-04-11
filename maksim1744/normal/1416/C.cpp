/*
    author:  Maksim1744
    created: 27.09.2020 18:20:30
*/

#include <bits/stdc++.h>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// find_by_order, order_of_key


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

    ll n;
    cin >> n;
    vector<ll> a(n);
    cin >> a;
    ll x = 0;

    auto count_inv = [&](vector<ll> &a, int b) {
        ll if0 = 0;
        ll if1 = 0;
        ll c0 = 0;
        ll c1 = 0;
        ll cur = 1ll << b;
        int n = a.size();
        for (int i = 0; i < n; ++i) {
            if (a[i] & cur) {
                ++c1;
                if1 += c0;
            } else {
                ++c0;
                if0 += c1;
            }
        }
        return mp(if0, if1);
    };

    vector<vector<ll>> cur = {a};
    vector<vector<ll>> next;

    for (int b = 32; b >= 0; --b) {
        ll if0 = 0, if1 = 0;
        next.clear();
        for (auto& a : cur) {
            auto p = count_inv(a, b);
            if0 += p.first;
            if1 += p.second;
            vector<ll> a0, a1;
            for (int i = 0; i < a.size(); ++i) {
                if (a[i] & (1ll << b))
                    a1.pb(a[i]);
                else
                    a0.pb(a[i]);
            }
            if (!a0.empty())
                next.pb(a0);
            if (!a1.empty())
                next.pb(a1);
        }
        if (if1 < if0) x ^= (1ll << b);
        swap(next, cur);
    }
    for (int i = 0; i < n; ++i) {
        a[i] ^= x;
    }
    ordered_set<pair<int, int>> s;
    ll u = maxe(a);
    s.insert({u + 1, 25});
    ll invs = 0;
    for (int i = 0; i < n; ++i) {
        int ind = s.order_of_key(*s.lower_bound(mp(a[i] + 1, -1)));
        invs += (int)s.size() - ind - 1;
        s.insert({a[i], i});
    }

    cout << invs << ' ' << x << '\n';

    return 0;
}