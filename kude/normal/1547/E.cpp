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
    int tt;
    cin >> tt;
    constexpr int INF = 1001001001;
    while(tt--) {
        int n, k;
        cin >> n >> k;
        VI a(k), t(k);
        rep(i, k) cin >> a[i];
        rep(i, k) cin >> t[i];
        VI d(n, INF);
        rep(i, k) d[a[i] - 1] = t[i];
        VI ans(n, INF);
        int now = INF;
        rep(i, n) {
            chmin(now, d[i]);
            chmin(ans[i], now);
            now++;
        }
        rrep(i, n) {
            chmin(now, d[i]);
            chmin(ans[i], now);
            now++;
        }
        rep(i, n) cout << ans[i] << " \n"[i + 1 == n];
    }
}