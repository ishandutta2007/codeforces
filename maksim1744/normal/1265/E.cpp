/*
    author:  Maksim1744
    created: 05.12.2019 18:16:17
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

#ifdef HOMEn
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

const ll mod = 998244353;

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
    return mpow(k, mod - 2);
}

int main() {
    int n;
    cin >> n;
    vector<ll> p(n);
    cin >> p;
    ll i100 = inv(100);
    for (int i = 0; i < n; ++i) {
        p[i] = p[i] * i100 % mod;
    }
    vector<ll> mul(n);
    mul[0] = p[0];
    for (int i = 1; i < n; ++i) {
        mul[i] = mul[i - 1] * p[i] % mod;
    }
    vector<ll> muli(n);
    muli.back() = inv(mul.back());
    for (int i = n - 2; i >= 0; --i) {
        muli[i] = muli[i + 1] * p[i + 1] % mod;
    }
    auto ask_muli = [&](int l, int r) {
        ll ans = muli[r];
        if (l != 0)
            ans = ans * mul[l - 1] % mod;
        return ans;
    };
    auto ask_mul = [&](int l, int r) {
        ll ans = mul[r];
        if (l != 0)
            ans = ans * muli[l - 1] % mod;
        return ans;
    };
    vector<ll> strange(n);
    strange.back() = 1;
    for (int i = n - 2; i >= 0; --i) {
        strange[i] = (strange[i + 1] * p[i] + 1) % mod;
    }
    auto ask = [&](int l, int r) {
        ll ans = strange[l];
        if (r != n - 1) {
            ans -= strange[r + 1] * ask_mul(l, r) % mod;
            ans = (ans + mod) % mod;
        }
        ans = ans * ask_muli(l, r) % mod;
        return ans;
    };
    ll cur = ask(0, n - 1);
    show(cur);
    cout << cur << endl;
    return 0;
}