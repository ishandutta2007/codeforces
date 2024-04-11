/*
    author:  Maksim1744
    created: 18.02.2021 17:58:50
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

const ll inf = 1e18;

template<typename T>
using pq = priority_queue<T, vector<T>, greater<T>>;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        int w;
        cin >> w;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }
    vector<ll> dist(n, inf);
    vector<vector<ll>> d1(n, vector<ll>(52, inf));
    dist[0] = 0;

    pq<pair<pair<ll, int>, int>> q;
    q.emplace(mp(0, -1), 0);
    while (!q.empty()) {
        auto [dw, v] = q.top();
        q.pop();
        auto [d, w] = dw;
        if (w == -1) {
            if (dist[v] < d) continue;
            for (auto [k, w2] : g[v]) {
                if (d1[k][w2] > d) {
                    d1[k][w2] = d;
                    q.emplace(mp(d1[k][w2], w2), k);
                }
            }
        } else {
            if (d1[v][w] < d) continue;
            for (auto [k, w2] : g[v]) {
                ll e = (w + w2);
                e *= e;
                if (dist[k] > d + e) {
                    dist[k] = d + e;
                    q.emplace(mp(dist[k], -1), k);
                }
            }
        }
    }


    for (int i = 0; i < n; ++i) {
        if (dist[i] == inf) dist[i] = -1;
    }
    cout << dist << '\n';

    return 0;
}