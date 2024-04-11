/*
    author:  Maksim1744
    created: 20.06.2020 18:24:57
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

pair<int, int> ask(vector<int> v) {
    ++v;
    cout << "? " << v.size() << ' ' << v << endl;
    int a, b;
    cin >> a >> b;
    --a;
    return {a, b};
}

void say(int a, int b) {
    ++a;
    ++b;
    cout << "! " << a << ' ' << b << endl;
    string s;
    cin >> s;
    if (s != "Correct") exit(0);
}

void test_case() {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        --a; --b;
        g[a].pb(b);
        g[b].pb(a);
    }
    vector<int> vv;
    for (int i = 0; i < n; ++i) {
        vv.pb(i);
    }
    auto [v, d] = ask(vv);
    show(v, d);
    vector<bool> u(n, false);
    vector<int> level(n);
    vector<int> par(n, -1);
    function<void(int, int, int)> dfs = [&](int v, int lvl, int p) {
        u[v] = true;
        level[v] = lvl;
        par[v] = p;
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs(k, lvl + 1, v);
            }
        }
    };
    dfs(v, 0, -1);
    vector<vector<int>> bylvl(n + 5);
    for (int i = 0; i < n; ++i) {
        bylvl[level[i]].pb(i);
    }
    show(bylvl);
    int l = 0, r = d + 1;
    while (l * 2 < d) ++l;
    map<int, int> asked;
    asked[0] = v;
    while (r - l > 1) {
        int c = (l + r) / 2;
        if (bylvl[c].empty()) {
            r = c;
            continue;
        }
        auto [x, ss] = ask(bylvl[c]);
        asked[c] = x;
        if (ss == d) {
            l = c;
        } else {
            r = c;
        }
    }
    show(asked);
    show(l, r);
    u.assign(n, false);
    // auto [v1, tmp1] = ask(bylvl[l]);
    int v1, tmp1;
    if (!asked.count(l))
        tie(v1, tmp1) = ask(bylvl[l]);
    else
        v1 = asked[l];
    show(v1);
    int x = v1;
    while (x != -1) {
        u[x] = true;
        x = par[x];
    }
    if (l == d) {
        say(v1, v);
    } else {
        vv.clear();
        for (auto k : bylvl[d - l]) {
            if (!u[k])
                vv.pb(k);
        }
        show(vv);
        auto [v2, tmp2] = ask(vv);
        show(v2);
        say(v1, v2);
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        test_case();
    }

    return 0;
}