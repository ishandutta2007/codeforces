/*
    author:  Maksim1744
    created: 31.05.2020 18:09:46
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
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    if (sum(b) != sum(c)) {
        cout << -1 << '\n';
        return 0;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<bool> u(n, false);
    vector<int> p(n, -1);
    vector<vector<int>> wrong(n, vector<int>(2, 0));
    function<void(int, int)> dfs1 = [&](int v, int par) {
        u[v] = true;
        p[v] = par;
        for (auto k : g[v]) {
            if (!u[k]) {
                a[k] = min(a[v], a[k]);
                dfs1(k, v);
                // wrong[v] += wrong[k];
            }
        }
        // if (b[v] != c[v]) ++wrong[v];
    };
    dfs1(0, -1);
    u.assign(n, false);
    ll ans = 0;
    function<void(int)> dfs2 = [&](int v) {
        u[v] = true;
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs2(k);
                wrong[v][0] += wrong[k][0];
                wrong[v][1] += wrong[k][1];
            }
        }
        if (b[v] != c[v]) {
            wrong[v][b[v]]++;
        }
        ll can = min(wrong[v][0], wrong[v][1]);
        wrong[v][0] -= can;
        wrong[v][1] -= can;
        ans += can * 2 * a[v];
    };
    dfs2(0);
    cout << ans << endl;

    return 0;
}