#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int cnt[10];
ll fact[20];
int cop[10];
ll dp[25][25];
ll c[25][25];
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    fact[0] = 1;
    for (int i = 1; i <= 19; i++) fact[i] = i * fact[i - 1];
    for (int i = 0; i <= 19; i++) {
        for (int j = 0; j <= i; j++) {
            c[i][j] = (fact[i]) / (fact[j] * fact[i - j]);
        }
    }
    ll n;
    cin >> n;
    while (n > 0) {
        cnt[n % 10]++;
        n /= 10;
    }
    dp[1][0] = 1;
    for (int i = 1; i <= 9; i++) {
        if (cnt[i] == 0) {
            for (int num = 0; num <= 20; num++) {
                dp[i + 1][num] = dp[i][num];
            }
            continue;
        }
        for (int num = 0; num <= 20; num++) {
            if (dp[i][num] == 0) continue;
            for (int dig = 1; dig <= cnt[i]; dig++) {
                dp[i + 1][num + dig] += dp[i][num] * c[num + dig][dig];
            }
        }
    }
    if (cnt[0] > 0) {
        for (int num = 0; num <= 20; num++) {
            if (dp[10][num] == 0) continue;
            for (int dig = 1; dig <= cnt[0]; dig++) {
                dp[11][num + dig] += dp[10][num] * c[num - 1 + dig][dig];
            }
        }
        ll ans = 0;
        for (int i = 0; i <= 20; i++) ans += dp[11][i];
        cout << ans;
    }
    else {
        ll ans = 0;

        for (int i = 0; i <= 20; i++) ans += dp[10][i];
        cout << ans;
    }
    return 0;
}