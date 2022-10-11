#include <bits/stdc++.h>
using namespace std;

const int N = 100005;

int n, d, ans = 0, a[N], su[N], mi[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> d;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = n; i >= 1; i--)
        mi[i] = min(mi[i + 1], su[i] = su[i + 1] + a[i]);
    int cur = 0;
    for (int i = 1; i <= n; i++)
    {
        if ((cur += a[i]) > d)
            return cout << -1, 0;
        if (a[i] == 0 && cur < 0)
        {
            ans++;
            cur = d - (su[i + 1] - mi[i + 1]);
            if (cur < 0)
                return cout << -1, 0;
        }
    }
    cout << ans;
}