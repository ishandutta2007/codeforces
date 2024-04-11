
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
    n += 2;
    vi a(n, 0);
    const int D = 20;
    vector<vi> dp(D + 1, vi(n, 0));
    rep(i, 2, n) cin >> a[i];
    int ans = 0;
    rep(i, 0, n) {
        rep(d, 1, D + 1) {
            if(i + d >= n) continue;
            ans = max(ans, dp[d][i]);
            if(i + d + 1 < n) {
                dp[1][i + d] = max(dp[1][i + d], (a[i] != a[i + d + 1]) + dp[d][i]);
                if(d + 1 <= D) dp[d + 1][i] = max(dp[d + 1][i], (a[i + d] != a[i + d + 1]) + dp[d][i]);
            }
        }
    }
    cout << ans << '\n';
}