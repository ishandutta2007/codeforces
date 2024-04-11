#include <bits/stdc++.h>

#define F first
#define S second
#define prev azaza
#define MP make_pair
#define PB push_back

using namespace std;
typedef long long ll;
typedef long double ld;

const int max_n = 111;
ll inf = 1000111222333LL;

int n, k;
string s;
ll dp[max_n][max_n];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    cin >> s;
    s = "$" + s;
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 1;
    }
    for (int len = 1; len <= n; ++len) {
        for (int j = 1; j <= n; ++j) {
            dp[len][j] = dp[len][j - 1] + dp[len - 1][j - 1];
            for (int k = j - 1; k >= 1; --k) {
                if (s[k] == s[j]) {
                    dp[len][j] -= dp[len - 1][k - 1];
                    break;
                }
            }
            dp[len][j] = min(dp[len][j], inf);
        }
    }
    ll ans = 0;
    for (int len = s.size(); len >= 0; --len) {
        ll cnt = dp[len][n];
        if (cnt < k) {
            ans += (cnt * (n - len));
            k -= cnt;
        } else {
            ans += (k * (n - len));
            k -= k;
            break;
        }
    }
    if (k) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
    return 0;
}