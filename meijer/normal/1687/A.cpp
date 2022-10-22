#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t, n, k, a[N];
int sm[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        int ans = 0;
        if (k >= n) {
            for (int i=0; i<n; i++) {
                ans += a[i];
            }
            ans += n * k;
            for (int i=1; i<=n; i++) {
                ans -= i;
            }
        } else {
            sm[0] = 0;
            for (int i=0; i<n; i++)
                sm[i+1] = sm[i] + a[i];
            for (int i=0; i<=n-k; i++) {
                ans = max(ans, sm[i+k] - sm[i]);
            }
            for (int i=1; i<k; i++) {
                ans += i;
            }
        }
        cout << ans << endl;
    }
}