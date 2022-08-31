/*
    author:  Maksim1744
    created: 16.08.2020 22:54:07
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

const ld pi = acosl(-1.0l);

ll dist(pair<ll, ll> a, pair<ll, ll> b) {
    ll x = a.first - b.first;
    ll y = a.second - b.second;
    return x * x + y * y;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<pair<pair<ll, ll>, ll>> v(n);
    cin >> v;
    vector<int> from(n, -1);
    for (int i = 0; i < n; ++i) {
        int best = -1;
        ll bestr = 1e9;
        for (int j = 0; j < n; ++j) {
            if (v[j].second <= v[i].second) continue;
            if (dist(v[i].first, v[j].first) < v[j].second * v[j].second) {
                if (bestr > v[j].second) {
                    best = j;
                    bestr = v[j].second;
                }
            }
        }
        from[i] = best;
    }
    show(from);
    vector<ld> area(n);
    for (int i = 0; i < n; ++i) {
        area[i] = (ld)v[i].second * v[i].second * pi;
    }
    ld ans = 0;
    vector<bool> u(n, false);
    vector<int> o;
    for (int i = 0; i < n; ++i) {
        if (from[i] == -1) {
            ans += area[i];
            u[i] = true;
        } else if (from[from[i]] == -1) {
            o.pb(i);
        }
    }
    for (auto i : o) {
        from[i] = -1;
    }
    vector<int> lvl(n, 1e9);
    for (int ii = 0; ii < n; ++ii) {
        for (int i = 0; i < n; ++i) {
            if (from[i] == -1) {
                lvl[i] = 0;
            } else {
                lvl[i] = min(lvl[i], lvl[from[i]] + 1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (lvl[i] % 2 == 1) {
            area[from[i]] -= area[i];
        }
    }
    for (int i = 0; i < n; ++i) {
        if (!u[i] && lvl[i] % 2 == 0)
            ans += area[i];
    }
    cout << fixed << setprecision(20) << ans << '\n';

    return 0;
}