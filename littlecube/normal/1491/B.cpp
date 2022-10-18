#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define MOD 1000000007
#define _INFINITY 9223372036854775807
#define fast ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

signed main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        ll n, u, v, ans = _INFINITY, pos[105];
        cin >> n >> u >> v;
        for (int i = 1; i <= n; i++)
            cin >> pos[i];
        for (int i = 1; i < n; i++)
            if (abs(pos[i] - pos[i + 1]) >= 2)
                ans = 0;
        for (int i = 1; i < n; i++)
            if (pos[i] != pos[i + 1])
                ans = min(ans, u);
        for (int i = 1; i < n; i++)
            if (abs(pos[i] - pos[i + 1]) == 1)
                ans = min(ans, v);
        ans = min(ans, u + v);
        ans = min(ans, v + v);
        cout << ans << '\n';
    }
}