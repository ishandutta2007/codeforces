/*
    author:  Maksim1744
    created: 13.03.2021 12:37:54
*/

#include "bits/stdc++.h"

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
template<typename T, typename U> pair<T,U>& operator--           (pair<T, U> &p){--p.first; --p.second;            return  p;}
template<typename T, typename U> pair<T,U>& operator++           (pair<T, U> &p){++p.first; ++p.second;            return  p;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}
template<typename T, typename U> pair<T,U> operator-(pair<T,U> a, pair<T,U> b){return mp(a.first-b.first, a.second-b.second);}
template<typename T, typename U> pair<T,U> operator+(pair<T,U> a, pair<T,U> b){return mp(a.first+b.first, a.second+b.second);}
template<typename T, typename U> void umin(T& a, U b){if (a > b) a = b;}
template<typename T, typename U> void umax(T& a, U b){if (a < b) a = b;}

#ifdef HOME
#define SHOW_COLORS
#include "C:/C++ libs/print.cpp"
#else
#define show(...)     42
#define mclock        42
#define shows         42
#define debug if (false)
#endif

// finds x and y such that a * x + b * y = c
template<typename T>
pair<T, T> egcd(T a, T b, T c) {
    if (a == 0) {
        // b * y = c
        assert(c % b == 0);
        return {0, c / b};
    }
    // a * x + b * y = c
    // a * x + (b % a + (b/a) * a) * y = c
    // a * (x + (b/a) * y) + (b % a) * y = c
    auto [y0, x0] = egcd(b % a, a, c);
    T y = y0;
    T x = x0 - (b / a) * y;
    return {x, y};
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, m;
    ll k;
    cin >> n >> m >> k;
    vector<int> a(n);
    vector<int> b(m);
    cin >> a >> b;

    int d = gcd(n, m);
    vector<vector<int>> as(d), bs(d);
    for (int i = 0; i < n; ++i) {
        as[i % d].pb(a[i]);
    }
    for (int i = 0; i < m; ++i) {
        bs[i % d].pb(b[i]);
    }

    show(d);
    show(as, bs);

    vector<vector<ll>> aa, bb;
    vector<ll> pers;
    vector<ll> st;

    ll inper = 0;
    ll mod;

    for (int i = 0; i < d; ++i) {
        map<int, vector<ll>> cura, curb;
        for (int j = 0; j < as[i].size(); ++j)
            cura[as[i][j]].pb(j);
        for (int j = 0; j < bs[i].size(); ++j)
            curb[bs[i][j]].pb(j);
        vector<int> vals = as[i];
        for (int k : bs[i])
            vals.pb(k);
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        ll n = as[i].size();
        ll m = bs[i].size();
        ll in = egcd(n, m, (ll)1).first;
        in = (in % m + m) % m;
        mod = n * m;
        inper += mod;
        ll X = n * in % mod;
        for (int k : vals) {
            auto a = cura[k];
            auto b = curb[k];
            if (a.empty() || b.empty()) continue;
            show(a, b);
            inper -= (ll)a.size() * (ll)b.size();
            for (auto &k : a)
                k = (k * (-X + 1) % mod + mod) % mod;
            for (auto &k : b)
                k = k * X % mod;
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            aa.pb(a);
            bb.pb(b);
            pers.pb(mod);
            st.pb(i);
        }
    }

    auto calc_upto = [&](vector<ll> &a, vector<ll> &b, ll c) {
        ll ans = 0;
        int r = (int)b.size() - 1;
        for (int i = 0; i < a.size(); ++i) {
            while (r >= 0 && a[i] + b[r] > c)
                --r;
            ans += r + 1;
        }
        return ans;
    };

    auto calc = [&](vector<ll> &a, vector<ll> &b, ll c) {
        return calc_upto(a, b, c - 1) + calc_upto(a, b, c + mod - 1) - calc_upto(a, b, mod);
    };

    // auto calc = [&](vector<ll> &a, vector<ll> &b, ll c) {
    //     int ans = 0;
    //     for (ll u : a)
    //         for (ll v : b)
    //             ans += (u + v) % mod < c;
    //     return ans;
    // };

    show(aa);
    show(bb);
    show(mod);
    show(st);
    ll L = -1, R = (ll)lcm((ll)n, (ll)m);
    show(R);
    show(inper);

    ll ans = (k - 1) / (inper) * R;
    show(ans);
    k %= inper;
    if (k == 0)
        k = inper;
    ll mmd = R;
    while (R - L > 1) {
        ll C = (L + R) / 2;
        ll cur = 0;
        for (int i = 0; i < aa.size(); ++i) {
            if (aa[i].empty() || bb[i].empty()) continue;
            show(i, (C - st[i] + d - 1) / d);
            cur += calc(aa[i], bb[i], (C - st[i] + d - 1) / d);
        }
        cur = C - cur;
        show(C, cur, k);
        if (cur >= k)
            R = C;
        else
            L = C;
    }
    show(R);
    cout << ans + R << '\n';

    return 0;
}