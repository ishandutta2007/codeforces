
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
    vector<string> s(n);
    rep(i, 0, n) cin >> s[i];
    vector<vector<vector<ll>>> dp(1 << n);
    rep(mask, 1, 1 << n) {
        dp[mask].resize(n);
        int cnt = __builtin_popcount(mask);
        rep(i, 0, n) {
            dp[mask][i].assign(1 << (cnt - 1), 0);
        }
    }
    rep(mask, 1, 1 << n) {
        int cnt = __builtin_popcount(mask);
        if(cnt == 1) {
            int i = 0;
            while(~mask >> i & 1) i++;
            dp[mask][i][0] = 1;
            continue;
        }
        rep(i, 0, n) {
            if(mask >> i & 1) {
                rep(str, 0, 1 << (cnt - 1)) {
                    rep(j, 0, n) {
                        if((mask >> j & 1) && (i != j) && (s[i][j] == '1') == (str & 1)) {
                            dp[mask][i][str] += dp[mask ^ (1 << i)][j][str >> 1];
                        }
                    }
                }
            }
        }
    }
    rep(str, 0, 1 << (n - 1)) {
        ll ans = 0;
        rep(i, 0, n) {
            ans += dp[(1 << n) - 1][i][str];
        }
        cout << ans << ' ';
    }
    cout << '\n';
}