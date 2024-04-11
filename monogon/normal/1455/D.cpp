
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

const int N = 505;
int dp[N][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n, x;
        cin >> n >> x;
        vi a(n);
        vi mn(n + 1, N);
        rep(i, 0, n) {
            cin >> a[i];
        }
        for(int i = n - 1; i >= 0; i--) {
            mn[i] = min(a[i], mn[i + 1]);
        }
        for(int i = n; i >= 0; i--) {
            rep(x, 0, N) {
                if(i == n) {
                    dp[i][x] = 0;
                    continue;
                }
                dp[i][x] = INT_MAX;
                if(a[i] > x && x <= mn[i + 1] && dp[i + 1][a[i]] != INT_MAX) {
                    dp[i][x] = min(dp[i][x], 1 + dp[i + 1][a[i]]);
                }
                if(a[i] <= mn[i + 1] && dp[i + 1][x] == 0) {
                    dp[i][x] = 0;
                }
                if(a[i] <= min(x, mn[i + 1]) && dp[i + 1][x] != INT_MAX) {
                    dp[i][x] = min(dp[i][x], dp[i + 1][x]);
                }
            }
        }
        cout << (dp[0][x] == INT_MAX ? -1 : dp[0][x]) << '\n';
    }
}