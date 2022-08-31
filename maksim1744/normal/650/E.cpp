/*
    author:  Maksim1744
    created: 24.07.2021 21:42:02
*/

#include "bits/stdc++.h"

using namespace std;

using ll = long long;
using ld = long double;

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

template<typename T>             vector<T>& operator--            (vector<T> &v){for (auto& i : v) --i;            return  v;}
template<typename T>             vector<T>& operator++            (vector<T> &v){for (auto& i : v) ++i;            return  v;}
template<typename T>             istream& operator>>(istream& is,  vector<T> &v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>  v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U> &p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>  p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "/home/maksim/cpplibs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

struct DSU {
    vector<int> rk;
    vector<int> p;
    vector<vector<pair<int, int>>> edges;
    set<pair<int, int>> removed;
    int n;

    DSU(int n = 1) : n(n) {
        reset(n);
    }

    void reset(int n) {
        p.resize(n);
        edges.resize(n);
        iota(p.begin(), p.end(), 0);
        rk.assign(n, 1);
    }

    int par(int v) {
        return v == p[v] ? v : p[v] = par(p[v]);
    }

    bool un(int u, int v) {
        u = par(u);
        v = par(v);
        if (u == v) return false;
        if (edges[u].size() > edges[v].size()) swap(u, v);
        p[u] = v;
        rk[v] += rk[u];
        for (auto e : edges[u])
            edges[v].pb(e);
        return true;
    }

    bool check(int u, int v) {
        return par(u) == par(v);
    }

    void add_edge(int u, int v) {
        int pu = par(u);
        int pv = par(v);
        if (u > v) swap(u, v);
        assert(pu != pv);
        edges[pu].eb(u, v);
        edges[pv].eb(u, v);
    }

    void del_edge(int u, int v) {
        if (u > v)
            swap(u, v);
        removed.emplace(u, v);
    }

    pair<int, int> get_edge(int v) {
        v = par(v);
        while (!edges[v].empty() && removed.count(edges[v].back()))
            edges[v].pop_back();
        assert(!edges[v].empty());
        return edges[v].back();
    }
};

template<class Fun>
class y_combinator_result {
    Fun fun_;
public:
    template<class T>
    explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
    decltype(auto) operator()(Args &&...args) {
        return fun_(std::ref(*this), std::forward<Args>(args)...);
    }
};
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<int>> g(n);
    set<pair<int, int>> other;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].pb(v);
        g[v].pb(u);
    }

    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        if (u > v) swap(u, v);
        --u; --v;
        other.emplace(u, v);
    }

    vector<pair<int, pair<int, int>>> order;
    DSU d(n);

    y_combinator([&](auto dfs, int v, int p) -> void {
        for (int k : g[v]) {
            if (k != p) {
                dfs(k, v);
                if (other.count(minmax(k, v))) {
                    d.un(k, v);
                    other.erase(minmax(k, v));
                } else {
                    order.eb(k, mp(k, v));
                }
            }
        }
    })(0, -1);

    for (auto [u, v] : other)
        d.add_edge(u, v);
    
    vector<pair<pair<int, int>, pair<int, int>>> ans;
    
    for (auto [v, e] : order) {
        auto [x, y] = d.get_edge(v);
        d.del_edge(x, y);
        ans.eb(e, mp(x, y));
        assert(!d.check(x, y));
        d.un(x, y);
    }

    cout << ans.size() << '\n';
    ++ans;
    for (auto p : ans)
        cout << p << '\n';

    return 0;
}