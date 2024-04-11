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
    vector<int> poses;
    for (int i = 0; i < n; i++) {
        int el;
        cin >> el;
        if (el)
            poses.pb(i);
    }
    int sm = poses.size();
    vector<ll> pref(sm + 1);
    pref[0] = 0;
    for (int i = 0; i < sm; i++)
        pref[i + 1] = pref[i] + poses[i];
    ll ans = -1;
    for (int k = 2; k < n; k++) {
        if (sm % k)
            continue;
        ll cur_ans = 0;
        for (int i = 0; i < sm; i += k) {
            int L = i, R = i + k - 1;
            int md = (L + R) / 2;
            ll lft = pref[md + 1] - pref[L];
            cur_ans += 1ll * (md - L + 1) * poses[md] - lft;
            ll rgt = pref[R + 1] - pref[md];
            cur_ans += -1ll * (R - md + 1) * poses[md] + rgt;
        }
        if (ans == -1 || ans > cur_ans)
            ans = cur_ans;
    }
    cout << ans;
}