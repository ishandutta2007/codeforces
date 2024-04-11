#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

void setmax(int &a, int b) {
    if (a < b)
        a = b;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (auto &x : a) {
        cin >> x;
        x--;
    }

    vector<int> b(n);
    for (auto &x : b)
        cin >> x;

    vector<int> cost(n + m);
    for (auto &x : cost)
        cin >> x;

    vector<int> cnt(n + m);
    for (auto x : a)
        cnt[x]++;

    constexpr int INF = 1e9;
    vector<vector<int>> dp(1, vector<int>(n + 1));

    for (int val = 0; val < n + m; val++) {
        int new_size = (len(dp) - 1) / 2 + cnt[val] + 1;
        vector<vector<int>> new_dp(new_size, vector<int>(n + 1, -INF));

        for (int prev_cnt = 0; prev_cnt < len(dp); prev_cnt++)
            for (int i = 0; i <= n; i++)
                setmax(new_dp[prev_cnt / 2][i], dp[prev_cnt][i]);

        for (int new_cnt = 0; new_cnt < new_size; new_cnt++)
            for (int i = n - 1; i >= 0; i--) {
                setmax(new_dp[new_cnt][i], new_dp[new_cnt][i + 1]);
                if (new_cnt > 0 && a[i] == val)
                    setmax(new_dp[new_cnt][i], new_dp[new_cnt - 1][i + 1] - b[i]);
            }

        for (int new_cnt = 0; new_cnt < new_size; new_cnt++)
            for (int i = 0; i <= n; i++)
                if (new_dp[new_cnt][i] != -INF)
                    new_dp[new_cnt][i] += new_cnt * cost[val];

        dp = new_dp;
    }

    int answer = dp[0][0];
    if (len(dp) > 1)
        answer = max(answer, dp[1][0]);

    cout << answer << '\n';
}