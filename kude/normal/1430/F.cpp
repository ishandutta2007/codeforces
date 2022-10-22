#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;


int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> l(n), r(n), a(n);
    rep(i, n) cin >> l[i] >> r[i] >> a[i];
    vector<ll> req(n);
    ll req_now = 0;
    rrep(i, n) {
        if (i + 1 < n && r[i] < l[i+1]) req_now = 0;
        req_now += a[i];
        req_now -= (r[i] - l[i]) * k;
        chmax(req_now, 0LL);
        if(req_now > k) {
            cout << -1 << endl;
            return 0;
        }
        req[i] = req_now;
    }
    ll ans = 0;
    ll now = k;
    ll time = 0;
    rep(i, n) {
        time = l[i];
        ll used = min(a[i], now);
        now -= used;
        a[i] -= used;
        ans += used;
        if (a[i]) {
            ll c = (a[i] + k - 1) / k;
            time += c;
            ans += a[i];
            now = c * k - a[i];
        }
        if (i + 1 < n && now < req[i+1]) {
            if (time >= l[i+1]) {
                cout << -1 << endl;
                return 0;
            }
            ans += now;
            now = k;
        }
    }
    cout << ans << endl;
}