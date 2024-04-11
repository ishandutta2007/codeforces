#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)
#define all(x) (x).begin(), (x).end()
using namespace std;
using ll = long long;
using P = pair<int,int>;
using VI = vector<int>;
using VVI = vector<VI>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n, q;
        cin >> n >> q;
        VI a(n+1), b(n);
        rep(i, n) {
            cin >> a[i+1];
            b[i] = a[i+1] - a[i];
        }
        ll ans = 0;
        rep(i, n) if (b[i] > 0) ans += b[i];
        cout << ans << '\n';
        while(q--) {
            int l, r;
            cin >> l >> r;
            if (l == r) {
                cout << ans << '\n';
                continue;
            }
            swap(a[l], a[r]);
            for(int s: {l, r}) {
                if (b[s-1] > 0) ans -= b[s-1];
                if (s < n && b[s] > 0) ans -= b[s];
                b[s-1] = a[s] - a[s-1];
                if (s < n) b[s] = a[s+1] - a[s];
                if (b[s-1] > 0) ans += b[s-1];
                if (s < n && b[s] > 0) ans += b[s];
            }
            cout << ans << '\n';
        }
    }
}