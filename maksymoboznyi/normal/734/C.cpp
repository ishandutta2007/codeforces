#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 5;

int n, m, k, a[N], b[N], c[N], d[N], x, sum;

signed main()
{
    cin >> n >> m >> k;
    cin >> x >> sum;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
        cin >> b[i];
    for (int i = 1; i <= k; i++)
        cin >> c[i];
    for (int i = 1; i <= k; i++)
        cin >> d[i];
    int ans = 5e18;
    b[0] = 0;
    a[0] = x;
    for (int i = 0; i <= m; i++)
        if (b[i] <= sum)
        {
            int pos = upper_bound(d + 1, d + k + 1, sum - b[i]) - d - 1;
           // cout << i << ' ' << pos << ' ' << d[pos] << ' ' << c[pos] << ' ' << (n - c[pos]) *a[i] << endl;
            if (pos == 0)
                ans = min(ans, a[i] * n);
            else
                ans = min(ans, max(n - c[pos], 1ll*0) * a[i]);
        }

    cout << ans;
    return 0;
}