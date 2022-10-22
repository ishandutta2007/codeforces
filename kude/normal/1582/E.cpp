#include<bits/stdc++.h>
using namespace std;
#define rep(i,n)for (int i = 0; i < int(n); ++i)
#define rrep(i,n)for (int i = int(n)-1; i >= 0; --i)
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

constexpr ll INF = 1002003004005006007;

ll dp[1000][1000];
ll a[100001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        int mx = 1;
        while(mx * (mx + 1) <= 2 * n) mx++;
        rep(i, n) cin >> a[i];
        reverse(a, a + n);
        rrep(i, n) a[i + 1] = a[i];
        a[0] = 0;
        rep(i, n) a[i + 1] += a[i];
        rep(i, mx) rep(j, mx) dp[i][j] = -1;
        dp[0][0] = INF;
        rep(i, n) {
            int ii = i % mx;
            {
                int jj = (i + 1) % mx;
                rep(k, mx) chmax(dp[jj][k], dp[ii][k]);
            }
            for(int j = i + 1; j <= n && j - i < mx; j++) {
                int k = j - i;
                int jj = j % mx;
                if (dp[ii][k - 1] > a[j] - a[i]) chmax(dp[jj][k], a[j] - a[i]);
            }
        }
        int ans = 0;
        int ii = n % mx;
        rep(k, mx) if (dp[ii][k] >= 0) ans = k;
        cout << ans << '\n';
    }
}