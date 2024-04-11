
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

const int N = 1005;
int dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i, 0, N) rep(j, 0, N) dp[i][j] = -1;
    auto solve = [&](auto solve, int i, int j) -> int {
        if(dp[i][j] != -1) return dp[i][j];
        if(i == j) return dp[i][j] = 0;
        if(i > j) return dp[i][j] = 1e9;
        dp[i][j] = 1e9;
        for(int x = 1; x * x <= i; x++) {
            int k = i + i / x;
            if(i < k && k <= j) dp[i][j] = min(dp[i][j], 1 + solve(solve, k, j));
            
            // max x such that k = i + floor(i / x) <= i + i / x
            // k x <= i x + i
            // (k - i) x <= i
            // x <= i / (k - i)
            if(i / (i / (x)) == x && i + x <= j) {
                dp[i][j] = min(dp[i][j], 1 + solve(solve, i + x, j));
            }
        }
        return dp[i][j];
    };
    rep(i, 1, N) {
        solve(solve, 1, i);
    }
    int te;
    cin >> te;
    while(te--) {
        int n, k;
        cin >> n >> k;
        vi b(n), c(n);
        rep(i, 0, n) cin >> b[i];
        rep(i, 0, n) cin >> c[i];
        if(k > 12*n) {
            cout << accumulate(all(c), 0) << '\n';
            continue;
        }
        vi ans(k + 1, 0);
        rep(i, 0, n) {
            int weight = solve(solve, 1, b[i]);
            int profit = c[i];
            for(int j = k; j >= weight; j--) {
                ans[j] = max(ans[j], profit + ans[j - weight]);
            }
        }
        cout << ans[k] << '\n';
    }
}