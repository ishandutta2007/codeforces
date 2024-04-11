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
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VL a(n);
        rep(i, n) cin >> a[i];
        ll s = 0;
        rep(i, n) s += a[i];
        ll tot = (s + (n - 2)) / (n - 1) * (n - 1);
        ll mx = 0;
        rep(i, n) chmax(mx, a[i]);
        chmax(tot, mx * (n - 1));
        ll ans = tot - s;
        cout << ans << '\n';
    }
}