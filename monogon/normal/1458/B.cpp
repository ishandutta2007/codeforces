
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

const int N = 105;
int dp[N][N * N], a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    int s = 0;
    rep(i, 1, n + 1) {
        cin >> a[i] >> b[i];
        s += b[i];
    }
    rep(k, 0, n + 1) rep(x, 0, N * N) dp[k][x] = -1;
    dp[0][0] = 0;
    rep(i, 1, n + 1) {
        for(int k = n; k >= 1; k--) {
            for(int x = N * N - 1; x >= b[i]; x--) {
                if(dp[k - 1][x - b[i]] != -1) {
                    dp[k][x] = max(dp[k][x], dp[k - 1][x - b[i]] + a[i] - b[i]);
                }
            }
        }
    }
    cout << fixed << setprecision(10);
    rep(k, 1, n + 1) {
        int ans = 0;
        rep(x, 0, N * N) {
            if(dp[k][x] != -1) {
                ans = max(ans, 2 * x + min(2 * dp[k][x], s - x));
            }
        }
        cout << 0.5 * ans << ' ';
    }
    cout << '\n';
}