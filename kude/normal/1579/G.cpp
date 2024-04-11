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
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        constexpr int INF = 1001001001;
        VI dp(2010, INF), ndp = dp;
        dp[0] = 0;
        rep(_, n) {
            int a;
            cin >> a;
            ndp.assign(2010, INF);
            rep(i, 2010) {
                if (i + a < 2010) chmin(ndp[i + a], max(dp[i] - a, 0));
                if (i >= a) chmin(ndp[i - a], dp[i] + a);
                else chmin(ndp[0], dp[i] + a);
            }
            swap(dp, ndp);

        }
        int ans = INF;
        rep(i, 2010) chmin(ans, i + dp[i]);
        cout << ans << '\n';
    }
}