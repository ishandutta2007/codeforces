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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n;
    VI a, b;
    rep(i, n) {
        int x;
        cin >> x;
        if (x == 0) b.push_back(i);
        else a.push_back(i);
    }
    n = a.size(), m = b.size();
    VI dp(m + 1);
    constexpr int INF = 1001001001;
    rep(i, n) {
        VI ndp(m + 1, INF);
        int mn = INF;
        rep(j, m) {
            chmin(mn, dp[j]);
            chmin(ndp[j + 1], mn + abs(a[i] - b[j]));
        }
        swap(dp, ndp);
        // rep(i, m + 1) cout << dp[i] << " \n"[i == m];
    }
    int ans = INF;
    rep(i, m + 1) chmin(ans, dp[i]);
    cout << ans << '\n';
}