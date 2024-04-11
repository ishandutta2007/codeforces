#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 2e5 + 10;
int n, k;
string s;
const int maxK = (1 << 17) + 10;
int dp[maxK];
const int maxT = 17;
int jump[maxN][maxT];
bool check(int len) {
    for (int i = 0; i < (1 << k); i++) {
        dp[i] = n + 2;
    }
    dp[0] = 0;
    for (int x = 0; x < k; x++) {
        jump[n][x] = n;
        int cur_len = 0;
        for (int i = n - 1; i >= 0; i--) {
            jump[i][x] = jump[i + 1][x];
            if (s[i] == '?' || s[i] == (char)('a' + x)) cur_len++;
            else cur_len = 0;
            if (cur_len >= len) jump[i][x] = i;
        }
    }
    for (int mask = 0; mask < (1 << k); mask++) {
        if (dp[mask] >= n) continue;
        for (int z = 0; z < k; z++) {
            if (!(mask & (1 << z))) {
                if (jump[dp[mask]][z] < n) {
                    dp[mask | (1 << z)] = min(dp[mask | (1 << z)], jump[dp[mask]][z] + len);
                }
            }
        }
    }
    return (dp[(1 << k) - 1] <= n);
}
int main() {
   // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    cin >> s;
    int l = 0;
    int r = n + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        }
        else {
            r = mid;
        }
    }
    cout << l;
}