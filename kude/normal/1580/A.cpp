#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int dp[6][410][410];
int d[410];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        rep(k, 5) rep(i, m + 1) rep(j, m + 1) dp[k][i][j] = 100;
        int ans = 100;
        rep(_, n) {
            rep(j, m) {
                char c;
                cin >> c;
                d[j + 1] = c - '0';
            }
            rep(j, m) d[j + 1] += d[j];
            rrep(k, 5) rep(r, m + 1) rrep(l, r - 4 + 1) {
                if (k == 0 || k == 4) {
                    int x = r - 1 - (l + 1) - (d[r - 1] - d[l + 1]);
                    if (k == 4) {
                        chmin(ans, x + dp[k][l][r]);
                        dp[k][l][r] += d[r - 1] - d[l + 1] + 1 - (d[l + 1] - d[l]) + 1 - (d[r] - d[r - 1]);
                    } else {
                        dp[1][l][r] = x;
                    }
                } else {
                    int x = d[r - 1] - d[l + 1] + 1 - (d[l + 1] - d[l]) + 1 - (d[r] - d[r - 1]);
                    if (k < 3) {
                        dp[k + 1][l][r] = dp[k][l][r] + x;
                    } else {
                        chmin(dp[k + 1][l][r], dp[k][l][r] + x);
                    }
                }
            }
        }
        cout << ans << '\n';
    }
}