/*
    author:  Maksim1744
    created: 17.04.2019 17:47:58
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
#define lowb(a, x) ( lower_bound((a).begin(), (a).end(), (x)) - (a).begin())
#define uppb(a, x) ( upper_bound((a).begin(), (a).end(), (x)) - (a).begin())

template<typename T>             istream& operator>>(istream& is,  vector<T>& v){for (auto& i : v) is >> i;        return is;}
template<typename T>             ostream& operator<<(ostream& os,  vector<T>& v){for (auto& i : v) os << i << ' '; return os;}
template<typename T, typename U> istream& operator>>(istream& is, pair<T, U>& p){is >> p.first >> p.second;        return is;}
template<typename T, typename U> ostream& operator<<(ostream& os, pair<T, U>& p){os << p.first << ' ' << p.second; return os;}

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

const ll mod = 1e9 + 7;
const ll p = 61;

long long mpow(long long a, long long p, long long mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

int main() {
    string s, t;
    cin >> s >> t;
    int c0 = 0, c1 = 0;
    int i0 = -1, i1 = -1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '0'){ 
            ++c0;
            if (i0 == -1)
                i0 = i;
        } else {
            ++c1;
            if (i1 == -1)
                i1 = i;
        }
    }
    int n = t.size();
    int ans = 0;
    if ((ll)c0 * (ll)c1 / __gcd(c0, c1) > sqrt(n)) {
        for (int s0 = 1; s0 * c0 <= n; ++s0) {
            int s1 = (n - s0 * c0) / c1;
            if (s1 == 0)
                break;
            if (s1 * c1 + s0 * c0 != n)
                continue;
            int j0 = i0 * s1;
            int j1 = i1 * s0;
            if (s0 == s1)
                if (t.substr(j0, s0) == t.substr(j1, s1))
                    continue;
            show(s0, s1, j0, j1);
            int r = 0;
            bool ok = true;
            for (int j = 0; j < s.size(); ++j) {
                if (s[j] == '0') {
                    for (int k = 0; k < s0; ++k) {
                        if (t[j0 + k] != t[r + k]) {
                            ok = false;
                            break;
                        }
                    }
                    r += s0;
                } else {
                    for (int k = 0; k < s1; ++k) {
                        if (t[j1 + k] != t[r + k]) {
                            ok = false;
                            break;
                        }
                    }
                    r += s1;
                }
                if (!ok)
                    break;
            }
            if (ok)
                ++ans;
        }
    } else {
        vector<ll> dp(n + 10, 1);
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = dp[i - 1] * p % mod;
        }
        vector<ll> dpi(n + 10, 1);
        dpi.back() = mpow(dp.back(), mod - 2, mod);
        for (int i = dpi.size() - 2; i >= 0; --i) {
            dpi[i] = dpi[i + 1] * p % mod;
        }
        vector<ll> h(n + 1);
        h[0] = 0;
        for (int i = 1; i <= n; ++i) {
            h[i] = (h[i - 1] + dp[i - 1] * (t[i - 1] - 'a' + 1)) % mod;
        }
        auto geth = [&](int l, int r) {
            ll ans = (h[r + 1] - h[l] + mod) * dpi[l] % mod;
            return ans;
        };
        for (int s0 = 1; s0 * c0 <= n; ++s0) {
            int s1 = (n - s0 * c0) / c1;
            if (s1 == 0)
                break;
            if (s1 * c1 + s0 * c0 != n)
                continue;
            int j0 = i0 * s1;
            int j1 = i1 * s0;
            if (s0 == s1)
                if (t.substr(j0, s0) == t.substr(j1, s1))
                    continue;
            ll h = 0;
            ll h0 = geth(j0, j0 + s0 - 1);
            ll h1 = geth(j1, j1 + s1 - 1);
            int r = 0;
            for (int i = 0; i < s.size(); ++i) {
                if (s[i] == '0') {
                    h = (h + dp[r] * h0) % mod;
                    r += s0;
                } else {
                    h = (h + dp[r] * h1) % mod;
                    r += s1;
                }
            }
            if (h == geth(0, n - 1)) {
                ++ans;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}