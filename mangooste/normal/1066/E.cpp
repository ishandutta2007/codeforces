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

const int mod = 998244353;
int n, m;
string a, b;
vector<int> power;

void precalc() {
    power.resize(n);
    power[0] = 1;
    for (int i = 1; i < n; i++)
        power[i] = (power[i - 1] * 2) % mod;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m >> a >> b;
    precalc();
    vector<int> pref(m);
    pref[m - 1] = (b[0] == '1');
    for (int i = m - 2; i >= 0; i--)
        pref[i] = pref[i + 1] + (b[m - i - 1] == '1');
    int ans = 0;
    for (int i = n - 1, bit = 0; i >= 0 && bit < m; i--, bit++) {
        if (a[i] != '1')
            continue;
        ans += (1LL * pref[bit] * power[bit]) % mod;
        if (ans >= mod)
            ans -= mod;
    }
    cout << ans << '\n';
}