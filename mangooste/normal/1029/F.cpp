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

vector<pair<ll, ll>> get_divs(ll a) {
    vector<pair<ll, ll>> cur;
    for (ll i = 1; i * i <= a; i++)
        if (a % i == 0)
            cur.emplace_back(i, a / i);
    return cur;
}

bool can(vector<pair<ll, ll>> &divs, pair<ll, ll> cur) {
    debug(divs, cur);
    int i = upper_bound(all(divs), cur) - divs.begin() - 1;
    debug(i);
    if (i == -1)
        return false;
    return divs[i].first <= cur.first && divs[i].second <= cur.second;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    ll a, b;
    cin >> a >> b;
    vector<pair<ll, ll>> divs_a = get_divs(a), divs_b = get_divs(b), divs_sum = get_divs(a + b);
    ll ans = 1e18;
    for (auto i : divs_sum)
        if (can(divs_a, i) || can(divs_b, i))
            ans = min(ans, (i.first + i.second) * 2);
    cout << ans << '\n';
}