/*
    author:  Maksim1744
    created: 22.07.2019 18:17:00
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

// const int N = 200005;

// array<pair<ll, ll>, N * 4> tree;

// void build() {
//     tree.fill(mp(0, 0));
// }

const ll mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<pair<ll, ll>> a(n);
    cin >> a;
    vector<pair<ll, ll>> hmx(n);  // here
    vector<pair<ll, ll>> pmx(n);  // prefix
    sort(a.begin(), a.end());
    for (int i = 0; i < n; ++i) {
        ll in = a[i].second, out = a[i].first;
        int l = -1, r = i;
        while (r - l > 1) {
            int c = (l + r) / 2;
            if (a[c].first <= in)
                l = c;
            else
                r = c;
        }
        if (l == -1) {
            hmx[i] = {out - in, 1};
        } else {
            hmx[i] = {out - in + pmx[l].first, pmx[l].second};
            if (hmx[i].first == out - in) {
                ++hmx[i].second;
            }
        }
        pmx[i] = hmx[i];
        if (i != 0) {
            if (pmx[i - 1].first == hmx[i].first) {
                pmx[i].second += pmx[i - 1].second;
            } else if (pmx[i - 1].first > hmx[i].first) {
                pmx[i] = pmx[i - 1];
            }
        }
        pmx[i].second %= mod;
    }
    show(a);
    show(hmx);
    show(pmx);
    ll mxin = 0;
    for (auto p : a) {
        umax(mxin, p.second);
    }
    vector<pair<ll, ll>> b;
    for (int i = 0; i < n; ++i) {
        if (a[i].first > mxin) {
            b.eb(a[i].first - hmx[i].first, hmx[i].second);
        }
    }
    if (b.size() == 0) {
        cout << 0 << '\n';
        return 0;
    }
    sort(b.begin(), b.end());
    ll ans = 0;
    for (auto p : b) {
        if (p.first == b[0].first)
            ans += p.second;
    }
    cout << ans % mod << '\n';
    return 0;
}