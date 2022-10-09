
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

const int N = 1e6 + 5;
int n, m, tile[N], dp[N][5][3];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        int a;
        cin >> a;
        tile[a]++;
    }
    rep(i, 1, m + 1) {
        // cout << tile[i] << ' ';
        rep(a, 0, 5) {
            rep(b, 0, 3) {
                if(i == 1 && b > 0) dp[i][a][b] = 0;
                else if(i <= 2) dp[i][a][b] = (tile[i] - a) / 3 + dp[i - 1][b][0];
                else {
                    dp[i][a][b] = (tile[i] - a) / 3 + dp[i - 1][b][0];
                    if(tile[i] - a > 0 && tile[i - 1] - b > 0 && tile[i - 2] > 0) {
                        dp[i][a][b] = max(dp[i][a][b], 1 + dp[i - 1][b + 1][1] + (tile[i] - a - 1) / 3);
                    }
                    if(tile[i] - a > 1 && tile[i - 1] - b > 1 && tile[i - 2] > 1) {
                        dp[i][a][b] = max(dp[i][a][b], 2 + dp[i - 1][b + 2][2] + (tile[i] - a - 2) / 3);
                    }
                }
            }
        }
    }
    // cout << endl;
    cout << dp[m][0][0] << '\n';
}