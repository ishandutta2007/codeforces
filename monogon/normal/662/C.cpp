
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
    int n, m;
    cin >> n >> m;
    vector<vi> dp(n + 1, vi(1 << n, 0));
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    rep(i, 0, m) {
        int mask = 0;
        rep(j, 0, n) {
            if(s[j][i] == '1') mask ^= (1 << j);
        }
        dp[0][mask]++;
    }
    rep(k, 1, n + 1) {
        rep(mask, 0, 1 << n) {
            rep(i, 0, n) {
                dp[k][mask] += dp[k - 1][mask ^ (1 << i)] / max(1, k - 1);
            }
            if(k >= 2) dp[k][mask] -= (n - k + 2) * dp[k - 2][mask] / max(1, k - 2);
        }
    }
    int ans = INT_MAX;
    rep(mask, 0, 1 << n) {
        int cnt = 0;
        rep(k, 1, n + 1) {
            cnt += (dp[k][mask] / k) * min(k, n - k);
        }
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
}