/*
    author:  Maksim1744
    created: 02.05.2021 18:06:50
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

struct DSU {
    vector<int> rk;
    vector<int> p;
    int n;

    DSU(int n = 1) : n(n) {
        reset(n);
    }

    void reset(int n) {
        p.resize(n);
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
        if (rk[u] > rk[v]) swap(u, v);
        p[u] = v;
        rk[v] += rk[u];
        return true;
    }

    bool check(int u, int v) {
        return par(u) == par(v);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    ll x;
    cin >> x;

    vector<ll> a(n);
    cin >> a;

    vector<vector<pair<int, int>>> g0(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g0[u].eb(v, i);
        g0[v].eb(u, i);
    }

    vector<vector<pair<int, int>>> g(n);
    {
        vector<bool> u(n, false);
        y_combinator([&](auto self, int v) -> void {
            u[v] = true;
            show(v);
            for (auto [k, i] : g0[v]) {
                if (!u[k]) {
                    self(k);
                    g[v].eb(k, i);
                    g[k].eb(v, i);
                }
            }
        })(0);
    }

    vector<int> where(n);
    for (int i = 0; i < n; ++i) {
        where[i] = i;
    }
    vector<vector<int>> sets(n);
    for (int i = 0; i < n; ++i) {
        sets[i].pb(i);
    }

    set<pair<ll, int>> st;
    for (int i = 0; i < n; ++i) {
        st.emplace(-a[i], i);
    }

    vector<int> ind(n, 0);
    vector<bool> u(m, false);
    vector<int> ans;

    vector<ll> sm = a;

    DSU d(n);

    set<int> wheres;
    for (int i = 0; i < n; ++i) {
        wheres.insert(i);
    }

    auto un = [&](int v, int u) {
        d.un(v, u);
        assert(wheres.count(v));
        int i1 = where[v];
        assert(wheres.count(u));
        int i2 = where[u];
        assert(i1 != i2);
        if (sets[i1].size() < sets[i2].size()) swap(i1, i2);

        for (int k : sets[i2]) {
            where[k] = i1;
            sets[i1].pb(k);
        }

        sm[i1] = sm[i1] + sm[i2] - x;

        return i1;
    };

    show(g);

    ll S = sum(a);
    if (S < (ll)(n - 1) * x) {
        cout << "NO\n";
        // cout << "YES\n";
        return 0;
    }
    cout << "YES\n";

    while (st.size() > 1) {
        auto [w, s] = *st.begin();
        st.erase(st.begin());
        show(st);
        while (true) {
            int v = sets[s].back();
            show(sets[s]);
            show(v);
            show(g);
            show(ind);
            show(sets);
            show(where);
            show(st);
            if (ind[v] == g[v].size()) {
                sets[s].pop_back();
            } else if (d.check(g[v][ind[v]].first, v)) {
                ++ind[v];
            } else if (u[g[v][ind[v]].second]) {
                assert(false);
                ++ind[v];
            } else {
                ans.pb(g[v][ind[v]].second);
                int k = g[v][ind[v]].first;
                assert(sm[where[v]] + sm[where[k]] >= x);
                assert(wheres.count(v));
                assert(wheres.count(k));
                st.erase({-sm[where[k]], where[k]});
                int ii = un(v, k);
                st.emplace(-sm[ii], ii);
                break;
            }
        }
    }

    assert(ans.size() == n - 1);

    ++ans;
    for (int k : ans)
        cout << k << '\n';

    return 0;
}