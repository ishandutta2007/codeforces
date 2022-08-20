/*
    author:  Maksim1744
    created: 11.06.2020 18:18:20
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

const ll mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    ll n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> g(n);
    vector<pair<pair<int, int>, ll>> es;
    for (int i = 0; i < m; ++i) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        --u; --v;
        g[u].push_back(es.size());
        g[v].push_back(es.size());
        es.eb(mp(u, v), w);
    }
    int K = min(q, m * 2 + 5);
    vector<ll> best(n, -1);
    best[0] = 0;

    ll ans = 0;
    for (int i = 0; i < K; ++i) {
        vector<ll> next(n, -1);
        next[0] = 0;
        for (int v = 0; v < n; ++v) {
            if (best[v] == -1) continue;
            for (auto num : g[v]) {
                int u = es[num].first.first + es[num].first.second - v;
                ll w = es[num].second;
                next[u] = max(next[u], best[v] + w);
            }
        }
        swap(best, next);
        ans = (ans + maxe(best)) % mod;
    }
    if (K == q) {
        cout << ans << endl;
        return 0;
    }
    vector<pair<ll, ll>> lines;
    for (int i = 0; i < es.size(); ++i) {
        ll a = max(best[es[i].first.first], best[es[i].first.second]);
        ll b = es[i].second;
        lines.eb(b, a);
    }
    lines.eb(0, 0);
    sort(lines.begin(), lines.end());
    {
        vector<pair<ll, ll>> tmp;
        tmp.pb(lines[0]);
        for (int i = 1; i < lines.size(); ++i) {
            if (tmp.back().first == lines[i].first)
                tmp.back() = lines[i];
            else
                tmp.pb(lines[i]);
        }
        swap(lines, tmp);
    }
    vector<ll> from;
    vector<ll> to;
    auto get_from = [&](pair<ll, ll> line1, pair<ll, ll> line2) {
        ll l = -10;
        ll r = 1e9 + 20;
        while (r - l > 1) {
            ll c = (l + r) / 2;
            ll val1 = line1.first * c + line1.second;
            ll val2 = line2.first * c + line2.second;
            if (val1 >= val2) {
                l = c;
            } else {
                r = c;
            }
        }
        return r;
    };
    {
        vector<pair<ll, ll>> tmp = lines;
        lines.clear();
        lines.pb(tmp[0]);
        from.pb(0);
        for (int i = 1; i < tmp.size(); ++i) {
            ll f = 0;
            while (true) {
                f = get_from(lines.back(), tmp[i]);
                if (lines.size() >= 2 && f <= from.back()) {
                    from.pop_back();
                    lines.pop_back();
                    f = 0;
                } else {
                    break;
                }
            }
            from.pb(max(0ll, f));
            lines.pb(tmp[i]);
        }
    }
    q -= K;
    for (int i = 1; i < lines.size(); ++i)
        to.pb(from[i] - 1);
    to.pb(q);
    for (int i = 0; i < lines.size(); ++i) {
        to[i] = min(to[i], q);
        from[i] = max(from[i], 1ll);
    }
    show(lines);
    show(from);
    show(to);
    show(ans);
    show(q);
    for (int i = 1; i < lines.size(); ++i) {
        if (from[i] > to[i]) continue;
        ll cur = lines[i].second % mod * ((to[i] - from[i] + 1) % mod) % mod;
        ll p1 = from[i] + to[i];
        ll p2 = to[i] - from[i] + 1;
        if (p1 % 2 == 0) p1 /= 2;
        else p2 /= 2;
        p1 %= mod;
        p2 %= mod;
        ll prod = p1 * p2 % mod;
        prod = prod % mod * (lines[i].first % mod) % mod;
        show(prod);
        ans = (ans + prod + cur) % mod;
    }
    cout << ans % mod << endl;

    return 0;
}