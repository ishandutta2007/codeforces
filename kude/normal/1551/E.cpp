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
        int n, k;
        cin >> n >> k;
        vector<int> dp(n + 1, -1);
        dp[0] = 0;
        rep(p, n) {
            VI ndp(n + 1, -1);
            int x;
            cin >> x;
            x--;
            for(int i = 0; i <= n; i++) if (dp[i] != -1) {
                if (x == p - i) chmax(ndp[i], dp[i] + 1);
                else chmax(ndp[i], dp[i]);
                chmax(ndp[i + 1], dp[i]);
            }
            swap(dp, ndp);
            // rep(i, n + 1) cout << dp[i] << " \n"[i == n];
        }
        int ans = -1;
        rep(i, n + 1) if (dp[i] >= k) {
            ans = i;
            break;
        }
        cout << ans << '\n';
    }
}