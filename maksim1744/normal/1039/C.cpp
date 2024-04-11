/*
    author:  Maksim1744
    created: 07.05.2019 15:35:44
*/

#include <bits/stdc++.h>

using namespace std;

#define ll   long long
#define ld   long double

#define mp   make_pair
#define pb   push_back
#define eb   emplace_back

#define mine(a)    (*min_element((a).begin(), (a).end()))
#define maxe(a)    (*max_element((a).begin(), (a).end()))
#define mini(a)    ( min_element((a).begin(), (a).end()) - (a).begin())
#define maxi(a)    ( max_element((a).begin(), (a).end()) - (a).begin())
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}

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
#define showt(...)       42;
#define printTree(...)   42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

const int nax = 500005;
const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<ll> p2(nax, 1);
    for (int i = 1; i < nax; ++i)
        p2[i] = p2[i - 1] * 2 % mod;
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> c(n);
    cin >> c;
    map<ll, pair<vector<int>, vector<int>>> cnt;
    vector<pair<int, int>> es;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        es.eb(u, v);
        pair<vector<int>, vector<int>>& s = cnt[c[u] ^ c[v]];
        s.first.pb(u);
        s.first.pb(v);
        s.second.pb(i);
    }
    vector<int> p(n);
    vector<int> rk(n);
    function<int(int)> par = [&](int v) {
        if (v == p[v])
            return v;
        p[v] = par(p[v]);
        return p[v];
    };
    auto un = [&](int u, int v) {
        u = par(u); v = par(v);
        if (u == v)
            return false;
        if (rk[u] < rk[v]) {
            p[u] = v;
            rk[v] += rk[u];
        } else {
            p[v] = u;
            rk[u] += rk[v];
        }
        return true;
    };
    show(es);
    ll ans = 0;
    for (auto& r : cnt) {
        shows;
        sort(r.second.first.begin(), r.second.first.end());
        r.second.first.erase(unique(r.second.first.begin(), r.second.first.end()), r.second.first.end());
        show(r);
        auto& v = r.second.first;
        for (int i = 0; i < v.size(); ++i) {
            p[v[i]] = v[i];
            rk[v[i]] = 1;
        }
        int comp = v.size();
        for (auto j : r.second.second) {
            comp -= (int)un(es[j].first, es[j].second);
        }
        show(comp);
        ll now = ((p2[v.size()] - p2[comp]) % mod + mod) * p2[n - (int)v.size()] % mod;
        show(now);
        ans += now;
    }
    ans = (p2[n] * p2[k] % mod - ans) % mod + mod;
    cout << ans % mod << '\n';
    return 0;
}