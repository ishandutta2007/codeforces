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
    while(tt--) {
        int n;
        cin >> n;
        VL a(n), b(n), c(n);
        rep(i, n) cin >> c[i];
        rep(i, n) cin >> a[i];
        rep(i, n) cin >> b[i];
        ll ans = 0;
        ll now = c[n - 1] - 1;
        rrep(i, n - 1) {
            now += 2;
            chmax(ans, now + abs(a[i + 1] - b[i + 1]));
            if (i == 0 || a[i + 1] == b[i + 1]) {
                now = c[i] - 1;
            } else {
                now += c[i] - 1 - abs(a[i + 1] - b[i + 1]);
                chmax(now, c[i] - 1);
            }
            
        }
        cout << ans << '\n';
    }
}