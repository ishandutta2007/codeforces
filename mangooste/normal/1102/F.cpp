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

int n, m;
vector<vector<int>> table;
vector<vector<int>> to, last;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    table.resize(n, vector<int>(m));
    for (auto &i : table)
        for (int &j : i)
            cin >> j;
    to.resize(n, vector<int>(n));
    last.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            to[i][j] = abs(table[i][0] - table[j][0]);
            for (int z = 1; z < m; z++)
                to[i][j] = min(to[i][j], abs(table[i][z] - table[j][z]));
            if (m == 1)
                last[i][j] = 1e9 + 7;
            else {
                last[i][j] = abs(table[j][1] - table[i][0]);
                for (int z = 2; z < m; z++)
                    last[i][j] = min(last[i][j], abs(table[j][z] - table[i][z - 1]));
            }
        }
    int MASK = (1 << n) - 1;
    vector<vector<vector<int>>> dp(MASK + 1, vector<vector<int>>(n, vector<int>(n, -1)));
    for (int i = 0; i < n; i++)
        dp[(1 << i)][i][i] = 1e9 + 7;
    for (int mask = 0; mask <= MASK; mask++) {
        vector<int> bits;
        for (int i = 0; i < n; i++)
            if (((mask >> i) & 1))
                bits.push_back(i);
        if (bits.size() <= 1)
            continue;
        for (int start : bits)
            for (int fin : bits) {
                if (start == fin)
                    continue;
                for (int frm : bits) {
                    if (frm == fin)
                        continue;
                    int pmask = mask - (1 << fin);
                    if (dp[pmask][start][frm] == -1)
                        continue;
                    int cur_ans = min(dp[pmask][start][frm], to[frm][fin]);
                    if (dp[mask][start][fin] == -1 || dp[mask][start][fin] < cur_ans)
                        dp[mask][start][fin] = cur_ans;
                }
            }
    }
    int ans = 0;
    for (int start = 0; start < n; start++)
        for (int fin = 0; fin < n; fin++)
            if (dp[MASK][start][fin] != -1)
                ans = max(ans, min(last[fin][start], dp[MASK][start][fin]));
    cout << ans << '\n';
}