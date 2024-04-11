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

vector<string> dgs = {
    "1110111",
    "0010010",
    "1011101",
    "1011011",
    "0111010",
    "1101011",
    "1101111",
    "1010010",
    "1111111",
    "1111011"
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<string> a(n);
    for (auto &el : a)
        cin >> el;
    vector<vector<pair<int, int>>> can(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            bool chk = true;
            int cnt = 0;
            for (int k = 0; k < 7; k++) {
                if (dgs[j][k] == '0')
                    chk &= (a[i][k] == '0');
                cnt += (dgs[j][k] == '1' && a[i][k] == '0');
            }
            if (chk)
                can[i].eb(j, cnt);
        }
        reverse(all(can[i]));
    }
    vector<vector<char>> dp(n + 1, vector<char>(k + 1, 0));
    dp[n][0] = 1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j <= k; j++)
            for (auto el : can[i])
                if (j - el.second >= 0 && dp[i + 1][j - el.second]) {
                    dp[i][j] = 1;
                    break;
                }
    if (!dp[0][k])
        return cout << "-1\n", 0;
    string ans = "";
    int bal = k;
    int pos = 0;
    while (pos < n) {
        for (auto el : can[pos])
            if (bal - el.second >= 0 && dp[pos + 1][bal - el.second]) {
                ans.pb('0' + el.first);
                bal -= el.second;
                break;
            }
        pos++;
    }
    cout << ans << '\n';
}