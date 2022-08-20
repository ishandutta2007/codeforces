/*
    author:  Maksim1744
    created: 25.12.2020 15:34:22
*/

#include "bits/stdc++.h"

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

    int n;
    cin >> n;
    pair<ll, ll> v1;
    pair<ll, ll> v2;
    cin >> v1 >> v2;
    if (v1.first < 0) {
        v1.first *= -1;
        v1.second *= -1;
    }
    if (v2.first < 0) {
        v2.first *= -1;
        v2.second *= -1;
    }

    ll det = v1.first * v2.second - v2.first * v1.second;

    if (det == 0) {
        cout << "NO\n";
        return 0;
    }
    while (v1.first != 0 && v2.first != 0) {
        if (v1.first < v2.first) swap(v1, v2);
        ll k = v1.first / v2.first;

        assert(((ll)4e18) / k > abs(v2.second));

        v1.first -= v2.first * k;
        v1.second -= v2.second * k;
    }

    if (v1.first == 0) swap(v1, v2);
    if (v2.second < 0) v2.second *= -1;

    vector<pair<int, int>> ans;
    for (ll x = 0; x < v1.first; ++x) {
        ll y0;
        if (v1.second == 0) {
            y0 = 0;
        } else if (v1.second < 0) {
            y0 = (__int128)v1.second * x / v1.first;
        } else {
            y0 = ((__int128)v1.second * x + v1.first - 1) / v1.first;
        }
        show(v1, v2, y0);
        assert((__int128)y0 * v1.first >= (__int128)x * v1.second);
        assert((__int128)(y0 - 1) * v1.first < (__int128)x * v1.second);
        if (ans.size() + v2.second > n) {
            cout << "NO\n";
            return 0;
        }
        for (int i = 0; i < v2.second; ++i) {
            ans.eb(x, y0 + i);
        }
    }
    if (ans.size() != n) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (auto p : ans) {
        cout << p << '\n';
    }

    return 0;
}