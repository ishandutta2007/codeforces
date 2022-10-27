#include<bits/stdc++.h>
using namespace std;
const int C = 2e7;
const int nax = 1e5 + 10;
int a[nax];
int n;
int cnt[C + 1];
int64_t dp[C + 1];
int primes[C / 5];
bool is_primes[C + 1];
int tot_primes;

int main() {
    for (int j = 2 ; j <= C ; ++ j) {
        if (is_primes[j]) continue;
        primes[++ tot_primes] = j;
        for (int k = j + j ; k <= C ; k += j)
            is_primes[k] = true;
    }

    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        int x;
        cin >> x;
        cnt[x] += 1;
    }


    for (int i = 1 ; i <= tot_primes ; ++ i) {
        int x = primes[i];
        for (int j = C / x ; j >= 1 ; -- j) {
            cnt[j] += cnt[j * x];
        }
    }


    int64_t ans = 0;
    for (int64_t i = 1 ; i <= C ; ++ i) {
        for (int k = 1 ; i * primes[k] <= C ; k ++) {
            int64_t m = dp[i];
            int j = i * primes[k];
            int64_t dist = cnt[i] - cnt[j];
            if (dist < 0) continue;
            dp[j] = max(dp[j], m + dist * i);
        }
        ans = max(ans, dp[i] + 1ll * i * cnt[i]);
    }
    cout << ans << '\n';
}