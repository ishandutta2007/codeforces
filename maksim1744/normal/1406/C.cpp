/*
    author:  Maksim1744
    created: 12.09.2020 16:55:48
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

void test_case(int test) {
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<int> sz(n, 1);
    vector<bool> u(n, false);
    map<int, vector<int>> best;
    function<void(int)> dfs = [&](int v) {
        u[v] = true;
        int cur_max = 0;
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs(k);
                sz[v] += sz[k];
                cur_max = max(cur_max, sz[k]);
            }
        }
        cur_max = max(cur_max, n - sz[v]);
        best[cur_max].pb(v);
    };
    dfs(0);
    // show(sz);
    auto v = best.begin()->second;
    if (v.size() == 1) {
        cout << 1 << ' ' << g[0][0] + 1 << '\n';
        cout << 1 << ' ' << g[0][0] + 1 << '\n';
        return;
    }
    // show(best);
    // show(v);
    assert(v.size() == 2);
    int a = v[0], b = v[1];
    u.assign(n, false);
    u[b] = true;
    dfs(a);
    int leaf = -1;
    for (int i = 0; i < n; ++i) {
        if (g[i].size() == 1 && u[i] && i != a && i != b) {
            leaf = i;
            break;
        }
    }
    int pleaf = g[leaf][0];
    cout << leaf + 1 << ' ' << pleaf + 1 << '\n';
    cout << leaf + 1 << ' ' << b + 1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        test_case(test);
    }

    return 0;
}