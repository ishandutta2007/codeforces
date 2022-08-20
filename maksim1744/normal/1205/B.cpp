/*
    author:  Maksim1744
    created: 18.08.2019 16:56:51
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

const int inf = 1e7;

int main() {
    int n;
    cin >> n;
    vector<ll> a;
    for (int i = 0; i < n; ++i) {
        ll k;
        cin >> k;
        if (k == 0)
            continue;
        else
            a.pb(k);
    }
    n = a.size();
    if (n <= 2) {
        cout << -1 << '\n';
        return 0;
    }
    vector<vector<ll>> bybits(62);
    for (auto k : a) {
        for (int i = 0; i < bybits.size(); ++i) {
            if (k & (1ll << i)) {
                bybits[i].pb(k);
            }
        }
    }
    for (int i = 0; i < bybits.size(); ++i) {
        if (bybits[i].size() >= 3) {
            cout << 3 << '\n';
            return 0;
        }
    }
    assert(n <= 128);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (a[i] & a[j]) {
                g[i].pb(j);
                g[j].pb(i);
            }
        }
    }
    int best = inf;
    for (int i = 0; i < n; ++i) {
        vector<bool> u(n, false);
        vector<int> p(n, -1);
        u[i] = true;
        queue<int> q;
        q.push(i);
        bool found = false;
        while (!q.empty() && !found) {
            int v = q.front();
            q.pop();
            for (auto k : g[v]) {
                if (k == p[v])
                    continue;
                if (u[k]) {
                    int v1 = k, v2 = v;
                    int now = 1;
                    while (v1 != i) {
                        v1 = p[v1];
                        ++now;
                    }
                    while (v2 != i) {
                        v2 = p[v2];
                        ++now;
                    }
                    best = min(best, now);
                    found = true;
                    break;
                } else {
                    u[k] = true;
                    p[k] = v;
                    q.push(k);
                }
            }
        }
    }

    if (best == inf)
        best = -1;
    cout << best << '\n';
    return 0;
}