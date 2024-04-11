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

using ll = long long;
using namespace std;

namespace Debug {
    // #define DEBUG

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

int n;
ll k;
vector<ll> a, mx_pw, power;

void precalc() {
    power.resize(11);
    power[0] = 1;
    for (int i = 1; i < 11; i++)
        power[i] = power[i - 1] * 10, power[i] %= k;
    mx_pw.resize(n);
    for (int i = 0; i < n; i++) {
        mx_pw[i] = 0;
        ll cur = a[i];
        while (cur != 0)
            cur /= 10, mx_pw[i]++;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> k;
    a.resize(n);
    for (auto &el : a)
        cin >> el;
    precalc();
    vector<map<ll, ll>> cnt(11);
    for (int i = 0; i < n; i++)
        for (int j = 1; j < 11; j++)
            cnt[j][(a[i] * power[j]) % k]++;
    ll ans = 0;
    for (int i = 0; i < n; i++)
        ans += cnt[mx_pw[i]][(k - a[i] % k) % k] - ((a[i] * power[mx_pw[i]] + a[i]) % k == 0);
    cout << ans << '\n';
}