/*
    author:  Maksim1744
    created: 04.06.2020 18:22:29
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

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    cin >> v;
    for (int i = 20; i >= 0; --i) {
        vector<pair<int, int>> e;
        int md = 1 << i;
        for (auto [x, y] : v) {
            e.eb(x % md, y % md);
        }
        vector<vector<int>> g(md);
        for (int i = 0; i < e.size(); ++i) {
            g[e[i].first].pb(i);
            g[e[i].second].pb(i);
        }
        bool ok = true;
        for (int i = 0; i < g.size(); ++i) {
            if (g[i].size() % 2 == 1) {
                ok = false;
                break;
            }
        }
        vector<int> eind(g.size(), 0);
        if (!ok) continue;
        vector<bool> u(e.size(), false);
        vector<pair<int, bool>> order;
        function<void(int)> dfs = [&](int v) {
            while (eind[v] < g[v].size()) {
                int ind = g[v][eind[v]];
                ++eind[v];
                if (!u[ind]) {
                    u[ind] = true;
                    dfs(e[ind].first + e[ind].second - v);
                    order.eb(ind, e[ind].first != v);
                }
            }
            // order.eb(v);
        };
        for (int i = 0; i < g.size(); ++i) {
            if (!g[i].empty()) {
                dfs(i);
                break;
            }
        }
        // show(e);
        // show(i, order.size());
        if (order.size() != e.size() + 0) continue;
        cout << i << '\n';
        for (int i = 0; i < order.size(); ++i) {
            auto [ind, b] = order[i];
            auto p = make_pair(ind * 2 + 1, ind * 2 + 2);
            if (!b) swap(p.first, p.second);
            cout << p << ' ';
        }
        cout << '\n';
        break;
    }

    return 0;
}