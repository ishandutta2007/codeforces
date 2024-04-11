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
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll s;
        cin >> n >> s;
        vector<pair<ll, ll>> a(n);
        for (auto &el : a)
            cin >> el.first >> el.second;
        sort(all(a));
        int need = n / 2 + 1;
        auto chk = [&](ll cur) {
            vector<pair<ll, ll>> ok, bad;
            for (auto el : a) {
                if (el.second >= cur)
                    ok.pb(el);
                else
                    bad.pb(el);
            }
            if (ok.size() < need)
                return false;
            ll sm = 0;
            for (auto el : bad)
                sm += el.first;
            for (int i = 0; i < ok.size() - need; i++)
                sm += ok[i].first;
            for (int i = ok.size() - need; i < ok.size(); i++)
                sm += max(cur, ok[i].first);
            return sm <= s;
        };
        ll L = 1, R = 2000000007;
        while (R - L > 1) {
            ll mid = (L + R) / 2;
            if (chk(mid))
                L = mid;
            else
                 R = mid;
        }
        cout << L << '\n';
    }
}