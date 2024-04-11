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
        VI a(n);
        rep(i, n) cin >> a[i];
        int ans;
        rep(i, n) {
            // [0, i]
            int s = 0;
            rep(j, i + 1) s += a[j];
            bool ok = true;
            int now = 0;
            int cnt = 0;
            rep(j, n) {
                now += a[j];
                if (now > s) {
                    ok = false;
                    break;
                } else if (now == s) {
                    now = 0;
                } else {
                    cnt++;
                }
            }
            if (now) ok = false;
            if (ok) {
                ans = cnt;
                break;
            }
        }
        cout << ans << '\n';
    }
}