
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
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

const int N = 5005, M = 998244353;
ll dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    rep(i, 0, N) rep(j, 0, N) {
        if(i == 0 || j == 0) dp[i][j] = 1;
        else {
            dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1] * j) % M;
        }
    }
    ll ans = (((dp[a][b] * dp[b][c]) % M) * dp[c][a]) % M;
    cout << ans << '\n';
}