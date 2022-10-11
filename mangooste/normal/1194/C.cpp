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
    int t;
    cin >> t;
    while (t--) {
        string s, t, p;
        cin >> s >> t >> p;
        vector<int> cnt(26, 0);
        for (auto el : p)
            cnt[el - 'a']++;
        int t_pos = 0;
        bool ok = true;
        for (int i = 0; i < s.size(); i++) {
            while (t_pos < t.size() && t[t_pos] != s[i]) {
                ok &= (cnt[t[t_pos] - 'a'] > 0);
                cnt[t[t_pos] - 'a']--;
                t_pos++;
            }
            ok &= (t_pos != t.size());
            t_pos++;
        }
        while (t_pos < t.size()) {
            ok &= (cnt[t[t_pos] - 'a'] > 0);
            cnt[t[t_pos] - 'a']--;
            t_pos++;
        }
        cout << (ok ? "Yes\n" : "No\n");
    }
}