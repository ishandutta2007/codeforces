#include <bits/stdc++.h>
#define pb push_back

using namespace std;

const int N = 5e5 + 5;

int last[N], n, a[N];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int ans = 0;
    for (int i = n; i > 0; i--)
    if (a[i] != a[1]) {
        ans = max(i - 1, ans);
        break;
    }
    for (int i = 1; i < n; i++)
        if (a[i] != a[n])
    {
        ans = max(ans, n - i);
    }
    cout << ans;
    return 0;
}