#include <bits/stdc++.h>
#define int long long
using namespace std;

#define fi first
#define se second
#define all(a) a.begin(), a.end()

const int N = (1<<20);
const int mod = 1e9+7;

int t, n, k, a[N];

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> k;
        for (int i=0; i<n; i++)
            cin >> a[i];
        
        int ans = 0;
        for (int i=0; i<n; i++)
            ans += a[i];
        ans += n * k;
        for (int i=1; i<=k; i++)
            ans -= i;
        
        for (int i=0; i<n; i++)
            a[i] += i;
        sort(a,a+n);
        for (int i=0; i<k; i++)
            ans -= a[n-i-1];

        cout << ans << endl;
    }
}