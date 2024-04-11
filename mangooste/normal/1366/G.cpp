#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

inline void setmin(int &a, int b) {
    if (a > b)
        a = b;
}

int main() {
    string from, need;
    cin >> from >> need;
    int m = int(from.size());
    int n = int(need.size());

    vector<int> balance(m);
    for (int i = 0; i < m; i++)
        balance[i] = (i ? balance[i - 1] : m) + (from[i] == '.' ? -1 : 1);

    vector<int> last_seen(2 * m + 1, -1);
    vector<int> nxt(m, -1);
    for (int i = m - 1; i >= 0; i--) {
        if (from[i] != '.')
            nxt[i] = last_seen[i ? balance[i - 1] : m];
        last_seen[balance[i]] = i;
    }

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, INF));
    dp[0][0] = 0;
    for (int pref1 = 0; pref1 <= m; pref1++)
        for (int pref2 = 0; pref2 <= n; pref2++) {
            if (dp[pref1][pref2] == INF)
                continue;
            if (pref2 != n && pref1 != m && from[pref1] == need[pref2])
                setmin(dp[pref1 + 1][pref2 + 1], dp[pref1][pref2]);
            if (pref1 != m)
                setmin(dp[pref1 + 1][pref2], dp[pref1][pref2] + 1);
            if (pref1 != m && nxt[pref1] != -1)
                setmin(dp[nxt[pref1] + 1][pref2], dp[pref1][pref2]);
        }

    cout << dp[m][n] << '\n';
}