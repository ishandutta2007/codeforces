/*
    author:  Maksim1744
    created: 09.02.2020 17:34:17
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

ll cp(pair<ll, ll> a, pair<ll, ll> b) {
    return a.first * b.second - a.second * b.first;
}

ll ln(pair<ll, ll> a) {
    return a.first * a.first + a.second * a.second;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<ll> v(n);
    cin >> v;
    for (int i = 1; i < n; ++i)
        v[i] += v[i - 1];
    vector<pair<ll, ll>> pts(n);
    for (int i = 0; i < n; ++i) {
        pts[i] = {i + 1, v[i]};
    }
    sort(pts.begin(), pts.end(), [&](pair<ll, ll> a, pair<ll, ll> b) {
        auto s = cp(a, b);
        if (s != 0) return s > 0;
        return ln(a) < ln(b);
    });
    show(pts);
    vector<pair<ll, ll>> ch;
    ch.eb(0, 0);
    for (auto p : pts) {
        if (p.first < ch.back().first) continue;
        while (ch.size() >= 2 && cp(ch[ch.size() - 1] - ch[ch.size() - 2], p - ch[ch.size() - 2]) <= 0) {
            ch.pop_back();
        }
        ch.pb(p);
    }
    show(ch);
    vector<ld> ans;
    for (int i = 0; i < ch.size() - 1; ++i) {
        ld x = (ld)(ch[i + 1].second - ch[i].second) / (ch[i + 1].first - ch[i].first);
        for (int j = 0; j < ch[i + 1].first - ch[i].first; ++j) {
            cout << setprecision(20) << fixed << x << ' ';
        }
    }
    cout << '\n';

    return 0;
}