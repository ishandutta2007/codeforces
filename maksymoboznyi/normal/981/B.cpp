#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

const int N = 1e5+5;
const long long inf = 2e18;

int n, m, a[N], b[N], x[N], y[N];
map <int, int> kol;
map <int, bool> used;
signed main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> x[i];
        kol[a[i]] = x[i];
        used[a[i]] = 0;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i] >> y[i];
        used[b[i]] = 0;
        kol[b[i]] = max(kol[b[i]], y[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += kol[a[i]];
        used[a[i]] = 1;
    }
    for (int i = 1; i <= m; i++)
    if (!used[b[i]])
    {
        ans += kol[b[i]];
        used[b[i]] = 1;
    }
    cout << ans;
    return 0;
}