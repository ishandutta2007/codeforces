/*
    author:  Maksim1744
    created: 19.11.2019 20:58:37
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
    int n;
    cin >> n;
    vector<vector<int>> v(n, vector<int>(3));
    cin >> v;
    --v;
    vector<int> cnt(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            cnt[v[i][j]]++;
        }
    }
    map<pair<int, int>, vector<int>> near;
    for (int i = 0; i < n; ++i) {
        near[mp(v[i][0], v[i][1])].pb(v[i][2]);
        near[mp(v[i][1], v[i][0])].pb(v[i][2]);
        near[mp(v[i][1], v[i][2])].pb(v[i][0]);
        near[mp(v[i][2], v[i][1])].pb(v[i][0]);
        near[mp(v[i][2], v[i][0])].pb(v[i][1]);
        near[mp(v[i][0], v[i][2])].pb(v[i][1]);
    }
    vector<int> p;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 1) {
            p.pb(i);
            cnt[i] = 0;
            break;
        }
    }
    vector<bool> u(n, false);
    u[p[0]] = true;
    for (int i = 0; i < n; ++i) {
        if (cnt[i] == 2 && !u[i] && near.count(mp(p[0], i))) {
            p.pb(i);
            u[i] = true;
            break;
        }
    }
    show(p);
    while (p.size() < n) {
        auto it = near.find(mp(p[p.size() - 2], p[p.size() - 1]));
        for (auto v : it->second) {
            if (!u[v]) {
                p.pb(v);
                u[v] = true;
            }
        }
    }
    ++p;
    cout << p << endl;
    return 0;
}