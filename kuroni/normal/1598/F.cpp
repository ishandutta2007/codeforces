#include <bits/stdc++.h>
using namespace std;

const int N = 20, MX = 4E5 + 5;

int n, sum[N], _cnt[N][2 * MX], _prv[N][2 * MX], *cnt[N], *prv[N];
int dp[1 << N], cs[1 << N], ans = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int &cur = sum[i];
        cnt[i] = _cnt[i] + MX; prv[i] = _prv[i] + MX;
        for (char c : s) {
            cur += (c == '(' ? 1 : -1);
            if (cnt[i][cur] == 0) {
                prv[i][cur] = cnt[i][cur + 1];
            }
            cnt[i][cur]++;
        }
    }
    fill(dp, dp + (1 << n), -1);
    dp[0] = 0;
    for (int msk = 0; msk < (1 << n); msk++) {
        if (dp[msk] != -1) {
            ans = max(ans, dp[msk]);
            int cur = cs[msk];
            for (int i = 0; i < n; i++) {
                if (!(msk >> i & 1)) {
                    if (cnt[i][-cur - 1] > 0) {
                        ans = max(ans, dp[msk] + prv[i][-cur - 1]);
                    } else {
                        dp[msk ^ (1 << i)] = max(dp[msk ^ (1 << i)], dp[msk] + cnt[i][-cur]);
                        cs[msk ^ (1 << i)] = cur + sum[i];
                    }
                }
            }
        }
    }
    cout << ans;
}