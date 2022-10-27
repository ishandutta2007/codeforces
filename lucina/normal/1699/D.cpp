#include<bits/stdc++.h>
using namespace std;
const int nax = 5010;

int dp[nax];
int n;
int a[nax];
int cnt[nax];

void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        dp[i] = -1e5;
    }

    for (int i = 1 ; i <= n ; ++ i) {
        int cnt_f = 0, mx_cnt = 0;
        for (int j = i - 1 ; j >= 0 ; -- j) {
            if (a[j] == a[i] || j == 0) {
                if (mx_cnt * 2 <= cnt_f && cnt_f % 2 == 0) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (j > 0) {
                cnt_f += 1;
                mx_cnt = max(mx_cnt, ++cnt[a[j]]);
            }
        }
        fill(cnt, cnt + 1 + n, 0);
    }

    int ans = 0;
    int cnt_f = 0, mx_cnt = 0;

    for (int i = n ; i >= 0 ; -- i) {
        if (mx_cnt * 2 <= cnt_f && cnt_f % 2 == 0) {
            ans = max(ans, dp[i]);
        }
        cnt_f += 1;
        mx_cnt = max(mx_cnt, ++cnt[a[i]]);
    }
    fill(cnt, cnt + 1 + n, 0);

    cout << ans << '\n';
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}