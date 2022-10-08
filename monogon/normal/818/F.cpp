
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define fi first
#define se second
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;

// X - X - X - X - X
// k bridges reserved
// n-k nodes left, we do (n - k) (n - k - 1) / 2 more edges
// (n - k)(n - k - 1) <= 2k

int t;
ll n;
typedef long double ftype;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        ll L = 0, R = n;
        while(L < R) {
            ll m = (L + R) / 2;
            if((n - m) * (n - m - 1) >= 2 * m) {
                L = m + 1;
            }else {
                R = m;
            }
        }
        ll ans = 0;
        for(ll k = max(0LL, L - 2); k <= min(n - 1, L + 2); k++) {
            ans = max(ans, k + min(k, (n - k) * (n - k - 1) / 2));
        }
        cout << ans << '\n';
    }
}