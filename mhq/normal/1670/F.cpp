#pragma pack(1)

#include <bits/stdc++.h>

#define f first
#define s second
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
int n;
ll l, r, z;
const int mod = (int)1e9 + 7;
int sum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int mult(int a, int b) {
    return (1LL * a * b) % mod;
}
int sub(int a, int b) {
    int s = a - b;
    if (s < 0) s += mod;
    return s;
}
const int maxB = 62;
const int maxN = 1005;
int dp[maxB][2][maxN];
int c[maxN][maxN];
int solve(int n, ll l, ll z) {
    if (l < 0) {
        return 0;
    }
    memset(dp, 0, sizeof dp);
    dp[0][1][0] = 1;
    for (int bit = 0; bit + 1 < maxB; bit++) {
        int his_bt = (z >> (ll)bit) & 1;
        int bit_r = (l >> (ll)bit) & 1;
        for (int flag = 0; flag < 2; flag++) {
            for (int was = 0; was <= n; was++) {
                if (!dp[bit][flag][was]) continue;
                for (int cnt = his_bt & 1; cnt <= n; cnt += 2) {
                    int num = (cnt + was) & 1;
                    int carry = (cnt + was) / 2;
                    int new_flag = (num < bit_r) || ((num == bit_r) & flag);
                    dp[bit + 1][new_flag][carry] = sum(dp[bit + 1][new_flag][carry], 
                                                    mult(dp[bit][flag][was], c[n][cnt]));
                }
            }
        }
    }
    return dp[maxB - 1][1][0];
}
int main()
{
    cin >> n >> l >> r >> z;
    c[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = sum(c[i - 1][j], c[i - 1][j - 1]);
        }
    }
    cout << sub(solve(n, r, z), solve(n, l - 1, z));
}