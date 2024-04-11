/*
    author:  Maksim1744
    created: 19.03.2020 17:47:13
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

const ll mod = 1791791791;
const ll p = 137;

const int N = 1e6 + 20;

long long mpow(long long a, long long p, long long mod = mod) {
    long long res = 1;
    while (p) {
        if (p & 1) res = res * a % mod;
        p >>= 1;
        a = a * a % mod;
    }
    return res;
}

ll inv(ll k, ll mod = mod) {
    return mpow(k, mod - 2, mod);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    vector<ll> dp(N);
    dp[0] = 1;
    for (int i = 1; i < N; ++i)
        dp[i] = dp[i - 1] * p % mod;

    vector<ll> dpi(N);
    dpi.back() = inv(dp.back());
    for (int i = N - 2; i >= 0; --i) {
        dpi[i] = dpi[i + 1] * p % mod;
    }

    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = s.size();
        int i1 = 0, i2 = n - 1;
        while (i1 < i2 && s[i1] == s[i2]) {
            ++i1;
            --i2;
        }
        if (i1 > i2) {
            cout << s << '\n';
            continue;
        }
        string s0 = s.substr(0, i1);
        string s2 = s.substr(i2 + 1, n);
        s = s.substr(i1, i2 - i1 + 1);
        n = s.size();
        vector<ll> h0(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            h0[i + 1] = (h0[i] + dp[i] * (ll)s[i]) % mod;
        }
        reverse(s.begin(), s.end());
        vector<ll> h1(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            h1[i + 1] = (h1[i] + dp[i] * (ll)s[i]) % mod;
        }
        reverse(s.begin(), s.end());
        auto geth = [&](vector<ll>& h, int l, int r) {
            ll res = (h[r + 1] - h[l] + mod) % mod;
            return res * dpi[l] % mod;
        };
        int mx0 = 0;
        for (int i = n; i >= 1; --i) {
            if (geth(h0, 0, i - 1) == geth(h1, n - i, n - 1)) {
                mx0 = i;
                break;
            }
        }
        int mx1 = 0;
        for (int i = n; i >= 1; --i) {
            if (geth(h0, n - i, n - 1) == geth(h1, 0, i - 1)) {
                mx1 = i;
                break;
            }
        }
        cout << s0;
        if (mx0 >= mx1)
            cout << s.substr(0, mx0);
        else
            cout << s.substr(n - mx1, mx1);
        cout << s2 << '\n';
    }

    return 0;
}