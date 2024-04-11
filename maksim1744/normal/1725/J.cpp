/*
    author:  Maksim1744
    created: 04.09.2022 17:56:24
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    ll total = 0;
    for (int i = 0; i < n - 1; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        --u; --v;
        total += w;
        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    vector<ll> path(n, 0);
    vector<ll> diam(n, 0);
    y_combinator([&](auto dfs, int v, int p) -> void {
        ll mx1 = 0, mx2 = 0;
        for (auto [k, w] : g[v]) {
            if (k == p) continue;
            dfs(k, v);
            ll x = path[k] + w;
            path[v] = max(path[v], x);
            if (x >= mx1) {
                mx2 = mx1;
                mx1 = x;
            } else {
                mx2 = max(mx2, x);
            }
            diam[v] = max(diam[v], diam[k]);
        }
        diam[v] = max(diam[v], mx1 + mx2);
    })(0, -1);

    show(diam);
    show(path);

    ll ans = 0;
    y_combinator([&](auto dfs, int v, int p, ll updiam, ll uppath) -> void {
        vector<int> ch;
        vector<ll> ws;
        for (auto [k, w] : g[v]) {
            if (k == p) continue;
            ws.pb(w);
            ch.pb(k);
        }
        if (ch.empty()) return;
        vector<ll> prefdiam(ch.size() + 2, 0), sufdiam(ch.size() + 2, 0);
        vector<pair<ll, ll>> prefmx(ch.size() + 2, {0, 0}), sufmx(ch.size() + 2, {0, 0});
        for (int i = 0; i < ch.size(); ++i) {
            prefdiam[i + 1] = sufdiam[i + 1] = diam[ch[i]];
        }
        for (int i = 1; i < prefdiam.size(); ++i)
            prefdiam[i] = max(prefdiam[i], prefdiam[i - 1]);
        for (int i = (int)sufdiam.size() - 2; i >= 0; --i)
            sufdiam[i] = max(sufdiam[i], sufdiam[i + 1]);

        auto addmx = [&](pair<ll, ll> a, ll b) {
            if (b >= a.first) {
                a.second = a.first;
                a.first = b;
            } else {
                a.second = max(a.second, b);
            }
            return a;
        };

        auto mergemx = [&](pair<ll, ll> a, pair<ll, ll> b) {
            a = addmx(a, b.first);
            a = addmx(a, b.second);
            return a;
        };

        for (int i = 0; i < ch.size(); ++i) {
            ll x = path[ch[i]] + ws[i];
            prefmx[i + 1] = addmx(prefmx[i], x);
        }
        for (int i = (int)ch.size() - 1; i >= 0; --i) {
            ll x = path[ch[i]] + ws[i];
            sufmx[i + 1] = addmx(sufmx[i + 2], x);
        }

        vector<ll> here = {uppath};
        for (int i = 0; i < ch.size(); ++i) {
            here.pb(ws[i] + path[ch[i]]);
        }
        if (here.size() >= 4) {
            sort(here.begin(), here.end());
            reverse(here.begin(), here.end());
            ans = max(ans, here[0] + here[1] + here[2] + here[3]);
        }

        show(v, ch);
        if (v == 0) {
            show(ch);
            show(ws);
            show(prefmx);
            show(sufmx);
            show(prefdiam);
            show(sufdiam);
        }

        for (int i = 0; i < ch.size(); ++i) {
            ll cur = ws[i] * 2;
            cur += diam[ch[i]];
            pair<ll, ll> mxs = prefmx[i];
            mxs = mergemx(mxs, sufmx[i + 2]);
            mxs = addmx(mxs, uppath);
            ll d = max({updiam, prefdiam[i], sufdiam[i + 2], mxs.first + mxs.second});
            cur += d;
            if (v == 0) {
                show(mxs);
                show(ch[i], d, cur);
            }
            ans = max(ans, cur);

            dfs(ch[i], v, d, mxs.first + ws[i]);
        }
    })(0, -1, 0, 0);

    show(total, ans);
    cout << total * 2 - ans << '\n';

    return 0;
}