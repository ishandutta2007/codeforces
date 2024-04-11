
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

const int N = 2e5 + 5;
int a[N];
int dp[2][N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        int n;
        cin >> n;
        rep(i, 0, n) {
            cin >> a[i];
        }
        dp[0][n] = dp[1][n] = 0;
        for(int i = n - 1; i >= 0; i--) {
            dp[0][i] = min(dp[1][i + 1], i < n - 1 ? dp[1][i + 2] : INT_MAX);
            dp[1][i] = min(a[i] + dp[0][i + 1], i < n - 1 ? a[i] + a[i + 1] + dp[0][i + 2] : INT_MAX);
        }
        cout << dp[1][0] << '\n';
    }
}