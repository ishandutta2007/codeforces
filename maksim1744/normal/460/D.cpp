/*
    author:  Maksim1744
    created: 19.08.2020 21:33:46
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

    ll l, r, k;
    cin >> l >> r >> k;
    ll best = l;
    vector<ll> bests = {l};
    if (k >= 3) {
        for (int j = 0; j < 5; ++j) {
            if (l + j + 1 > r) continue;
            vector<ll> ss = {l + j, l + j + 1};
            ll cur = ss[0] ^ ss[1];
            if (cur < best) {
                best = cur;
                bests = ss;
            }
        }
        if (k == 3) {
            for (int j = 0; j < 5; ++j) {
                if (l + j + 2 > r) continue;
                vector<ll> ss = {l + j, l + j + 1, l + j + 2};
                ll cur = ss[0] ^ ss[1] ^ ss[2];
                if (cur < best) {
                    best = cur;
                    bests = ss;
                }
            }
        }
        for (ll p = 2; p <= r; p *= 2) {
            if (p <= l) continue;
            ll a = l;
            ll b = p;
            ll c = p;
            b += (1ll << __lg(l));
            c = a ^ b;
            if (b > r) continue;
            ll r = (a ^ b ^ c);
            assert(r == 0);
            if (r < best) {
                bests = vector<ll>{a, b, c};
                best = r;
            }
        }
    }
    if (true) {
        r = min(r, l + 19);
    }
    int ln = r - l + 1;
    for (int i = 1; i < (1 << ln); ++i) {
        if (__builtin_popcount(i) > k) continue;
        vector<ll> s;
        for (int j = 0; j < ln; ++j) {
            if ((i >> j) & 1) {
                s.pb(l + j);
            }
        }
        ll res = 0;
        for (auto u : s) {
            res ^= u;
        }
        if (res < best) {
            best = res;
            bests = s;
        }
    }
    cout << best << '\n';
    cout << bests.size() << '\n';
    cout << bests << '\n';

    return 0;
}