/*
    author:  Maksim1744
    created: 21.10.2019 20:53:51
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
#endif

const ll mod = 1e9 + 7;

long long mpow(long long a, long long p, long long mod = mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

ll inv(ll k) {
    return mpow(k, mod - 2, mod);
}

int main() {
    ll n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    vector<vector<int>> cycles;
    vector<bool> u(n, false);
    vector<int> pr(n, -1);
    vector<bool> out(n, false);
    function<void(int, int)> dfs = [&](int v, int p) {
        u[v] = true;
        pr[v] = p;
        for (auto k : g[v]) {
            if (!u[k]) {
                dfs(k, v);
            } else if (k != p && !out[k]) {
                int v0 = v;
                cycles.pb({v0});
                while (v0 != k) {
                    v0 = pr[v0];
                    // shows;
                    // show(v0, k, pr, cycles);
                    cycles.back().pb(v0);
                }
            }
        }
        out[v] = true;
    };
    dfs(0, -1);
    show(cycles);

    vector<vector<int>> in_cycle(n);
    for (int i = 0; i < cycles.size(); ++i) {
        for (auto v : cycles[i]) {
            in_cycle[v].pb(i);
        }
    }
    show(in_cycle);

    ll exp = n * inv(2) % mod - m * inv(4) % mod + mod;
    exp %= mod;
    for (int i = 0; i < cycles.size(); ++i) {
        exp += inv(mpow(2, cycles[i].size()));
    }
    exp %= mod;
    // show(exp, inv(4)*5%mod);

    ll expsq = 0;
    expsq += n * (n + 1) % mod * inv(4) % mod;
    // show(expsq%mod, inv(2)*15%mod);

    ll adj_edg = 0;
    for (int i = 0; i < n; ++i) {
        adj_edg += (ll)(g[i].size()) * (g[i].size() - 1);
    }
    expsq += adj_edg % mod * inv(8) % mod;
    expsq += m * inv(4) % mod;
    expsq += (m * m - adj_edg - m) % mod * inv(16) % mod;
    expsq %= mod;

    ll sth = 0;
    for (int i = 0; i < cycles.size(); ++i) {
        ll c = cycles[i].size();
        sth += inv(mpow(2, c));
    }
    sth %= mod;
    show(sth,inv(4));
    sth = sth * sth % mod;
    for (int i = 0; i < cycles.size(); ++i) {
        ll c = cycles[i].size();
        sth = (sth - inv(mpow(2, c * 2)) + inv(mpow(2, c)) + mod) % mod;
    }

    for (int i = 0; i < n; ++i) {
        if (in_cycle[i].size() > 1) {
            ll sth2 = 0;
            for (auto ind : in_cycle[i]) {
                sth2 += inv(mpow(2, cycles[ind].size()));
            }
            sth2 %= mod;
            sth2 = sth2 * sth2 * 2 % mod;
            for (auto ind : in_cycle[i]) {
                sth2 -= inv(mpow(2, cycles[ind].size() * 2 - 1));
            }
            sth2 = (sth2 % mod + mod) % mod;
            sth = (sth + sth2 * inv(2) % mod + mod) % mod;
        }
    }

    show(sth, inv(16)*5%mod);

    expsq += sth % mod;
    expsq %= mod;

    show(expsq, inv(16)*199%mod)

    expsq -= m * 2 * inv(4) * 2 % mod;
    expsq -= m * (n - 2) % mod * inv(8) * 2 % mod;

    sth = 0;
    for (int i = 0; i < cycles.size(); ++i) {
        ll c = cycles[i].size();
        sth -= c * inv(mpow(2, c)) % mod;
        ll adj = 0;
        for (auto v : cycles[i]) {
            ll now = g[v].size() - 2;
            adj += now;
        }
        sth -= adj * inv(mpow(2, c + 1)) % mod;
        sth -= (m - adj - c) * inv(mpow(2, c + 2)) % mod;

        sth += c * inv(mpow(2, c)) % mod;
        sth += (n - c) * inv(mpow(2, c + 1)) % mod;
    }
    expsq += sth * 2 % mod;
    // expsq %= mod;
    expsq = (expsq % mod + mod) % mod;
    // show(expsq, inv(4)*29%mod);
    ll d = expsq - exp * exp % mod;
    d = (d % mod + mod) % mod;
    cout << d << '\n';
    return 0;
}