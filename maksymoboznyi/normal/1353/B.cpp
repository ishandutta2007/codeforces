#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int n, m, a[N], b[N];


signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> n >> k;
        int ans = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], ans += a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        sort(a + 1, a + n + 1);
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= k; i++)
            if (a[i] >= b[n - i + 1])
                break;
            else
                ans -= a[i], ans += b[n - i + 1];
        cout << ans << "\n";
    }
    return 0;
}