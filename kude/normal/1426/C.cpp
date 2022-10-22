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
    int t;
    cin >> t;
    while(t--) {
        ll n;
        cin >> n;
        ll l = 0, r = 1000000;
        while(r - l > 1) {
            ll m = (l + r) / 2;
            if (m * m < n) l = m;
            else r = m;
        }
        ll ans = r - 1;
        ans += (n + r - 1) / r - 1;
        cout << ans << endl;
    }
}