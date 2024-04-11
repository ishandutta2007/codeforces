/*
    author:  Maksim1744
    created: 05.11.2019 20:51:45
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
const int N = 30;
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
const int N = 100010;
#endif

int main() {
    vector<int> primes;
    primes.pb(2);
    for (int i = 3; i < N; i += 2) {
        bool ok = true;
        for (auto p : primes) {
            if (i % p == 0) {
                ok = false;
                break;
            }
        }
        if (ok)
            primes.pb(i);
    }
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    cin >> a;
    map<vector<pair<int, int>>, ll> m;
    for (auto t : a) {
        vector<pair<int, int>> v;
        for (auto p : primes) {
            if (t < p)
                break;
            if (t % p == 0) {
                v.eb(p, 0);
                while (t % p == 0) {
                    t /= p;
                    v.back().second++;
                }
                v.back().second %= k;
                if (v.back().second == 0)
                    v.pop_back();
            }
        }
        if (t != 1)
            v.eb(t, 1);
        m[v]++;
    }
    ll ans = 0;
    show(m);
    for (auto& [v, t] : m) {
        vector<pair<int, int>> need;
        for (auto [x, y] : v) {
            need.eb(x, k - y);
        }
        // show(v, need);
        if (need == v)
            ans += t * (t - 1);
        else
            ans += t * m[need];
    }
    cout << ans / 2 << endl;
    return 0;
}