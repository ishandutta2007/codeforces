#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
const int maxN = 55;
int dp[2][maxN][maxN];
ll k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> k;
    dp[0][0][40] = 1;
    for (int bit = 39; bit >= 0; bit--) {
        int kbit = (k >> bit) & 1;
        for (int flag = 0; flag < 2; flag++) {
            for (int cnt = 0; cnt <= 40; cnt++) {
                for (int will_take = 0; will_take < 2; will_take++) {
                    for (int will_bit = 0; will_bit < 2; will_bit++) {
                        if (will_bit == 1 && kbit == 0 && flag == 0) continue;
                        int nflag = flag | (will_bit < kbit);
                        if (will_bit == 0 && will_take == 1) continue;
                        if (will_take == 1) {
                            dp[nflag][cnt + will_take][bit] = sum(dp[nflag][cnt + will_take][bit], dp[flag][cnt][bit + 1]);
                            continue;
                        }
                        if (cnt == 0 && will_bit == 1) continue;
                        if (cnt == 0) {
                            dp[nflag][cnt][bit] = sum(dp[nflag][cnt][bit], dp[flag][cnt][bit + 1]);
                            continue;
                        }
                        int coef = ((1LL << (cnt - 1))) % mod;
                        dp[nflag][cnt][bit] = sum(dp[nflag][cnt][bit], mult(dp[flag][cnt][bit + 1], coef));
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int flag = 0; flag < 2; flag++) {
        for (int i = 0; i <= 40; i++) {
            ans = sum(ans, dp[flag][i][0]);
        }
    }
    cout << ans;
    return 0;
}