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

int dp[1 << 18][2];
int a[1 << 18];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    auto add = [&](int pos, int d) {
        if (d == dp[pos][0] || d == dp[pos][1]) return;
        if (d > dp[pos][0]) {
            dp[pos][1] = dp[pos][0];
            dp[pos][0] = d;
            return;
        } else if (d > dp[pos][1]) {
            dp[pos][1] = d;
        }
    };
    while(tt--) {
        int n, k;
        cin >> n >> k;
        int n2 = 1, p = 0;
        while(n2 <= n) n2 *= 2, p++;
        rep(i, n2) rep(j, 2) dp[i][j] = -1;
        for(int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            add(x, i);
        }
        rep(d, p) rep(i, n2) if ((i >> d & 1) == 0) {
            int j = i | 1 << d;
            add(j, dp[i][0]);
            add(j, dp[i][1]);
        }
        ll ans = -1e18;
        rep(i, n2) if (dp[i][1] != -1) chmax(ans, (ll)dp[i][0] * dp[i][1] - k * i);
        cout << ans << '\n';
    }
}