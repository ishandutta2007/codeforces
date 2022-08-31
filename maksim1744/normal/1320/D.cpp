/*
    author:  Maksim1744
    created: 01.03.2020 17:12:10
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
const ll p = 131;

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

    int n;
    cin >> n;
    string s;
    cin >> s;
    string t0, t1;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            t0.pb('0' + (i % 2));
            t1.pb('0' + (1 - i % 2));
        }
    }
    show(t0);
    show(t1);
    int q;
    cin >> q;
    int m = t0.size();
    if (m == 0) {
        for (int i = 0; i < q; ++i) {
            cout << "Yes\n";
        }
        return 0;
    }
    vector<ll> dp(n + 1);
    vector<ll> dpi(n + 1);
    dp[0] = 1;
    for (int i = 1; i < dp.size(); ++i)
        dp[i] = dp[i - 1] * p % mod;
    dpi.back() = inv(dp.back());
    for (int i = (int)dpi.size() - 2; i >= 0; --i)
        dpi[i] = dpi[i + 1] * p % mod;
    vector<ll> h0(m);
    h0[0] = t0[0];
    for (int i = 1; i < m; ++i) {
        h0[i] = (h0[i - 1] + (dp[i] * (ll)t0[i])) % mod;
    }

    vector<ll> h1(m);
    h1[0] = t1[0];
    for (int i = 1; i < m; ++i) {
        h1[i] = (h1[i - 1] + (dp[i] * (ll)t1[i])) % mod;
    }

    auto askh = [&](vector<ll>& h, int l, int r) {
        show(h, l, r);
        if (l > r)
            return 0ll;
        ll ans = h[r];
        if (l > 0)
            ans = (ans - h[l - 1] + mod) % mod;
        ans = ans * dpi[l] % mod;
        return ans;
    };

    vector<int> ind(n + 1);
    ind.back() = m;
    for (int i = n - 1; i >= 0; --i) {
        ind[i] = ind[i + 1];
        if (s[i] == '0')
            ind[i]--;
    }
    show(ind);
    for (int i = 0; i < q; ++i) {
        int i1, i2, ln;
        cin >> i1 >> i2 >> ln;
        --i1; --i2;
        ll x1 = askh(h0, ind[i1], ind[i1 + ln] - 1);
        ll x2;
        if (i1 % 2 == i2 % 2)
            x2 = askh(h0, ind[i2], ind[i2 + ln] - 1);
        else
            x2 = askh(h1, ind[i2], ind[i2 + ln] - 1);
        show(x1, x2);
        if (x1 == x2)
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}