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
    string s;
    cin >> s;
    int n = s.size();
    vector<vector<int>> cnt(n + 1, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
        cnt[i + 1] = cnt[i];
        cnt[i + 1][s[i] - 'a']++;
    }
    int t;
    cin >> t;
    while (t--) {
        int L, R;
        cin >> L >> R, L--, R--;
        if (R == L) {
            cout << "Yes\n";
            continue;
        }
        int cur = 0;
        for (int i = 0; i < 26; i++)
            cur += (cnt[R + 1][i] - cnt[L][i] != 0);
        if (cur > 2 || cur == 2 && s[L] != s[R])
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}