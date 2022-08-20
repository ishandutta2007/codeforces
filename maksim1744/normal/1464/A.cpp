/*
    author:  Maksim1744
    created: 20.12.2020 18:08:34
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
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + m);
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        --x; --y;
        if (x == y) continue;
        int ind = n + i;
        g[x].pb(ind);
        g[y].pb(ind);
        g[ind].pb(x);
        g[ind].pb(y);
    }
    vector<int> col(g.size(), -1);
    int color = 0;
    function<void(int)> dfs = [&](int v) {
        col[v] = color;
        for (auto k : g[v]) {
            if (col[k] == -1) {
                dfs(k);
            }
        }
    };
    for (int i = 0; i < g.size(); ++i) {
        if (col[i] == -1) {
            dfs(i);
            ++color;
        }
    }
    vector<vector<int>> comps(color);
    for (int i = 0; i < g.size(); ++i) {
        comps[col[i]].pb(i);
    }
    int ans = 0;
    for (auto comp : comps) {
        bool line = false;
        for (auto v : comp) {
            if (g[v].size() <= 1) {
                line = true;
                break;
            }
        }
        if (line) {
            ans += comp.size() / 2;
        } else {
            ans += comp.size() / 2 + 1;
        }
    }
    cout << ans << '\n';
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