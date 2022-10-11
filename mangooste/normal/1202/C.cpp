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

ll solve(vector<int> &bal) {
    if (bal.size() == 1)
        return 1;
    int n = bal.size();
    vector<int> pref_min(n), pref_max(n);
    pref_min[0] = pref_max[0] = bal[0];
    for (int i = 1; i < n; i++) {
        pref_min[i] = min(pref_min[i - 1], bal[i]);
        pref_max[i] = max(pref_max[i - 1], bal[i]);
    }
    int mx = bal.back(), mn = bal.back();
    int ans = pref_max.back() - pref_min.back();
    for (int i = n - 2; i >= 0; i--) {
        ans = min(ans, max({pref_max[i], mx + 1, bal[i] + 1}) - min({pref_min[i], mn + 1, bal[i] + 1}));
        ans = min(ans, max({pref_max[i], mx - 1, bal[i] - 1}) - min({pref_min[i], mn - 1, bal[i] - 1}));
        mx = max(mx, bal[i]);
        mn = min(mn, bal[i]);
    }
    ans++;
    debug("solve", bal, ans);
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<int> bal_x, bal_y;
        bal_x.pb(0);
        bal_y.pb(0);
        for (auto el : s) {
            if (el == 'W')
                bal_x.pb(bal_x.back() + 1);
            else if (el == 'S')
                bal_x.pb(bal_x.back() - 1);
            else if (el == 'A')
                bal_y.pb(bal_y.back() - 1);
            else
                bal_y.pb(bal_y.back() + 1);
        }
        int mn_x = *min_element(all(bal_x));
        int mx_x = *max_element(all(bal_x));
        int mn_y = *min_element(all(bal_y));
        int mx_y = *max_element(all(bal_y));
        ll ans = min({ 1ll * max(1, mx_x - mn_x + 1) * max(1, mx_y - mn_y + 1), max(1, mx_x - mn_x + 1) * solve(bal_y), max(1, mx_y - mn_y + 1) * solve(bal_x) });
        cout << ans << '\n';
    }
}