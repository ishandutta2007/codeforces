/*
    author:  Maksim1744
    created: 12.05.2019 18:35:26
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
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}

#ifdef HOME
#define TAG_LENGTH       25
#define LR_LEFT          left
#define LR_RIGHT         right
#define LR_VALUE         value
#define LR_SECOND_VALUE  mn
#include "C:/C++ libs/print.cpp"
const int nax = 7;
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
const int nax = 500005;
#endif


int is = 0;
array<int, nax> a, p, ts;
array<vector<int>, nax> g, to;
array<bool, nax> u;
vector<int> st;

void dfs(int v) {
    u[v] = true;
    for (auto k : g[v])
        if (!u[k])
            dfs(k);
    ts[is++] = v;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        --a[i];
    }
    is = 0;
    for (int i = 0; i < n + 1; ++i) {
        g[i].clear();
        to[i].clear();
        p[i] = -1;
        u[i] = false;
        ts[i] = -1;
    }
    int r = -1;
    for (int i = 0; i < n; ++i) {
        if (a[i] == -2)
            a[i] = i + 1;
        // if (i >= r) {
        //     r = a[i];
        // } else {
        //     if (a[i] > r) {
        //         cout << -1 << '\n';
        //         return;
        //     }
        // }
    }
    for (int i = 0; i < n; ++i) {
        to[a[i]].pb(i);
    }
    for (int i = 0; i < n + 1; ++i)
        for (int j = 0; j + 1 < to[i].size(); ++j)
            g[to[i][j]].pb(to[i][j + 1]);
    for (int i = 0; i < n + 1; ++i)
        for (int j = 0; j < to[i].size(); ++j)
            g[i].pb(to[i][j]);
    for (int i = n; i >= 0; --i) {
        if (!u[i])
            dfs(i);
    }
    int y = 1;
    for (int i = 0; i < n + 1; ++i) {
        p[ts[i]] = y++;
    }
    // show(g, ts, p, a);
    st = {n};
    for (int i = n - 1; i >= 0; --i) {
        while (p[i] > p[st.back()])
            st.pop_back();
        if (a[i] != st.back()) {
            cout << -1 << '\n';
            return;
        }
        st.push_back(i);
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] << ' ';
    }
    cout << '\n';
    // show(g);
    // show(to);
    // cout << 0 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}