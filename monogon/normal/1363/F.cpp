
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

const int N = 2005;
int q, n, cnts[N][26], cntt[N][26], dp[N][N];
string s, t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> q;
    while(q--) {
        cin >> n >> s >> t;
        fill(cnts[0], cnts[0] + 26, 0);
        fill(cntt[0], cntt[0] + 26, 0);
        rep(i, 1, n + 1) {
            rep(c, 0, 26) {
                cnts[i][c] = cnts[i - 1][c];
                cntt[i][c] = cntt[i - 1][c];
            }
            cnts[i][s[i - 1] - 'a']++;
            cntt[i][t[i - 1] - 'a']++;
        }
        rep(c, 0, 26) {
            if(cnts[n][c] != cntt[n][c]) {
                cout << "-1\n";
                goto lab;
            }
        }
        rep(i, 0, n + 1) rep(j, 0, n + 1) {
            if(i == 0 || j == 0) dp[i][j] = 0;
            else {
                dp[i][j] = dp[i - 1][j];
                if(i <= j - 1) dp[i][j] = max(dp[i][j], dp[i][j - 1]);
                if(s[i - 1] == t[j - 1] && 1 + dp[i - 1][j - 1] > dp[i][j]) {
                    bool flag = true;
                    rep(c, 0, 26) {
                        if(cnts[i][c] > cntt[j][c]) {
                            flag = false;
                            break;
                        }
                    }
                    if(flag) dp[i][j] = 1 + dp[i - 1][j - 1];
                }
            }
        }
        cout << n - dp[n][n] << '\n';
        lab:;
    }
}