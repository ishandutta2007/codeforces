/*
    author:  Maksim1744
    created: 02.05.2021 18:51:24
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
#include "C:/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

vector<int> scc(vector<vector<pair<int, ll>>>& g) {
    int n = g.size();
    vector<int> topsort; topsort.reserve(n);
    vector<bool> u(n, false);
    function<void(int)> scc_dfs1 = [&](int v) {
        u[v] = true;
        for (auto [k, w] : g[v])
            if (!u[k])
                scc_dfs1(k);
        topsort.push_back(v);
    };
    for (int i = 0; i < n; ++i)
        if (!u[i])
            scc_dfs1(i);
    vector<vector<int>> gi(n);
    for (int i = 0; i < n; ++i)
        for (auto [j, w] : g[i])
            gi[j].push_back(i);
    int color = 0;
    vector<int> comp(n, -1);
    reverse(topsort.begin(), topsort.end());
    function<void(int, int)> scc_dfs2 = [&](int v, int color) {
        comp[v] = color;
        for (auto k : gi[v])
            if (comp[k] == -1)
                scc_dfs2(k, color);
    };
    for (auto v : topsort)
        if (comp[v] == -1)
            scc_dfs2(v, color++);
    return comp;
}

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
// auto gcd = std::y_combinator([](auto gcd, int a, int b) -> int {
//     return b == 0 ? a : gcd(b, a % b);
// });

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, ll>>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        --a; --b;
        g[a].eb(b, w);
    }

    auto col = scc(g);
    vector<vector<int>> comps(maxe(col) + 1);
    for (int i = 0; i < n; ++i) {
        comps[col[i]].pb(i);
    }

    vector<ll> a(n, 0);
    vector<bool> u(n, false);
    for (int i = 0; i < comps.size(); ++i) {
        if (comps[i].size() == 1) {
            a[comps[i][0]] = -1;
            continue;
        }
        auto dfs = y_combinator([&](auto self, int v) -> void {
            u[v] = true;
            for (auto [k, w] : g[v]) {
                if (col[k] != col[v]) continue;
                if (u[k]) continue;
                a[k] = a[v] + w;
                self(k);
            }
        });
        a[comps[i][1]] = 0;
        dfs(comps[i][1]);
        ll dd = a[comps[i][0]];
        for (int k : comps[i])
            u[k] = false;
        a[comps[i][0]] = 0;
        dfs(comps[i][0]);
        show(a);
        ll x = dd + a[comps[i][1]];
        show(a);
        show(x);
        for (int v : comps[i]) {
            for (auto [k, w] : g[v]) {
                if (col[k] != col[v]) continue;
                x = gcd(x, abs(a[v] + w - a[k]));
            }
        }
        assert(x != 0);
        for (int v : comps[i])
            a[v] = x;
    }

    show(a);

    int q;
    cin >> q;
    while (q--) {
        int v, s, t;
        cin >> v >> s >> t;
        --v;
        if (s == 0) {
            cout << "YES\n";
            continue;
        }
        if (a[v] == -1) {
            cout << "NO\n";
            continue;
        }
        ll d = t - s;
        if (d % gcd(a[v], t) == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}