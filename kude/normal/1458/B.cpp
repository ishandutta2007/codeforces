#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;
using VL = vector<ll>;
using VVL = vector<VL>;

int dp[101][40100];
constexpr int B = 20050;
constexpr int inf = 1001001001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(12);
    int n;
    cin >> n;
    rep(j, n + 1) for(int k = -n * 200; k <= n * 200; ++k) dp[j][B + k] = -inf;
    dp[0][B] = 0;
    rep(i, n) {
        int a, b;
        cin >> a >> b;
        a *= 2;
        b *= 2;
        // pour and throw away
        rrep(j, n + 1) for(int k = -n * 200; k <= n * 200; ++k) {
            if (j < n && k + a - b <= n * 200) chmax(dp[j+1][B+k+a-b], dp[j][B+k] + b);
            if (-n * 200 <= k - b / 2) chmax(dp[j][B+k-b/2], dp[j][B+k] + b / 2);
        }
        // use the glass
        //rep(j, n) for(int k = -n * 100; k + a - b <= n * 100; ++k) {
        //    chmax(dp[i+1][j+1][B+k+a-b], dp[i][j][B+k] + b);
        //    //if (j == 0 && k == 0)
        //}
        //if (i == 0) cout << dp[1][1][B+1] << endl;
    }
    for(int j = 1; j <= n; ++j) {
        int ans = -inf;
        for(int k = -n * 200; k <= n * 200; ++k) {
            if (k < 0) chmax(ans, dp[j][B+k] + k);
            else chmax(ans, dp[j][B+k]);
            //if (ans == 22) cout << "xx" << k << endl;
        }
        cout << double(ans) / 2 << '\n';
    }
}