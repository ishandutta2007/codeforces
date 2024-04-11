/*
    author:  Maksim1744
    created: 15.02.2021 17:58:12
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
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<int> ns(4);
    cin >> ns;
    vector<vector<ll>> v(4);
    for (int i = 0; i < 4; ++i) {
        v[i].resize(ns[i]);
        cin >> v[i];
    }

    vector<vector<vector<int>>> with(4);
    for (int i = 1; i < 4; ++i) {
        with[i].resize(ns[i]);
        int m;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            int x, y;
            cin >> x >> y;
            --x; --y;
            with[i][y].pb(x);
        }
    }

    show(v);
    show(with);

    for (int i = 1; i < 4; ++i) {
        multiset<ll> s;
        for (auto k : v[i - 1]) {
            s.insert(k);
        }
        shows;
        show(i);
        show(s);
        for (int j = 0; j < ns[i]; ++j) {
            for (auto k : with[i][j]) {
                s.erase(s.find(v[i - 1][k]));
            }
            show(j, s);
            if (s.empty()) {
                v[i][j] = 1e18;
            } else {
                v[i][j] += *s.begin();
            }
            for (auto k : with[i][j]) {
                s.insert(v[i - 1][k]);
            }
        }
    }
    show(v);

    ll ans = mine(v.back());
    if (ans > 1e16)
        ans = -1;
    cout << ans << '\n';

    return 0;
}