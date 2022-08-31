#include <bits/stdc++.h>
using namespace std;
string s;
int n, m;
const int maxN = (int)1e5 + 10;
int cnt[maxN];
int f[maxN][2];
pair < int, int > dp[maxN];
bool ok(int i) {
    if (i + m > n) return false;
    if (f[i][0] < (m + 1) / 2) return false;
    if (f[i + 1][1] < (m / 2)) return false;
    return true;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n;
    cin >> s;
    cin >> m;
    for (int i = 0; i < n; i++) {
        cnt[i + 1] = cnt[i];
        if (s[i] == '?') cnt[i + 1]++;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == 'b') f[i][0] = 0;
        else f[i][0] = f[i + 2][0] + 1;
        if (s[i] == 'a') f[i][1] = 0;
        else f[i][1] = f[i + 2][1] + 1;
    }
    for (int i = n - 1; i >= 0; i--) {
        if (ok(i)) {
            //cout << i << " ";
            if (dp[i].first < dp[i + m].first + 1) {
                dp[i].first = dp[i + m].first + 1;
                dp[i].second = dp[i + m].second + cnt[i + m] - cnt[i];
            }
            else if (dp[i].first == dp[i + m].first + 1) {
                dp[i].second = min(dp[i].second, dp[i + m].second + cnt[i + m] - cnt[i]);
            }
        }
        if (dp[i].first < dp[i + 1].first) {
            dp[i].first = dp[i + 1].first;
            dp[i].second = dp[i + 1].second;
        }
        else if (dp[i].first == dp[i + 1].first) {
            dp[i].second = min(dp[i].second, dp[i + 1].second);
        }
    }
    cout << dp[0].second;
    return 0;
}