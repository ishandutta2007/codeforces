/*
    author:  Maksim1744
    created: 13.04.2021 00:04:28
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

    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    cin >> a;
    auto b = a;
    sort(b.begin(), b.end());
    map<pair<int, int>, deque<int>> where;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) {
            where[{a[i], b[i]}].pb(i);
        }
    }
    show(a);
    show(b);
    show(where);
    int tot = 0;
    vector<vector<int>> ans;

    auto x = a;
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());

    vector<vector<int>> g(x.size());

    vector<pair<int, int>> e;

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            e.eb(lowb(x, a[i]), lowb(x, b[i]));
            g[e.back().first].pb(e.back().second);
        }
    }

    vector<bool> u(x.size(), false);
    vector<int> ind(g.size(), 0);

    for (int i = 0; i < x.size(); ++i) {
        if (!u[i] && !g[i].empty()) {
            vector<int> path;

            function<void(int)> go = [&](int v) {
                u[v] = true;
                while (ind[v] < g[v].size()) {
                    int i = ind[v];
                    ++ind[v];
                    go(g[v][i]);
                }
                path.pb(v);
            };

            go(i);

            vector<int> cyc;
            path.pop_back();
            show(path);
            for (int i = 0; i < path.size(); ++i) {
                int k = path[i];
                int k1 = path[(i + 1) % path.size()];
                cyc.pb(where[{x[k1], x[k]}][0] + 1);
                where[{x[k1], x[k]}].pop_front();
            }
            show(cyc);
            // reverse(cyc.begin(), cyc.end());
            ans.pb(cyc);
            tot += cyc.size();
        }
    }

    if (tot > s) {
        cout << -1 << '\n';
        return 0;
    }

    if (ans.size() > 1) {
        int left = s - tot;
        left = min(left, (int)ans.size());
        if (left > 2) {
            vector<int> c1;
            vector<int> c2;
            for (int i = 0; i < left; ++i) {
                auto c = ans.back();
                ans.pop_back();
                for (int j = 0; j < c.size(); ++j) {
                    c1.pb(c[j]);
                }
                c2.pb(c[0]);
            }
            reverse(c2.begin(), c2.end());
            ans.pb(c1);
            ans.pb(c2);
        }
    }

    cout << ans.size() << '\n';
    for (auto v : ans) {
        cout << v.size() << '\n';
        cout << v << '\n';
    }

    return 0;
}