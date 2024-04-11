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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n;
    cin >> n;
    vector<map<ll, ll>> hist(n);
    VI sm(n);
    rep(i, n) {
        string s;
        cin >> s;
        ll now = 0;
        ll mn = 1001001001;
        for(char c: s) {
            if (c == '(') now++;
            else now--;
            chmin(mn, now);
            if (now == mn) hist[i][now]++;
        }
        sm[i] = now;
    }
    ll ans = 0;
    VL dp(1 << n, (ll)-1e18);
    dp[0] = 0;
    rep(s, 1 << n) {
        ll now = 0;
        rep(i, n) if (s >> i & 1) now += sm[i];
        rep(j, n) if (!(s >> j & 1)) {
            auto it = hist[j].find(-now);
            ll nxt = dp[s] + (it != hist[j].end() ? it->second : 0);
            // if (nxt == 2) cout << s << ' ' << j << endl;
            chmax(ans, nxt);
            if (now + hist[j].begin()->first >= 0) chmax(dp[s | 1 << j], nxt);
        }
    }
    // rep(i, 4) cout <<dp[i] << ' ';
    cout << ans << endl;
}