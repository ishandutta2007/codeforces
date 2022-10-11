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

const int MOD = 1e9 + 7;
int n, m;
string s;
vector<int> to;
vector<vector<int>> cnt;
vector<vector<vector<int>>> dp;

int add(int a, int b) {
    int c = a + b;
    if (c >= MOD)
        c -= MOD;
    return c;
}

int mult(int a, int b) {
    return (1LL * a * b) % MOD;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> s;
    m = s.size();
    to.resize(m, -1);
    for (int i = 0; i < m - 1; i++) {
        string cur = s.substr(0, i + 1);
        if (s[i + 1] == '(')
            cur.push_back(')');
        else
            cur.push_back('(');
        for (int j = 0; j <= i; j++)
            if (s.substr(0, j + 1) == cur.substr(i + 1 - j, j + 1))
                to[i] = j;
    }
    cnt.resize(2 * n, vector<int>(n + 1, 0));
    cnt[0][1] = 1;
    for (int i = 1; i < 2 * n; i++)
        for (int bal = 0; bal <= n; bal++) {
            if (bal != 0)
                cnt[i][bal] = add(cnt[i][bal], cnt[i - 1][bal - 1]);
            if (bal != n)
                cnt[i][bal] = add(cnt[i][bal], cnt[i - 1][bal + 1]);
        }
    dp.resize(2 * n, vector<vector<int>>(n + 1, vector<int>(m + 1, 0)));
    if (s[0] == '(')
        dp[0][1][1] = 1;
    else
        dp[0][1][0] = 1;
    for (int i = 0; i < 2 * n - 1; i++)
        for (int bal = 0; bal <= n; bal++)
            for (int j = 0; j < m; j++) {
                if (bal != n) {
                    if (s[j] == '(')
                        dp[i + 1][bal + 1][j + 1] = add(dp[i + 1][bal + 1][j + 1], dp[i][bal][j]);
                    else if (j == 0)
                        dp[i + 1][bal + 1][j] = add(dp[i + 1][bal + 1][j], dp[i][bal][j]);
                    else
                        dp[i + 1][bal + 1][to[j - 1] + 1] = add(dp[i + 1][bal + 1][to[j - 1] + 1], dp[i][bal][j]);
                }
                if (bal != 0) {
                    if (s[j] == ')')
                        dp[i + 1][bal - 1][j + 1] = add(dp[i + 1][bal - 1][j + 1], dp[i][bal][j]);
                    else if (j == 0)
                        dp[i + 1][bal - 1][j] = add(dp[i + 1][bal - 1][j], dp[i][bal][j]);
                    else
                        dp[i + 1][bal - 1][to[j - 1] + 1] = add(dp[i + 1][bal - 1][to[j - 1] + 1], dp[i][bal][j]);
                }
            }
    int ans = 0;
    for (int i = 0; i < 2 * n; i++) 
        for (int bal = 0; bal <= n; bal++) {
            if (i == 2 * n - 1)
                ans = add(ans, (bal == 0 ? dp[i][bal][m] : 0));
            else
                ans = add(ans, mult(dp[i][bal][m], cnt[2 * n - 2 - i][bal]));
        }
    cout << ans << '\n';
}