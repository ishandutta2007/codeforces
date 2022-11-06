#include <bits/stdc++.h>
#define pb push_back
#define int long long

using namespace std;

const int N = 1e5 + 5;
const int INF = 1e18;

int n, t, a[N], have[50], b[N];

bool check(int r) {
    r--;
    for (int i = 1; i <= n; i++)
        b[i] = a[i];
    for (int i = 2; i <= n; i++)
        if (a[i] < a[i - 1])
            for (int b = min(r, 40ll); b >= 0; b--)
                if (a[i] + (1ll << b) <= a[i - 1])
                    a[i] += (1ll << b);
    int cur = 0, mx = 0;
    for (int i = 2; i <= n; i++)
        if (a[i] < a[i - 1])
            cur++;
        else
            mx = max(mx, cur), cur = 0;
    mx = max(mx, cur);
    for (int i = 1; i <= n; i++)
        a[i] = b[i];
    if (mx == 0)
        return 1;
    return (40 + mx <= r);
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> n;
        bool is = 1;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        int l = -1, r = 33 * n;
        while (l < r - 1) {
            int m = (l + r) / 2;
            if (check(m))
                r = m;
            else
                l = m;
        }
        cout << r << "\n";

    }
    return 0;
}