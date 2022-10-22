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

int dp[1000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    rep(i, 1000) dp[i] = 1001001001;
    dp[1] = 0;
    dp[2] = 1;
    for(int i = 2; i < 1000; ++i) {
        chmin(dp[i+1], dp[i] + 1);
        for(int j = 2;; ++j) {
            if (i * j >= 1000) break;
            chmin(dp[i*j], dp[i] + 1);
        }
    }
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        int ans = 0;
        if (n < 1000) ans = dp[n];
        else ans = n % 2 == 0 ? 2 : 3;
        cout << ans << '\n';
    }
}