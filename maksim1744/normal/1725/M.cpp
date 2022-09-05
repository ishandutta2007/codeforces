/*
    author:  Maksim1744
    created: 04.09.2022 16:57:35
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
#endif

template<typename T>
using pq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n), gi(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].eb(v, w);
        gi[v].eb(u, w);
    }

    const ll inf = 1e18;
    vector<ll> d(n, inf);
    d[0] = 0;
    pq<pair<ll, int>> q;
    q.emplace(0, 0);
    while (!q.empty()) {
        auto [dd, v] = q.top();
        q.pop();
        if (d[v] != dd) continue;
        for (auto [k, w] : g[v]) {
            if (d[k] > d[v] + w) {
                d[k] = d[v] + w;
                q.emplace(d[k], k);
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        q.emplace(d[i], i);
    }
    while (!q.empty()) {
        auto [dd, v] = q.top();
        q.pop();
        if (d[v] != dd) continue;
        for (auto [k, w] : gi[v]) {
            if (d[k] > d[v] + w) {
                d[k] = d[v] + w;
                q.emplace(d[k], k);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (d[i] == inf) d[i] = -1;
    }
    d.erase(d.begin());
    cout << d << '\n';

    return 0;
}