
#include <bits/stdc++.h>

#define ll long long
#define rep(i, a, b) for(int i = (a); i < (b); i++)
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pii pair<int, int>
#define vi vector<int>

using namespace std;

const int N = 205;
int n, k;
string s, t;
ll dp[N][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> k >> s >> t;
    if(t[0] == t[1]) {
        ll cnt = 0;
        rep(i, 0, n) cnt += (s[i] == t[0]);
        ll mx = min(1LL * n, cnt + k);
        cout << mx * (mx - 1) / 2 << '\n';
        return 0;
    }
    rep(i, 0, n) {
        rep(op, 0, k + 1) {
            rep(c, 0, n + 1) {
                auto &d = dp[i][op][c];
                d = -1;
                // if change to t[0]
                int cost = (s[i] == t[0] ? 0 : 1);
                if(cost <= op) {
                    if(i == 0 && c <= 1) d = max(d, 0LL);
                    else if(i != 0 && dp[i - 1][op - cost][max(c - 1, 0)] != -1)
                        d = max(d, dp[i - 1][op - cost][max(c - 1, 0)]);
                }
                // if change to t[1]
                cost = (s[i] == t[1] ? 0 : 1);
                if(cost <= op) {
                    if(i == 0 && c == 0) d = max(d, 0LL);
                    else if(i != 0 && dp[i - 1][op - cost][c] != -1)
                        d = max(d, c + dp[i - 1][op - cost][c]);
                }
                // if useless character
                if(i == 0 && c == 0) d = max(d, 0LL);
                else if(i != 0 && dp[i - 1][op][c] != -1)
                    d = max(d, dp[i - 1][op][c]);
            }
        }
    }
    cout << *max_element(dp[n - 1][k], dp[n - 1][k] + n + 1) << '\n';
}