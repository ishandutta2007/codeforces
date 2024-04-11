#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = __int128;
using namespace std;

namespace Debug {
    #define DEBUG

    template<class A, class B>
    ostream& operator << (ostream &out, pair<A, B> &p) {
        out << "(" << p.first << ", " << p.second << ")";
        return out;
    }

    template<class T> 
    ostream& operator << (ostream &out, vector<T> &v) {
        out << "{";
        string sep;
        for (T el : v)
            out << sep << el, sep = ", ";
        out << "}";
        return out;
    }

    template<class T>
    ostream& operator << (ostream &out, set<T> &st) {
        out << '(';
        string sep = "";
        for (auto el : st)
            out << sep << el, sep = ", ";
        out << ')';
        return out;
    }

    void debug_out() { cerr << endl; }
    template<class Head, class... Tail>
    void debug_out(Head head, Tail... tail) {
        cerr << ' ' << head;
        debug_out(tail...);
    }

    #ifdef DEBUG
    #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
    #else
    #define debug(...)
    #endif
}

using namespace Debug;

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back

istream& operator >> (istream &in, __int128 &a) {
    long long b;
    cin >> b;
    a = b;
    return in;
}

ostream& operator << (ostream &out, __int128 &a) {
    string s;
    while (a != 0) {
        s.pb(a % 10 + '0');
        a /= 10;
    }
    reverse(all(s));
    out << s;
    return out;
}

const ll MOD = 1e9 + 7;

ll bin_pow(ll a, ll b) {
    if (b == 0)
        return 1ll;
    if (b % 2 == 1)
        return (bin_pow(a, b - 1) * a) % MOD;
    ll md = bin_pow(a, b / 2);
    return (md * md) % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll x, n;
    cin >> x >> n;
    vector<ll> primes;
    for (ll i = 2, start = x; i * i <= start && i <= x; i++) {
        ll cnt = 0;
        while (x % i == 0)
            cnt++, x /= i;
        if (cnt != 0)
            primes.pb(i);
    }
    if (x != 1)
        primes.pb(x);
    ll ans = 1;
    auto get = [](ll n, ll power) {
        return n / power;
    };
    for (auto pr : primes) {
        ll power = 1LL;
        while (power <= n) {
            ll cnt = get(n, power) - get(n, power * pr);
            ans = ans * bin_pow(power % MOD, cnt) % MOD;
            power *= pr;
        }
    }
    cout << ans << '\n';
}