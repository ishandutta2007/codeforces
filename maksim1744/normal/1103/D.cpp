/*
    author:  Maksim1744
    created: 08.05.2021 20:56:44
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

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    ll k;
    cin >> n >> k;
    ll g = 0;
    vector<pair<ll, ll>> e(n);
    for (int i = 0; i < n; ++i) {
        cin >> e[i].second;
        g = gcd(g, e[i].second);
    }
    for (int i = 0; i < n; ++i) {
        cin >> e[i].first;
    }
    sort(e.begin(), e.end());

    vector<ll> pr;
    for (ll p = 2; p * p <= g; ++p) {
        if (g % p == 0) {
            pr.pb(p);
            while (g % p == 0) {
                g /= p;
            }
        }
    }
    if (g != 1)
        pr.pb(g);

    map<vector<int>, vector<ll>> best;
    for (auto [cost, n] : e) {
        vector<int> v(pr.size());
        for (int i = 0; i < pr.size(); ++i) {
            while (n % pr[i] == 0) {
                n /= pr[i];
                v[i]++;
            }
        }
        best[v].pb(cost);
    }

    ll inf = 1e18;
    vector<vector<ll>> dp(1 << pr.size(), vector<ll>(pr.size() + 1, inf));
    vector<vector<ll>> next(1 << pr.size(), vector<ll>(pr.size() + 1, inf));
    dp[0].assign(dp[0].size(), 0);
    vector<ll> prod_cost(1 << pr.size());

    auto pw = [&](ll x, ll p) {
        ll r = 1;
        while (p) {
            if (p & 1) r *= x;
            x *= x;
            p >>= 1;
        }
        return r;
    };

    show(best);

    for (auto [v, costs] : best) {
        int s = min(pr.size(), costs.size());
        for (int i = 0; i < s; ++i) {
            ll cost = costs[i];
            prod_cost[0] = 1;
            for (int i = 1; i < prod_cost.size(); ++i) {
                int j = __builtin_ctz(i);
                prod_cost[i] = prod_cost[i ^ (1 << j)] * pw(pr[j], v[j]);
            }
            show(prod_cost);

            next = dp;

            for (int m = 0; m < dp.size(); ++m) {
                for (int m2 = m;; m2 = ((m2 - 1) & m)) {
                    if (prod_cost[m2] <= k) {
                        for (int cnt = 1; cnt <= pr.size(); ++cnt) {
                            next[m][cnt] = min(next[m][cnt], dp[m ^ m2][cnt - 1] + cost);
                        }
                    }

                    if (m2 == 0) break;
                }
            }


            swap(dp, next);
            show(dp);
        }
    }

    ll ans = inf;
    for (int c = 0; c <= pr.size(); ++c) {
        if (dp.back()[c] != inf)
            ans = min(ans, dp.back()[c] * c);
    }
    if (ans == inf) ans = -1;
    cout << ans << '\n';

    return 0;
}