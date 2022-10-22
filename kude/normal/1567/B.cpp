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
    VI dp(400000);
    rep(i, 400000 - 1) dp[i + 1] = dp[i] ^ i;
    while(tt--) {
        int a, b;
        cin >> a >> b;
        int ans = a;
        int x = dp[a] ^ b;
        if (x > 0) {
            if (x != a) ans++;
            else ans += 2;
        }
        cout << ans << '\n';
    }
}