#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

const ll MOD = 998244353ll;
ll k;

ll bin_pow(ll a, ll b) {
    if (a <= 0)
        return 0ll;
    if (b == 0)
        return 1ll;
    if (b % 2)
        return bin_pow(a, b - 1) * a % MOD;
    else
        return bin_pow(a * a % MOD, b / 2);
}

ll get(vector<int> &a) {
    int n = a.size();
    ll ans = 1;
    for (int i = 0; i < n;) {
        while(i < n && a[i] != -1)
            i++;
        if (i == n)
            break;
        int lft_val = -1;
        if (i != 0)
            lft_val = a[i - 1];
        int j = i;
        while (i < n && a[i] == -1)
            i++;
        int rgt_val = -1;
        if (i != n)
            rgt_val = a[i];
        int len = i - j;
        if (lft_val == -1) {
            if (rgt_val == -1) {
                ans *= k;
                ans %= MOD;
                ans *= bin_pow(k - 1, len - 1);
                ans %= MOD;
            } else {
                ans *= bin_pow(k - 1, len);
                ans %= MOD;
            }
        } else {
            if (rgt_val == -1) {
                ans *= bin_pow(k - 1, len);
                ans %= MOD;
            } else if (lft_val == rgt_val) {
                if (len == 1) {
                    ans *= (k - 1);
                    ans %= MOD;
                } else {
                    vector<array<ll, 2>> dp(len - 1);
                    dp[0][0] = 0;
                    dp[0][1] = (k > 1 ? 1ll : 0ll);
                    for (int i = 1; i < len - 1; i++) {
                        dp[i][0] = dp[i - 1][1] * (k - 1) % MOD;
                        dp[i][1] = dp[i - 1][0] + dp[i - 1][1] * max(0ll, (k - 2)) % MOD;
                        dp[i][1] %= MOD;
                    }
                    ans *= dp.back()[0] * (k - 1) % MOD + dp.back()[1] * max(0ll, (k - 2)) % MOD * max(0ll, k - 1) % MOD;
                    ans %= MOD;  
                }
            } else {
                if (len == 1) {
                    ans *= k - 2;
                    ans %= MOD;
                } else {
                    vector<array<ll, 3>> dp(len - 1);
                    dp[0][0] = 0;
                    dp[0][1] = 1;
                    dp[0][2] = (k > 2 ? 1ll : 0ll);
                    for (int i = 1; i < len - 1; i++) {
                        dp[i][0] = dp[i - 1][1] + dp[i - 1][2] * (k - 2) % MOD;
                        dp[i][0] %= MOD;
                        dp[i][1] = dp[i - 1][0] + dp[i - 1][2] * (k - 2) % MOD;
                        dp[i][1] %= MOD;
                        dp[i][2] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] * max(0ll, (k - 3)) % MOD;
                        dp[i][2] %= MOD;
                    }
                    ans *= dp.back()[0] * (k - 2) % MOD + dp.back()[1] * (k - 1) % MOD + dp.back()[2] * max(0ll, k - 2) % MOD * (k - 2) % MOD;
                    ans %= MOD;
                }
            }
        }
    }
    return ans;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n >> k;
    vector<int> a(n);
    for (int &el : a)
        cin >> el;
    bool chk = true;
    for (int i = 0; i + 2 < n; i++)
        chk &= (a[i] != a[i + 2] || a[i] == -1);
    if (!chk)
        return cout << "0\n", 0;
    vector<int> odd, even;
    for (int i = 0; i < n; i += 2)
        even.pb(a[i]);
    for (int i = 1; i < n; i += 2)
        odd.pb(a[i]);
    cout << get(even) * get(odd) % MOD << '\n';
}