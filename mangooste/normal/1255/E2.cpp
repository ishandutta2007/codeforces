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

using namespace std;
using ll = long long;
using pii = pair<int, int>;

namespace Debug {
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

    #define DEBUG

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
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    ll s = 0;
    vector<ll> a(n);
    for (auto &el : a)
        cin >> el, s += el;
    ll ans = -1;
    vector<ll> primes;
    ll val = s;
    for (ll i = 2; i * i <= val; i++) 
        if (val % i == 0) {
            primes.pb(i);
            while (val % i == 0)
                val /= i;
        }
    if (val != 1)
        primes.pb(val);
    for (int i = 1; i < n; i++)
        a[i] += a[i - 1];
    for (auto k : primes) {
        ll cur_ans = 0;
        for (int i = 0; i < n; i++)
            cur_ans += min(a[i] % k, k - a[i] % k);
        if (ans == -1 || cur_ans < ans)
            ans = cur_ans;
    }
    cout << ans << '\n';
}