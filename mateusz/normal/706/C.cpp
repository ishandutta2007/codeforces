#include <bits/stdc++.h>

using namespace std;

const int N = 100005;
const long long INF = 1e18;

int n;
int cost[N];
long long dp[N][2];
string word[N];

int main() {

    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
        dp[i][0] = dp[i][1] = INF;
    }

    for (int i = 1; i <= n; i++) {
        cin >> word[i];
        if (i == 1) {
            dp[i][0] = 0;
            dp[i][1] = cost[i];
        } else {
            string prev = word[i - 1];
            if (prev <= word[i]) {
                dp[i][0] = dp[i - 1][0];
            }
            reverse(prev.begin(), prev.end());
            if (prev <= word[i]) {
                dp[i][0] = min(dp[i][0], dp[i - 1][1]);
            }
            reverse(prev.begin(), prev.end());
            reverse(word[i].begin(), word[i].end());
            if (prev <= word[i]) {
                dp[i][1] = dp[i - 1][0] + cost[i];
            }
            reverse(prev.begin(), prev.end());
            if (prev <= word[i]) {
                dp[i][1] = min(dp[i][1], dp[i - 1][1] + cost[i]);
            }
            reverse(word[i].begin(), word[i].end());
        }
    }

    if (min(dp[n][0], dp[n][1]) >= INF) {
        printf("-1\n");
    } else {
        printf("%lld\n", min(dp[n][0], dp[n][1]));
    }

    return 0;
}