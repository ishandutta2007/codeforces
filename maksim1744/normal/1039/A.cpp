/*
    author:  Maksim1744
    created: 07.05.2019 14:35:26
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}

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
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const ll inf = 3'000'000'000'000'000'005;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    ll t;
    cin >> n >> t;
    vector<ll> a(n);
    cin >> a;
    vector<ll> x(n);
    cin >> x;
    for (int i = 0; i < n; ++i) {
        --x[i];
    }
    auto y = x;
    sort(y.begin(), y.end());
    for (int i = 0; i < n; ++i) {
        if (y[i] < i) {
            cout << "No\n";
            return 0;
        }
    }
    vector<pair<ll, ll>> bb(n, {0, inf});
    for (int i = 0; i < n; ++i) {
        bb[i].first = a[i] + t;
    }
    vector<pair<int, int>> v;
    for (int i = 0; i < n; ++i) {
        if (i + 1 <= x[i])
            v.eb(i + 1, x[i]);
    }
    if (v.size() > 0) {
        vector<pair<int, int>> vv;
        vv.pb(v[0]);
        for (int i = 1; i < v.size(); ++i) {
            if (v[i].first <= vv.back().second)
                vv.back().second = max(vv.back().second, v[i].second);
            else
                vv.pb(v[i]);
        }
        // show(vv);
        for (auto [l, r] : vv) {
            for (int i = l; i <= r; ++i)
                bb[i - 1].first = max(bb[i - 1].first, a[i] + t);
        }
    }
    for (auto j : x) {
        if (j != n - 1) {
            bb[j].second = min(bb[j].second, a[j + 1] + t - 1);
            bb[j + 1].first = max(bb[j + 1].first, a[j + 1] + t);
        }
    }
    show(bb);
    vector<ll> b(n);
    b[0] = bb[0].first;
    for (int i = 0; i < n; ++i) {
        if (i > 0)
            b[i] = max(bb[i].first, b[i - 1] + 1);
        if (b[i] > bb[i].second) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
    cout << b << '\n';
    return 0;
}