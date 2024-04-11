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
        int n, k;
        cin >> n >> k;
        VI h(n);
        rep(i, n) cin >> h[i];
        bool ok = true;
        int mn, mx;
        mn = mx = h[0];
        for(int i = 1; i < n - 1; ++i) {
            mx = min(h[i], mx) + k - 1;
            mn = max(h[i], mn - (k - 1));
            if (mx < mn) ok = false;
        }
        if (!(mn - (k - 1) <= h[n-1] && h[n-1] <= mx + (k - 1))) ok = false;
        cout << (ok ? "YES\n" : "NO\n");
    }
}