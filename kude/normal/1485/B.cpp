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
    ll n, q, k;
    cin >> n >> q >> k;
    VL a(n);
    rep(i, n) cin >> a[i];
    VL d(n);
    for(int i = 1; i + 1 < n; ++i) {
        d[i] = a[i+1] - a[i-1] - 2;
    }
    VL s(n);
    rep(i, n - 1) s[i+1] = s[i] + d[i];
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--;
        if (l + 1 == r) {
            cout << k - 1 << '\n';
            continue;
        }
        ll ans = 0;
        if (l + 1 < r - 1) {
            ans += s[r-1] - s[l+1];
        }
        ans += a[l+1] - 2;
        ans += k - a[r-2] - 1;
        cout << ans << '\n';
    }
}