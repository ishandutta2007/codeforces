
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
    int n;
    cin >> n;
    vi c(n);
    vector<vi> pos(n + 1);
    rep(i, 0, n) {
        cin >> c[i];
        pos[c[i]].push_back(i);
    }
    vector<vi> dp(n + 1, vi(n));
    rep(len, 1, n + 1) {
        rep(l, 0, n - len + 1) {
            int r = l + len - 1;
            dp[len][l] = dp[len - 1][l];
            for(int i : pos[c[r]]) {
                if(l <= i && i < r) {
                    dp[len][l] = max(dp[len][l], 1 + dp[i - l + 1][l] + dp[r - i][i]);
                }
            }
        }
    }
    cout << n - 1 - dp[n][0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}