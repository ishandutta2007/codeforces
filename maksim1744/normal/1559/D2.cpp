/*
    author:  Maksim1744
    created: 15.08.2021 17:53:14
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
#include "/mnt/c/C++ libs/print.cpp"
#else
#define show(...) void(0)
#define mclock    void(0)
#define shows     void(0)
#define debug  if (false)
#endif

struct DSU {
    vector<int> rk;
    vector<int> p;
    vector<int> mx;
    vector<set<int>> good;
    int n;

    DSU(int n = 1) : n(n) {
        reset(n);
    }

    void reset(int n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
        mx = p;
        good.resize(n);
        for (int i = 0; i < n; ++i) {
            good[i].insert(i);
        }
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
        mx[v] = max(mx[v], mx[u]);
        if (good[u].size() > good[v].size()) swap(good[u], good[v]);
        for (int k : good[u])
            good[v].insert(k);
        return true;
    }

    bool check(int u, int v) {
        return par(u) == par(v);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m1, m2;
    cin >> n >> m1 >> m2;

    DSU d1(n), d2(n);

    vector<vector<int>> g(n);
    for (int i = 0; i < m1; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        d1.un(u, v);
    }

    for (int i = 0; i < m2; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        d2.un(u, v);
    }

    set<int> par2;
    for (int i = 0; i < n; ++i)
        if (d2.par(i) == i)
            par2.insert(i);
    set<int> good2;
    for (int i = 0; i < n; ++i)
        if (d2.par(i) == i)
            good2.insert(i);

    set<int> left1;
    for (int i = 0; i < n; ++i) {
        left1.insert(i);
    }
    auto mark_bad = [&](int v) {
        show("bad", v);
        left1.erase(v);
        int p = d2.par(v);
        d2.good[p].erase(v);
        if (d2.good[p].empty()) good2.erase(p);
    };

    for (int i = 0; i < n; ++i)
        if (d1.check(i, 0))
            mark_bad(i);

    vector<pair<int, int>> ans;
    while (!left1.empty()) {
        int i = *left1.begin();
        if (par2.size() < 2) break;
        if (d1.check(0, i)) assert(false);
        shows;
        show(left1);
        show(i);
        show(d1.p, d2.p);
        show(d1.good, d2.good);
        show(good2, par2);

        auto unv = [&](int a, int b) {
            assert(!d1.check(a, b));
            assert(!d2.check(a, b));
            ans.eb(a, b);
            for (int k : d1.good[d1.par(b)])
                mark_bad(k);
            d1.un(a, b);

            par2.erase(d2.par(a));
            par2.erase(d2.par(b));
            good2.erase(d2.par(a));
            good2.erase(d2.par(b));
            d2.un(a, b);
            par2.insert(d2.par(a));
            if (!d2.good[d2.par(a)].empty())
                good2.insert(d2.par(a));
        };

        assert(!good2.empty());
        if (good2.size() >= 2) {
            int a = 0;
            int b1 = *d2.good[*good2.begin()].begin();
            int b2 = *d2.good[*next(good2.begin())].begin();
            int b = b1;
            if (d2.check(a, b)) b = b2;
            show(a, b);
            unv(a, b);
        } else {
            int c = -1;
            for (int k : par2) {
                if (!good2.count(k)) {
                    c = k;
                    break;
                }
            }
            assert(c != -1);
            show(c, i);
            unv(c, i);
        }
    }

    assert(d1.rk[d1.par(0)] == n || d2.rk[d2.par(0)] == n);

    cout << ans.size() << '\n';
    for (auto [u, v] : ans)
        cout << u + 1 << ' ' << v + 1 << '\n';

    return 0;
}