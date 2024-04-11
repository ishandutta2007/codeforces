#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const ll INF = 1e18 + 10;
const int maxN = 65;
ll dp[maxN];
ll safe_mult(ll a, ll b) {
    if (!a || !b) return 0;
    if (a >= (INF + b - 1) / b) return INF;
    return a * b;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    ll n;
    cin >> n;
    string s;
    cin >> s;
    int t = s.size();
    dp[0] = 0;
    for (int i = 0; i <= t - 1; i++) {
        dp[i] = INF;
        for (int from = i; from >= 0; from--) {
            ll cur_num = 0;
            if (s[from] == '0' && from != i) continue;
            for (int j = from; j <= i; j++) {
                cur_num = 10 * cur_num + (s[j] - '0');
                if (cur_num >= n) break;
            }
            if (cur_num >= n) continue;
            if (from == 0) dp[i] = min(dp[i], cur_num);
            else {
                dp[i] = min(dp[i], safe_mult(dp[from - 1], n) + cur_num);
            }
        }
    }
    cout << dp[t - 1];
    return 0;
}