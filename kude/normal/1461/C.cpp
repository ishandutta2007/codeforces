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
    cout << fixed << setprecision(12);
    int tt;
    cin >> tt;
    while(tt--) {
        int n, m;
        cin >> n >> m;
        VI a(n);
        int mx = -1;
        rep(i, n) {
            int t;
            cin >> t;
            t--;
            if (t != i) mx = i;
        }
        double acc = 1;
        rep(i, m) {
            int r;
            double p;
            cin >> r >> p;
            --r;
            if (r >= mx) acc *= 1 - p;
        }
        double ans = (mx == -1 ? 1 : 1 - acc);
        cout << ans << '\n';
    }
}