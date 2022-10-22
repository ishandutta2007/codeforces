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
    VL a(n);
    rep(i, n) cin >> a[i];
    ll s = accumulate(all(a), 0LL);
    sort(all(a));
    int m;
    cin >> m;
    rep(_, m) {
        ll x, y;
        cin >> x >> y;
        int i = lower_bound(all(a), x) - a.begin();
        ll ans = 2002003004005006007;
        if (i < n) {
            ll defense = s - a[i];
            chmin(ans, max(0LL, y - defense));
        }
        if (i) {
            ll defense = s - a[i-1];
            chmin(ans, max(0LL, y - defense) + x - a[i - 1]);
        }
        cout << ans << '\n';
    }
}