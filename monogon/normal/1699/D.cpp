
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    rep(i, 0, n) {
        cin >> a[i];
    }

    vi dp(n);
    dp[0] = 0;
    vi cnt(n + 1);
    rep(i, 1, n) {
        fill(all(cnt), 0);
        int mx = 0;
        int num = 0;
        dp[i] = INT_MAX;
        for(int j = i - 1; j >= 0; j--) {
            if(num % 2 == 1 || mx * 2 > num) {
                // not possible
            }else {
                // possible
                if(a[j] == a[i] && dp[j] != INT_MAX) {
                    dp[i] = min(dp[i], num / 2 + dp[j]);
                }
            }
            cnt[a[j]]++;
            num++;
            mx = max(mx, cnt[a[j]]);
        }
        if(num % 2 == 0 && mx * 2 <= num) {
            dp[i] = min(dp[i], (i + 1) / 2);
        }
    }
    fill(all(cnt), 0);
    int mx = 0, num = 0;
    int ans = INT_MAX;
    for(int j = n - 1; j >= 0; j--) {
        if(num % 2 == 1 || mx * 2 > num) {
            // not possible
        }else if(dp[j] != INT_MAX) {
            ans = min(ans, num / 2 + dp[j]);
        }
        cnt[a[j]]++;
        num++;
        mx = max(mx, cnt[a[j]]);
    }
    if(num % 2 == 0 && mx * 2 <= num) {
        ans = min(ans, n / 2);
    }
    cout << n - 2 * ans << '\n';

    // vector<vi> dp(n, vi(n + 1));
    // rep(val, 1, n + 1) {
    //     dp[0][val] = (val == a[0] ? 0 : INT_MAX);
    // }
    // rep(i, 1, n) {
    //     int j = i - 1;
    //     int cnt = 1;
    //     while(j >= 0 && cnt > 0) {
    //         if(a[i] == a[j]) {
    //             cnt++;
    //         }else {
    //             cnt--;
    //         }
    //         j--;
    //     }

    //     // dp[i][val] = min_j {dp[j][val]}
    //     // y y y y y y y x x z a[i]

    //     rep(val, 1, n + 1) {
    //         if(cnt == 0) {
    //             if(j < 0) {
    //                 dp[i][val] = (i + 1) / 2;
    //             }else {
    //                 dp[i][val] = dp[j][val] == INT_MAX ? INT_MAX : (i - j) / 2 + dp[j][val];
    //             }
    //         }else {
    //             dp[i][val] = INT_MAX;
    //         }
    //     }
    //     dp[i][a[i]] = min(dp[i][a[i]], dp[i - 1][a[i]]);

    //     dp[i][0] = INT_MAX;
    //     rep(val, 1, n + 1) {
    //         dp[i][0] = min(dp[i][0], dp[i][val]);
    //     }
    // }
    // cout << n - 2 * dp[n - 1][0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}