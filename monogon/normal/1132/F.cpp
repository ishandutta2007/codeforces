
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

const int N = 505;
int n;
string s;
int dp[N][N][27];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> s;
    int k = 0;
    rep(i, 0, n) {
        if(i == 0 || s[i] != s[k - 1]) {
            s[k++] = s[i];
        }
    }
    n = k;
    s.erase(s.begin() + k, s.end());
    rep(len, 1, n + 1) {
        rep(i, 0, n - len + 1) {
            rep(c, 0, 26) {
                dp[len][i][c] = (s[i] - 'a' != c) + dp[len - 1][i + 1][c];
                rep(j, i + 1, i + len) {
                    dp[len][i][c] = min({
                        dp[len][i][c],
                        dp[j - i][i][c] + dp[len - j + i][j][c],
                        dp[j - i][i][26] + dp[len - j + i][j][c] + 1,
                        dp[j - i][i][c] + dp[len - j + i][j][26] + 1
                    });
                }
            }
            dp[len][i][26] = *min_element(dp[len][i], dp[len][i] + 26);
        }
    }
    cout << 1 + dp[n][0][26] << '\n';
}