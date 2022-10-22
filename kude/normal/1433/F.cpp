#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int MX = 70 * m + 1;
    int rmx = m / 2;
    VI dp0(k, -1);
    dp0[0] = 0;
    rep(_, n) {
        VVI dp(rmx + 1, VI(MX));
        dp[0][0] = true;
        rep(_, m) {
            int x;
            cin >> x;
            rrep(i, rmx) rep(j, MX) {
                if (dp[i][j]) {
                    //cout << i << ' ' << j << ' ' << i + 1 << ' ' << j + x << endl;
                    dp[i+1][j+x] = true;
                }
            }
        }
        VI d(k, -1);
        rep(j, MX) rep(i, rmx+1) {
            if (dp[i][j]) d[j%k] = j;
        }

        VI ndp(k, -1);
        rep(i, k) if (dp0[i] >= 0) rep(j, k) if (d[j] >= 0) {
            chmax(ndp[(j+i)%k], dp0[i] + d[j]);
        }
        dp0 = move(ndp);
    }

    int ans = dp0[0];
    cout << ans << endl;
}