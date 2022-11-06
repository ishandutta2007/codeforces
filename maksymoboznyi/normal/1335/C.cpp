#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 2e5 + 5;
const int INF = 1e18;

int a[N], kol[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
            kol[i] = 0;
        int mx = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i], kol[a[i]]++, mx = max(mx, kol[a[i]]);
        int d = 0;
        for (int i = 1; i <= n; i++)
            d += (kol[i] > 0);
        int ans = min(d - 1, mx);
        ans = max(ans, min(d, mx - 1));
        cout << ans << "\n";

    }
    return 0;
}