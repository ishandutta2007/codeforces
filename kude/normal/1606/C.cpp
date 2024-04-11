#include<bits/stdc++.h>
namespace {
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

ll pow10[19];

} int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    pow10[0] = 1;
    rep(i, 18) pow10[i + 1] = 10 * pow10[i];
    int tt;
    cin >> tt;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        k++;
        VI a(n);
        rep(i, n) cin >> a[i];
        ll ans = 0;
        rep(i, n - 1) {
            int mx = pow10[a[i + 1] - a[i]] - 1;
            int r = min(k, mx);
            k -= r;
            ans += pow10[a[i]] * r;
        }
        ans += pow10[a[n - 1]] * k;
        cout << ans << '\n';
    }
}