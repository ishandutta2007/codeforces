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
    int n;
    cin >> n;
    VL a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    VVL dp(n + 1, VL(n + 1));
    rep(r, n + 1) {
        dp[r][r] = 0;
        if (r - 1 >= 0) dp[r - 1][r] = a[r - 1] * b[r - 1];
        if (r - 2 >= 0) dp[r - 2][r] = a[r - 2] * b[r - 1] + a[r - 1] * b[r - 2];
        for(int l = r - 3; l >= 0; l--) {
            dp[l][r] = dp[l + 1][r - 1] + a[l] * b[r - 1] + a[r - 1] * b[l];
        }
    }
    VL s(n + 1);
    rep(i, n) s[i + 1] = s[i] + a[i] * b[i];
    ll ans = s[n];
    rep(r, n + 1) rep(l, r) {
        chmax(ans, s[l] + dp[l][r] + s[n] - s[r]);
    }
    cout << ans << '\n';
}