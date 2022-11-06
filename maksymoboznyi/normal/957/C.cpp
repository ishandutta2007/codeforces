#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int N = 2e5+5;
const long long inf = 2e18;
int pos[N], t[4*N], n, u, a[N], pref[N], suff[N];

signed main()
{
    cin >> n >> u;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    double ans = -1;
    for (int j = 2; j < n; j++)
    {
        int l = j+1, r = n;
        while (l < r-1)
        {
            int m = (l+r)/2;
            if (a[m] - a[j-1] >= u)
                r = m;
            else
                l = m;
        }
        if (a[r] - a[j-1] <= u)
            ans = max(ans, (a[r] - a[j])*1.0/(a[r] - a[j-1]));
        else
            if (a[l] - a[j-1] <= u)
                ans = max(ans, (a[l]-a[j])*1.0/(a[l] - a[j-1]));
    }
    if (ans == -1)
        cout << -1;
    else
        cout << fixed << setprecision(9) << ans;
    return 0;
}