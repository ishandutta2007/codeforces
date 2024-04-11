/*
    author:  Maksim1744
    created: 07.05.2021 17:48:55
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
    vector<int> dp1(n, 1e9);
    vector<int> dp2(n, 1e9);
    vector<int> fr1(n);
    vector<pair<int, int>> fr2(n);

    vector<bool> u(n, false);

    vector<vector<int>> chi(n);

    auto dfs = y_combinator([&](auto dfs, int v) -> void {
        u[v] = true;
        vector<int> ch;
        for (int k : g[v]) {
            if (!u[k]) {
                dfs(k);
                ch.pb(k);
            }
        }
        chi[v] = ch;
        if (ch.empty()) {
            dp1[v] = dp2[v] = 0;
            return;
        }
        int tot = 0;
        for (int k : ch)
            tot += min(dp1[k], dp2[k]);
        sort(ch.begin(), ch.end(), [&](int a, int b) {
            return dp1[a] - min(dp1[a], dp2[a]) < dp1[b] - min(dp1[b], dp2[b]);
        });
        int mn = dp1[ch[0]] - min(dp1[ch[0]], dp2[ch[0]]);
        dp1[v] = tot + mn + ch.size() - 1;
        fr1[v] = ch[0];
        if (ch.size() >= 2) {
            int a = ch[0];
            int b = ch[1];
            dp2[v] = tot + dp1[a] - min(dp1[a], dp2[a]) + dp1[b] - min(dp1[b], dp2[b]) + ch.size() - 2;
            fr2[v] = {a, b};
        }
    });
    dfs(0);
    show(dp1);
    show(dp2);
    int cur = min(dp1[0], dp2[0]);
    vector<pair<int, int>> dels, ads;
    cout << cur << '\n';
    int v = 0;
    show(chi);
    auto build = y_combinator([&](auto build, int v, int tp) -> void {
        int cur = min(dp1[v], dp2[v]);
        show(v, cur, tp, chi[v], fr1[v]);
        if (chi[v].empty()) return;
        if (cur == dp1[v] || tp == 1) {
            for (int k : chi[v]) {
                if (k != fr1[v]) {
                    dels.eb(minmax(v, k));
                    build(k, -1);
                }
            }
            v = fr1[v];
            build(v, 1);
        } else {
            for (int k : chi[v]) {
                if (k != fr2[v].first && k != fr2[v].second) {
                    dels.eb(minmax(v, k));
                    build(k, -1);
                }
            }
            cur -= chi[v].size() - 2;
            build(fr2[v].first, 1);
            build(fr2[v].second, 1);
        }
    });
    build(v, -1);
    show(dels);
    set<pair<int, int>> sdels(dels.begin(), dels.end());
    vector<int> deg(n, 0);
    DSU d(n);
    vector<pair<int, int>> prs;
    for (int i = 0; i < n; ++i) {
        for (int j : g[i]) {
            if (!sdels.count(minmax(i, j))) {
                ++deg[i];
                d.un(i, j);
            }
        }
    }
    vector<pair<int, int>> paths;
    map<int, vector<int>> where;
    for (int i = 0; i < n; ++i) {
        if (deg[i] <= 1)
            where[d.par(i)].pb(i);
    }
    for (auto [a, b] : where) {
        if (b.empty()) continue;
        if (b.size() == 1) {
            prs.eb(b[0], b[0]);
        } else if (b.size() == 2) {
            prs.eb(b[0], b[1]);
        } else {
            assert(false);
        }
    }
    for (int i = 0; i + 1 < prs.size(); ++i) {
        ads.eb(prs[i].second, prs[i + 1].first);
    }
    show(ads);
    ++dels;
    ++ads;
    for (int i = 0; i < dels.size(); ++i) {
        cout << dels[i] << ' ' << ads[i] << '\n';
    }
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