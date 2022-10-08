
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

const int N = 5005;
int dp[2][N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;
    rep(i, 0, n + 1) {
        rep(j, 0, m + 1) {
            dp[1][i][j] = 0;
            if(i > 0 && j > 0 && s[i - 1] == t[j - 1] && dp[1][i - 1][j - 1] + 2 > dp[1][i][j]) {
                dp[1][i][j] = dp[1][i - 1][j - 1] + 2;
            }
            if(i > 0 && dp[1][i - 1][j] - 1 > dp[1][i][j]) {
                dp[1][i][j] = dp[1][i - 1][j] - 1;
            }
            if(j > 0 && dp[1][i][j - 1] - 1 > dp[1][i][j]) {
                dp[1][i][j] = dp[1][i][j - 1] - 1;
            }
            dp[0][i][j] = dp[1][i][j];
            if(i > 0 && dp[0][i - 1][j] > dp[0][i][j]) dp[0][i][j] = dp[0][i - 1][j];
            if(j > 0 && dp[0][i][j - 1] > dp[0][i][j]) dp[0][i][j] = dp[0][i][j - 1];
        }
    }
    cout << dp[0][n][m] << '\n';
}