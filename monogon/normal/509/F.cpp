
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

// b1 = 1
// select increasing subsequence, dp

const int N = 505, M = 1e9 + 7;
int n, b[N];
ll dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, n) {
        cin >> b[i];
    }
    rep(len, 0, n) {
        rep(i, 0, n - len + 1) {
            if(len == 0) {
                dp[len][i] = 1;
            }else {
                dp[len][i] = dp[len - 1][i + 1];
                rep(k, i + 1, i + len) {
                    if(b[k] > b[i]) {
                        dp[len][i] = (dp[len][i] + dp[k - i - 1][i + 1] * dp[i + len - k][k]) % M;
                    }
                }
            }
            // cout << dp[len][i] << ' ';
        }
        // cout << endl;
    }
    cout << dp[n - 1][1] << '\n';
}