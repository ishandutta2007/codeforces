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
    const int Log = 20;
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        vector<int> left(n, 0);
        left[0] = (s[0] == '0' ? 1 : 0);
        for (int i = 1; i < n; i++) {
            if (s[i - 1] == '0')
                left[i] = left[i - 1] + (s[i] != '1');
            else
                left[i] = (s[i] != '1');
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (left[i] == i + 1)
                continue;
            int cur_val = 0;
            for (int j = 0; j < Log && i - j >= 0; j++) {
                int cur_pw = (1 << j);
                cur_val += (s[i - j] - '0') * cur_pw;
                if (cur_val == j + 1)
                    ans++;
            }
            if (i < Log)
                continue;
            int pos = i - Log + 1;
            int cnt_left = left[pos];
            if (s[pos] == '0')
                cnt_left--;
            if (cnt_left == 0)
                continue;
            int mx_ln = Log + cnt_left;
            int mn_ln = Log + 1;
            if (mn_ln <= cur_val && cur_val <= mx_ln)
                ans++;
        }
        cout << ans << '\n';
    }
}