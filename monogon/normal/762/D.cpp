
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

// | . .
// . | .
// . . |
//    _
// | | |

//  _
// | | |

// odd subset moving down

const int N = 1e5 + 5, TY = 5;
int n;
ll a[3][N], dp[N][5];
int masks[TY] = {1, 2, 4, 7, 7};
// 3 -> index 0 is the tail
// 4 -> index 2 is the tail

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    rep(i, 0, 3) {
        rep(j, 1, n + 1) {
            cin >> a[i][j];
        }
    }
    fill(dp[0], dp[0] + 8, LLONG_MIN);
    dp[0][0] = 0;
    rep(i, 1, n + 1) {
        ll sum = a[0][i] + a[1][i] + a[2][i];
        rep(ty, 0, 5) {
            dp[i][ty] = LLONG_MIN;
            switch(ty) {
            case 0:
                if(dp[i - 1][0] != LLONG_MIN) {
                    dp[i][ty] = a[0][i] + dp[i - 1][0];
                }
                if(dp[i - 1][4] != LLONG_MIN) {
                    dp[i][ty] = max(dp[i][ty], sum + dp[i - 1][4]);
                }
                if(dp[i - 1][1] != LLONG_MIN) {
                    dp[i][ty] = max(dp[i][ty], a[0][i] + a[1][i] + dp[i - 1][1]);
                }
                if(dp[i - 1][2] != LLONG_MIN) {
                    dp[i][ty] = max(dp[i][ty], sum + dp[i - 1][2]);
                }
                break;
            case 1:
                if(dp[i - 1][1] != LLONG_MIN) {
                    dp[i][ty] = a[1][i] + dp[i - 1][1];
                }
                if(dp[i - 1][0] != LLONG_MIN) {
                    dp[i][ty] = max(dp[i][ty], a[0][i] + a[1][i] + dp[i - 1][0]);
                }
                if(dp[i - 1][2] != LLONG_MIN) {
                    dp[i][ty] = max(dp[i][ty], a[1][i] + a[2][i] + dp[i - 1][2]);
                }
                break;
            case 2:
                if(dp[i - 1][2] != LLONG_MIN) {
                    dp[i][ty] = a[2][i] + dp[i - 1][2];
                }
                if(dp[i - 1][3] != LLONG_MIN) {
                    dp[i][ty] = max(dp[i][ty], sum + dp[i - 1][3]);
                }
                if(dp[i - 1][0] != LLONG_MIN) {
                    dp[i][ty] = max(dp[i][ty], sum + dp[i - 1][0]);
                }
                if(dp[i - 1][1] != LLONG_MIN) {
                    dp[i][ty] = max(dp[i][ty], a[1][i] + a[2][i] + dp[i - 1][1]);
                }
                break;
            case 3:
                if(dp[i - 1][3] != LLONG_MIN) {
                    dp[i][ty] = sum + dp[i - 1][3];
                }
                if(dp[i - 1][0] != LLONG_MIN) {
                    dp[i][ty] = max(dp[i][ty], sum + dp[i - 1][0]);
                }
                break;
            case 4:
                if(dp[i - 1][4] != LLONG_MIN) {
                    dp[i][ty] = sum + dp[i - 1][4];
                }
                if(dp[i - 1][2] != LLONG_MIN) {
                    dp[i][ty] = max(dp[i][ty], sum + dp[i - 1][2]);
                }
                break;
            }
        }
    }
    // rep(i, 0, 5) rep(j, 0, n + 1) {
    //     if(dp[j][i] == LLONG_MIN) cout << ". ";
    //     else cout << dp[j][i] << ' ';
    //     if(j == n) cout << endl;
    // }
    cout << dp[n][2] << '\n';
}