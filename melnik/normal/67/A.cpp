#include <bits/stdc++.h>

using namespace std;

static constexpr int maxn = 1050;
static constexpr int inf = 2e9;

int dp[maxn][maxn];
int anc[maxn][maxn];

int main() {
    srand(time(NULL));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < maxn; ++i) {
        for (int j = 0; j < maxn; ++j) {
            dp[i][j] = inf;
        }
    }
    for (int i = 1; i < maxn; ++i) {
        dp[1][i] = i;
    }

    string s;
    cin >> s;
    for (int i = 2; i <= n; ++i) {
        char c = s[i - 2];
        int start, finish, dx;
        if (c == 'L') {
            start = n;
            finish = 0;
            dx = -1;
        } else {
            start = 1;
            finish = n + 1;
            dx = 1;
        }
        int cur_min = inf;
        int cur_min_pos = -1;
        for (int j = start; j != finish; j += dx) {
            if (c == '=') {
                dp[i][j] = j + dp[i - 1][j];
                anc[i][j] = j;
                continue;
            }
            if (cur_min_pos != -1) {
                dp[i][j] = j + cur_min;
                anc[i][j] = cur_min_pos;
            }
            if (dp[i - 1][j] < cur_min) {
                cur_min = dp[i - 1][j];
                cur_min_pos = j;
            }
        }
    }

    int min_pos = 1;
    for (int i = 1; i <= n; ++i) {
        if (dp[n][i] < dp[n][min_pos]) {
            min_pos = i;
        }
    }
    assert(dp[n][min_pos] < inf);

    vector<int> ans;
    for (int i = n; i >= 1; --i) {
        ans.push_back(min_pos);
        min_pos = anc[i][min_pos];
    }
    reverse(ans.begin(), ans.end());

    for (auto x : ans) {
        cout << x << ' ';
    }

}