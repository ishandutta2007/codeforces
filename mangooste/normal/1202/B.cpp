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
    string s;
    getline(cin, s);
    int n = s.size();
    vector<int> dels;
    for (int i = 1; i < n; i++)
        dels.pb((10 + s[i] - s[i - 1]) % 10);
    sort(all(dels));
    debug(dels);
    vector<int> cnt(10, 0);
    for (auto el : dels)
        cnt[el]++;
    dels.resize(unique(all(dels)) - dels.begin());
    int m = dels.size();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            int x = i, y = j;
            if (x > y)
                swap(x, y);
            bool can = true;
            const int BUBEN = 10 * 10 + 1;
            vector<int> dp(BUBEN, -1);
            dp[x] = dp[y] = 0;
            for (int i = 0; i < BUBEN; i++) {
                if (dp[i] != -1)
                    continue;
                if (x != 0 && i - x >= 0 && dp[i - x] != -1)
                    dp[i] = dp[i - x] + 1;
                if (y != 0 && i - y >= 0 && dp[i - y] != -1 && (dp[i] == -1 || dp[i] > dp[i - y] + 1))
                    dp[i] = dp[i - y] + 1;
            }
            int ans = 0;
            for (int el = 0; el < 10; el++) {
                int mn = -1;
                for (int k = el; k < BUBEN; k += 10)
                    if (dp[k] != -1 && (mn == -1 || mn > dp[k]))
                        mn = dp[k];
                can &= (cnt[el] == 0 || mn != -1);
                ans += cnt[el] * mn;
            }
            if (!can)
                cout << "-1 ";
            else
                cout << ans << ' ';
        }
        cout << '\n';
    }
}