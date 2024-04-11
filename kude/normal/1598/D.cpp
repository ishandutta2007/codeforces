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
    int tt;
    cin >> tt;
    while(tt--) {
        ll n;
        cin >> n;
        VI a(n), b(n);
        VI hist_a(n), hist_b(n);
        rep(i, n) cin >> a[i] >> b[i], a[i]--, b[i]--, hist_a[a[i]]++, hist_b[b[i]]++;
        ll ans = n * (n - 1) * (n - 2) / 6;
        rep(i, n) {
            ans -= ll(hist_a[a[i]] - 1) * (hist_b[b[i]] - 1);
        }
        cout << ans << '\n';
    }
}