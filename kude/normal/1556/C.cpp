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
    VL c(n);
    rep(i, n) cin >> c[i];
    VL s(n + 1);
    rep(i, n) {
        if (i % 2 == 0) s[i + 1] = s[i] + c[i];
        else s[i + 1] = s[i] - c[i];
    }
    map<ll, int> mp;
    rep(i, n + 1) mp[s[i]], mp[s[i] + 1];
    int sz = 0;
    for(auto& [k, v]: mp) v = sz++;
    VL to_d(sz);
    for(auto& [k, v]: mp) to_d[v] = k;
    VL dp(sz);
    int now = mp[0];
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int nxt = mp[s[i]];
        // cout << now << ' ' << nxt << endl;
        if (i % 2) {
            for(; now < nxt; now++) dp[now]++;
        } else {
            for(; now > nxt; now--) ans += (to_d[now + 1] - to_d[now]) * dp[now], dp[now] = 0;
            ans += (to_d[nxt + 1] - to_d[nxt]) * dp[nxt];
        }
        // rep(i, sz) cout << dp[i] << " \n"[i + 1 == sz];
        now = nxt;
    }
    cout << ans << '\n';
}