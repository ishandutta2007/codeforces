#include <bits/stdc++.h>
#define int long long
#define pb push_back
using namespace std;

const int N = 2e5 + 5;

int n, m, a[N], b[N];
int x, k, y;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> x >> k >> y;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int j = 1; j <= m; j++)
        cin >> b[j];
    int cur = 1;
    int ans = 0;
    n++;
    m++;
    for (int i = 1; i <= m; i++) {
        int sz = 0;
        int mx = 0;
        while (cur <= n && a[cur] != b[i])
            sz++, mx = max(mx, a[cur]), cur++;
        if (cur > n) {
            cout << -1;
            return 0;
        }
        cur++;

        int cc = 1e18;
        if (mx < b[i] || mx < b[i - 1])
            cc = y * sz;
        if (sz >= k)
            cc = min(cc, sz % k * y + sz / k * x);
        if (sz >= k)
            cc = min(cc, x + (sz - k) * y);
        if (cc == 1e18) {
            cout << -1;
            return 0;
        }///!!!
        ans += cc;
    }
    cout << ans;
    return 0;
}