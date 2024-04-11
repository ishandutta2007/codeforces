
// smh with that memory limit

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

const int N = 500, M = 1e9 + 7;
int n, m;
string s[N];
int dp[2][N][N];

int solve(int x, int y, int x2) {
    int b = (x + y) % 2;
    if(x < 0 || x >= n || y < 0 || y >= m || x2 < 0 || x2 >= n) return 0;
    if(dp[b][x][x2] != -1) return dp[b][x][x2];
    int y2 = n + m - 2 - (x + y) - x2;
    if(y < 0 || y >= m || s[x][y] != s[x2][y2]) return dp[b][x][x2] = 0;
    if(abs(x + y - x2 - y2) <= 1) {
        if(abs(x - x2) + abs(y - y2) > 1) return dp[b][x][x2] = 0;
        else return dp[b][x][x2] = 1;
    }
    ll ans = 0;
    ans += max(0, solve(x + 1, y, x2));
    ans += max(0, solve(x, y + 1, x2));
    ans += max(0, solve(x + 1, y, x2 - 1));
    ans += max(0, solve(x, y + 1, x2 - 1));
    return dp[b][x][x2] = ans % M;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    rep(i, 0, n) {
        cin >> s[i];
    }
    // rep(b, 0, 2) rep(x, 0, n) rep(x2, 0, n) {
    //     dp[b][x][x2] = -1;
    // }
    for(int s = (n + m - 2) / 2; s >= 0; s--) {
        rep(x, 0, n) rep(x2, 0, n) {
            dp[s % 2][x][x2] = -1;
            int y = s - x;
            solve(x, y, x2);
        }
    }
    cout << solve(0, 0, n - 1) << '\n';
}