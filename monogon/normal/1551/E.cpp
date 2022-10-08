
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n, k;
    cin >> n >> k;
    vi a(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    vector<vi> dp(n + 1, vi(n + 1, -1e9));
    dp[0][0] = 0;
    rep(i, 1, n + 1) {
        rep(k, 0, i + 1) {
            dp[i][k] = -1e9;
            // delete
            if(k > 0 && dp[i - 1][k - 1] >= 0) dp[i][k] = max(dp[i][k], dp[i - 1][k - 1]);
            // don't delete
            if(dp[i - 1][k] >= 0) dp[i][k] = max(dp[i][k], dp[i - 1][k] + (a[i] == i - k ? 1 : 0));
        }
    }
    int j = 0;
    while(j <= n && dp[n][j] < k) j++;
    if(j == n + 1) cout << -1 << '\n';
    else cout << j << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}