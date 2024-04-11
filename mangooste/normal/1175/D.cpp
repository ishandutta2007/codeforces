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

    // #define DEBUG

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
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for (auto &el : a)
        cin >> el;
    if (k == 1) 
        return cout << accumulate(all(a), 0ll) << '\n', 0;
    vector<ll> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + a[i];
    vector<ll> dp(n, 1e18);
    multiset<ll> st;
    ll sm = 0;
    for (int i = 0; i < k - 1; i++) {
        sm += pref[i];
        st.insert(pref[i]);
    }
    dp[k - 2] = sm;
    for (int i = k - 1; i < n; i++) {
        ll mx = *(--st.end());
        if (mx > pref[i]) {
            sm -= mx;
            st.erase(--st.end());
            st.insert(pref[i]);
            sm += pref[i];
        }
        dp[i] = sm;
    }
    debug(pref);
    debug(dp);
    cout << pref[n - 1] * k - *min_element(dp.begin(), dp.end() - 1) << '\n';
}