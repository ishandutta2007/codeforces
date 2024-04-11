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

bool a[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, p, k;
        cin >> n >> p >> k;
        --p;
        rep(i, n) {
            char c;
            cin >> c;
            a[i] = c - '0';
        }
        int x, y;
        cin >> x >> y;
        VI dp(n);
        rrep(i, n) {
            if (i + k >= n) {
                dp[i] = (!a[i]) * x;
            } else {
                dp[i] = (!a[i]) * x + dp[i+k];
            }
        }
        int ans = 1001001001;
        for(int i = p; i < n; ++i) {
            chmin(ans, (i - p) * y + dp[i]);
        }
        cout << ans << '\n';
    }
}