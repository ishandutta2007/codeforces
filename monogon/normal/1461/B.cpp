
// #pragma GCC target ("avx2")
// #pragma GCC optimize ("O3")
// #pragma GCC optimize ("unroll-loops")
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<vi> dp(n, vi(m, 0));
    ll ans = 0;
    rep(i, 0, n) {
        cin >> s[i];
    }
    // auto ins = [&](int i, int j) {
    //     return 0 <= i && i < n && 0 <= j && j < m;
    // };
    for(int i = n - 1; i >= 0; i--) {
        rep(j, 0, m) {
            if(s[i][j] == '*') {
                dp[i][j] = 1;
                if(j > 0 && j < m - 1 && i < n - 1 && s[i + 1][j] == '*') {
                    dp[i][j] = 1 + min(dp[i + 1][j - 1], dp[i + 1][j + 1]);
                }
            }
            ans += dp[i][j];
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}