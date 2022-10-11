#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    
    constexpr int INF = 1e9 + 228;
    vector<int> dp_left(n, INF), dp_right(n, INF);
    for (int rot = 0; rot < 2; rot++, reverse(all(a))) {
        auto &cur = rot == 0 ? dp_left : dp_right;
        cur[0] = 0;
        for (int i = 1; i < n; i++) {
            if (a[i] > cur[i - 1]) {
                cur[i] = min(cur[i], a[i - 1]);
            }
            if (a[i] > a[i - 1]) {
                cur[i] = min(cur[i], cur[i - 1]);
            }
        }
    }
    reverse(all(dp_right));

    int answer = 0;
    for (int rot : {0, 1}) {
        int pos = max_element(all(a)) - a.begin();
        vector<array<int, 2>> dp(n, {INF, 0});
        dp[pos][0] = dp_left[pos];
        for (int i = pos + 1; i < n; i++) {
            if (dp[i - 1][1] > a[i]) {
                dp[i][0] = min(dp[i][0], a[i - 1]);
            }
            if (a[i] > a[i - 1]) {
                dp[i][1] = max(dp[i][1], dp[i - 1][1]);
            }
            if (a[i] > dp[i - 1][0]) {
                dp[i][1] = max(dp[i][1], a[i - 1]);
            }
            if (a[i] < a[i - 1]) {
                dp[i][0] = min(dp[i][0], dp[i - 1][0]);
            }
            answer += dp[i][1] > dp_right[i];
        }

        swap(dp_left, dp_right);
        reverse(all(dp_left));
        reverse(all(dp_right));
        reverse(all(a));
    }
    cout << answer << '\n';
}