#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 1E6 + 5;

int n, k, l;
char s[N];
long long ans = N;
pair<long long, int> dp[N];

pair<long long, int> solve(int c, bool typ) {
    for (int i = 1; i <= n; i++) {
        int cur = ('a' <= s[i] && s[i] <= 'z') ^ typ;
        dp[i] = {dp[i - 1].fi + cur, dp[i - 1].se};
        dp[i] = min(dp[i], {(i < l ? 0 : dp[i - l].fi) + c, (i < l ? 0 : dp[i - l].se) + 1});
    }
    return dp[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k >> l >> (s + 1);
    for (int typ = 0; typ < 2; typ++) {
        int le = 0, ri = n;
        while (le <= ri) {
            int mi = (le + ri) / 2;
            if (solve(mi, typ).se <= k) {
                ri = mi - 1;
            } else {
                le = mi + 1;
            }
        }
        auto [mx, cnt] = solve(le, typ);
        ans = min(ans, mx - 1LL * le * k);
    }
    cout << ans;
}