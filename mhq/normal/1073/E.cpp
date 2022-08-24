#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 998244353;
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
const int maxN = 1030;
int bits[maxN];
bool ok[maxN];
ll l, r;
int k;
string to_str(ll t) {
    string ans = "";
    while (t > 0) {
        ans += '0' + t % 10;
        t /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
int dp[21][maxN][2];
ll pw[25];
int dp2[21][maxN][2];
// skolko est ok chisel, kotorye nachinautsa na to chto dymaem
int solve_fixed_len(ll num) {
    if (num <= 9) {
        return (int)((num * (num + 1)) / 2);
    }
    memset(dp, 0, sizeof dp);
    memset(dp2, 0, sizeof dp2);
    string s = to_str(num);
    int n = s.size();
    dp[0][0][0] = 1;
    // dig ->
    // dp[i][mask]
    // left, mask,
    // dp[last][mask][2]
    for (int i = 0; i < n; i++) {
        for (int flag = 0; flag < 2; flag++) {
            for (int mask = 0; mask < (1 << 10); mask++) {
                for (int dig = 0; dig < 10; dig++) {
                    if (dig == 0 && i == 0) continue;
                    if (flag == 0 && dig > s[i] - '0') continue;
                    dp[i + 1][mask | (1 << dig)][flag | (dig < (s[i] - '0'))] = sum(dp[i + 1][mask | (1 << dig)][flag | (dig < (s[i] - '0'))],
                            dp[i][mask][flag]);
                    dp2[i + 1][mask | (1 << dig)][flag | (dig < (s[i] - '0'))] = sum(dp2[i + 1][mask | (1 << dig)][flag | (dig < (s[i] - '0'))],
                            sum(mult(10, dp2[i][mask][flag]), mult(dig, dp[i][mask][flag])));
                }
            }
        }
    }
    // mask
    // dig, mask1, mask2
    // flag
    // dp[i][mask][j] ->
    //skolko est cifr, kotorye na dig i
    int ans = 0;
    for (int flag = 0; flag < 2; flag++) {
        for (int mask = 0; mask < (1 << 10); mask++) {
            if (ok[mask]) {
                ans = sum(ans, dp2[n][mask][flag]);
            }
        }
    }
    return ans;
}
int solve(ll num) {
    if (num == 0) return 0;
    // len = len
    int ans = 0;
    for (int i = 1; ; i++) {
        if (pw[i] > num) break;
        ans = sum(ans, solve_fixed_len(pw[i] - 1));
    }
    ans = sum(ans, solve_fixed_len(num));
    return ans;
}
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    pw[0] = 1;
    for (int i = 1; i <= 20; i++) pw[i] = 10 * pw[i - 1];
    cin >> l >> r >> k;
    for (int i = 1; i < (1 << 10); i++) {
        for (int j = 0; j < 10; j++) {
            if (i & (1 << j)) {
                bits[i] = bits[i ^ (1 << j)] + 1;
                if (bits[i] <= k) {
                    ok[i] = true;
                }
                break;
            }
        }
    }
    cout << sub(solve(r), solve(l - 1));
    return 0;
}