
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// Could take all stickers. Reverse order.
// Otherwise, do DP on prefix to see who wins
// assume on a prefix, you are allowed to take only 1
// dp[i] = max_{1 <= j < i} (sum_{j < k <= i} (a[k]) - dp[j])
// = - sum(i < k) (a[k]) + max_{1 <= j < i} (sum_{j < k} - dp[j])

// Petya will either take everything and game ends, or will choose - min_{1 <= i < n} (dp[i])

// Reverse order, take prefix.
// DP on i, first token is sum_{1 <= j < i} (a[j])
// if you take everything, your point is just pref[n]

const int N = 2e5 + 5;
int n;
ll a[N], pref[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    reverse(a + 1, a + n + 1);
    rep(i, 1, n + 1) {
        pref[i] = pref[i - 1] + a[i];
    }
    ll dp = pref[n];
    ll mx = (pref[n] - pref[1]) - dp;
    rep(i, 2, n) {
        dp = max(pref[n], mx);
        mx = max(mx, (pref[n] - pref[i]) - dp);
    }
    cout << dp << '\n';
}