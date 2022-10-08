
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n + 1), b(n + 1), pref(n + 1);
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) cin >> b[i];
    rep(i, 1, n + 1) pref[i] = pref[i - 1] + a[i] * b[i];
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    ll ans = 0;
    rep(len, 1, n + 1) {
        for(int i = 1; i + len <= n + 1; i++) {
            if(len == 1) dp[len][i] = a[i] * b[i];
            else {
                dp[len][i] = dp[len - 2][i + 1] + a[i] * b[i + len - 1] + a[i + len - 1] * b[i];
            }
            ans = max(ans, dp[len][i] + pref[n] - pref[i + len - 1] + pref[i - 1]);
        }
    }
    cout << ans << '\n';
}