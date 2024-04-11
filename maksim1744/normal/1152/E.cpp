/*
    author:  Maksim1744
    created: 25.04.2019 18:38:38
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

vector<vector<int>> g;
vector<pair<int, int>> e;
vector<bool> ue;
vector<int> path;
vector<int> ind;

void go(int v) {
    show(v);
    while (ind[v] + 1 < g[v].size()) {
        if (!ue[g[v][++ind[v]]]) {
            ue[g[v][ind[v]]] = true;
            go(e[g[v][ind[v]]].first + e[g[v][ind[v]]].second - v);
        }
    }
    path.pb(v);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> b(n - 1), c(n - 1);
    cin >> b >> c;
    auto no = []() {
        cout << -1 << '\n';
        exit(0);
    };
    for (int i = 0; i < n - 1; ++i)
        if (b[i] > c[i])
            no();
    vector<int> p;
    p.reserve(2 * n);
    for (int i = 0; i < n - 1; ++i) {
        p.pb(b[i]);
        p.pb(c[i]);
    }
    sort(p.begin(), p.end());
    p.erase(unique(p.begin(), p.end()), p.end());
    // show(p);
    for (int i = 0; i < n - 1; ++i) {
        b[i] = lowb(p, b[i]);
        c[i] = lowb(p, c[i]);
    }
    // show(b, c);
    g.resize(p.size());
    vector<int> loops(p.size(), 0);
    for (int i = 0; i < n - 1; ++i) {
        if (b[i] != c[i]) {
            g[b[i]].pb(e.size());
            g[c[i]].pb(e.size());
            e.eb(b[i], c[i]);
        } else {
            ++loops[b[i]];
        }
    }
    vector<int> odd;
    for (int i = 0; i < g.size(); ++i) {
        if (g[i].size() % 2)
            odd.pb(i);
    }
    int start = 0;
    if (odd.size() == 2) {
        start = odd[0];
        // g[odd[0]].pb(e.size());
        // g[odd[1]].pb(e.size());
        // e.eb(odd[0], odd[1]);
    }
    // show(g);
    path.reserve(e.size() + 10);
    if (odd.size() == 0 || odd.size() == 2) {
        ue.assign(e.size(), false);
        ind.assign(g.size(), -1);
        go(start);
        // int cut = path.size() - 1;
        // if (odd.size() == 2) {
        //     for (int i = 0; i < path.size() - 1; ++i) {
        //         if (set<int>{path[i], path[i + 1]} == set<int>{odd[0], odd[1]}) {
        //             cut = i;
        //             break;
        //         }
        //     }
        // }
        show(path);
        // for (int i = cut + 1; i < path.size(); ++i)
        //     cout << p[path[i]] << ' ';
        vector<int> ans;
        vector<bool> u(p.size(), false);
        for (int i = 0; i < path.size(); ++i) {
            for (int j = 0; j < loops[path[i]] + 1; ++j) {
                ans.pb(p[path[i]]);
                u[path[i]] = true;
            }
            loops[path[i]] = 0;
        }
        for (auto y : u) {
            if (!y)
                no();
        }
        if (ans.size() != n)
            no();
        cout << ans << '\n';
    } else no();
    return 0;
}