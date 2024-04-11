#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define rrep(i,n) for (int i = (n)-1; i >= 0; --i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    int tt;
    cin >> tt;
    while(tt--) {
        int n;
        cin >> n;
        VI a(n);
        rep(i, n) cin >> a[i];
        int mx = -1;
        rep(i, n) chmax(mx, a[i]);
        int ans = -2;
        rep(i, n) {
            if (i && a[i] == mx && a[i-1] < mx) ans = i;
            if (i + 1 < n && a[i] == mx && a[i+1] < mx) ans = i;
        }
        cout << ans + 1 << '\n';
    }
}