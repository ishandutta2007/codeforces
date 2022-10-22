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
        int n, m;
        cin >> n >> m;
        VI k(n), c(m);
        rep(i, n) cin >> k[i], --k[i];
        rep(i, m) cin >> c[i];
        sort(all(k));
        int j = 0;
        ll ans = 0;
        rrep(i, n) {
            if (j < k[i]) ans += c[j++];
            else ans += c[k[i]];
        }
        cout << ans << '\n';
    }
}