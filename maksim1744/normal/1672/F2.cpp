/*
    author:  Maksim1744
    created: 23.04.2022 19:49:34
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
#include "/mnt/c/Libs/tools/print.cpp"
#else
#define show(...) void(0)
#define debugf(fun)   fun
#define debugv(var)   var
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#define OSTREAM(...)    ;
#define OSTREAM0(...)   ;
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

mt19937_64 rng(738628);
ll rnd (ll l, ll r) { return (ll)(rng() % (r - l + 1)) + l; }
ll rnd (ll r)       { return rng() % r; }
ll rnd ()           { return rng(); }
ld rndf()           { return (ld)rng() / (ld)ULLONG_MAX; }
ld rndf(ld l, ld r) { return rndf() * (r - l) + l; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a;
    auto x = a;
    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());
    for (int i = 0; i < n; ++i) {
        a[i] = lowb(x, a[i]);
    }
    map<int, vector<int>> where;
    for (int i = 0; i < n; ++i) {
        where[a[i]].pb(i);
    }
    int cnt = 0;
    while (!where.empty()) {
        vector<int> cyc;
        for (auto& [a, b] : where) {
            cyc.pb(b.back());
            b.pop_back();
        }
        ++cnt;

        vector<int> bad;
        for (auto& [a, b] : where)
            if (b.empty())
                bad.pb(a);
        for (int k : bad)
            where.erase(k);
    }

    vector<int> b(n);
    cin >> b;
    for (int i = 0; i < n; ++i) {
        b[i] = lowb(x, b[i]);
    }
    int N = x.size();

    vector<pair<int, int>> e;
    vector<vector<int>> g(N);
    for (int i = 0; i < n; ++i) {
        e.eb(a[i], b[i]);
        g[a[i]].pb(e.size() - 1);
    }
    int m = e.size();
    vector<char> ue(m, false);
    vector<int> path;
    vector<int> ind(N, -1);
    vector<char> u(N, false);
    vector<char> has(N, false);
    vector<int> curp;
    for (int it = 0; it < 17; ++it) {
        ue.assign(m, false);
        path.clear();
        ind.assign(N, -1);
        u.assign(N, false);
        has.assign(N, false);
        curp.clear();
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            shuffle(g[i].begin(), g[i].end(), rng);
        }

        auto go = y_combinator([&](auto go, int v, int eid) -> void {
            u[v] = true;
            while (ind[v] + 1 < g[v].size()) {
                if (!ue[g[v][++ind[v]]]) {
                    ue[g[v][ind[v]]] = true;
                    go(e[g[v][ind[v]]].first ^ e[g[v][ind[v]]].second ^ v, g[v][ind[v]]);
                }
            }
            path.push_back(v);
        });
        for (int i = 0; i < N; ++i) {
            if (!u[i]) {
                go(i, -1);
            }
        }

        show(g);
        show(e);

        show(path);

        for (int k : path) {
            if (has[k]) {
                while (has[k]) {
                    has[curp.back()] = false;
                    curp.pop_back();
                }
                ++ans;
            }
            has[k] = true;
            curp.pb(k);
        }
        show(ans, cnt);
        if (ans != cnt) {
            cout << "WA\n";
            // assert(it == 0);
            return;
        }
    }
    cout << "AC\n";
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