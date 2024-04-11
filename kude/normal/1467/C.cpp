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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n[3];
    rep(i, 3) cin >> n[i];
    VVL a;
    rep(i, 3) {
        VL t(n[i]);
        rep(j, n[i]) cin >> t[j];
        a.push_back(t);
    }
    ll ans = -1e16;
    ll sm = 0;
    ll mn[3];
    rep(i, 3) {
        ll t = 1e18;
        rep(j, n[i]) chmin(t, a[i][j]);
        mn[i] = t;
    }
    rep(i, 3) rep(j, n[i]) sm += a[i][j];
    rep(i, 3) rep(j, i) {
        chmax(ans, sm - (mn[i] + mn[j]) * 2);
    }
    rep(i, 3) {
        ll t = 0;
        rep(j, n[i]) t += a[i][j];
        chmax(ans, sm - t * 2);
    }
    cout << ans << endl;
}