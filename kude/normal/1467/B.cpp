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

int score(int x, int y, int z) {
    return x < y && y > z || x > y && y < z;
}

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
        int tot = 0;
        for(int i = 1; i < n - 1; ++i) {
            tot += score(a[i-1], a[i], a[i+1]);
        }
        int ans = tot;
        rep(i, n) {
            if (i - 1 >= 0) {
                int t = tot;
                if (i + 1 < n) {
                    t -= score(a[i-1], a[i], a[i+1]);
                }
                if (0 <= i - 2) {
                    t -= score(a[i-2], a[i-1], a[i]);
                }
                if (i + 2 < n) {
                    t -= score(a[i], a[i+1], a[i+2]);
                    t += score(a[i-1], a[i+1], a[i+2]);
                }
                chmin(ans, t);
            }
            if (i + 1 < n) {
                int t = tot;
                if (0 <= i - 1) {
                    t -= score(a[i-1], a[i], a[i+1]);
                }
                if (i + 2 < n) {
                    t -= score(a[i], a[i+1], a[i+2]);
                }
                if (0 <= i - 2) {
                    t -= score(a[i-2], a[i-1], a[i]);
                    t += score(a[i-2], a[i-1], a[i+1]);
                }
                chmin(ans, t);
            }
        }
        cout << ans << '\n';
    }
}