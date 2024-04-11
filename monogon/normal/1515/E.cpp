
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
    int n; ll M;
    cin >> n >> M;
    vector<vector<ll>> choose(n + 1, vector<ll>(n + 1, 0));
    vector<ll> p2(n + 1, 1);
    rep(i, 0, n + 1) rep(j, 0, n + 1) {
        if(j == 0) choose[i][j] = 1;
        else if(i == 0) choose[i][j] = 0;
        else choose[i][j] = (choose[i - 1][j] + choose[i - 1][j - 1]) % M;
    }
    rep(i, 1, n + 1) {
        p2[i] = (2 * p2[i - 1]) % M;
    }
    vector<vector<ll>> dp(n + 1, vector<ll>(n + 1, 0));
    ll ans = 0;
    rep(i, 1, n + 1) {
        rep(k, 0, i + 1) {
            auto &d = dp[i][k];
            d = 0;
            rep(j, 1, k + 1) {
                ll val = (choose[k][j] * p2[j - 1]) % M;
                ll dp2 = (i - j - 1 == -1 ? 1 : dp[i - j - 1][k - j]);
                val = (val * dp2) % M;
                d = (d + val) % M;
            }
            if(i == n) ans = (ans + d) % M;
        }
    }
    cout << ans << '\n';
}