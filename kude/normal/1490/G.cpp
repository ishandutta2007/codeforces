#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < int(n); ++i)
#define rrep(i,n) for(int i = int(n)-1; i >= 0; --i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<class T> void chmax(T& a, const T& b) {a = max(a, b);}
template<class T> void chmin(T& a, const T& b) {a = min(a, b);}
using ll = long long;
using P = pair<ll,int>;
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
        int n, m;
        cin >> n >> m;
        VL a(n);
        rep(i, n) cin >> a[i];
        VL s{0};
        rep(i, n) s.push_back(s.back() + a[i]);
        rep(i, n) s.push_back(s.back() + a[i]);
        ll tot = s[n];
        rep(i, 2 * n) chmax(s[i+1], s[i]);
        rep(i, m) {
            ll x;
            cin >> x;
            ll l = 0, r = 1002003004005006007;
            while(r - l > 1) {
                ll c = l + r >> 1;
                ll q = c / n, rm = c % n;
                bool ok = false;
                if (q != 0 && tot >= (x + q - 1) / q) ok = true;
                else {
                    if (tot < 0) {
                        if (q) {
                            rm = n;
                            q = 0;
                        }
                    } else if (q >= 1) {
                        q -= 1;
                        rm += n;
                    }
                    if (s[rm] + tot * q >= x) ok = true;
                }
                if (ok) r = c;
                else l = c;
            }
            ll ans = r - 1;
            if (ans == 1002003004005006006) ans = -1;
            cout << ans << " \n"[i + 1 == m];
        }
    }
}