/*
    author:  Maksim1744
    created: 01.11.2020 17:26:50
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

const ll mod = 998244353;

ll dijkstra(vector<vector<pair<int, ll>>>& g, int from, vector<int> to) {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> s;
    vector<ll> d(g.size(), 1e18);
    d[from] = 0;
    s.emplace(0, from);
    vector<bool> ends(g.size(), false);
    for (auto k : to) {
        ends[k] = true;
    }
    while (!s.empty()) {
        auto [dd, v] = s.top();
        s.pop();
        if (ends[v]) break;
        if (dd > d[v]) continue;
        for (auto [k, w] : g[v]) {
            if (d[k] > d[v] + w) {
                d[k] = d[v] + w;
                s.emplace(d[k], k);
            }
        }
    }
    ll ans = 1e18;
    for (auto k : to) {
        ans = min(ans, d[k]);
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n), gi(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        gi[v].push_back(u);
    }
    vector<vector<pair<int, ll>>> g2(n * 2);
    for (int i = 0; i < n; ++i) {
        g2[i].eb(i + n, 1e9);
        g2[i + n].eb(i, 1e9);
        for (auto j : g[i]) {
            g2[i].eb(j, 1);
            g2[j + n].eb(i + n, 1);
        }
    }
    // show(g2);
    ll have = dijkstra(g2, 0, {n - 1, n + n - 1});
    ll revs = have / 1000000000;
    show(revs);
    if (revs >= 30) {
        assert(revs <= 1000000);
        ll real_cost = have % 1000000000;
        ll w = 1;
        for (int i = 0; i < revs; ++i) {
            real_cost = (real_cost + w) % mod;
            w = w * 2 % mod;
        }
        cout << real_cost % mod << endl;
        return 0;
    }
    ll real_cost = have % 1000000000;
    ll w = 1;
    for (int i = 0; i < revs; ++i) {
        real_cost += w;
        w *= 2;
    }
    // show(real_cost);
    ll ans = real_cost;
    const int K = 21;
    vector<vector<pair<int, ll>>> gl(n * K);
    for (int lvl = 0; lvl < K; ++lvl) {
        for (int i = 0; i < n; ++i) {
            if (lvl != 0) {
                gl[(lvl - 1) * n + i].eb(lvl * n + i, 1ll << (lvl - 1));
            }
            for (auto j : g[i]) {
                if (lvl % 2 == 0)
                    gl[lvl * n + i].eb(lvl * n + j, 1);
                else
                    gl[lvl * n + j].eb(lvl * n + i, 1);
            }
        }
    }
    vector<int> to;
    for (int i = 0; i < K; ++i) {
        to.pb(i * n + n - 1);
    }
    ll lgans = dijkstra(gl, 0, to);
    show(lgans);
    ans = min(ans, lgans);
    cout << ans % mod << '\n';

    return 0;
}